xterm -T jtag_uart_2 -n jtag_uart_2 -fg yellow -bg black -e $1/perl -- atail-f.pl jtag_uart_2_output_stream.dat
