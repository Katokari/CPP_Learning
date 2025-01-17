#include <iostream>
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

std::string JoinString(std::vector<std::string> vWords, std::string Delim = " ") {
    std::string Str = "";
    std::vector<std::string>::iterator Iter;
    for (Iter = vWords.begin(); Iter != vWords.end(); Iter++) {
        Str += *Iter + Delim;
    }
    return Str.substr(0, Str.length() - Delim.length());
}

std::string ReplaceWords(std::string Str, std::string ReplaceFrom, std::string ReplaceTo, bool MatchCase) {
    std::vector<std::string> vWords = SplitString(Str);

    for (std::vector<std::string>::iterator i = vWords.begin(); i < vWords.end(); i++) {
        if (MatchCase) {
            if (trans::ToLower(*i) == trans::ToLower(ReplaceFrom)) {
                *i = ReplaceTo;
            }
        } else {
            if (*i == ReplaceFrom) {
                *i = ReplaceTo;
            }
        }
    }

    return JoinString(vWords);
}

int main() {
    std::string Str = "My name is Kato , im kato , kato nyan";
    std::cout << ReplaceWords(Str, "kato", "meow", 0) << std::endl;
    std::cout << ReplaceWords(Str, "kato", "meow", 1) << std::endl;
    return 0;
}