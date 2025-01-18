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
    bool Delete = false;
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

std::string ConvertRecordToLine(stClient Client, std::string Delim) {
    std::string Record = "";
    Record += Client.AccountNumber + Delim;
    Record += Client.PinNumber + Delim;
    Record += Client.Name + Delim;
    Record += Client.PhoneNumber + Delim;
    Record += std::to_string(Client.AccountBalance);
    return Record;
}

void SaveClientsToFile(std::vector<stClient>& vClients, std::string Path) {
    std::fstream File;
    File.open(Path, std::ios::out);

    while (File.is_open())
    {
        for (stClient& Client : vClients) {
            if (Client.Delete != true) {
                File << ConvertRecordToLine(Client, "#//#") << "\n";
            }
        }

        File.close();
    }
}

stClient UpdateClient(std::string AccountNumber) {
    stClient Client;
    Client.AccountNumber = AccountNumber;
    Client.PinNumber = input::ReadString("Enter PinCode? ");
    Client.Name = input::ReadString("Enter Name? ");
    Client.PhoneNumber = input::ReadString("Enter Phone Number? ");
    Client.AccountBalance = input::ReadNumber("Enter Account Balance? ", "Error, Enter a Valid Number? ");
    return Client;
}

bool UpdateClient(std::string Path, std::string Account) {
    std::vector<stClient> vClients = LoadClientsFromFile("./Clients.txt");
    char Vertificate = 'y';
    for (stClient& Client : vClients) {
        if (Client.AccountNumber == Account) {
            std::cout << "The following are the client details:\n\n";
            PrintClient(Client);
            input::ReadChar("\n\nAre you sure you want to update this client? y/n?");
            if (tolower(Vertificate) == 'y') {
                Client = UpdateClient(Account);
                SaveClientsToFile(vClients, "./Clients.txt");
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string Account = input::ReadString("Please Enter Account Number? ");
    std::cout << std::endl;
    stClient Client;
    if (UpdateClient("./Clients.txt", Account)) {
        std::cout << "Client Updated Successfully";
    } else {
        std::cout << "Client with Account Number (" << Account << ") Not Found!";
    }
    return 0;
}