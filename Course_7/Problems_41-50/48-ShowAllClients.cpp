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

void PrintClientRecord(stClient Client)
{
    std::cout << "| " << std::setw(15) << std::left << Client.AccountNumber;
    std::cout << "| " << std::setw(10) << std::left << Client.PinNumber;
    std::cout << "| " << std::setw(40) << std::left << Client.Name;
    std::cout << "| " << std::setw(12) << std::left << Client.PhoneNumber;
    std::cout << "| " << std::setw(12) << std::left << Client.AccountBalance;
}

void PrintAllClientsData(std::vector<stClient> vClients)
{
    std::cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
    std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
    std::cout << "| " << std::left << std::setw(15) << "Accout Number";
    std::cout << "| " << std::left << std::setw(10) << "Pin Code";
    std::cout << "| " << std::left << std::setw(40) << "Client Name";
    std::cout << "| " << std::left << std::setw(12) << "Phone";
    std::cout << "| " << std::left << std::setw(12) << "Balance";
    std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
    
    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        std::cout << std::endl;
    }

    std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
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

void ReadClientsFromFile() {
    std::vector<stClient> vClients;
    vClients = LoadClientsFromFile("./Clients.txt");
    PrintAllClientsData(vClients);
}

int main() {
    ReadClientsFromFile();
    return 0;
}