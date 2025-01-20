#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

int DaysSinceStart(int Day, int Month, int Year) {
    int Days = 0;
    for (int i = 1; i < Month; i++) {
        Days += NumberOfDaysInMonth(Year, i);
    }
    return Days += Day;
}

std::string DateFromDayOrder(int Order, int Year) {
    int Month = 1;
    int Day = 1;

    for (int i = 1; i <= 12; i++) {
        int MonthDays = NumberOfDaysInMonth(Year, i);
        if (Order > MonthDays) {
            Month++;
            Order -= MonthDays;
        }
    }

    Day = Order;

    return std::to_string(Day) + "/" + std::to_string(Month) + "/" + std::to_string(Year);
}

int main() {
    int Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    int Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    int Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");

    int Order = DaysSinceStart(Day, Month, Year);
    std::cout << "Days since the beginning of the year is " << Order << std::endl;

    std::cout << "Date for [" << Order << "] is: " << DateFromDayOrder(Order, Year);
    return 0;
}