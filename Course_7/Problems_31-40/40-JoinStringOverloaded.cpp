#include <iostream>
#include <string>
#include <vector>
#include "../InputLib.h"

std::string JoinString(std::vector<std::string> vWords, std::string Delim = " ") {
    std::string Str = "";
    std::vector<std::string>::iterator Iter;
    for (Iter = vWords.begin(); Iter != vWords.end(); Iter++) {
        Str += *Iter + Delim;
    }
    return Str.substr(0, Str.length() - Delim.length());
}

std::string JoinString(std::string vWords[], int size, std::string Delim = " ") {
    std::string Str = "";
    for (int i = 0; i < size; i++) {
        Str += *(vWords + i) + Delim;
    }
    return Str.substr(0, Str.length() - Delim.length());
}

int main() {
    std::string Words[4] = {"My", "Name", "Is", "Kato"};
    std::vector<std::string> vWords = {"My", "Name", "Is", "Kato"};

    std::cout << JoinString(Words, 4, "#") << std::endl;
    std::cout << JoinString(vWords, "#") << std::endl;

	return 0;
}