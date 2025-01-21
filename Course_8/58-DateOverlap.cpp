#include <iostream>
#include <string>
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date2.Year > Date1.Year) ? true : (Date2.Month > Date1.Month) ? true : (Date2.Day > Date1.Day);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
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

int main() {
    std::cout << "Enter Period1:\n";
    stPeriod P1 = ReadPeriod();

    std::cout << "Enter Period2:\n";
    stPeriod P2 = ReadPeriod();

    if (IsPeriodsOverlap(P1, P2)) {
        std::cout << "Yes period1 overlaps period2.";
    } else {
        std::cout << "No period1 does NOT overlap period2.";
    }
}