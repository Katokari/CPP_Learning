#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

struct stDate
{
    int Year;
    int Month;
    int Day;
};

stDate ReadDate() {
    stDate Date;
    Date.Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");
    Date.Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    Date.Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    return Date;
}

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

bool IsValidDate(stDate D) {
    if (D.Month > 12 || D.Month < 1)
        return false;
    
    if (D.Day < 1 || D.Day > NumberOfDaysInMonth(D.Year, D.Month))
        return false;
    
    return true;
}

int main() {
    stDate Date = ReadDate();

    if (IsValidDate(Date)) {
        std::cout << "Yes its a valid date.";
    } else {
        std::cout << "No its NOT a valid date.";
    }

    return 0;
}