add wave -noupdate -divider {cpu_2: top-level ports}
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/i_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/i_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/i_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/i_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/i_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/clk
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/reset_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_byteenable
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_write
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_writedata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_irq
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/d_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_dataa
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_datab
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_ipending
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_status
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_estatus
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_a
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_b
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_c
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_readra
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_readrb
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_writerc
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_result
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_clk_en
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_start
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/A_ci_multi_done
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/the_cpu_2_test_bench/W_pcb
add wave -noupdate -format Logic -radix ascii /test_bench/DUT/the_cpu_2/the_cpu_2_test_bench/W_vinst
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/the_cpu_2_test_bench/W_valid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_2/the_cpu_2_test_bench/W_iw

configure wave -justifyvalue right
configure wave -signalnamewidth 1
TreeUpdate [SetDefaultTree]
