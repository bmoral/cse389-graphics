################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MainComponent.cpp \
../src/Object.cpp \
../src/ShaderProgram.cpp \
../src/Window.cpp \
../src/main.cpp 

C_SRCS += \
../src/glad.c 

OBJS += \
./src/MainComponent.o \
./src/Object.o \
./src/ShaderProgram.o \
./src/Window.o \
./src/glad.o \
./src/main.o 

CPP_DEPS += \
./src/MainComponent.d \
./src/Object.d \
./src/ShaderProgram.d \
./src/Window.d \
./src/main.d 

C_DEPS += \
./src/glad.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


