//
// Created by mathm on 12/12/2024.
//

#include <cassert>
#include <iostream>
#include "Day05.h"

#include <ranges>
#include <algorithm>

#include "Base/DayEnum/DayEnum.h"
#include "Utility/ParseUtility/ParseUtility.h"

using PageIdType = uint16_t;
using UpdateVectorType = std::vector<PageIdType>;
using PageOrderingRulePairType = std::pair<PageIdType, PageIdType>;

std::ostream& operator<<(std::ostream& os, const PageOrderingRulePairType& rule) {
        os << "{" << rule.first << ", " << rule.second << "}";
        return os;
}

std::ostream& operator<<(std::ostream& os, const UpdateVectorType& Update) {
        os << "{";
        if (!Update.empty()) {
                os << *Update.begin();
                for (auto itr = Update.begin() + 1; itr != Update.end(); ++itr) {
                        auto Page = *itr;
                        os << ", " << Page;
                }
        }
        os << "}";
        return os;
}

void PrintRules(const std::vector<PageOrderingRulePairType>& Rules) {
        for (const PageOrderingRulePairType& Rule: Rules) {
                std::cout << "Rule: " << Rule.first << " -> " << Rule.second << std::endl;
        }
}

void PrintUpdates(const std::vector<UpdateVectorType>& Updates) {
        for (const UpdateVectorType& Update: Updates) {
                std::cout << "Update: ";
                for (const PageIdType& PageId: Update) {
                        std::cout << PageId << " ";
                }
                std::cout << std::endl;
        }
}

bool BuildRulesAndUpdates(const std::vector<StringType>& Input, std::vector<UpdateVectorType>& OutUpdates, std::vector<PageOrderingRulePairType>& OutRules) {
        bool bHasReachedUpdates = false;
        for (const StringType& Line: Input) {
                if (Line.empty()) {
                        bHasReachedUpdates = true;
                        continue;
                }

                if (bHasReachedUpdates) {
                        UpdateVectorType Update{};
                        ParseUtility::ParseTest(Line, Update, " ,");
                        OutUpdates.emplace_back(Update);
                        continue;
                }

                std::vector<PageIdType> ReadRuleValues{};
                ParseUtility::ParseTest<PageIdType>(Line, ReadRuleValues, "|");
                assert(ReadRuleValues.size() == 2);
                OutRules.emplace_back(ReadRuleValues[0], ReadRuleValues[1]);
        }
        return true;
}

bool UpdatesContainsPageId(const UpdateVectorType& Updates, const PageIdType& RuleId) {
        return std::ranges::any_of(Updates, [RuleId](const PageIdType& Updates) {
            return Updates == RuleId;
        });
}


bool UpdateContainsPageOrderRule(const UpdateVectorType& Updates, const PageOrderingRulePairType& Rule) {
        auto filter_view = std::ranges::views::filter(Updates, [Rule](const PageIdType& PageId) {
            return PageId == Rule.first || PageId == Rule.second;
        });
        return std::ranges::distance(filter_view.begin(), filter_view.end()) == 2;
}

bool DoesUpdateSatisfyRule(const UpdateVectorType& Update, const PageOrderingRulePairType& Rule) {
        // If updates does not contain the rule, we assume it to be valid
        if (!UpdateContainsPageOrderRule(Update, Rule)) {
                return true;
        }

        // The rule exists. Is it satisfied?
        auto first_itr = std::find(Update.begin(), Update.end(), Rule.first);
        auto second_itr = std::find(Update.begin(), Update.end(), Rule.second);

        const uint16_t FirstIndex = std::distance(Update.begin(), first_itr);
        const uint16_t SecondIndex = std::distance(Update.begin(), second_itr);

        if (FirstIndex > SecondIndex) {
                return false;
        }
        return true;
}

bool DoesUpdateSatisfyRules(const UpdateVectorType& Update, const std::vector<PageOrderingRulePairType>& Rules) {
        return std::ranges::all_of(Rules, [Update](const PageOrderingRulePairType& Rule) {
            return DoesUpdateSatisfyRule(Update, Rule);
        });
//    for (const PageOrderingRulePairType& Rule : Rules) {
//        // If updates does not contain the rule, we assume it to be valid
//        if (!UpdateContainsPageOrderRule(Update, Rule)) {
//            continue;
//        }
//
//        // The rule exists. Is it satisfied?
//
//        auto first_itr = std::find(Update.begin(), Update.end(), Rule.first);
//        auto second_itr = std::find(Update.begin(), Update.end(), Rule.second);
//
//        const uint16_t FirstIndex = std::distance(Update.begin(), first_itr);
//        const uint16_t SecondIndex = std::distance(Update.begin(), second_itr);
//
//        if (FirstIndex > SecondIndex) {
//            return false;
//        }
//    }
//    return true;
}

// Lets try and make this recursive, why not. (Though a loop would be better)
void CorrectUpdate(UpdateVectorType& Update, const std::vector<PageOrderingRulePairType>& Rules) {
        for (const auto& Rule: Rules) {
                // If updates does not contain the rule, we assume it to be valid
                if (!UpdateContainsPageOrderRule(Update, Rule)) {
                        continue;
                }

                // The rule exists. Is it satisfied?
                auto first_itr = std::find(Update.begin(), Update.end(), Rule.first);
                auto second_itr = std::find(Update.begin(), Update.end(), Rule.second);

                const uint16_t FirstIndex = std::distance(Update.begin(), first_itr);
                const uint16_t SecondIndex = std::distance(Update.begin(), second_itr);

                if (FirstIndex > SecondIndex) {
                        std::swap(*first_itr, *second_itr);
                        break;
                }
        }

        if (!DoesUpdateSatisfyRules(Update, Rules)) {
                CorrectUpdate(Update, Rules);
        }
}


namespace KT::Days {
    EDay Day05::GetDay() const {
            return EDay::Day05;
    }

    IDayProblemBase::DayReturnType Day05::SolvePart1(const std::vector<StringType>& Input) {
            std::vector<PageOrderingRulePairType> Rules{};
            std::vector<UpdateVectorType> Updates{};
            BuildRulesAndUpdates(Input, Updates, Rules);

            PrintRules(Rules);
            PrintUpdates(Updates);

            uint16_t Sum = 0;
            for (auto UpdateItr = Updates.begin(); UpdateItr != Updates.end(); UpdateItr++) {
                    const UpdateVectorType& Update = *UpdateItr;
                    const bool bSatifiesRules = DoesUpdateSatisfyRules(Update, Rules);
                    std::cout << "Update: " << std::ranges::distance(Updates.begin(), UpdateItr) << "Satisfies Rules: " << bSatifiesRules << "\n";
                    if (bSatifiesRules) {
                            Sum += Update[Update.size() / 2];
                    }
            }

            return Sum;
    }

    IDayProblemBase::DayReturnType Day05::SolvePart2(const std::vector<StringType>& Input) {
            std::vector<PageOrderingRulePairType> Rules{};
            std::vector<UpdateVectorType> Updates{};
            BuildRulesAndUpdates(Input, Updates, Rules);

            PrintRules(Rules);
            PrintUpdates(Updates);

            uint16_t Sum = 0;
            for (auto UpdateItr = Updates.begin(); UpdateItr != Updates.end(); UpdateItr++) {
                    UpdateVectorType& Update = *UpdateItr;
                    const bool bSatifiesRules = DoesUpdateSatisfyRules(Update, Rules);
                    const uint8_t Index = std::ranges::distance(Updates.begin(), UpdateItr);
//                    std::cout << "Update: " << Index << " Satisfies Rules: " << bSatifiesRules << "\n";

                    if (!bSatifiesRules) {
                            CorrectUpdate(Update, Rules);
                            std::cout << "Corrected Update: " << Update << "\n";
                            uint16_t MiddleNumber = Update[Update.size() / 2];
                            std::cout << "Number Chosen : " << MiddleNumber << "\n";
                            Sum += MiddleNumber;
                    }

            }

            return Sum;
    }

}