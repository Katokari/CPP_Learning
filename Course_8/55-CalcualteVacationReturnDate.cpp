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

int DayOfWeekOrder(int Day, int Month, int Year) {
    int a = (14 - Month)/12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    int d = (Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

    return d;
}

int DayOfWeekOrder(stDate Date) {
    int a = (14 - Date.Month)/12;
    int y = Date.Year - a;
    int m = Date.Month + 12 * a - 2;

    int d = (Date.Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

    return d;
}

std::string DayName(int Order) {
    std::vector<std::string> Name = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
    return Name[Order];
}

std::string DateForamt(stDate Date) {
    return DayName(DayOfWeekOrder(Date)) +  " , " +
    std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
}

bool IsWeekEnd(int DayOrder) {
    return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(int DayOrder) {
    return !(IsWeekEnd(DayOrder));
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

stDate VacationReturn(stDate Date, int VacationDays) {
    while (VacationDays > 0)
    {
        if (IsBusinessDay(DayOfWeekOrder(Date))) {
            VacationDays--;
        }

        Date = IncreaseDate(Date);
    }  
    return Date;
}

int main() {
    std::cout << "Vacation Starts:\n";
    stDate Date = ReadDate();

    int VacationDays = input::ReadNumber("Please enter vacation days? ", "Error please enter a valid number");

    std::cout << "\n\nReturn Date: " << DateForamt(VacationReturn(Date, VacationDays));
    return 0;
}