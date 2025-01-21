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

enum enFormat { DDMMYYYY = 0, YYYYDDMM, MMDDYYYY, DashMMDDYYYY, DashDDMMYYYY, Detailed};

bool IsLeapYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Year, int Month) {
    std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Days.at(Month-1);
}

bool IsValidDate(stDate D) {
    if (D.Month > 12 || D.Month < 1)
        return false;
    
    if (D.Day < 1 || D.Day > NumberOfDaysInMonth(D.Year, D.Month))
        return false;
    
    return true;
}

std::vector<std::string> SplitString(std::string Str, std::string Delim = " ") {
    std::vector<std::string> vWords;
    short pos = 0;
    std::string Word;

    while ((pos = Str.find(Delim)) != std::string::npos) {
        Word = Str.substr(0, pos);
        if (Word != "") {
            vWords.push_back(Word);
        }
        Str.erase(0, pos + Delim.length());
    } 

    if (Str != "") {
        vWords.push_back(Str);
    }
    
    return vWords;
}

stDate ReadDate(std::string Date) {
    std::vector<std::string> vDate = SplitString(Date, "/");
    stDate D;
    D.Day = std::stoi(vDate.at(0));
    D.Month = std::stoi(vDate.at(1));
    D.Year = std::stoi(vDate.at(2));

    return D;
}

std::string ReplaceWords(std::string Str, std::string StringToReplace, std::string RepalceTo)
{
    short pos = Str.find(StringToReplace);
    while (pos != std::string::npos)
        {
            Str = Str.replace(pos, StringToReplace.length(), RepalceTo);
            pos = Str.find(StringToReplace);
        }
    return Str;
}

std::string FormatDate(stDate Date, std::string Format) {
    std::string Formated = "";
    Formated = ReplaceWords(Format, "DD", std::to_string(Date.Day));
    Formated = ReplaceWords(Formated, "MM", std::to_string(Date.Month));
    Formated = ReplaceWords(Formated, "YYYY", std::to_string(Date.Year));
    return Formated;
}

int main() {
    stDate Date = ReadDate(input::ReadString("Please enter a date DD/MM/YYYY? "));

    std::cout << FormatDate(Date, "DD/MM/YYYY") << std::endl;
    std::cout << FormatDate(Date, "MM/DD/YYYY") << std::endl;
    std::cout << FormatDate(Date, "YYYY/DD/MM") << std::endl;
    std::cout << FormatDate(Date, "DD-MM-YYYY") << std::endl;
    std::cout << FormatDate(Date, "MM-DD-YYYY") << std::endl;
    std::cout << FormatDate(Date, "Day:DD, Month:MM, Year:YYYY") << std::endl;

    return 0;
}