################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD.program.c \
../DIO_program.c \
../GIE_program.c \
../LCD_PROGRAM.c \
../SPI_PROGRAM.c \
../keypad.c \
../main.c \
../mainconfig.c \
../motor.c 

OBJS += \
./CLCD.program.o \
./DIO_program.o \
./GIE_program.o \
./LCD_PROGRAM.o \
./SPI_PROGRAM.o \
./keypad.o \
./main.o \
./mainconfig.o \
./motor.o 

C_DEPS += \
./CLCD.program.d \
./DIO_program.d \
./GIE_program.d \
./LCD_PROGRAM.d \
./SPI_PROGRAM.d \
./keypad.d \
./main.d \
./mainconfig.d \
./motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


