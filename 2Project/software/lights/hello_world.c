/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
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

int main()
{
	alt_u32 current_value;
	alt_u32 current_state;
	alt_u8 current_direction;
	alt_u32 keys;
	current_state=3;
	current_value=1;
	current_direction=0;
	printf("Program running (UART)...\n");
	fprintf(stderr,"Program running (LCD)...\n");

	while (1) {
	/*
	IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,3);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,4);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,5);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,6);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,12);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,56);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,87);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,127);
	*/
	// read the current state of the keys
	keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
	// switch speed if necessary
	if ((keys != 7) && (keys != current_state)) {
		if (keys == 3)  printf("speed set to 250 ms\n");
		else if (keys == 5)
			printf("speed set to 150 ms\n");
		else if (keys == 6)
			printf("speed set to 50 ms\n");
		current_state=keys;
	}


	if (current_state == 3) {
		//assign configurations of 7-segment displays randomly
		IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,rand() % 127);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,rand() % 127);

	} else if (current_state == 5) {
		//create a clockwise rotation of a single outer segment along the 8 7-segment displays
		int i;
		for(i = 0; i < 20; ++i) {
			usleep (20000);
			//check each iteration to determine whether a different button has been pressed
			keys = keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
			if (keys != 7 && keys != 5) {
				break;
			}
			IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,127);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,127);

			if(i == 0) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,126);
			}
			if(i == 1) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,125);
			}
			if(i == 2) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,123);
			}
			if(i == 3) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,119);
			}
			if(i == 4) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,119);
			}
			if(i == 5) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,119);
			}
			if(i == 6) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,119);
			}
			if(i == 7) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,119);
			}
			if(i == 8) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,119);
			}
			if(i == 9) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,119);
			}
			if(i == 10) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,119);
			}
			if(i == 11) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,111);
			}
			if(i == 12) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,95);
			}
			if(i == 13) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,126);
			}
			if(i == 14) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,126);
			}
			if(i == 15) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,126);
			}
			if(i == 16) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,126);
			}
			if(i == 17) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,126);
			}
			if(i == 18) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,126);
			}
			if(i == 19) {
				IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,126);
				}

		}

	} else if (current_state == 6) {
		//printf("speed set to 50 ms\n");
		int zero = 64, one = 121, two = 36, three = 48, four = 25, five = 18, six = 2, seven = 120, eight = 0, nine = 16;
		int decimalArr[] = {zero, one, two, three, four, five, six, seven, eight, nine};
		int sleepTime = 15000;
		int a, b, c, d, e, f, g, h;
		IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,zero);
		IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,zero);


		for (a = 0; a < 10; ++a) {
			usleep(sleepTime);
			for (b = 1; b < 10; ++b) {
				usleep(sleepTime);
				for (c = 1; c < 10; ++c) {
					usleep(sleepTime);
					for (d = 1; d < 10; ++d) {
						usleep(sleepTime);
						for (e = 1; e < 10; ++e) {
							usleep(sleepTime);
							for(f = 1; f < 10; ++f) {
								usleep(sleepTime);
								for(g = 1; g < 10; ++g) {
									usleep(sleepTime);
									for(h = 1; h < 10; ++h) {
										usleep(sleepTime);
										//check to make sure a different  button has been pushed, if so exit the nested loop structure
										keys = keys=IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);
										if (keys != 7 && keys != 6) {
											goto EXIT;
										}
										IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,decimalArr[h]);
									}
									//after each inner for loop has run through 9, that particular display needs to be set
									//back to zero
									IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,zero);
									IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,decimalArr[g]);
								}
								IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,zero);
								IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,decimalArr[f]);
							}
							IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,zero);
							IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,decimalArr[e]);
						}
						IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,zero);
						IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,decimalArr[d]);
					}
					IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,zero);
					IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,decimalArr[c]);
				}
				IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,zero);
				IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,decimalArr[b]);
			}
			IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,zero);
			IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,decimalArr[a]);
		}
		EXIT: ;
	}

			//current_state=keys;




	// switch direction if necessary
	if ((current_direction==0) && (current_value==(1 << 25)))
		current_direction=1;
	else if ((current_direction==1) && (current_value==1))
		current_direction=0;
	// move light
	else if (current_direction==0)
		current_value = current_value << 1;
	else
		current_value = current_value >> 1;
	// update lights
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,current_value);
	// wait

	if (current_state==3) {
		usleep(250000);
	}
	else if (current_state==5) {
		usleep(125000);
	}
	else {
		usleep (50000);}
	}
}
