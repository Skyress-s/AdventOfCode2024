//
// Created by mathm on 05/12/2024.
//

#include "Day02.h"

#include <iostream>
#include <algorithm>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

bool IsReportSafe(const std::vector<int32_t>& Report) {
    int8_t PreviousNormalizedDirection = 0;
    for (int i = 0; i < Report.size() - 1; ++i) {
        const int32_t CurrentValue = Report[i];
        const int32_t NextValue = Report[i + 1];
        const bool ValidAbs = std::abs(CurrentValue - NextValue) <= 3 && CurrentValue - NextValue != 0;
        if (!ValidAbs) {
            return false;
        }
        const int8_t NormalizedDirection = std::clamp(CurrentValue - NextValue, -1, 1);

        if (std::abs(NormalizedDirection - PreviousNormalizedDirection) > 1) {
            return false;
        }
        PreviousNormalizedDirection = NormalizedDirection;
    }

    return true;
}

// Assumes that the report is unsafe
bool TryFindSafeReport(const std::vector<int32_t>& Report) {

    for (int i = 0; i < Report.size(); ++i) {
        std::vector<int32_t> ReportCopy = Report;
        ReportCopy.erase(ReportCopy.begin() + i);
        if (IsReportSafe(ReportCopy)) {
            return true;
        }
    }
    return false;
}


namespace KT::Days {
EDay Day02::GetDay() const
{
    return EDay::Day02;
}

int32_t Day02::SolvePart1(const std::vector<StringType>& Input) {
    uint32_t TotalSafeReports = 0;
    for (const StringType& Line: Input) {
        std::vector<int32_t> Report;
        ParseUtility::ParseTest(Line, Report, " ");

        // std::cout << "Line: " << Line << " IsSafe: " << bIsSafe << std::endl;

        TotalSafeReports += IsReportSafe(Report);
    }
    return static_cast<int32_t>(TotalSafeReports);
}

int32_t Day02::SolvePart2(const std::vector<StringType>& Input) {
    uint32_t TotalSafeReports = 0;
    for (const StringType& Line: Input) {
        std::vector<int32_t> Report;
        ParseUtility::ParseTest(Line, Report, " ");

        if (IsReportSafe(Report)) {
            TotalSafeReports++;
            continue;
        }
        if (TryFindSafeReport(Report)) {
            TotalSafeReports++;
        }

    }
    return static_cast<int32_t>(TotalSafeReports);
}

} // KT::Days