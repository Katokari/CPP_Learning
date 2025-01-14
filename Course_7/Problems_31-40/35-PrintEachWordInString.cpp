#include <iostream>
#include <string>
#include "../InputLib.h"

void PrintWordsInString(std::string Str) {
    std::string Delim = " ";
    short pos = 0;
    std::string Word;
    
    while ((pos = Str.find(Delim)) != std::string::npos) {
        Word = Str.substr(0, pos);
        if (Word != "") {
            std::cout << Word << std::endl;
        }
        Str.erase(0, pos + Delim.length());
    } 

    if (Str != "") {
        std::cout << Str << std::endl;
    }
}

int main() {
	PrintWordsInString(input::ReadStrings("Please enter a string? "));
	return 0;
}