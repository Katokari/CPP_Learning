#include <iostream>
#include <string>
#include <math.h>
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date2.Year > Date1.Year) ? true : (Date2.Month > Date1.Month) ? true : (Date2.Day > Date1.Day);
}

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

int DiffDate1Date2(stDate Date1, stDate Date2) {
    int Year = abs(Date1.Year - Date2.Year);
    int Days1 = DaysSinceStart(Date1.Day, Date1.Month, Date1.Year);
    int Days2 = DaysSinceStart(Date2.Day, Date2.Month, Date2.Year);
    int Days = abs(Days1 - Days2);
    return Year * 365 + Days;
}

int main() {
    stDate Date1 = ReadDate();    
    std::cout << std::endl;
    stDate Date2 = ReadDate();
    std::cout << std::endl;

    std::cout << DiffDate1Date2(Date1, Date2);
}       