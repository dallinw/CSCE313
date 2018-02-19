xterm -T jtag_uart_0 -n jtag_uart_0 -fg yellow -bg black -e $1/perl -- atail-f.pl jtag_uart_0_output_stream.dat
