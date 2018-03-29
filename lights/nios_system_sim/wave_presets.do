# Display signals from module onchip_memory2_1
add wave -noupdate -divider {onchip_memory2_1}
add wave -noupdate -format Logic /test_bench/DUT/the_onchip_memory2_1/chipselect
add wave -noupdate -format Logic /test_bench/DUT/the_onchip_memory2_1/write
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_1/address
add wave -noupdate -format Literal -radix binary /test_bench/DUT/the_onchip_memory2_1/byteenable
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_1/readdata
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_1/writedata


# Display signals from module onchip_memory2_0
add wave -noupdate -divider {onchip_memory2_0}
add wave -noupdate -format Logic /test_bench/DUT/the_onchip_memory2_0/chipselect
add wave -noupdate -format Logic /test_bench/DUT/the_onchip_memory2_0/write
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_0/address
add wave -noupdate -format Literal -radix binary /test_bench/DUT/the_onchip_memory2_0/byteenable
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_0/readdata
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_onchip_memory2_0/writedata


# Display signals from module sdram_0
add wave -noupdate -divider {sdram_0}
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/az_addr
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/az_be_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/az_cs
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/az_data
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/az_rd_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/az_wr_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/clk
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/za_data
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/za_valid
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/za_waitrequest
add wave -noupdate -format Literal -radix ascii /test_bench/DUT/the_sdram_0/CODE
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/zs_addr
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/zs_ba
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/zs_cs_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/zs_ras_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/zs_cas_n
add wave -noupdate -format Logic /test_bench/DUT/the_sdram_0/zs_we_n
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/zs_dq
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_sdram_0/zs_dqm


# Display signals from module mailbox_1
add wave -noupdate -divider {mailbox_1}
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_1/chipselect
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/address
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_1/write
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/data_from_cpu
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_1/read
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/data_to_cpu
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/reset_reg0
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/reset_reg1
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/mutex0
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_1/mutex1


# Display signals from module mailbox_0
add wave -noupdate -divider {mailbox_0}
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_0/chipselect
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/address
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_0/write
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/data_from_cpu
add wave -noupdate -format Logic /test_bench/DUT/the_mailbox_0/read
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/data_to_cpu
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/reset_reg0
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/reset_reg1
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/mutex0
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_mailbox_0/mutex1


# Display signals from module jtag_uart_1
add wave -noupdate -divider {jtag_uart_1}
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_1/av_address
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/av_chipselect
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/av_irq
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/av_read_n
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_1/av_readdata
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/av_waitrequest
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/av_write_n
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_1/av_writedata
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/dataavailable
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_1/readyfordata


# Display signals from module cpu_0
add wave -noupdate -divider {cpu_0}
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/i_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/i_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/i_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/i_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/i_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/clk
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/reset_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_readdata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_waitrequest
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_address
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_byteenable
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_read
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_write
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_writedata
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_irq
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/d_readdatavalid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_dataa
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_datab
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_ipending
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_status
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_estatus
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_a
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_b
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_c
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_readra
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_readrb
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_writerc
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_result
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_clk_en
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_start
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/A_ci_multi_done
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/the_cpu_0_test_bench/W_pcb
add wave -noupdate -format Logic -radix ascii /test_bench/DUT/the_cpu_0/the_cpu_0_test_bench/W_vinst
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/the_cpu_0_test_bench/W_valid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_0/the_cpu_0_test_bench/W_iw


# Display signals from module jtag_uart_0
add wave -noupdate -divider {jtag_uart_0}
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_0/av_address
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/av_chipselect
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/av_irq
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/av_read_n
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_0/av_readdata
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/av_waitrequest
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/av_write_n
add wave -noupdate -format Literal -radix hexadecimal /test_bench/DUT/the_jtag_uart_0/av_writedata
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/dataavailable
add wave -noupdate -format Logic /test_bench/DUT/the_jtag_uart_0/readyfordata


# Display signals from module cpu_1
add wave -noupdate -divider {cpu_1}
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
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_dataa
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_datab
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_ipending
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_status
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_estatus
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_n
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_a
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_b
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_c
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_readra
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_readrb
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_writerc
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_result
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_clk_en
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_start
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/A_ci_multi_done
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_pcb
add wave -noupdate -format Logic -radix ascii /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_vinst
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_valid
add wave -noupdate -format Logic -radix hexadecimal /test_bench/DUT/the_cpu_1/the_cpu_1_test_bench/W_iw


configure wave -justifyvalue right
configure wave -signalnamewidth 1
TreeUpdate [SetDefaultTree]