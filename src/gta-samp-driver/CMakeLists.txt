cmake_minimum_required(VERSION 3.16)
project(gta-samp-driver)

set(Boost_USE_STATIC_LIBS OFF)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(
        gta-samp-driver
        Bot.cpp
        AxisManager.cpp
        GameResources.cpp
        MathTrigonometry.cpp
        MemoryReader.cpp
        Movement.cpp
        CaptchaSolver.cpp
        ChatManager.cpp
        routes/DolphinFisherman.cpp
)