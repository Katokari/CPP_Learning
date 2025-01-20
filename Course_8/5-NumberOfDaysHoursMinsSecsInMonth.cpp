#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

int NumberOfHoursInMonth(int Year, int Month) {
    return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutesInMonth(int Year, int Month) {
    return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSecondsInMonth(int Year, int Month) {
    return NumberOfMinutesInMonth(Year, Month) * 60;
}

int main()
{
    int Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    int Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    std::cout << "Number of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year, Month) << std::endl;
    std::cout << "Number of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year, Month) << std::endl;
    std::cout << "Number of Minutes in Month [" << Month << "] is " << NumberOfMinutesInMonth(Year, Month) << std::endl;
    std::cout << "Number of Seconds in Month [" << Month << "] is " << NumberOfSecondsInMonth(Year, Month) << std::endl;
    return 0;
}