cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 26)

set(INCLUDE_DIRECTORIES ./)

include_directories(${INCLUDE_DIRECTORIES})

#configure_file(Resources/Day01-Day02-TestInput.txt Resources/Day01-Day02-TestInput.txt COPYONLY) # replace https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
#configure_file(Resources/Day01-Day02-Input.txt Resources/Day01-Day02-Input.txt COPYONLY)
#
#configure_file(Day02/Day02-TestInput.txt Day02/Day02-TestInput.txt COPYONLY) # replace https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html
#configure_file(Day02/Day02-Input.txt Day02/Day02-Input.txt COPYONLY)

add_executable(AdventOfCode main.cpp
        Base/IDayProblemBase.cpp
        Base/IDayProblemBase.h
        Days/Day01/Day01.cpp
        Days/Day01/Day01.h
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
        Days/Day02/Day02.cpp
        Days/Day02/Day02.h
        Base/ConsoleUtility/ListChoice.cpp
        Base/ConsoleUtility/ListChoice.h
        Utility/ParseUtility/ParseUtility.tpp
        Utility/ParseUtility/ParseUtility.cpp
        Utility/ParseUtility/ParseUtility.h
        Days/Day03/Day03.cpp
        Days/Day03/Day03.h
        Utility/ParseUtility/ParseUtility.cpp
        Days/Day04/Day04.cpp
        Days/Day04/Day04.h
        Days/Day05/Day05.cpp
        Days/Day05/Day05.h
        Base/TemplateTest.cpp
        Base/TemplateTest.h
        Base/ConsoleUtility/ListChoice.tpp
        Days/Day06/Day06.cpp
        Days/Day06/Day06.h
        Base/Vector2D/Vector2D.cpp
        Base/Vector2D/Vector2D.h
        Days/Day07/Day07.cpp
        Days/Day07/Day07.h
        Days/Day08/Day08.cpp
        Days/Day08/Day08.h
        Base/Grid/TGrid.tpp
        Base/Grid/TGrid.h
        Base/Grid/GridUtility.tpp
        Base/Grid/GridUtility.h
        Utility/GridMath.h
        Utility/GridMath.cpp
        Utility/PrimeFactorization.cpp
        Utility/PrimeFactorization.h
)

# Copies the resources into the binary directory
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/Resources
        ${PROJECT_BINARY_DIR}/Resources
        COMMENT "Copying resources into binary directory")


add_dependencies(AdventOfCode copy_resources)
