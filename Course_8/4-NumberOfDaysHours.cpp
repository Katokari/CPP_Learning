#include <iostream>
#include <string>
#include "InputLib.h"

struct stTime {
    int Days;
    int Hours;
    int Mins;
    int Seconds;
};

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

stTime NumberOfDaysHoursMinsSecsInYear(int Year) {
    stTime Time;
    Time.Days = (IsLeapYear(Year)) ? 366 : 365;

    Time.Hours = Time.Days * 24;
    Time.Mins = Time.Hours * 60;
    Time.Seconds = Time.Mins * 60;

    return Time;
}

int main()
{
    int Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    stTime Time = NumberOfDaysHoursMinsSecsInYear(Year);
    std::cout << "Number of Days    in Year [" << Year << "] is " << Time.Days << std::endl;
    std::cout << "Number of Hours   in Year [" << Year << "] is " << Time.Hours << std::endl;
    std::cout << "Number of Minutes in Year [" << Year << "] is " << Time.Mins << std::endl;
    std::cout << "Number of Seconds in Year [" << Year << "] is " << Time.Seconds << std::endl;
    return 0;
}