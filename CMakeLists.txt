cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 26)

set(INCLUDE_DIRECTORIES ./)

include_directories(${INCLUDE_DIRECTORIES})

add_executable(AdventOfCode main.cpp
        Base/ProblemBase.cpp
        Base/ProblemBase.h
        day-01/Day-01.cpp
        day-01/Day-01.h
        Base/BaseTypeDefs.h
        Utility/IOUtility.cpp
        Utility/IOUtility.h
        Base/MenuSystem/MenuSystem.cpp
        Base/MenuSystem/MenuSystem.h
        Utility/TerminalUtility.cpp
        Utility/TerminalUtility.h
)
