/*
 * PROJECT 4: WYLIE GUNN AND DALLIN WILLIAMS
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
#include <altera_avalon_performance_counter.h>
#include "altera_avalon_mailbox.h"

#define FIXED_POINT

alt_up_pixel_buffer_dma_dev *my_pixel_buffer; //declare global var
const int num_rows = 240;  //from 320
const int num_cols = 320; //from 240
float row;
float col;
int shift_amt = 9;
int div_amt = 512.0f;
//int div_amt = 512.0f;


int rcount;
int bool_dec;
float scount;

int main()
{

	// open the .dat file
	FILE *myfile;
	//myfile = fopen("my_fs/myfile.dat","rb");
	myfile=fopen("my_fs/myfile.dat","rb");
	if(myfile==NULL) perror ("error opening datafile");

	//allocate memory and read image data

	alt_u32 keys;
	alt_u32 current_value = 1;
	alt_u32 current_state = 3;
	alt_u8 *my_image;
	my_image = (alt_u8 *)malloc(320*240*3);
	fread(my_image,sizeof(alt_u8),320*240*3,myfile);

	//declaring mailboxes
	alt_u32 message = 0;
	alt_mailbox_dev* mailbox_0;
	alt_mailbox_dev* mailbox_1;

	mailbox_0 = altera_avalon_mailbox_open("/dev/mailbox_0");
	mailbox_1 = altera_avalon_mailbox_open("/dev/mailbox_1");


	int cpuid = __builtin_rdctl(5);
	if(cpuid == 1){
	#define CPU1;
	}
#ifdef CPU1
	printf("CPU 1 active");
#endif

	/*
	if(cpuid == 0) {
		altera_avalon_mailbox_post(mailbox_1, message);
		altera_avalon_mailbox_pend(mailbox_0);
	} else {
		altera_avalon_mailbox_post(mailbox_0, message);
		altera_avalon_mailbox_pend(mailbox_1);
	}
*/


	//pixel buffer

	//alt_up_pixel_buffer_dma_dev *my_pixel_buffer; //declare global var
	my_pixel_buffer=alt_up_pixel_buffer_dma_open_dev("/dev/video_pixel_buffer_dma_0"); //assign it
	alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);//clear_screen();

	//character buffer
	alt_up_char_buffer_dev *my_char_buffer; //declare global var
	my_char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	if(!my_char_buffer) printf ("error opening character buffer\n");
	alt_up_char_buffer_clear(my_char_buffer);

	//write_text("Video works!");

	while (1) {
	keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);

	// detect key press
	if ((keys != 7) && (keys != current_state)) {
		alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
		if (keys == 3)  printf("key 3 pressed\n");
		else if (keys == 5) {
			rcount = 10;
			alt_up_char_buffer_clear(my_char_buffer);
			printf("key 2 pressed\n");
		}

		else if (keys == 6) {
			bool_dec = 1;
			scount = 1.0f;
			alt_up_char_buffer_clear(my_char_buffer);
			printf("key 1 pressed\n");
		}
		current_state=keys;
	}

	//default state: display image and text
	if (current_state == 3) {
		// Display the unaltered image to the VGA

		alt_up_char_buffer_string(my_char_buffer, "Original Image!",0,59);
		int i, j;

		for(i=0; i<239; i++){
			//break if key press
			keys = keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			if (keys != 7 && keys != 3) {
				break;
			}
			for(j=0; j<320; j++) {
				//draw_pixel(i,j);
				alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(my_image[(i*320*3+j*3+2)]) +(my_image[(i*320*3+j*3+1)]<<8) +(my_image[(i*320*3+j*3+0)]<<16),j,i);
				//alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(my_image[(0.9*i*320*3+0.9*j*3+2)]) +(my_image[(0.9*i*320*3+0.9*j*3+1)]<<8) +(my_image[(0.9*i*320*3+0.9*j*3+0)]<<16),j,i);

			}
		}
	}

	// Continuously rotate the image clockwise; 10 degree increments
	// As fast as the processor can handle
	else if (current_state == 5) {
		alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
		int i, j;


		#ifdef FIXED_POINT

		int sine = (int) (sinf(rcount*(M_PI/180))*div_amt);
		int cosine = (int)(cosf(rcount*(M_PI/180))*div_amt);

		#else

		float sine = sinf(rcount*(M_PI/180));
		float cosine = cosf(rcount*(M_PI/180));

		#endif



		//reset performance counter
		PERF_RESET(PERFORMANCE_COUNTER_0_BASE);
		PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);


		//int cpuid = __builtin_rdctl(5);
		printf("%d cpuid_first_loop: \n", cpuid);
		if(cpuid == 0){
		for(i=cpuid; i<num_rows-1; i+=2){
			//break if key press
			keys = keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			if (keys != 7 && keys != 5) {
				break;
			}



			for(j=0; j<num_cols-1; j++) {
				//start performance counter to record cycles of this innermost loop

				//PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);

				//initial_counter = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
				//printf("%d\n", initial_counter);

				// to rotate about center calculate offset
				int offset_i = i - num_rows/2;
				int offset_j = j - num_cols/2;

				int rowf = 0;
				int colf = 0;


				#ifdef FIXED_POINT
				//calcuate row&col value from fixed point sine/cosine
				alt_u32 rowi = (offset_i*cosine-offset_j*sine + (num_rows*512)/2);
				alt_u32 coli = (offset_i*sine+offset_j*cosine + (num_cols*512)/2);
				//check bounds
				if(coli>(num_cols*512) || coli<0 || rowi>(num_rows*512) || rowi<(0)) continue;
				//'floor' for interpolation
				rowf = rowi/512*512;
				colf = coli/512*512;

				alt_u32 rfrac = (rowi-rowf)/512;
				alt_u32 cfrac = (coli-colf)/512;

				//calculate weights; divide by 512^2

				alt_u32 weight1 = (512-rfrac)*(512-cfrac);
				alt_u32 weight2 = rfrac*(512-cfrac);
				alt_u32 weight3 = rfrac*cfrac;
				alt_u32 weight4 = (512-rfrac)*cfrac;


				weight1 /= 512*512;
				//printf("weight1: %d\n" , weight1);
				weight2 /= 512*512;
				weight3 /= 512*512;
				weight4 /= 512*512;
				//reset rowf&colf values for pixel calculations
				rowf /= 512;
				colf /= 512;
				#endif
				int pixel1 = rowf*320*3 + colf*3;
				int pixel2 = (rowf + 1)*320*3 + colf*3;
				int pixel3 = (rowf + 1)*320*3 + (colf + 1)*3;
				int pixel4 = rowf*320*3 + (colf + 1)*3;


				//three colors
				int in1 = (int) (weight1*my_image[pixel1] +
						weight2*my_image[pixel2] +
						weight3*my_image[pixel3] +
						weight4*my_image[pixel4]);

				int in2 = (int) (weight1*my_image[pixel1+1] +
						weight2*my_image[pixel2+1] +
						weight3*my_image[pixel3+1] +
						weight4*my_image[pixel4+1]);

				int in3 = (int) (weight1*my_image[pixel1+2] +
						weight2*my_image[pixel2+2] +
						weight3*my_image[pixel3+2] +
						weight4*my_image[pixel4+2]);



				//draw_pixel
				alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);

				//send message to mailbox_1
				//altera_avalon_mailbox_post(mailbox_1, message);
				//altera_avalon_mailbox_pend(mailbox_0);

			}
/*
//second for loop for odd iterations
			for(j=1; j<num_cols-1; j+=2) {
				//start performance counter to record cycles of this innermost loop
				//PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);
				//initial_counter = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
				//printf("%d\n", initial_counter);

				// to rotate about center calculate offset
				int offset_i = i - num_rows/2;
				int offset_j = j - num_cols/2;

				int rowf = 0;
				int colf = 0;


				#ifdef FIXED_POINT
				//calcuate row&col value from fixed point sine/cosine
				alt_u32 rowi = (offset_i*cosine-offset_j*sine + (num_rows*512)/2);
				alt_u32 coli = (offset_i*sine+offset_j*cosine + (num_cols*512)/2);
				//check bounds
				if(coli>(num_cols*512) || coli<0 || rowi>(num_rows*512) || rowi<(0)) continue;
				//'floor' for interpolation
				rowf = rowi/512*512;
				colf = coli/512*512;

				alt_u32 rfrac = (rowi-rowf)/512;
				alt_u32 cfrac = (coli-colf)/512;

				//calculate weights; divide by 512^2

				alt_u32 weight1 = (512-rfrac)*(512-cfrac);
				alt_u32 weight2 = rfrac*(512-cfrac);
				alt_u32 weight3 = rfrac*cfrac;
				alt_u32 weight4 = (512-rfrac)*cfrac;


				weight1 /= 512*512;
				//printf("weight1: %d\n" , weight1);
				weight2 /= 512*512;
				weight3 /= 512*512;
				weight4 /= 512*512;
				//reset rowf&colf values for pixel calculations
				rowf /= 512;
				colf /= 512;
				#endif
				int pixel1 = rowf*320*3 + colf*3;
				int pixel2 = (rowf + 1)*320*3 + colf*3;
				int pixel3 = (rowf + 1)*320*3 + (colf + 1)*3;
				int pixel4 = rowf*320*3 + (colf + 1)*3;


				//three colors
				int in1 = (int) (weight1*my_image[pixel1] +
						weight2*my_image[pixel2] +
						weight3*my_image[pixel3] +
						weight4*my_image[pixel4]);

				int in2 = (int) (weight1*my_image[pixel1+1] +
						weight2*my_image[pixel2+1] +
						weight3*my_image[pixel3+1] +
						weight4*my_image[pixel4+1]);

				int in3 = (int) (weight1*my_image[pixel1+2] +
						weight2*my_image[pixel2+2] +
						weight3*my_image[pixel3+2] +
						weight4*my_image[pixel4+2]);



				//draw_pixel
				alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);
				altera_avalon_mailbox_post(mailbox_0, message);
				altera_avalon_mailbox_pend(mailbox_1);
			}
	*/



		}


		//altera_avalon_mailbox_post(mailbox_1, message);
		//altera_avalon_mailbox_pend(mailbox_0);
		altera_avalon_mailbox_post(mailbox_1, message);
		altera_avalon_mailbox_pend(mailbox_0);

		printf("%d cpuid_second_loop: \n", cpuid);
		}
		if(cpuid ==1){
		for(i=cpuid + 1; i<num_rows-1; i+=2){
					//break if key press
					keys = keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
					if (keys != 7 && keys != 5) {
						break;
					}



					for(j=0; j<num_cols-1; j++) {
						//start performance counter to record cycles of this innermost loop

						//PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);

						//initial_counter = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
						//printf("%d\n", initial_counter);

						// to rotate about center calculate offset
						int offset_i = i - num_rows/2;
						int offset_j = j - num_cols/2;

						int rowf = 0;
						int colf = 0;


						#ifdef FIXED_POINT
						//calcuate row&col value from fixed point sine/cosine
						alt_u32 rowi = (offset_i*cosine-offset_j*sine + (num_rows*512)/2);
						alt_u32 coli = (offset_i*sine+offset_j*cosine + (num_cols*512)/2);
						//check bounds
						if(coli>(num_cols*512) || coli<0 || rowi>(num_rows*512) || rowi<(0)) continue;
						//'floor' for interpolation
						rowf = rowi/512*512;
						colf = coli/512*512;

						alt_u32 rfrac = (rowi-rowf)/512;
						alt_u32 cfrac = (coli-colf)/512;

						//calculate weights; divide by 512^2

						alt_u32 weight1 = (512-rfrac)*(512-cfrac);
						alt_u32 weight2 = rfrac*(512-cfrac);
						alt_u32 weight3 = rfrac*cfrac;
						alt_u32 weight4 = (512-rfrac)*cfrac;


						weight1 /= 512*512;
						//printf("weight1: %d\n" , weight1);
						weight2 /= 512*512;
						weight3 /= 512*512;
						weight4 /= 512*512;
						//reset rowf&colf values for pixel calculations
						rowf /= 512;
						colf /= 512;
						#endif
						int pixel1 = rowf*320*3 + colf*3;
						int pixel2 = (rowf + 1)*320*3 + colf*3;
						int pixel3 = (rowf + 1)*320*3 + (colf + 1)*3;
						int pixel4 = rowf*320*3 + (colf + 1)*3;


						//three colors
						int in1 = (int) (weight1*my_image[pixel1] +
								weight2*my_image[pixel2] +
								weight3*my_image[pixel3] +
								weight4*my_image[pixel4]);

						int in2 = (int) (weight1*my_image[pixel1+1] +
								weight2*my_image[pixel2+1] +
								weight3*my_image[pixel3+1] +
								weight4*my_image[pixel4+1]);

						int in3 = (int) (weight1*my_image[pixel1+2] +
								weight2*my_image[pixel2+2] +
								weight3*my_image[pixel3+2] +
								weight4*my_image[pixel4+2]);



						//draw_pixel
						alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);

						//send message to mailbox_1
						//altera_avalon_mailbox_post(mailbox_1, message);
						//altera_avalon_mailbox_pend(mailbox_0);

					}
		/*
		//second for loop for odd iterations
					for(j=1; j<num_cols-1; j+=2) {
						//start performance counter to record cycles of this innermost loop
						//PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);
						//initial_counter = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
						//printf("%d\n", initial_counter);

						// to rotate about center calculate offset
						int offset_i = i - num_rows/2;
						int offset_j = j - num_cols/2;

						int rowf = 0;
						int colf = 0;


						#ifdef FIXED_POINT
						//calcuate row&col value from fixed point sine/cosine
						alt_u32 rowi = (offset_i*cosine-offset_j*sine + (num_rows*512)/2);
						alt_u32 coli = (offset_i*sine+offset_j*cosine + (num_cols*512)/2);
						//check bounds
						if(coli>(num_cols*512) || coli<0 || rowi>(num_rows*512) || rowi<(0)) continue;
						//'floor' for interpolation
						rowf = rowi/512*512;
						colf = coli/512*512;

						alt_u32 rfrac = (rowi-rowf)/512;
						alt_u32 cfrac = (coli-colf)/512;

						//calculate weights; divide by 512^2

						alt_u32 weight1 = (512-rfrac)*(512-cfrac);
						alt_u32 weight2 = rfrac*(512-cfrac);
						alt_u32 weight3 = rfrac*cfrac;
						alt_u32 weight4 = (512-rfrac)*cfrac;


						weight1 /= 512*512;
						//printf("weight1: %d\n" , weight1);
						weight2 /= 512*512;
						weight3 /= 512*512;
						weight4 /= 512*512;
						//reset rowf&colf values for pixel calculations
						rowf /= 512;
						colf /= 512;
						#endif
						int pixel1 = rowf*320*3 + colf*3;
						int pixel2 = (rowf + 1)*320*3 + colf*3;
						int pixel3 = (rowf + 1)*320*3 + (colf + 1)*3;
						int pixel4 = rowf*320*3 + (colf + 1)*3;


						//three colors
						int in1 = (int) (weight1*my_image[pixel1] +
								weight2*my_image[pixel2] +
								weight3*my_image[pixel3] +
								weight4*my_image[pixel4]);

						int in2 = (int) (weight1*my_image[pixel1+1] +
								weight2*my_image[pixel2+1] +
								weight3*my_image[pixel3+1] +
								weight4*my_image[pixel4+1]);

						int in3 = (int) (weight1*my_image[pixel1+2] +
								weight2*my_image[pixel2+2] +
								weight3*my_image[pixel3+2] +
								weight4*my_image[pixel4+2]);



						//draw_pixel
						alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);
						altera_avalon_mailbox_post(mailbox_0, message);
						altera_avalon_mailbox_pend(mailbox_1);
					}
			*/





				}





		altera_avalon_mailbox_post(mailbox_0, message);
		altera_avalon_mailbox_pend(mailbox_1);


		int time = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
		printf("Average time %d\n", time/(320*240));

		rcount+=10;


		}
	}

	// Shrink the image in 10% increments until it is 10% of the original
	// Grow the image back to original size
	// Repeat as fast as the processor can handle
	else if (current_state == 6) {
		alt_up_pixel_buffer_dma_clear_screen(my_pixel_buffer,0);
		printf("scount before drawing is:");
		printf("%f\n", scount);
		int i, j;
		for(i=0; i<num_rows-1; i++){
			//break if key press
			keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			if (keys != 7 && keys != 6) {
				break;
			}
			for(j=0; j<num_cols-1; j++) {
				//center transformation
				int offset_i = i - num_rows/2;
				int offset_j = j - num_cols/2;
				//shrink/grow 10%
				row = offset_i*scount+num_rows/2;
				col = offset_j*scount+num_cols/2;

				if(col>num_cols || col<0 || row>num_rows || row<0) continue;


				//interpolation: cut and pasted from above; should be put in a function
				int rowf = (int)floorf(row);
				int colf = (int)floorf(col);
				float rfrac = row-rowf;
				float cfrac = col-colf;


				float weight1 = (1.0-rfrac)*(1.0-cfrac);
				float weight2 = rfrac*(1.0-cfrac);
				float weight3 = rfrac*cfrac;
				float weight4 = (1.0-rfrac)*cfrac;


				int pixel1 = (rowf*320*3 + colf*3);
				int pixel2 = ((rowf + 1)*320*3 + colf*3);
				int pixel3 = ((rowf + 1)*320*3 + (colf + 1)*3);
				int pixel4 = (rowf*320*3 + (colf + 1)*3);

				int in1 = (int) (weight1*my_image[pixel1] +
						weight2*my_image[pixel2] +
						weight3*my_image[pixel3] +
						weight4*my_image[pixel4]);

				int in2 = (int) (weight1*my_image[pixel1+1] +
						weight2*my_image[pixel2+1] +
						weight3*my_image[pixel3+1] +
						weight4*my_image[pixel4+1]);

				int in3 = (int) (weight1*my_image[pixel1+2] +
						weight2*my_image[pixel2+2] +
						weight3*my_image[pixel3+2] +
						weight4*my_image[pixel4+2]);

				//draw_pixel(row, col, my_image);
				alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);
			}
		}
		if(bool_dec == 1) {
			scount+=0.1f;
			printf("scount is decrementing to:");
			printf("%f\n", scount);
			if (scount >=1.9f) {
				bool_dec = 0;
			}
		} else if(bool_dec == 0) {
			scount-=0.1f;
			printf("scount is incrementing to:");
			printf("%f\n", scount);
			if (scount <=1.0f) {
				bool_dec = 1;
			}
		}

		}
	}
}











//original rotation double for-loop
/*
for(j=0; j<num_cols-1; j++) {
				//start performance counter to record cycles of this innermost loop

				//PERF_START_MEASURING(PERFORMANCE_COUNTER_0_BASE);

				//initial_counter = perf_get_total_time ((void*) PERFORMANCE_COUNTER_0_BASE);
				//printf("%d\n", initial_counter);

				// to rotate about center calculate offset
				int offset_i = i - num_rows/2;
				int offset_j = j - num_cols/2;

				int rowf = 0;
				int colf = 0;


				#ifdef FIXED_POINT
				//calcuate row&col value from fixed point sine/cosine
				alt_u32 rowi = (offset_i*cosine-offset_j*sine + (num_rows*512)/2);
				alt_u32 coli = (offset_i*sine+offset_j*cosine + (num_cols*512)/2);
				//check bounds
				if(coli>(num_cols*512) || coli<0 || rowi>(num_rows*512) || rowi<(0)) continue;
				//'floor' for interpolation
				rowf = rowi/512*512;
				colf = coli/512*512;

				alt_u32 rfrac = (rowi-rowf)/512;
				alt_u32 cfrac = (coli-colf)/512;

				//calculate weights; divide by 512^2

				alt_u32 weight1 = (512-rfrac)*(512-cfrac);
				alt_u32 weight2 = rfrac*(512-cfrac);
				alt_u32 weight3 = rfrac*cfrac;
				alt_u32 weight4 = (512-rfrac)*cfrac;


				weight1 /= 512*512;
				//printf("weight1: %d\n" , weight1);
				weight2 /= 512*512;
				weight3 /= 512*512;
				weight4 /= 512*512;
				//reset rowf&colf values for pixel calculations
				rowf /= 512;
				colf /= 512;

				#else
				row = offset_i*cosine-offset_j*sine + num_rows/2.0f;
				col = offset_i*sine+offset_j*cosine + num_cols/2.0f;
				//printf("row: %f\n", offset_i*cosine-offset_j*sine + (num_rows*512)/2);
				//printf("col: %f\n", offset_i*sine+offset_j*cosine + (num_cols*512)/2);

				if(col>num_cols || col<0 || row>num_rows || row<0) continue;

				rowf = (int)floorf(row);
				colf = (int)floorf(col);
				//printf("rowf: %d\n", rowf);
				//printf("colf: %d\n", colf);


				float rfrac = row-rowf;
				float cfrac = col-colf;
				//printf("rfrac: %f\n", rfrac);
				//printf("cfrac: %f\n", cfrac);

				//weight for each pixel
				float weight1 = (1.0-rfrac)*(1.0-cfrac);
				float weight2 = rfrac*(1.0-cfrac);
				float weight3 = rfrac*cfrac;
				float weight4 = (1.0-rfrac)*cfrac;

				#endif

				int pixel1 = rowf*320*3 + colf*3;
				int pixel2 = (rowf + 1)*320*3 + colf*3;
				int pixel3 = (rowf + 1)*320*3 + (colf + 1)*3;
				int pixel4 = rowf*320*3 + (colf + 1)*3;


				//three colors
				int in1 = (int) (weight1*my_image[pixel1] +
						weight2*my_image[pixel2] +
						weight3*my_image[pixel3] +
						weight4*my_image[pixel4]);

				int in2 = (int) (weight1*my_image[pixel1+1] +
						weight2*my_image[pixel2+1] +
						weight3*my_image[pixel3+1] +
						weight4*my_image[pixel4+1]);

				int in3 = (int) (weight1*my_image[pixel1+2] +
						weight2*my_image[pixel2+2] +
						weight3*my_image[pixel3+2] +
						weight4*my_image[pixel4+2]);



				//draw_pixel
				alt_up_pixel_buffer_dma_draw(my_pixel_buffer,(in3 +(in2<<8) +(in1<<16)),j,i);
			}
		}

 */
