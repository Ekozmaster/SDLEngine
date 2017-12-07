################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EngineBase/AppWindow.cpp \
../EngineBase/Application.cpp \
../EngineBase/EngineHub.cpp \
../EngineBase/EventHandler.cpp \
../EngineBase/Input.cpp \
../EngineBase/Renderer.cpp \
../EngineBase/Scene.cpp \
../EngineBase/SceneManager.cpp \
../EngineBase/WindowManager.cpp 

OBJS += \
./EngineBase/AppWindow.o \
./EngineBase/Application.o \
./EngineBase/EngineHub.o \
./EngineBase/EventHandler.o \
./EngineBase/Input.o \
./EngineBase/Renderer.o \
./EngineBase/Scene.o \
./EngineBase/SceneManager.o \
./EngineBase/WindowManager.o 

CPP_DEPS += \
./EngineBase/AppWindow.d \
./EngineBase/Application.d \
./EngineBase/EngineHub.d \
./EngineBase/EventHandler.d \
./EngineBase/Input.d \
./EngineBase/Renderer.d \
./EngineBase/Scene.d \
./EngineBase/SceneManager.d \
./EngineBase/WindowManager.d 


# Each subdirectory must supply rules for building sources it contributes
EngineBase/%.o: ../EngineBase/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


