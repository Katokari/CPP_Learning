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

stDate DecreaseDateByOneDay(stDate Date) {
    Date.Day--;
    if (Date.Day < 1) {
        Date.Month--;
        if (Date.Month < 1) {
            Date.Month = 12;
            Date.Year--;
        }
        Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
    }
    return Date;
}

stDate DecreaseDateByXDays(stDate Date, int Days) {
    for (int i = 1; i <= Days; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {
    return DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeeks(stDate Date, int Weeks) {
    for (int i = 1; i <= Weeks; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {
    if (Date.Month < 1) {
        Date.Month = 12;
        Date.Year--;
    } else {
        Date.Month--;
    }
    short MonthsCurrentDays = NumberOfDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > Date.Month) {
        Date.Day = MonthsCurrentDays;
    }
    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, int Months) {
    for (int i = 1; i <= Months; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, int Years) {
    for (int i = 1; i <= Years; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFast(stDate Date, int Years) {
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, int Decades) {
    for (int i = 1; i <= Decades; i++) {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFast(stDate Date, int Decades) {
    Date.Year -= (10 * Decades);
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date) {
    Date.Year -= 1000;
    return Date;
}

std::string DateForamt(stDate Date) {
    return std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
}

int main() {
    stDate Date = ReadDate();    
    std::cout << std::endl;

    std::cout << "Date After: \n\n";

    Date = DecreaseDateByOneDay(Date);
    std::cout << "1-Decreasing one day is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXDays(Date, 10);
    std::cout << "2-Decreasing 10 days is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneWeek(Date);
    std::cout << "3-Decreasing one week is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXWeeks(Date, 10);
    std::cout << "4-Decreasing 10 weeks is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneMonth(Date);
    std::cout << "5-Decreasing one month is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXMonths(Date, 5);
    std::cout << "6-Decreasing 5 months is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneYear(Date);
    std::cout << "7-Decreasing one year is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXYears(Date, 10);
    std::cout << "8-Decreasing 10 years is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXYearsFast(Date, 10);
    std::cout << "9-Decreasing 10 years (faster) is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneDecade(Date);
    std::cout << "10-Decreasing one decade is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXDecades(Date, 10);
    std::cout << "11-Decreasing 10 decades is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByXDecadesFast(Date, 10);
    std::cout << "12-Decreasing 10 decades (faster) is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneCentury(Date);
    std::cout << "13-Decreasing one century is: " << DateForamt(Date) << std::endl;
    Date = DecreaseDateByOneMillennium(Date);
    std::cout << "13-Decreasing one millennium is: " << DateForamt(Date) << std::endl;
    return 0;
}