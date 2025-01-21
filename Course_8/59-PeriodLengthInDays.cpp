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

struct stPeriod
{
    stDate Start;
    stDate End;
};

stDate ReadDate() {
    stDate Date;
    Date.Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");
    Date.Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    Date.Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    return Date;
}

stPeriod ReadPeriod() {
    stPeriod Period;
    std::cout << "\nEnter start date:\n\n";
    Period.Start = ReadDate();
    std::cout << "\nEnter end date:\n\n";
    Period.End = ReadDate();  
    return Period;
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

int DiffDate1Date2(stDate Date1, stDate Date2, bool IncludeLastDay) {
    int Swap = 1;
    int Days = 0;
    if (IsDate1BeforeDate2(Date1, Date2)) {
        std::swap(Date1, Date2);
    }

    while (IsDate1BeforeDate2(Date2, Date1))
    {
        Days++;
        Date2 = IncreaseDate(Date2);
    }

    if (IncludeLastDay) {
        return Days * Swap + 1;
    }
    return Days * Swap;
}

int PeriodLength(stPeriod P, bool IncludeLastDay) {
    return DiffDate1Date2(P.Start, P.End, IncludeLastDay);
}

int main() {
    std::cout << "Enter Period1:\n";
    stPeriod P1 = ReadPeriod();

    std::cout << "Period Length is " << PeriodLength(P1, false) << std::endl;
    std::cout << "Period Length is (Including last day) " << PeriodLength(P1, true) << std::endl;
}