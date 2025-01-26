#pragma once

#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
#include "clsPeriod.h"

class clsInputValidate {
    static bool IsNumberBetween(short Num, short From, short To) {
        if (Num <= To && Num >= From)
            return true;
        return false;
    }

    static bool IsNumberBetween(int Num, int From, int To) {
        if (Num <= To && Num >= From)
            return true;
        return false;
    }

    static bool IsNumberBetween(float Num, float From, float To) {
        if (Num <= To && Num >= From)
            return true;
        return false;
    }

    static bool IsNumberBetween(double Num, double From, double To) {
        if (Num <= To && Num >= From)
            return true;
        return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2) {
        if (clsDate::IsDate1BeforeDate2(Date1, Date2)) {
            clsUtil::Swap(Date1, Date2);
        }
        clsPeriod Period(Date1, Date2);
        return Period.IsDateWithinPeriod(Date);
    }

	static int ReadIntNumber(std::string Message, std::string ErrMessage) {
		int Number;
		std::string input;
		std::cout << Message;
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

	static int ReadIntNumberBetween(std::string Message, std::string ErrMessage, int Min, int Max) {
		int Number;
		std::string input;
		std::cout << Message;
		
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

	static double ReadDblNumber(std::string Message, std::string ErrMessage) {
		double Number;
		std::string input;
		std::cout << Message;
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

	static int ReadDblNumberBetween(std::string Message, std::string ErrMessage, double Min, double Max) {
		double Number;
		std::string input;
		std::cout << Message;
		
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

    static bool IsValidDate(clsDate Date) {
        return clsDate::IsValidDate(Date);
    }

};
