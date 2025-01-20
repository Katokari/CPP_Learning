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
    Date.Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    Date.Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    Date.Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");
    return Date;
}

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month)) ? true : false;
}

bool IsLastMonthInYear(stDate Date) {
    return (Date.Month == 12) ? true : false;
}

int main() {
    stDate Date = ReadDate();    
    std::cout << std::endl;

    if (IsLastDayInMonth(Date)) {
        std::cout << "Yes day is last day in month";
    } else {
        std::cout << "No day is not last day in month";
    }

    std::cout << std::endl;
    
    if (IsLastMonthInYear(Date)) {
        std::cout << "Yes month is last month in year";
    } else {
        std::cout << "No month is not last month in year";
    }
}