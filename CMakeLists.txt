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

# TESTING
#FetchContent_Declare(Catch2
#)

#include(CTest)
#enable_testing()
#add_test(EqualTest, "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}" "0")
# Need fetch to get catch2 from internjet



#------------


Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

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
        Days/Day09/Day09.cpp
        Days/Day09/Day09.h
        Days/Day10/Day10.cpp
        Days/Day10/Day10.h
)

add_executable(Catch_Tests_Run SimpleTest.cpp
        Days/Day10/Day09Tests.cpp
        #        Base/Vector2D/Vector2D.cpp
#        Base/Vector2D/Vector2D.h
)

# More catch2 stuff


target_link_libraries(Catch_Tests_Run PRIVATE Catch2::Catch2WithMain)

# Copies the resources into the binary directory
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/Resources
        ${PROJECT_BINARY_DIR}/Resources
        COMMENT "Copying resources into binary directory")


add_dependencies(AdventOfCode copy_resources)

# might have to do some
#catch_discover_tests(Catch_Tests_Run)
# since we use Fetch_Content we might have to do some aditional step here
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top