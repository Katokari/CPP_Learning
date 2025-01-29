#pragma once
#include <iostream>
#include "clsString.h"
#include <vector>
#include <iomanip>
#include <string>
#include <cstdio>

class clsDate {
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

    static std::string WhiteSpaces(int Num) {
        std::string Ws = "";
        for (int i = 0; i < Num; i++) {
            Ws += " ";
        }
        return Ws;
    }

public:
    clsDate() {
        time_t t = time(0);
        tm* gmtm = localtime(&t);
        _Day = gmtm->tm_mday;
        _Month = gmtm->tm_mon + 1;
        _Year = gmtm->tm_year + 1900;
    }

    clsDate(std::string Date) {
        std::vector<std::string> vDate = clsString::Split(Date, "/");
        _Day = std::stoi(vDate.at(0));
        _Month = std::stoi(vDate.at(1));
        _Year = std::stoi(vDate.at(2));
    }

    clsDate(short Day, short Month, short Year) {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(int DaysSinceYearStart, short Year) {
        _Year = Year;
        *this = AddDaysToDate(*this, DaysSinceYearStart);
    }

    void setDay(short Day) {
        _Day = Day;
    }

    short getDay() {
        return _Day;
    }

    void setMonth(short Month) {
        _Month = Month;
    }

    short getMonth() {
        return _Month;
    }

    void setYear(short Year) {
        _Year = Year;
    }

    short getYear() {
        return _Year;
    }

    void Print()
	{
		std::cout << DateToString() << std::endl;
	}

    static clsDate GetCurrentDate() {
        time_t t = time(0);
        tm* now = localtime(&t);

        clsDate Date(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);

        return Date;
    }

    static bool IsValidDate(clsDate D) {
        if (D.getMonth() > 12 || D.getMonth() < 1)
            return false;
        
        if (D.getDay() < 1 || D.getDay() > NumberOfDaysInMonth(D.getYear(), D.getMonth()))
            return false;
        
        return true;
    }

    bool IsValid() {
        return IsValidDate(*this);
    }

    static bool IsLeapYear(int Year) {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool IsLeapYear() {
        return IsLeapYear(_Year);
    }

	static short NumberOfDaysInAYear(short Year)
	{
		return  IsLeapYear(Year) ? 365 : 364;
	}

	short NumberOfDaysInAYear()
	{
		return  NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return  NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear();
	}

    static int NumberOfDaysInMonth(int Year, int Month) {
        std::vector<int> Days = { 31, (IsLeapYear(Year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return Days.at(Month-1);
    }

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInMonth(_Year, _Month);
	}

	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return  NumberOfDaysInMonth(Year, Month) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return  NumberOfDaysInMonth(_Year, _Month) * 24;
	}

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return  NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return  NumberOfHoursInAMonth(_Month, _Year) * 60;
	}

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return  NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
	}

    static int DayOfWeekOrder(int Day, int Month, int Year) {
        int a = (14 - Month)/12;
        int y = Year - a;
        int m = Month + 12 * a - 2;

        int d = (Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

        return d;
    }

    int DayOfWeekOrder() {
        return DayOfWeekOrder(_Day, _Month, _Year);
    }

    static int DayOfWeekOrder(clsDate Date) {
        int a = (14 - Date.getMonth())/12;
        int y = Date.getYear() - a;
        int m = Date.getMonth() + 12 * a - 2;

        int d = (Date.getDay() + y + (y/4) - (y/100) + (y/400) + ((31*m)/12)) % 7;

        return d;
    }

    static std::string DayName(int Order) {
        std::vector<std::string> Name = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
        return Name[Order];
    }

    static std::string DayName(int Day, int Month, int Year) {
        std::vector<std::string> Name = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
        return Name[DayOfWeekOrder(Day, Month, Year)];
    }

    std::string DayName() {
        std::vector<std::string> Name = { "Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
        return Name[DayOfWeekOrder(_Day, _Month, _Year)];
    }

    static std::string MonthShortName(int Month) {
        std::vector<std::string> Months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[Month-1];
    }

    std::string MonthShortName() {
        std::vector<std::string> Months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[_Month-1];
    }

    static void PrintMonthCalendar(int Month, int Year) {
        std::cout << "_______________" << MonthShortName(Month) << "_______________" << std::endl;
        std::cout << std::endl;
        std::cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;

        for (int i = 1; i <= NumberOfDaysInMonth(Year, Month); i++) {
            short Order = DayOfWeekOrder(i, Month, Year);

            if (Order == 0) {
                std::cout << std::endl;
            }

            if (i == 1) {
                std::cout << WhiteSpaces(Order * 5);
            }

            std::cout << std::left << std::setw(3) << i << "  ";
        }

        std::cout << std::endl << "_________________________________" << std::endl;
    }

    void PrintMonthCalendar() {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year) {
        std::cout << "_________________________________\n\n";
        std::cout << "\tCalindar - " << Year << "\n";
        std::cout << "_________________________________\n\n";

        for (int i = 1; i <= 12; i++) {
            PrintMonthCalendar(i, Year);
            std::cout << "\n";
        }
    }

    void PrintYearCalendar() {
        PrintYearCalendar(_Year);
    }

    static int DaysSinceStart(int Day, int Month, int Year) {
        int Days = 0;
        for (int i = 1; i < Month; i++) {
            Days += NumberOfDaysInMonth(Year, i);
        }
        return Days + Day;
    }

    int DaysSinceStart() {
        int Days = 0;
        for (int i = 1; i < _Month; i++) {
            Days += NumberOfDaysInMonth(_Year, i);
        }
        return Days + _Day;
    }

    static clsDate AddDaysToDate(clsDate Date, int Days) {
        Days += DaysSinceStart(Date.getDay(), Date.getMonth(), Date.getYear());
        Date.setDay(1);
        Date.setMonth(1);
        while (Days > 0) {
            int DaysInCurrentMonth = NumberOfDaysInMonth(Date.getYear(), Date.getMonth());
            if (Days > DaysInCurrentMonth) {
                Days -= DaysInCurrentMonth;
                Date.setMonth(Date.getMonth()+1);
                
                if (Date.getMonth() > 12) {
                    Date.setYear(Date.getYear()+1);
                    Date.setMonth(1);
                }
            } else {
                Date.setDay(Days);
                Days = 0;
            }
        }

        return Date;
    }

    void AddDays(int Days) {
        *this = AddDaysToDate(*this, Days);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
        return (Date1.getYear() == Date2.getYear() && Date1.getMonth() == Date2.getMonth() && Date1.getDay() == Date2.getDay()) ? true : false;
    }

    bool IsDateEqualDate2(clsDate Date2) {
        return IsDate1EqualDate2(*this, Date2);
    }

    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        return (Date2.getYear() > Date1.getYear()) ? true : (Date2.getMonth() > Date1.getMonth()) ? true : (Date2.getDay() > Date1.getDay());
    }

    bool IsDateBeforeDate2(clsDate Date2) {
        return IsDate1BeforeDate2(*this, Date2);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
    }

    bool IsDateAfterDate2(clsDate Date2) {
        return IsDate1AfterDate2(*this, Date2);
    }

    static bool IsLastDayInMonth(clsDate Date) {
        return (Date.getDay() == NumberOfDaysInMonth(Date.getYear(), Date.getMonth())) ? true : false;
    }

    bool IsLastDayInMonth() {
        IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(clsDate Date) {
        return (Date.getMonth() == 12) ? true : false;
    }

    bool IsLastMonthInYear() {
        IsLastMonthInYear(*this);
    }

	static std::string DateToString(clsDate Date)
	{
		return  std::to_string(Date.getDay()) + "/" + std::to_string(Date.getMonth()) + "/" + std::to_string(Date.getYear());
	}

    std::string DateToString()
	{
		return  DateToString(*this);
	}

    static clsDate IncreaseDateByOneDay(clsDate Date) {
        Date.setDay(Date.getDay()+1);
        if (Date.getDay() > NumberOfDaysInMonth(Date.getYear(), Date.getMonth())) {
            Date.setDay(1);
            Date.setMonth(Date.getMonth()+1);
            if (Date.getMonth() > 12) {
                Date.setMonth(1);
                Date.setYear(Date.getYear()+1);
            }
        }
        return Date;
    }

    void IncreaseDateByOneDay() {
        *this = IncreaseDateByOneDay(*this);
    }

    static int DiffDate1Date2(clsDate Date1, clsDate Date2, bool IncludeLastDay = true) {
        int Swap = 1;
        int Days = 0;
        if (IsDate1BeforeDate2(Date1, Date2)) {
            std::swap(Date1, Date2);
            Swap = -1;
        }

        while (IsDate1BeforeDate2(Date2, Date1))
        {
            Days++;
            Date2 = IncreaseDateByOneDay(Date2);
        }

        if (IncludeLastDay) {
            if (Swap == -1) {
                return Days * Swap - 1;
            }
            return Days * Swap + 1;
        }

        return Days * Swap;
    }

    int DiffDateDate2(clsDate Date2, bool IncludeLastDay = true) {
        return DiffDate1Date2(*this, Date2, IncludeLastDay);
    }

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return DiffDate1Date2(clsDate::GetCurrentDate(), DateOfBirth, true);
	}

    static clsDate IncreaseDateByXDays(clsDate Date, int Days) {
        for (int i = 1; i <= Days; i++) {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDays(int Days) {
        *this = IncreaseDateByXDays(*this, Days);
    }

    static clsDate IncreaseDateByOneWeek(clsDate Date) {
        return IncreaseDateByXDays(Date, 7);
    }

    void IncreaseDateByOneWeek() {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(clsDate Date, int Weeks) {
        for (int i = 1; i <= Weeks; i++) {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(int Weeks) {
        *this = IncreaseDateByXWeeks(*this, Weeks);
    }

    static clsDate IncreaseDateByOneMonth(clsDate Date) {
        if (Date.getMonth() == 12) {
            Date.setMonth(1);
            Date.setYear(Date.getYear()+1);
        } else {
            Date.setMonth(Date.getMonth()+1);
        }
        short MonthsCurrentDays = NumberOfDaysInMonth(Date.getYear(), Date.getMonth());
        if (Date.getDay() > MonthsCurrentDays) {
            Date.setDay(MonthsCurrentDays);
        }
        return Date;
    }

    void IncreaseDateByOneMonth() {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(clsDate Date, int Months) {
        for (int i = 1; i <= Months; i++) {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(int Months) {
        *this = IncreaseDateByXMonths(*this, Months);
    }

    static clsDate IncreaseDateByOneYear(clsDate Date) {
        Date.setYear(Date.getYear()+1);
        return Date;
    }

    void IncreaseDateByOneYear() {
        *this = IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(clsDate Date, int Years) {
        for (int i = 1; i <= Years; i++) {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }

    void IncreaseDateByXYears(int Years) {
        *this = IncreaseDateByXYears(*this, Years);
    }

    static clsDate IncreaseDateByXYearsFast(clsDate Date, int Years) {
        Date.setYear(Date.getYear()+Years);
        return Date;
    }

    void IncreaseDateByXYearsFast(int Years) {
        *this = IncreaseDateByXYearsFast(*this, Years);
    }

    static clsDate IncreaseDateByOneDecade(clsDate Date) {
        Date.setYear(Date.getYear()+10);
        return Date;
    }

    void IncreaseDateByOneDecade() {
        *this = IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(clsDate Date, int Decades) {
        for (int i = 1; i <= Decades; i++) {
            Date = IncreaseDateByOneDecade(Date);
        }
        return Date;
    }

    void IncreaseDateByXDecades(int Decades) {
        *this = IncreaseDateByXDecades(*this, Decades);
    }

    static clsDate IncreaseDateByXDecadesFast(clsDate Date, int Decades) {
        Date.setYear(Date.getYear() + (Decades * 10));
        return Date;
    }

    void IncreaseDateByXDecadesFast(int Decades) {
        *this = IncreaseDateByXDecadesFast(*this, Decades);
    }

    static clsDate IncreaseDateByOneCentury(clsDate Date) {
        Date.setYear(Date.getYear()+100);
        return Date;
    }

    void IncreaseDateByOneCentury() {
        *this = IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate Date) {
        Date.setYear(Date.getYear()+1000);
        return Date;
    }

    void IncreaseDateByOneMillennium() {
        *this = IncreaseDateByOneMillennium(*this);
    }

    static clsDate DecreaseDateByOneDay(clsDate Date) {
        Date.setDay(Date.getDay()-1);
        if (Date.getDay() < 1) {
            Date.setMonth(Date.getMonth()-1);
            if (Date.getMonth() < 1) {
                Date.setMonth(12);
                Date.setYear(Date.getYear()-1);
            }
            Date.setDay(NumberOfDaysInMonth(Date.getYear(), Date.getMonth()));
        }
        return Date;
    }

    void DecreaseDateByOneDay() {
        *this = DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDays(clsDate Date, int Days) {
        for (int i = 1; i <= Days; i++) {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByXDays(int Days) {
        *this = DecreaseDateByXDays(*this, Days);
    }

    static clsDate DecreaseDateByOneWeek(clsDate Date) {
        return DecreaseDateByXDays(Date, 7);
    }

    void DecreaseDateByOneWeek() {
        *this = DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(clsDate Date, int Weeks) {
        for (int i = 1; i <= Weeks; i++) {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeeks(int Weeks) {
        *this = DecreaseDateByXWeeks(*this, Weeks);
    }

    static clsDate DecreaseDateByOneMonth(clsDate Date) {
        if (Date.getMonth() < 1) {
            Date.setMonth(12);
            Date.setYear(Date.getYear()-1);
        } else {
            Date.setMonth(Date.getMonth()-1);
        }
        short MonthsCurrentDays = NumberOfDaysInMonth(Date.getYear(), Date.getMonth());
        if (Date.getDay() > MonthsCurrentDays) {
            Date.setDay(MonthsCurrentDays);
        }
        return Date;
    }

    void DecreaseDateByOneMonth() {
        *this = DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(clsDate Date, int Months) {
        for (int i = 1; i <= Months; i++) {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonths(int Months) {
        *this = DecreaseDateByXMonths(*this, Months);
    }

    static clsDate DecreaseDateByOneYear(clsDate Date) {
        Date.setYear(Date.getYear()-1);
        return Date;
    }

    void DecreaseDateByOneYear() {
        *this = DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(clsDate Date, int Years) {
        for (int i = 1; i <= Years; i++) {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }

    void DecreaseDateByXYears(int Year) {
        *this = DecreaseDateByXYears(*this, Year);
    }

    static clsDate DecreaseDateByXYearsFast(clsDate Date, int Years) {
        Date.setYear(Date.getYear() - Years);
        return Date;
    }

    void DecreaseDateByXYearsFast(int Year) {
        *this = DecreaseDateByXYearsFast(*this, Year);
    }

    static clsDate DecreaseDateByOneDecade(clsDate Date) {
        Date.setYear(Date.getYear() - 10);
        return Date;
    }

    void DecreaseDateByOneDecade() {
        *this = DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(clsDate Date, int Decades) {
        for (int i = 1; i <= Decades; i++) {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }

    void DecreaseDateByXDecades(int Decades) {
        *this = DecreaseDateByXDecades(*this, Decades);
    }

    static clsDate DecreaseDateByXDecadesFast(clsDate Date, int Decades) {
        Date.setYear(Date.getYear() - (Decades * 10));
        return Date;
    }

    void DecreaseDateByXDecadesFast(int Decades) {
        *this = DecreaseDateByXDecadesFast(*this, Decades);
    }

    static clsDate DecreaseDateByOneCentury(clsDate Date) {
        Date.setYear(Date.getYear() - 100);
        return Date;
    }

    void DecreaseDateByOneCentury() {
        *this = DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate Date) {
        Date.setYear(Date.getYear() - 1000);
        return Date;
    }

    void DecreaseDateByOneMillennium() {
        *this = DecreaseDateByOneMillennium(*this);
    }

    static bool IsEndOfWeek(clsDate Date) {
        return (DayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear()) == 6);
    }

    bool IsEndOfWeek() {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date) {
        int DayOrder = DayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear());
        return (DayOrder == 5 || DayOrder == 6);
    }

    bool IsWeekEnd() {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date) {
        return !(IsWeekEnd(Date));
    }

    bool IsBusinessDay() {
        return IsBusinessDay(*this);
    }

    static int DaysUntilTheEndOfWeek(clsDate Date) {
        return 6 - DayOfWeekOrder(Date.getDay(), Date.getMonth(), Date.getYear());
    }

    int DaysUntilTheEndOfWeek() {
        return DaysUntilTheEndOfWeek(*this);
    }

    static int DaysUntilTheEndOfMonth(clsDate Date) {
        return (NumberOfDaysInMonth(Date.getYear(), Date.getMonth()) - Date.getDay()) + 1;
    }

    int DaysUntilTheEndOfMonth() {
        return DaysUntilTheEndOfMonth(*this);
    }

    static int DaysUntilTheEndOfYear(clsDate Date) {
        return NumberOfDaysInAYear(Date.getYear()) - DaysSinceStart(Date.getDay(), Date.getMonth(), Date.getYear()) + 1;
    }

    int DaysUntilTheEndOfYear() {
        return DaysUntilTheEndOfYear(*this);
    }

    static int CalculateVacationDays(clsDate Date1, clsDate Date2) {
        int Vacation = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            if (IsBusinessDay(Date1)) {
                Vacation++;
            }
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return Vacation;
    }

    static clsDate VacationReturn(clsDate Date, int VacationDays) {
        while (VacationDays > 0)
        {
            if (IsBusinessDay(Date)) {
                VacationDays--;
            }

            Date = IncreaseDateByOneDay(Date);
        }  
        return Date;
    }

    enum enCompare{ After = 0, Equal, Before};

    static enCompare CompareDate(clsDate Date1, clsDate Date2) {
        if (IsDate1AfterDate2(Date1, Date2)) {
            return enCompare::After;
        }
        if (IsDate1EqualDate2(Date1, Date2)) {
            return enCompare::Equal;
        }

        return enCompare::Before;
    }

    enCompare CompareDate(clsDate Date2) {
        return CompareDate(*this, Date2);
    }

	static std::string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year,Hour,Minute,Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (std::to_string(Day) + "/" + std::to_string(Month) + "/" + std::to_string(Year) + " - " + 
        std::to_string(Hour) + ":" + std::to_string(Minute) + ":" + std::to_string(Second));

	}
};