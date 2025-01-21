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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date2.Year > Date1.Year) ? true : (Date2.Month > Date1.Month) ? true : (Date2.Day > Date1.Day);
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

int ActualVacationDays(stDate Date1, stDate Date2) {
    int Vacation = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        if (IsBusinessDay(DayOfWeekOrder(Date1))) {
            Vacation++;
        }
        Date1 = IncreaseDate(Date1);
    }
    return Vacation;
}

int main() {
    std::cout << "Vacation Starts:\n";
    stDate Date1 = ReadDate();
    std::cout << "\nVacation Ends:\n";
    stDate Date2 = ReadDate();

    std::cout << "\nVacation From: " << DateForamt(Date1) << std::endl;
    std::cout << "\nVacation To: " << DateForamt(Date2) << std::endl;
    std::cout << "\n\nActual Vacation Days is: " << ActualVacationDays(Date1, Date2);
    return 0;
}