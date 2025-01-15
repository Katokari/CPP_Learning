#include <iostream>
#include <string>
#include <vector>
#include "../InputLib.h"

int CountWordsInString(std::string Str) {
    std::string Delim = " ";
    short pos = 0;
    std::string Word;
    int Counter = 0;

    while ((pos = Str.find(Delim)) != std::string::npos) {
        Word = Str.substr(0, pos);
        if (Word != "") {
            Counter++;
        }
        Str.erase(0, pos + Delim.length());
    } 

    if (Str != "") {
        Counter++;
    }
    
    return Counter;
}

int main() {
    std::string S1 = input::ReadStrings("Please enter a string? \n");
    std::cout << "Words count in string is " << CountWordsInString(S1);
	return 0;
}