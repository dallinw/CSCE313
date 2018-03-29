################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/altera_avalon_cfi_flash.c \
../drivers/src/altera_avalon_cfi_flash_amd.c \
../drivers/src/altera_avalon_cfi_flash_intel.c \
../drivers/src/altera_avalon_cfi_flash_table.c \
../drivers/src/altera_avalon_jtag_uart_fd.c \
../drivers/src/altera_avalon_jtag_uart_init.c \
../drivers/src/altera_avalon_jtag_uart_ioctl.c \
../drivers/src/altera_avalon_jtag_uart_read.c \
../drivers/src/altera_avalon_jtag_uart_write.c \
../drivers/src/altera_avalon_lcd_16207.c \
../drivers/src/altera_avalon_lcd_16207_fd.c \
../drivers/src/altera_avalon_mailbox.c \
../drivers/src/altera_avalon_mutex.c \
../drivers/src/altera_avalon_performance_counter.c \
../drivers/src/altera_avalon_sysid.c \
../drivers/src/altera_ro_zipfs.c \
../drivers/src/altera_up_avalon_video_character_buffer_with_dma.c \
../drivers/src/altera_up_avalon_video_pixel_buffer_dma.c \
../drivers/src/perf_print_formatted_report.c 

OBJS += \
./drivers/src/altera_avalon_cfi_flash.o \
./drivers/src/altera_avalon_cfi_flash_amd.o \
./drivers/src/altera_avalon_cfi_flash_intel.o \
./drivers/src/altera_avalon_cfi_flash_table.o \
./drivers/src/altera_avalon_jtag_uart_fd.o \
./drivers/src/altera_avalon_jtag_uart_init.o \
./drivers/src/altera_avalon_jtag_uart_ioctl.o \
./drivers/src/altera_avalon_jtag_uart_read.o \
./drivers/src/altera_avalon_jtag_uart_write.o \
./drivers/src/altera_avalon_lcd_16207.o \
./drivers/src/altera_avalon_lcd_16207_fd.o \
./drivers/src/altera_avalon_mailbox.o \
./drivers/src/altera_avalon_mutex.o \
./drivers/src/altera_avalon_performance_counter.o \
./drivers/src/altera_avalon_sysid.o \
./drivers/src/altera_ro_zipfs.o \
./drivers/src/altera_up_avalon_video_character_buffer_with_dma.o \
./drivers/src/altera_up_avalon_video_pixel_buffer_dma.o \
./drivers/src/perf_print_formatted_report.o 

C_DEPS += \
./drivers/src/altera_avalon_cfi_flash.d \
./drivers/src/altera_avalon_cfi_flash_amd.d \
./drivers/src/altera_avalon_cfi_flash_intel.d \
./drivers/src/altera_avalon_cfi_flash_table.d \
./drivers/src/altera_avalon_jtag_uart_fd.d \
./drivers/src/altera_avalon_jtag_uart_init.d \
./drivers/src/altera_avalon_jtag_uart_ioctl.d \
./drivers/src/altera_avalon_jtag_uart_read.d \
./drivers/src/altera_avalon_jtag_uart_write.d \
./drivers/src/altera_avalon_lcd_16207.d \
./drivers/src/altera_avalon_lcd_16207_fd.d \
./drivers/src/altera_avalon_mailbox.d \
./drivers/src/altera_avalon_mutex.d \
./drivers/src/altera_avalon_performance_counter.d \
./drivers/src/altera_avalon_sysid.d \
./drivers/src/altera_ro_zipfs.d \
./drivers/src/altera_up_avalon_video_character_buffer_with_dma.d \
./drivers/src/altera_up_avalon_video_pixel_buffer_dma.d \
./drivers/src/perf_print_formatted_report.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -U__x86_64 -U__INT_FAST32_MAX__ -U__SIG_ATOMIC_MAX__ -U__FLT_EPSILON__ -U__DEC64_MANT_DIG__ -U__DBL_MIN__ -USYSTEM_BUS_WIDTH -U__INT_LEAST64_TYPE__ -U__SCHAR_MAX__ -U__DEC128_MANT_DIG__ -U__nios2__ -U__UINTPTR_TYPE__ -U__GCC_ATOMIC_INT_LOCK_FREE -U__DBL_MIN_10_EXP__ -U__GNUC_STDC_INLINE__ -U__unix__ -U__DBL_DENORM_MIN__ -U__GCC_IEC_559 -U__DBL_HAS_DENORM__ -U__SHRT_MAX__ -U__SIZEOF_WCHAR_T__ -U__SIZEOF_PTRDIFF_T__ -U__DEC32_MAX__ -U__linux__ -U__SIZEOF_DOUBLE__ -U__FLT_MIN_EXP__ -U__LDBL_MANT_DIG__ -U__DEC32_EPSILON__ -U__nios2 -U__INTPTR_MAX__ -U__LDBL_DIG__ -U__INT_LEAST8_MAX__ -U__DEC32_MIN_EXP__ -U__DEC128_MAX__ -U__LDBL_DENORM_MIN__ -U__SIZEOF_FLOAT80__ -U__INT_FAST8_MAX__ -U__UINT_LEAST8_MAX__ -U__nios2_little_endian__ -U__GNUC_PATCHLEVEL__ -U__DEC32_SUBNORMAL_MIN__ -U__SIZEOF_POINTER__ -U__SSE2_MATH__ -U__FLT_MAX_10_EXP__ -U__LDBL_HAS_INFINITY__ -U__WINT_MAX__ -U__code_model_small__ -U__DEC64_MIN_EXP__ -U__ATOMIC_ACQ_REL -U__DEC32_MIN__ -U__MMX__ -U__LDBL_MIN_10_EXP__ -U__SIZEOF_LONG_LONG__ -U__UINT_FAST8_MAX__ -U__DEC64_MAX_EXP__ -U__STDC_IEC_559__ -U__INT16_MAX__ -U__UINT16_C(c) -U__k8__ -U__LDBL_MAX_EXP__ -U__UINT_LEAST64_MAX__ -U__FLT_MANT_DIG__ -U__SSE__ -U__FLT_RADIX__ -U__INTMAX_C(c) -U__gnu_linux__ -U__UINT8_MAX__ -U__FLT_DIG__ -U__INTMAX_TYPE__ -U__INT_LEAST32_TYPE__ -U__LDBL_MIN_EXP__ -U__UINT32_MAX__ -U__SIZEOF_INT128__ -U__nios2_5b -U__LONG_LONG_MAX__ -U__NIOS2 -U__amd64 -U__DBL_HAS_INFINITY__ -U__UINT32_C(c) -U__FLT_HAS_QUIET_NAN__ -U__DBL_MAX_10_EXP__ -U__SIG_ATOMIC_TYPE__ -U__FLT_HAS_DENORM__ -U__NIOS2__ -U__NO_INLINE__ -U__INT_LEAST16_MAX__ -U__DEC128_EPSILON__ -U__FLT_DECIMAL_DIG__ -U__GNUC__ -U__INT_LEAST8_TYPE__ -U__GCC_ATOMIC_WCHAR_T_LOCK_FREE -UALT_NO_INSTRUCTION_EMULATION -URO_ZIPFS -U__GCC_ATOMIC_LONG_LOCK_FREE -U__unix -U__k8 -U__DEC128_MIN_EXP__ -U__UINT_FAST64_TYPE__ -U__GCC_IEC_559_COMPLEX -U__INTPTR_TYPE__ -U__INT64_TYPE__ -U__ATOMIC_ACQUIRE -U__DBL_MAX_EXP__ -U__WINT_TYPE__ -U__FLOAT_WORD_ORDER__ -U__ATOMIC_CONSUME -U__DEC64_SUBNORMAL_MIN__ -U__INT_FAST32_TYPE__ -U__has_include(STR) -U__UINT_FAST8_TYPE__ -U__PTRDIFF_MAX__ -U__GCC_ATOMIC_BOOL_LOCK_FREE -U__INT_LEAST16_TYPE__ -U__SIZE_TYPE__ -U__DEC32_MANT_DIG__ -UALT_SINGLE_THREADED -UNIOS2 -U__STDC_VERSION__ -U__ATOMIC_RELAXED -U__DBL_MAX__ -U__GCC_ATOMIC_TEST_AND_SET_TRUEVAL -U__INT_FAST16_MAX__ -U__UINT16_MAX__ -U__UINT_LEAST8_TYPE__ -Uunix -U__UINT_FAST32_TYPE__ -U__nios2_5b__ -U__FLT_EVAL_METHOD__ -U__UINT16_TYPE__ -U__STDC_UTF_32__ -U__UINT32_TYPE__ -U__PRAGMA_REDEFINE_EXTNAME -U__UINT_FAST16_MAX__ -U__FLT_MAX_EXP__ -U__LDBL_EPSILON__ -U__DEC64_MIN__ -U_LP64 -U__UINT64_C(c) -U__REGISTER_PREFIX__ -U__INT_FAST8_TYPE__ -U__STDC_NO_THREADS__ -U__ORDER_LITTLE_ENDIAN__ -U__LDBL_HAS_QUIET_NAN__ -U__INT8_MAX__ -U__FLT_DENORM_MIN__ -U__CHAR32_TYPE__ -U__WCHAR_MIN__ -U__ELF__ -U__FXSR__ -U__UINTMAX_MAX__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 -U__ATOMIC_HLE_RELEASE -U__FLT_MIN_10_EXP__ -U__UINTPTR_MAX__ -U__UINT64_MAX__ -U__WCHAR_MAX__ -U__ATOMIC_HLE_ACQUIRE -U__INT_FAST16_TYPE__ -U__LDBL_HAS_DENORM__ -U__GXX_ABI_VERSION -U__ATOMIC_RELEASE -U__UINTMAX_C(c) -U__GCC_ATOMIC_POINTER_LOCK_FREE -U__INT_LEAST64_MAX__ -U__DBL_MIN_EXP__ -U__UINT_LEAST32_TYPE__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -U__SIZEOF_LONG_DOUBLE__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -U__SIZE_MAX__ -U__SSP_STRONG__ -U__UINT_FAST32_MAX__ -Unios2 -U__INT_FAST64_MAX__ -U__x86_64__ -U__DBL_DECIMAL_DIG__ -U__SIG_ATOMIC_MIN__ -U__FLT_MIN__ -U__GCC_ATOMIC_CHAR32_T_LOCK_FREE -U__DBL_EPSILON__ -U__hal__ -U__UINT_FAST64_MAX__ -U__DEC128_MAX_EXP__ -U__SIZEOF_SIZE_T__ -U__DBL_DIG__ -U__UINT_LEAST16_MAX__ -U__GNUC_MINOR__ -U__ORDER_PDP_ENDIAN__ -U__BIGGEST_ALIGNMENT__ -U__DEC64_MAX__ -U__UINT_LEAST16_TYPE__ -U__DECIMAL_BID_FORMAT__ -Unios2_5b -U__nios2_little_endian -U__GCC_ATOMIC_SHORT_LOCK_FREE -U__WINT_MIN__ -U__INT64_MAX__ -U__INT16_C(c) -U__INT_MAX__ -U__STDC_ISO_10646__ -U__SIZEOF_FLOAT128__ -U__DEC64_EPSILON__ -U__INT32_C(c) -U__INT32_TYPE__ -U__INT_LEAST32_MAX__ -U__STDC_IEC_559_COMPLEX__ -U__STDC__ -U__LDBL_MIN__ -U__SSE2__ -Unios2_little_endian -U__INT8_TYPE__ -U__BYTE_ORDER__ -U_STDC_PREDEF_H -U__SIZEOF_FLOAT__ -U__INTMAX_MAX__ -U__GCC_ATOMIC_LLONG_LOCK_FREE -U__INT_FAST64_TYPE__ -U__UINT64_TYPE__ -U__DEC32_MAX_EXP__ -U__ATOMIC_SEQ_CST -U__INT32_MAX__ -U__VERSION__ -U__INT64_C(c) -U__GCC_ATOMIC_CHAR_LOCK_FREE -U__SIZEOF_WINT_T__ -U__SIZEOF_INT__ -U__USER_LABEL_PREFIX__ -U__LONG_MAX__ -U__INT16_TYPE__ -U__ORDER_BIG_ENDIAN__ -U__INT8_C(c) -U__UINT_LEAST32_MAX__ -U__PTRDIFF_TYPE__ -U__CHAR_BIT__ -U__UINT8_C(c) -U__DEC128_SUBNORMAL_MIN__ -U__has_include_next(STR) -U__DBL_HAS_QUIET_NAN__ -U__SSE_MATH__ -U__SIZEOF_SHORT__ -U__STDC_UTF_16__ -U__DEC_EVAL_METHOD__ -U__amd64__ -U__DBL_MANT_DIG__ -U__FLT_MAX__ -U__UINT_FAST16_TYPE__ -U__linux -U__UINT_LEAST64_TYPE__ -U__DEC128_MIN__ -U__FLT_HAS_INFINITY__ -U__UINT8_TYPE__ -U__GCC_HAVE_DWARF2_CFI_ASM -U__STDC_HOSTED__ -Ulinux -U__DECIMAL_DIG__ -U__LDBL_MAX_10_EXP__ -U__SIZEOF_LONG__ -U__UINTMAX_TYPE__ -U__LDBL_MAX__ -U__FINITE_MATH_ONLY__ -U__WCHAR_TYPE__ -U__LP64__ -U__GCC_ATOMIC_CHAR16_T_LOCK_FREE -U__CHAR16_TYPE__ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

