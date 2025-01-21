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

enum enCompare { After = 1, Equal = 0, Before = -1 };

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

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date2.Year > Date1.Year) ? true : (Date2.Month > Date1.Month) ? true : (Date2.Day > Date1.Day);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
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

enCompare CompareDate(stDate Date1, stDate Date2) {
    if (IsDate1AfterDate2(Date1, Date2)) {
        return enCompare::After;
    }
    if (IsDate1EqualDate2(Date1, Date2)) {
        return enCompare::Equal;
    }

    return enCompare::Before;

}

bool IsPeriodsOverlap(stPeriod P1, stPeriod P2) {
    if (CompareDate(P1.End, P2.Start) == enCompare::Before || CompareDate(P1.Start, P2.End) == enCompare::After)
        return false;
    return true;
}

int PeriodLength(stPeriod P, bool IncludeLastDay) {
    return DiffDate1Date2(P.Start, P.End, IncludeLastDay);
}

bool IsDateWithinPeriod(stPeriod P, stDate D) {
    return !(CompareDate(D, P.Start) == enCompare::Before || CompareDate(D, P.End) == enCompare::After);
}

int OverlapDays(stPeriod P1, stPeriod P2) {
    int P1Length = PeriodLength(P1, true); 
    int P2Length = PeriodLength(P2, true); 

    if (!IsPeriodsOverlap(P1, P2))
        return 0;

    int Count = 0;
    if (P1Length < P2Length) {
        while (CompareDate(P1.Start, P1.End) == enCompare::Before)
        {
            if (Count > 0 && IsDateWithinPeriod(P2, P1.Start))
                return Count;

            if (IsDateWithinPeriod(P2, P1.Start))
                Count++;
            
            P1.Start = IncreaseDate(P1.Start);
        }
        return Count;
    }

    return OverlapDays(P2, P1);
}

int main() {
    std::cout << "Enter Period1:\n";
    stPeriod P1 = ReadPeriod();

    std::cout << "Enter Period2:\n";
    stPeriod P2 = ReadPeriod();

    std::cout << "\nOverlap days is " << OverlapDays(P1, P2);
}