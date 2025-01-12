#pragma once

#include <iostream>
#include <string>
#include <limits>

namespace input {
	int ReadNumber(std::string Message, std::string ErrMessage) {
		int Number;
		std::cout << Message;
		std::cin >> Number;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << ErrMessage;
			std::cin >> Number;
		}
		return Number;
	}

	std::string ReadString(std::string Message) {
		std::string Str;
		std::cout << Message;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, Str);
		return Str;
	}

	std::string ReadStrings(std::string Message) {
		std::string Str;
		std::cout << Message;
		std::getline(std::cin, Str);
		return Str;
	}
}

namespace trans {
	std::string ToUpper(std::string Str) {
		std::string NewStr = "";
		for (int i = 0; i < Str.size(); i++)
			NewStr += toupper(Str[i]);
		return NewStr;
	}
}

namespace random_ {
	int GenerateRandNum(int From, int To) { return (rand() % (To - From + 1) + From); }
}