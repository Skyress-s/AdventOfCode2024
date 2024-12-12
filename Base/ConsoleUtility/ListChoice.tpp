
template<typename TEntry>
[[nodiscard]] const TEntry& KT::UI::ListChoice2(const std::vector<TListItem<TEntry>>& ListItems, const StringType& Title){

    assert(!ListItems.empty());

    TerminalUtility::ClearTerminal();
    std::cout << TerminalUtility::k_Clear;
    int32_t Current = 0;

    while (true) {
        std::cout << Title << "\n";

        std::vector<StringType> RowNames{};
        for (const auto& ListItem : ListItems){
            RowNames.push_back(ListItem.second);
        }
//        auto RowNames = ListItems | std::views::transform([](const TListItem<TEntry>& Entry){
//            return Entry.second;
////            return std::get<1>(Entry);
//        });
        PrintList2(RowNames, Current);
        const int ch = getch();
        if (ch == 224) {
            const int ch2 = getch();
            switch (ch2) {
                case 72: // Up
                    Current = std::max(0, Current - 1);
                    break;
                case 80: // Down
                    Current = std::min(static_cast<int32_t>(ListItems.size() - 1), Current + 1);
                    break;
            }
        } else if (ch == 13) { // Enter
            break;
        }
        TerminalUtility::ClearTerminal();
    }
    return ListItems[Current].first;
}
