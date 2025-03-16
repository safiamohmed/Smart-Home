################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../GIE_program.c \
../LCD_PROGRAM.c \
../LM35_program.c \
../SPI_PROGRAM.c \
../TIMER_PROGRAM.c \
../TWI_program.c \
../main.c \
../option.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./GIE_program.o \
./LCD_PROGRAM.o \
./LM35_program.o \
./SPI_PROGRAM.o \
./TIMER_PROGRAM.o \
./TWI_program.o \
./main.o \
./option.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./GIE_program.d \
./LCD_PROGRAM.d \
./LM35_program.d \
./SPI_PROGRAM.d \
./TIMER_PROGRAM.d \
./TWI_program.d \
./main.d \
./option.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


