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

std::string JoinStringInReverse(std::string Str) {
    std::string NewStr = "";
    std::string Delim = "#";
    std::vector<std::string> vWords = SplitString(Str, Delim);
    std::vector<std::string>::reverse_iterator Iter;
    for (Iter = vWords.rbegin(); Iter != vWords.rend(); Iter++) {
        NewStr += *Iter;
        if (Iter+1 != vWords.rend())
            NewStr += Delim;
    }
    return NewStr;
}

int main() {
    std::vector<std::string> vWords;
    std::string S1 = input::ReadStrings("Please enter a string? \n");
    std::cout << JoinStringInReverse(S1);
	return 0;
}