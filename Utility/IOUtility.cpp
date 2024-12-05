//
// Created by mathm on 01/12/2024.
//

#include "IOUtility.h"

#include <fstream>
#include <iostream>

#include "Base/DayEnum/DayEnum.h"

std::vector<StringType> KT::IOUtility::ReadFile(const StringType& Path) {
    std::ifstream Infile(Path);
    if (Infile.is_open()) {
        std::cout << "Found File!" << std::endl;
    }
    else {
        std::cout << "Could not find file at: " << Path << std::endl;
        return {};
    }

    StringType Line;
    std::vector<StringType> Lines;
    while (std::getline(Infile, Line)) {
        Lines.push_back(Line);
    }
    return Lines;
}

StringType KT::IOUtility::GetInputFilePathFromDay(const EDay Day) {
    const StringType DayString = GetDayNumberString(Day);
    const StringType Path = "day-" + DayString + "/Input.txt";
    return Path;
}
