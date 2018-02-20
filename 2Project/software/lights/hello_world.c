/*
 * PROJECT 2: WYLIE GUNN AND DALLIN WILLIAMS
 */

#include <stdio.h>
#include <unistd.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "alt_types.h"
#include <altera_up_avalon_video_character_buffer_with_dma.h>  // to write characters to video
#include <altera_up_avalon_video_pixel_buffer_dma.h> // to swap front and back buffer
#include <math.h>  // for trigonometry functions
#include <stdlib.h>  // for file I/O

/*
A few functions to simplify video/character buffer stuff
*/

void clear_screen() {
	alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
}

//not sure about this one
void draw_pixel(int i, int j) {
	alt_up_pixel_buffer_dma_draw(my_pixel_buffer, 
		(my_image[(i*320*3+j*3+2)]) +
		(my_image[(i*32-*3+j*3+1)]<<8) +
		(my_image[(i*320*3+j*3+0)]<<16), j, i);
}
	
void write_text(string message) {
	alt_up_char_buffer_string(my_char_buffer,message,0,59);
}

//TODO:
void rotate() {

}

void scale_down() {

}

void scale_up(){

}

int main()
{
	// open the .dat file
	FILE *myfile;
	myfile = fopen("my_fs/myfile.dat","rb");
	if(myfile==NULL) perror ("error opening datafile");

	//allocate memory and read image data
	my_image = (alt_u8 *)malloc(320*240*3);
	fread(my_image,sizeof(alt_u8),320*240*3,myfile);


	//pixel buffer

	alt_up_pixel_buffer_dma_dev *my_pixel_buffer; //declare global var
	my_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0"); //assign it
	clear_screen();

	//character buffer
	alt_up_char_buffer_dev *my_char_buffer; //declare global var
	my_char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	if(!my_char_buffer) printf ("error opening character buffer\n");
	alt_up_char_buffer_clear(my_char_buffer);
	write_text("Video works!");

	//to keep track of scaling 
	int scale_counter = 0;


	while (1) {
	keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
	
	// detect key press
	if ((keys != 7) && (keys != current_state)) {
		if (keys == 3)  printf("key 3 pressed\n");
		else if (keys == 5)
			printf("key 2 pressed\n");
		else if (keys == 6)
			printf("key 1 pressed\n");
		current_state=keys;
	}


	if (current_state == 3) {
		// Display the unaltered image to the VGA
		for(int i=0; i<239; i++){
			for(int j=0; j<320; j++) {
				draw_pixel(i,j);
			}
		}
		// Also display text that says "original image"
		write_text("Original Image")
	} 
	else if (current_state == 5) {
		// Continuously rotate the image clockwise; 10 degree increments
		// As fast as the processor can handle
		rotate();
	} 
	else if (current_state == 6) {
		// Shrink the image in 10% increments until it is 10% of the original
		// Grow the image back to original size
		// Repeat as fast as the processor can handle
		if(scale_counter < 10) {
			scale_down();
		}
		else if(scale_counter < 20) {
			scale_up();
		}
		if(scale_counter == 20) {
			scale_counter = 0;
		}
		scale_counter++;
	}


	// update lights
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,current_value);

}
