xterm -T jtag_uart_3 -n jtag_uart_3 -fg yellow -bg black -e $1/perl -- atail-f.pl jtag_uart_3_output_stream.dat
