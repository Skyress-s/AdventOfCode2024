//
// Created by mathm on 01/12/2024.
//

#include "DayEnum.h"

#include <iomanip>
#include <ostream>


StringType GetDayNumberString(const EDay Day) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << static_cast<int32_t>(Day);
    return ss.str();
}

StringType GetDayName(const EDay Day) {
    const StringType DayPrefix = "Day_";
    return DayPrefix + std::to_string(static_cast<uint8_t>(Day));
}

std::ostream& operator<<(std::ostream &os, const EDay day) {
    os << GetDayName(day);
    return os;
}
