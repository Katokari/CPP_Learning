#include <iostream>
#include <cstring>

class clsCalculator {
private:
    std::string _LastOperation;
    float _LastNumber, _LastResults, _Results;

    void _SavaOperation(int Num, std::string Operation) {
        _LastOperation = Operation;
        _LastNumber = Num;
        _LastResults = _Results;
    }


public:
    void Clear() {
        _SavaOperation(0, "Clear");
        _Results = 0;
    }

    void Add(int Num) {
        _SavaOperation(Num, "Adding");
        _Results += Num;
    }

    void Subtract(int Num) {
        _SavaOperation(Num, "Subtracting");
        _Results -= Num;
    }

    void Multiply(int Num) {
        _SavaOperation(Num, "Multiplying");
        _Results *= Num;
    }

    void Divide(int Num) {
        Num = (Num == 0) ? 1 : 0;
        _SavaOperation(Num, "Dividing");
        _Results /= Num;
    }

    void PrintResults() {
        printf("Results After %s %.2f is: %.2f", _LastOperation.c_str(), _LastNumber, _Results);
    }

    float GetResults() {
        return _Results;
    }

    void Undo() {
        _SavaOperation(0, "Undo");
        _Results = _LastResults;
    }
};

int main() {
    clsCalculator Calculator;

    Calculator.Clear();
    Calculator.Add(10);
    Calculator.PrintResults();
    return 0;
}