#include <iostream>
#include <string>
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
}

int main() {
    stDate Date1 = ReadDate();    
    std::cout << std::endl;
    stDate Date2 = ReadDate();
    std::cout << std::endl;

    if (IsDate1EqualDate2(Date1, Date2)) {
        std::cout << "Yes Date1 is equal to Date2";
    } else {
        std::cout << "No Date1 is not equal to Date2";
    }
}