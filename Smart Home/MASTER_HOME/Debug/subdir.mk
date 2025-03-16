################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../CLCD.program.c \
../DIO_program.c \
../EEPROM.c \
../EEPROM_program.c \
../EXTI_program.c \
../GIE_program.c \
../LCD_PROGRAM.c \
../SPI_PROGRAM.c \
../TIMER_PROGRAM.c \
../TWI_program.c \
../croutine.c \
../heap_1.c \
../i2c.c \
../keypad.c \
../list.c \
../main.c \
../mainconfig.c \
../port.c \
../queue.c \
../spislave.c \
../tasks.c \
../timers.c 

OBJS += \
./ADC_program.o \
./CLCD.program.o \
./DIO_program.o \
./EEPROM.o \
./EEPROM_program.o \
./EXTI_program.o \
./GIE_program.o \
./LCD_PROGRAM.o \
./SPI_PROGRAM.o \
./TIMER_PROGRAM.o \
./TWI_program.o \
./croutine.o \
./heap_1.o \
./i2c.o \
./keypad.o \
./list.o \
./main.o \
./mainconfig.o \
./port.o \
./queue.o \
./spislave.o \
./tasks.o \
./timers.o 

C_DEPS += \
./ADC_program.d \
./CLCD.program.d \
./DIO_program.d \
./EEPROM.d \
./EEPROM_program.d \
./EXTI_program.d \
./GIE_program.d \
./LCD_PROGRAM.d \
./SPI_PROGRAM.d \
./TIMER_PROGRAM.d \
./TWI_program.d \
./croutine.d \
./heap_1.d \
./i2c.d \
./keypad.d \
./list.d \
./main.d \
./mainconfig.d \
./port.d \
./queue.d \
./spislave.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


