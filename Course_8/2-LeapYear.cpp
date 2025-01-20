#include <iostream>
#include <string>
#include "InputLib.h"

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int main()
{
    if (IsLeapYear(input::ReadNumber("Please enter a year? ", "Error enter a valid year? "))) {
        std::cout << "Yes the year is a leap year";
    } else {
        std::cout << "No the year is NOT a leap year";
    }
    return 0;
}