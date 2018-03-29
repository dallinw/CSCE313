xterm -T jtag_uart_1 -n jtag_uart_1 -fg yellow -bg black -e $1/perl -- atail-f.pl jtag_uart_1_output_stream.dat
