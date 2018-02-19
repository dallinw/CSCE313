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

	IOWR_ALTERA_AVALON_PIO_DATA(HEX0_BASE,3);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX1_BASE,4);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX2_BASE,5);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX3_BASE,6);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX4_BASE,12);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX5_BASE,56);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX6_BASE,87);
	IOWR_ALTERA_AVALON_PIO_DATA(HEX7_BASE,127);
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
	// switch direction if necessary
	if ((current_direction==0) && (current_value==(1 << 25))) current_direction=1;
	else if ((
	current_direction==1) && (current_value==1)) current_direction=0;
	// move light
	else if (current_direction==0) current_value = current_value << 1;
	else current_value = current_value >> 1;
	// update lights
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE,current_value);
	// wait
	if (current_state==3) usleep(250000);
	else if (current_state==5) usleep(125000);
	else usleep (50000);}
}
