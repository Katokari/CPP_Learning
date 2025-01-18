#include <iostream>
#include <vector>
#include <fstream>
#include "../InputLib.h"
#include <iomanip>

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

std::vector<stClient> LoadClientsFromFile(std::string Path) {
    std::vector<stClient> vClients;
    std::fstream File;
    File.open(Path, std::ios::in);

    if (File.is_open()) {
        std::string Line;

        while (getline(File, Line)) {
            vClients.push_back(ConvertLineToRecord(Line, "#//#"));
        }

        File.close();
    }

    return vClients;
}

void PrintClient(stClient Client) {
    std::cout << "Account Number: " << Client.AccountNumber << std::endl;
    std::cout << "Pin Code      : " << Client.PinNumber << std::endl;
    std::cout << "Name          : " << Client.Name << std::endl;
    std::cout << "Phone Number  : " << Client.PhoneNumber << std::endl;
    std::cout << "Account Balance: " << Client.AccountBalance << std::endl;
}

bool FindClient(std::string Path, std::string Account, stClient& C) {
    std::vector<stClient> vClients = LoadClientsFromFile("./Clients.txt");
    for (stClient& Client : vClients) {
        if (Client.AccountNumber == Account) {
            C = Client;
            return true;
        }
    }
    return false;
}

int main() {
    std::string Account = input::ReadString("Please Enter Account Number? ");
    std::cout << std::endl;
    stClient Client;
    if (FindClient("./Clients.txt", Account, Client)) {
        std::cout << "The following are the client details:\n\n";
        PrintClient(Client);
    } else {
        std::cout << "Client with Account Number (" << Account << ") Not Found!";
    }
    return 0;
}