#include <iostream>
#include <string>
#include <vector>
#include "../InputLib.h"

std::vector<std::string> SplitString(std::string Str, std::string Delim = " ") {
    std::vector<std::string> vWords;
    short pos = 0;
    std::string Word;

    while ((pos = Str.find(Delim)) != std::string::npos) {
        Word = Str.substr(0, pos);
        if (Word != "") {
            vWords.push_back(Word);
        }
        Str.erase(0, pos + Delim.length());
    } 

    if (Str != "") {
        vWords.push_back(Str);
    }
    
    return vWords;
}

void PrintWordsFromVector(std::vector<std::string>& vWords) {
    for (std::string& Word : vWords)
        std::cout << Word << std::endl;
}

int main() {
    std::vector<std::string> vWords;
    std::string S1 = input::ReadStrings("Please enter a string? \n");
    vWords = SplitString(S1);
    std::cout << "\nTokens = " << vWords.size() << std::endl;
    PrintWordsFromVector(vWords);
	return 0;
}