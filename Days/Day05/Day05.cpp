//
// Created by mathm on 12/12/2024.
//

#include <cassert>
#include <iostream>
#include "Day05.h"

#include <ranges>
#include <bits/ranges_algo.h>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

using PageIdType = uint16_t;
using UpdateVectorType = std::vector<PageIdType>;
using PageOrderingRulePairType = std::pair<PageIdType, PageIdType>;

void PrintRules(const std::vector<PageOrderingRulePairType>& Rules){
    for (const PageOrderingRulePairType& Rule : Rules){
        std::cout << "Rule: " << Rule.first << " -> " << Rule.second << std::endl;
    }
}

void PrintUpdates(const std::vector<UpdateVectorType>& Updates){
    for (const UpdateVectorType& Update : Updates){
        std::cout << "Update: ";
        for (const PageIdType& PageId : Update){
            std::cout << PageId << " ";
        }
        std::cout << std::endl;
    }
}

bool BuildRulesAndUpdates(const std::vector<StringType>& Input, std::vector<UpdateVectorType>& OutUpdates, std::vector<PageOrderingRulePairType>& OutRules) {
    bool bHasReachedUpdates = false;
    for (const StringType& Line : Input) {
        if (Line.empty()){
            bHasReachedUpdates = true;
            continue;
        }

        if (bHasReachedUpdates) {
            UpdateVectorType Update{};
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

bool UpdatesContainsPageId(const UpdateVectorType& Updates, const PageIdType& RuleId)
{
    return std::ranges::any_of(Updates, [RuleId](const PageIdType& Updates) {
        return Updates == RuleId;
    });
}

bool UpdateContainsPageOrderRule(const UpdateVectorType& Updates, const PageOrderingRulePairType& Rule)
{
     auto filter_view = std::ranges::views::filter(Updates, [Rule](const PageIdType& PageId) {
        return PageId == Rule.first || PageId == Rule.second;
    });
    return std::ranges::distance(filter_view.begin(), filter_view.end()) == 2;
}

namespace KT::Days {
        EDay Day05::GetDay() const {
            return EDay::Day05;
        }

        int32_t Day05::SolvePart1(const std::vector<StringType> &Input) {
            std::vector<PageOrderingRulePairType> Rules{};
            std::vector<UpdateVectorType> Updates{};
            BuildRulesAndUpdates(Input, Updates, Rules);

            PrintRules(Rules);
            PrintUpdates(Updates);

            return 0;
        }

        int32_t Day05::SolvePart2(const std::vector<StringType> &Input) {
            return 0;
        }

}