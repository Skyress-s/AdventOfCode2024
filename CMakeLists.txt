cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 26)

set(INCLUDE_DIRECTORIES ./)

include_directories(${INCLUDE_DIRECTORIES})

configure_file(day-01/TestInput.txt day-01/TestInput.txt COPYONLY) # replace https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
configure_file(day-01/Input.txt day-01/Input.txt COPYONLY)


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
        Base/DayEnum/DayEnum.h
        Base/DayEnum/DayEnum.cpp
        Utility/Clock/Stopwatch.cpp
        Utility/Clock/Stopwatch.h
)
