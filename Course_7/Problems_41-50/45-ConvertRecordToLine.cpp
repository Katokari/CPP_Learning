#include <iostream>
#include "../InputLib.h"

struct stClient {
    std::string AccountNumber;
    std::string PinNumber;
    std::string Name;
    std::string PhoneNumber;
    int AccountBalance;
};

std::string ConvertRecordToLine(stClient Client, std::string Delim) {
    std::string Record = "";
    Record += Client.AccountNumber + Delim;
    Record += Client.PinNumber + Delim;
    Record += Client.Name + Delim;
    Record += Client.PhoneNumber + Delim;
    Record += std::to_string(Client.AccountBalance);
    return Record;
}

stClient ReadClientRecord() {
    stClient Client;
    std::cout << "Please Enter Client Data:\n\n";
    Client.AccountNumber = input::ReadStrings("Enter Account Number? ");
    Client.PinNumber = input::ReadStrings("Enter PinCode? ");
    Client.Name = input::ReadStrings("Enter Name? ");
    Client.PhoneNumber = input::ReadStrings("Enter Phone Number? ");
    Client.AccountBalance = input::ReadNumber("Enter Account Balance? ", "Error, Enter a Valid Number? ");
    return Client;
}

int main() {
    stClient Client = ReadClientRecord();
    std::cout << "\n\n\n";
    std::cout << "Client Record for Saving is:\n";
    std::cout << ConvertRecordToLine(Client, "#//#");
    return 0;
}