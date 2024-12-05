cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 26)

set(INCLUDE_DIRECTORIES ./)

include_directories(${INCLUDE_DIRECTORIES})

configure_file(Day01/TestInput.txt Day01/TestInput.txt COPYONLY) # replace https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
configure_file(Day01/Input.txt Day01/Input.txt COPYONLY)

configure_file(Day02/TestInput.txt Day02/TestInput.txt COPYONLY) # replace https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
configure_file(Day02/Input.txt Day02/Input.txt COPYONLY)


add_executable(AdventOfCode main.cpp
        Base/ProblemBase.cpp
        Base/ProblemBase.h
        day01/Day01.cpp
        day01/Day01.h
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
        Base/DaySolver/IDaySolver.h
        Day02/Day02.cpp
        Day02/Day02.h
        Base/ConsoleUtility/ListChoice.cpp
        Base/ConsoleUtility/ListChoice.h
        Utility/ParseUtility/ParseUtility.tpp
        Utility/ParseUtility/ParseUtility.h
)
