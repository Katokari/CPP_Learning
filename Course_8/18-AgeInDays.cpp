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

stDate IncreaseDate(stDate Date) {
    Date.Day++;
    if (Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month)) {
        Date.Day = 1;
        Date.Month++;
        if (Date.Month > 12) {
            Date.Month = 1;
            Date.Year++;
        }
    }
    return Date;
}

int DiffDate1Date2(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2)) {
        std::swap(Date1, Date2);
    }
    int Days = 0;
    while (IsDate1BeforeDate2(Date2, Date1))
    {
        Days++;
        Date2 = IncreaseDate(Date2);
    }
    return Days;
}

stDate GetCurrentDate() {
    time_t t = time(0);
    tm* now = localtime(&t);

    stDate Date;
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}

int main() {
    stDate Date1 = ReadDate();    
    std::cout << std::endl;

    std::cout << DiffDate1Date2(Date1, GetCurrentDate());
}