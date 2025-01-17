#include <iostream>
#include <cstdlib>
using namespace std;

bool IsPunctuation(char Char) {
    if (Char >= 33 && Char <= 47) {
        return true;
    }
    return false;
}

std::string RemovePunctuations(std::string Str) {
    std::string S1 = "";
    for (std::string::iterator i = Str.begin(); i != Str.end(); i++) {
        if (!IsPunctuation(*i)) {
            S1 += *i;
        }
    }
    return S1;
}

int main() {
    std::string S1 = "My name is kato, im 22yo.";

    std::cout << RemovePunctuations(S1);

    return 0;
}

