add wave -noupdate -divider {cpu_1: top-level ports}
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/i_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/i_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/i_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/i_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/i_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/clk
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/reset_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_byteenable
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_write
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_writedata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_irq
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/d_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_pcb
add wave -noupdate -format Logic -radix ascii /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_vinst
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_valid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_iw

configure wave -justifyvalue right
configure wave -signalnamewidth 1
TreeUpdate [SetDefaultTree]
