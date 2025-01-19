#include <iostream>
#include <string>
#include "InputLib.h"

bool IsLeapYear(int Year) {
    if (Year % 4 == 0) {
        return true;
    } else if (Year % 100 == 0) {
        if (Year % 400 == 0) {
            return true;
        }
        return false;
    }
    return false;
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