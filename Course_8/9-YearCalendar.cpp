#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "InputLib.h"

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

int DayOfWeekOrder(int Day, int Month, int Year) {
    int a = (14 - Month)/12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    int d = (Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

    return d;
}

std::string MonthShortName(int Month) {
    std::vector<std::string> Months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return Months[Month-1];
}

std::string WhiteSpaces(int Num) {
    std::string Ws = "";
    for (int i = 0; i < Num; i++) {
        Ws += " ";
    }
    return Ws;
}

void PrintMonthCalendar(int Month, int Year) {
    std::cout << "_______________" << MonthShortName(Month) << "_______________" << std::endl;
    std::cout << std::endl;
    std::cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;

    for (int i = 1; i <= NumberOfDaysInMonth(Year, Month); i++) {
        short Order = DayOfWeekOrder(i, Month, Year);

        if (Order == 0) {
            std::cout << std::endl;
        }

        if (i == 1) {
            std::cout << WhiteSpaces(Order * 5);
        }

        std::cout << std::left << std::setw(3) << i << "  ";
    }

    std::cout << std::endl << "_________________________________" << std::endl;
}

void PrintCalendar(int Year) {
    std::cout << "_________________________________\n\n";
    std::cout << "\tCalindar - " << Year << "\n";
    std::cout << "_________________________________\n\n";

    for (int i = 1; i <= 12; i++) {
        PrintMonthCalendar(i, Year);
        std::cout << "\n";
    }
}

int main() {
    int Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    PrintCalendar(Year);
    return 0;
}