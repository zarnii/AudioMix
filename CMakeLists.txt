cmake_minimum_required(VERSION 3.30)
project(AudioMix)
include_directories(include)
set(CMAKE_CXX_STANDART 20)
set(SRC 
	src/main.cpp 
	src/AudioSession.cpp
	src/AudioSessionFactory.cpp
	src/ConsoleLogger.cpp
	src/Mixer.cpp
	src/MockServer.cpp
	src/Normalizer.cpp
	src/ProcessHandler.cpp
	src/SliderMapper.cpp
	src/PortSerializer.cpp)
add_executable(AudioMix ${SRC})