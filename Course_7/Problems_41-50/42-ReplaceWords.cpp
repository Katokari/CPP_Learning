#include <iostream>
#include <string>
#include <vector>
#include "../InputLib.h"

std::string ReplaceWords(std::string Str, std::string StringToReplace, std::string RepalceTo)
{
    short pos = Str.find(StringToReplace);
    while (pos != std::string::npos)
        {
            Str = Str.replace(pos, StringToReplace.length(), RepalceTo);
            pos = Str.find(StringToReplace);
        }
    return Str;
}

int main() {
    std::string S1 = "My name is kato";
    
    std::cout << ReplaceWords(S1, "kato", "meow");

    
	return 0;
}