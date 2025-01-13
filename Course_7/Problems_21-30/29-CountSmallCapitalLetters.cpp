#include <iostream>
#include <string>
#include "../InputLib.h"

enum enWhatToCount { Small = 0, Capital };

int CountLetters(std::string Str, enWhatToCount WhatToCount) {
    int Count = 0;
    for (int i = 0; i < Str.length(); i++)
    {
        if (WhatToCount == enWhatToCount::Small && islower(Str[i]))
            Count++;

        if (WhatToCount == enWhatToCount::Capital && isupper(Str[i]))
            Count++;
    }

    return Count;
}

int main() {
    std::string Str = input::ReadStrings("Please enter a string: \n");
    
    std::cout << "String Length = " << Str.length() << std::endl;
    std::cout << "Capital Letters Count = " << CountLetters(Str, enWhatToCount::Capital) << std::endl;
    std::cout << "Small Letters Count = " << CountLetters(Str, enWhatToCount::Small) << std::endl;
    return 0;
}