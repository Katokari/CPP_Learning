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

std::string DateForamt(stDate Date, int DayOrder) {
    return DayName(DayOrder) +  " , " +
    std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
}

int DaysSinceStart(int Day, int Month, int Year) {
    int Days = 0;
    for (int i = 1; i < Month; i++) {
        Days += NumberOfDaysInMonth(Year, i);
    }
    return Days += Day;
}

int NumberOfDaysInYear(int Year) {
    return (IsLeapYear(Year)) ? 366 : 365;
}

bool IsEndOfWeek(int DayOrder) {
    return (DayOrder == 6);
}

bool IsWeekEnd(int DayOrder) {
    return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(int DayOrder) {
    return !(IsWeekEnd(DayOrder));
}

int DaysUntilTheEndOfWeek(int DayOrder) {
    return 6 - DayOrder;
}

int DaysUntilTheEndOfMonth(stDate Date) {
    return (NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day) + 1;
}

int DaysUntilTheEndOfYear(stDate Date) {
    return NumberOfDaysInYear(Date.Year) - DaysSinceStart(Date.Day, Date.Month, Date.Year) + 1;
}

int main() {
    stDate Date = ReadDate();
    int DayOrder = DayOfWeekOrder(Date);

    std::cout << "\nToday is " << DateForamt << "\n\n";

    std::cout << "Is it End of Week?\n";
    if (IsEndOfWeek(DayOrder)) {
        std::cout << "Yes, end of week.\n\n";
    } else {
        std::cout << "No, Not end of week.\n\n";
    }

    std::cout << "Is it Weekend?\n";
    if (IsWeekEnd(DayOrder)) {
        std::cout << "Yes, it is a Weekend.\n\n";
    } else {
        std::cout << "No, it is Not a Weekend.\n\n";
    }

    std::cout << "Is it Business Day?\n";
    if (IsWeekEnd(DayOrder)) {
        std::cout << "Yes, it is a Business Day.\n\n";
    } else {
        std::cout << "No, it is Not a Business Day.\n\n";
    }

    std::cout << "Days until end of week " << DaysUntilTheEndOfWeek(DayOrder) << std::endl;
    std::cout << "Days until end of month " << DaysUntilTheEndOfMonth(Date) << std::endl;
    std::cout << "Days until end of year " << DaysUntilTheEndOfYear(Date) << std::endl;

    return 0;
}