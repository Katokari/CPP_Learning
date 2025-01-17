#include <iostream>
#include <vector>
#include "../InputLib.h"

struct stClient {
    std::string AccountNumber;
    std::string PinNumber;
    std::string Name;
    std::string PhoneNumber;
    int AccountBalance;
};

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

stClient ConvertLineToRecord(std::string Line, std::string Delim) {
    std::vector<std::string> vData = SplitString(Line, "#//#");
    stClient Client;
    Client.AccountNumber = vData.at(0);
    Client.PinNumber = vData.at(1);
    Client.Name = vData.at(2);
    Client.PhoneNumber = vData.at(3);
    Client.AccountBalance = stoi(vData.at(4));
    return Client;
}

void PrintRecord(stClient Client) {
    std::cout << "Account Number: " << Client.AccountNumber << std::endl;
    std::cout << "Pin Code      : " << Client.PinNumber << std::endl;
    std::cout << "Name          : " << Client.Name << std::endl;
    std::cout << "Phone Number  : " << Client.PhoneNumber << std::endl;
    std::cout << "Account Balance: " << Client.AccountBalance << std::endl;
}

int main() {
    std::string Line = "A001#//#005#//#Kato#//#094913000#//#5000";
    stClient Client = ConvertLineToRecord(Line, "#//#");
    std::cout << "Line Record is:\n" << Line << "\n\n";
    std::cout << "The following is the extracted client data:\n\n\n";
    PrintRecord(Client);
    return 0;
}