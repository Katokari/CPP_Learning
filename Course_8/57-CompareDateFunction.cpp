#include <iostream>
#include <string>
#include "InputLib.h"

struct stDate
{
    int Year;
    int Month;
    int Day;
};

enum enCompare { After = 1, Equal = 0, Before = -1 };

stDate ReadDate() {
    stDate Date;
    Date.Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    Date.Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    Date.Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");
    return Date;
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

int main() {
    std::cout << "Enter Date1:\n";
    stDate Date1 = ReadDate();

    std::cout << "\nEnter Date2:\n";
    stDate Date2 = ReadDate();

    std::cout << "\n\nCompare Result: " << std::to_string(int(CompareDate(Date1, Date2)));
}