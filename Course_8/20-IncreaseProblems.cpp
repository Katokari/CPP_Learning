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

stDate IncreaseDateByXDays(stDate Date, int Days) {
    for (int i = 1; i <= Days; i++) {
        Date = IncreaseDate(Date);
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
    return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, int Weeks) {
    for (int i = 1; i <= Weeks; i++) {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    } else {
        Date.Month++;
    }
    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int Months) {
    for (int i = 1; i <= Months; i++) {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {
    Date.Year++;
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, int Years) {
    for (int i = 1; i <= Years; i++) {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFast(stDate Date, int Years) {
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
    Date.Year += 10;
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int Decades) {
    for (int i = 1; i <= Decades; i++) {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFast(stDate Date, int Decades) {
    Date.Year += (10 * Decades);
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date) {
    Date.Year += 1000;
    return Date;
}

std::string DateForamt(stDate Date) {
    return std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
}

int main() {
    stDate Date = ReadDate();    
    std::cout << std::endl;

    std::cout << "Date After: \n\n";

    Date = IncreaseDate(Date);
    std::cout << "1-Adding one day is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXDays(Date, 10);
    std::cout << "2-Adding 10 days is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneWeek(Date);
    std::cout << "3-Adding one week is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXWeeks(Date, 10);
    std::cout << "4-Adding 10 weeks is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneMonth(Date);
    std::cout << "5-Adding one month is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXMonths(Date, 5);
    std::cout << "6-Adding 5 months is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneYear(Date);
    std::cout << "7-Adding one year is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXYears(Date, 10);
    std::cout << "8-Adding 10 years is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXYearsFast(Date, 10);
    std::cout << "9-Adding 10 years (faster) is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneDecade(Date);
    std::cout << "10-Adding one decade is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXDecadesFast(Date, 10);
    std::cout << "11-Adding 10 decades is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByXDecadesFast(Date, 10);
    std::cout << "12-Adding 10 decades (faster) is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneCentury(Date);
    std::cout << "13-Adding one century is: " << DateForamt(Date) << std::endl;
    Date = IncreaseDateByOneMillennium(Date);
    std::cout << "13-Adding one millennium is: " << DateForamt(Date) << std::endl;
    return 0;
}