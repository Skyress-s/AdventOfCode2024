#include <fstream>
#include <iostream>

#include "Base/MenuSystem/MenuSystem.h"
#include "day-01/Day-01.h"
#include "Utility/IOUtility.h"

int main()
{
    // MenuSystem Men;
    // Menu.AddProblem(std::make_unique_for_overwrite<Day01>());
    // Menu.PrintAllProblems();

    KT::IOUtility::ReadFile("../Test.txt");

    std::ofstream outfile("example.txt");

    if (outfile.is_open()) {
        outfile << "This is a simple file.\n";
        outfile << "It contains some text.\n";
        outfile.close();
        std::cout << "File created and written successfully." << std::endl;
    } else {
        std::cerr << "Error: Could not create the file." << std::endl;
    }

    return 0;
}
