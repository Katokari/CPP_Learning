#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
#include "clsPeriod.h"

template <typename T>
class clsInputValidate {
public:
    static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2) {
        if (clsDate::IsDate1BeforeDate2(Date1, Date2)) {
            clsUtil::Swap(Date1, Date2);
        }
        clsPeriod Period(Date1, Date2);
        return Period.IsDateWithinPeriod(Date);
    }

	static bool IsNumberBetween(T Num, T From, T To) {
        if (Num <= To && Num >= From)
            return true;
        return false;
	}

	static T ReadNumber(std::string ErrMessage) {
		T Number;
		std::string input;
		while (true) {
			std::getline(std::cin >> std::ws, input);

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

	static T ReadNumberBetween(std::string ErrMessage, T Min, T Max) {
		T Number;
		std::string input;
		
		while (true) {
			std::getline(std::cin >> std::ws, input);
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

	static std::string ReadString() {
		std::string input;
		std::getline(std::cin >> std::ws, input);
		return input;
	}

    static bool IsValidDate(clsDate Date) {
        return clsDate::IsValidDate(Date);
    }
};
