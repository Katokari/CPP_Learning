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

std::string FormatDate(stDate Date, enFormat Format) {
    switch (Format)
    {
    case enFormat::DDMMYYYY:
        return std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year);
        break;
    
    case enFormat::MMDDYYYY:
        return std::to_string(Date.Month) + "/" + std::to_string(Date.Day) + "/" + std::to_string(Date.Year);
        break;

    case enFormat::YYYYDDMM:
        return std::to_string(Date.Year) + "/" + std::to_string(Date.Day) + "/" + std::to_string(Date.Month);
        break;

    case enFormat::DashDDMMYYYY:
        return std::to_string(Date.Day) + "-" + std::to_string(Date.Month) + "-" + std::to_string(Date.Year);
        break;

    case enFormat::DashMMDDYYYY:
        return std::to_string(Date.Month) + "-" + std::to_string(Date.Day) + "-" + std::to_string(Date.Year);
        break;

    case enFormat::Detailed:
        return "Day:" + std::to_string(Date.Day) + ", Month:" + std::to_string(Date.Month) + ", Year:" + std::to_string(Date.Year);
        break;
    }
}

int main() {
    stDate Date = ReadDate(input::ReadString("Please enter a date DD/MM/YYYY? "));

    std::cout << FormatDate(Date, enFormat::DDMMYYYY) << std::endl;
    std::cout << FormatDate(Date, enFormat::MMDDYYYY) << std::endl;
    std::cout << FormatDate(Date, enFormat::YYYYDDMM) << std::endl;
    std::cout << FormatDate(Date, enFormat::DashDDMMYYYY) << std::endl;
    std::cout << FormatDate(Date, enFormat::DashMMDDYYYY) << std::endl;
    std::cout << FormatDate(Date, enFormat::Detailed) << std::endl;

    return 0;
}