//
// Created by mathm on 01/12/2024.
//

#include "IOUtility.h"

#include <fstream>
#include <iostream>

std::vector<StringType> KT::IOUtility::ReadFile(const StringType& Path) {
    std::ifstream Infile(Path);
    if (Infile.is_open()) {
        std::cout << "is open" << std::endl;
    }
    else {
        std::cout << "is not open" << std::endl;
    }

    StringType Line;
    std::vector<StringType> Lines;
    while (std::getline(Infile, Line)) {
        std::cout << Line << std::endl;
        Lines.push_back(Line);
    }
    return Lines;
}
