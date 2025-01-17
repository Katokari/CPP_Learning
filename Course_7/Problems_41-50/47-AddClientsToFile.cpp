#include <iostream>
#include <vector>
#include <fstream>
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
    Client.AccountNumber = input::ReadString("Enter Account Number? ");
    Client.PinNumber = input::ReadString("Enter PinCode? ");
    Client.Name = input::ReadString("Enter Name? ");
    Client.PhoneNumber = input::ReadString("Enter Phone Number? ");
    Client.AccountBalance = input::ReadNumber("Enter Account Balance? ", "Error, Enter a Valid Number? ");
    return Client;
}

void AddClientsToFile(std::vector<std::string>& vRecords, std::string Path) {
    std::fstream File;
    File.open(Path, std::ios::out | std::ios::app);

    while (File.is_open())
    {
        for (std::string& Record : vRecords) {
            File << Record << "\n";
        }

        File.close();
    }
}

void ReadClientsToFile() {
    std::vector<std::string> vRecords;
    char Again = 'y';
    do {
        std::cout << "\nAdding New Client:\n\n";
        vRecords.push_back(ConvertRecordToLine(ReadClientRecord(), "#//#"));
        Again = input::ReadChar("\nClient Added Successfully, do you want to add more clients? y/n?");
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
    } while (tolower(Again) == 'y');

    AddClientsToFile(vRecords, "./Records.txt");
}

int main() {
    ReadClientsToFile();
    return 0;
}