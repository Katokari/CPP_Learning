#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <sstream>

namespace input {
	int ReadNumber(std::string Message, std::string ErrMessage) {
		int Number;
		std::string input;

		while (true) {
			std::cout << Message;
			std::getline(std::cin, input);

			std::stringstream ss(input);

			if (ss >> Number) {
				char remainingChar;
				if(ss >> remainingChar){
					std::cout << ErrMessage;
					continue;
				}else{
					return Number;
				}

			} else {
				std::cout << ErrMessage;
			}
		}
	}

	int ReadNumberInRange(std::string Message, std::string ErrMessage, int Min, int Max) {
		int Number;
		std::string input;

		while (true) {
			std::cout << Message;
			std::getline(std::cin, input);

			std::stringstream ss(input);

			if (ss >> Number && Number >= Min && Number <= Max) {
				char remainingChar;
				if(ss >> remainingChar){
					std::cout << ErrMessage;
					continue;
				}else{
					return Number;
				}

			} else {
				std::cout << ErrMessage;
			}
		}
	}
	
	std::string ReadString(std::string Message) {
		std::string Str;

		if (std::cin.rdbuf()->in_avail() > 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << Message;
		std::getline(std::cin >> std::ws, Str);
		return Str;
	}

	std::string ReadStrings(std::string Message) {
		std::string Str;
		std::cout << Message;
		std::getline(std::cin, Str);
		return Str;
	}

	char ReadChar(std::string Message) {
		char Char;
		std::cout << Message;
		std::cin >> Char;
		return Char;
	}
}

namespace trans {
	std::string ToUpper(std::string Str) {
		for (int i = 0; i < Str.size(); i++)
			Str[i] = toupper(Str[i]);
		return Str;
	}

		std::string ToLower(std::string Str) {
		for (int i = 0; i < Str.size(); i++)
			Str[i] = tolower(Str[i]);
		return Str;
	}
}

namespace random_ {
	int GenerateRandNum(int From, int To) { return (rand() % (To - From + 1) + From); }
}