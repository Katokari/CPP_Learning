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

int DaysSinceStart(int Day, int Month, int Year) {
    int Days = 0;
    for (int i = 1; i < Month; i++) {
        Days += NumberOfDaysInMonth(Year, i);
    }
    return Days + Day;
}

stDate AddDaysToDate(stDate Date, int Add) {
    Add += DaysSinceStart(Date.Day, Date.Month, Date.Year);
    Date.Month = 1;
    Date.Day = 1;
    while (Add > 0) {
        int DaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
        if (Add > DaysInCurrentMonth) {
            Add -= DaysInCurrentMonth;
            Date.Month++;
            
            if (Date.Month > 12) {
                Date.Year++;
                Date.Month = 1;
            }
        } else {
            Date.Day = Add;
            Add = 0;
        }
    }

    return Date;
}

int main() {
    stDate Date = ReadDate();
    int Add = input::ReadNumber("How many days to add? ", "Error, please enter a valid number? ");
    Date = AddDaysToDate(Date, Add);
    std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
    return 0;
}