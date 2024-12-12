//
// Created by mathm on 12/12/2024.
//

#include <cassert>
#include <iostream>
#include "Day05.h"

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

using PageIdType = uint16_t;
using UpdateType = std::vector<PageIdType>;
using RulesType = std::pair<PageIdType, PageIdType>;

void PrintRules(const std::vector<RulesType>& Rules){
    for (const RulesType& Rule : Rules){
        std::cout << "Rule: " << Rule.first << " -> " << Rule.second << std::endl;
    }
}

void PrintUpdates(const std::vector<UpdateType>& Updates){
    for (const UpdateType& Update : Updates){
        std::cout << "Update: ";
        for (const PageIdType& PageId : Update){
            std::cout << PageId << " ";
        }
        std::cout << std::endl;
    }
}

bool BuildRulesAndUpdates(const std::vector<StringType>& Input, std::vector<UpdateType>& OutUpdates, std::vector<RulesType>& OutRules) {
    bool bHasReachedUpdates = false;
    for (const StringType& Line : Input) {
        if (Line.empty()){
            bHasReachedUpdates = true;
            continue;
        }

        if (bHasReachedUpdates) {
            UpdateType Update{};
            ParseUtility::ParseTest(Line, Update, " ,");
            OutUpdates.emplace_back(Update);
            continue;
        }

        std::vector<PageIdType> ReadRuleValues {};
        ParseUtility::ParseTest<PageIdType>(Line, ReadRuleValues, "|");
        assert(ReadRuleValues.size() == 2);
        OutRules.emplace_back(ReadRuleValues[0], ReadRuleValues[1]);
    }
    return true;
}

namespace KT::Days {
        EDay Day05::GetDay() const {
            return EDay::Day05;
        }



        int32_t Day05::SolvePart1(const std::vector<StringType> &Input) {
            std::vector<RulesType> Rules{};
            std::vector<UpdateType> Updates{};
            BuildRulesAndUpdates(Input, Updates, Rules);

            PrintRules(Rules);
            PrintUpdates(Updates);

            return 0;
        }

        int32_t Day05::SolvePart2(const std::vector<StringType> &Input) {
            return 0;
        }

}