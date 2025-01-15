#include <iostream>
#include <string>
#include <vector>
#include "../InputLib.h"

std::string TrimLeft(std::string Str) {
    for (int i = 0; i < Str.length(); i++) {
        if (Str[i] != ' ') {
            return Str.substr(i);
        }
    }
    return "";
}

std::string TrimRight(std::string Str) {
    for (int i = Str.length() - 1; i > 0; i--) {
        if (Str[i] != ' ') {
            return Str.substr(0, i + 1);
        }
    }
    return "";
}

std::string Trim(std::string Str) { return TrimLeft(TrimRight(Str)); }

int main() {
    std::string S1 = "           Katokari X          ";
    std::cout << "String      = " << S1 << std::endl;
    std::cout << "Trim Left   = " << TrimLeft(S1) << std::endl;
    std::cout << "Trim Right  = " << TrimRight(S1) << std::endl;
    std::cout << "Trim        = " << Trim(S1) << std::endl;
	return 0;
}