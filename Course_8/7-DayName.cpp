#include <iostream>
#include <string>
#include <vector>
#include "InputLib.h"

int DayOfWeekOrder(int Day, int Month, int Year) {
    int a = (14 - Month)/12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    int d = (Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

    return d;
}

std::string DayName(int Order) {
    std::vector<std::string> Name = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
    return Name[Order];
}

void PrintDateInfo(int Day, int Month, int Year) {
    std::cout << "Date      : " << Day << "/" << Month << "/" << Year << std::endl;
    int Order = DayOfWeekOrder(Day, Month, Year);
    std::cout << "Day Order : " << Order << std::endl;
    std::cout << "Day Name  : " << DayName(Order) << std::endl;
}

int main()
{
    int Year = input::ReadNumber("Please enter a year? ", "Error, please enter a valid year? ");
    int Month = input::ReadNumber("Please enter a month? ", "Error, please enter a valid month? ");
    int Day = input::ReadNumber("Please enter a day? ", "Error, please enter a valid day? ");

    PrintDateInfo(Day, Month, Year);

    return 0;
}