#pragma once

#include <iostream>
#include "clsDate.h"

class clsPeriod {
private:
    clsDate _DateStart;
    clsDate _DateEnd;

public:
    clsPeriod(clsDate DateStart, clsDate DateEnd) {
        _DateStart = DateStart;
        _DateEnd = DateEnd;
    }

    void SetDateStart(clsDate DateStart) {
        _DateStart = DateStart;
    }

    clsDate GetDateStart() {
        return _DateStart;
    }

    void SetDateEnd(clsDate DateEnd) {
        _DateEnd = DateEnd;
    }

    clsDate GetDateEnd() {
        return _DateEnd;
    }

    static bool IsDateWithinPeriod(clsPeriod P, clsDate D) {
        return !(clsDate::CompareDate(D, P.GetDateStart()) == clsDate::enCompare::Before || clsDate::CompareDate(D, P.GetDateEnd()) == clsDate::enCompare::After);
    }

    bool IsDateWithinPeriod(clsDate D) {
        return IsDateWithinPeriod(*this, D);
    }
};