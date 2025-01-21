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

bool IsDateWithinPeriod(stPeriod P, stDate D) {
    return !(CompareDate(D, P.Start) == enCompare::Before || CompareDate(D, P.End) == enCompare::After);
}

int main() {
    std::cout << "Enter Period1:\n";
    stPeriod P = ReadPeriod();

    std::cout << "\nEnter a date to check:\n";
    stDate D = ReadDate();

    if (IsDateWithinPeriod(P, D)) {
        std::cout << "Yes, date is within period";
    } else {
        std::cout << "No, date is Not within period";
    }
}