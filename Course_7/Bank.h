#pragma once
#include <vector>
#include <fstream>
#include <iomanip>
#include "InputLib.h"

namespace bank {
    struct stClient {
        std::string AccountNumber;
        std::string PinNumber;
        std::string Name;
        std::string PhoneNumber;
        int AccountBalance;
        bool Delete = false;
    };

    void Pause() {
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.get();
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
    
    std::string ConvertRecordToLine(stClient Client, std::string Delim) {
        std::string Record = "";
        Record += Client.AccountNumber + Delim;
        Record += Client.PinNumber + Delim;
        Record += Client.Name + Delim;
        Record += Client.PhoneNumber + Delim;
        Record += std::to_string(Client.AccountBalance);
        return Record;
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

    void PrintClientRecord(stClient Client)
    {
        std::cout << "| " << std::setw(15) << std::left << Client.AccountNumber;
        std::cout << "| " << std::setw(10) << std::left << Client.PinNumber;
        std::cout << "| " << std::setw(40) << std::left << Client.Name;
        std::cout << "| " << std::setw(12) << std::left << Client.PhoneNumber;
        std::cout << "| " << std::setw(12) << std::left << Client.AccountBalance;
    }

    void PrintAllClientsData(std::vector<stClient>& vClients)
    {
        std::cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        std::cout << "| " << std::left << std::setw(15) << "Accout Number";
        std::cout << "| " << std::left << std::setw(10) << "Pin Code";
        std::cout << "| " << std::left << std::setw(40) << "Client Name";
        std::cout << "| " << std::left << std::setw(12) << "Phone";
        std::cout << "| " << std::left << std::setw(12) << "Balance";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        
        for (stClient& Client : vClients)
        {
            if (!Client.Delete) {
                PrintClientRecord(Client);
                std::cout << std::endl;
            }
        }

        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        Pause();
    }

    void PrintClient(stClient Client) {
        std::cout << "Account Number: " << Client.AccountNumber << std::endl;
        std::cout << "Pin Code      : " << Client.PinNumber << std::endl;
        std::cout << "Name          : " << Client.Name << std::endl;
        std::cout << "Phone Number  : " << Client.PhoneNumber << std::endl;
        std::cout << "Account Balance: " << Client.AccountBalance << std::endl;
    }

    bool DeleteClient(std::vector<stClient>& vClients) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tDelete Client Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Account = input::ReadString("Please Enter Account Number? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (stClient& Client : vClients) {
            if (Client.AccountNumber == Account) {
                std::cout << "The following are the client details:\n\n";
                PrintClient(Client);
                input::ReadChar("\n\nAre you sure you want to delete this client? y/n?");
                if (tolower(Vertificate) == 'y') {
                    Client.Delete = true;
                    return true;
                }
            }
        }
        return false;
    }

    stClient UpdateClientRecord(std::string AccountNumber) {
        stClient Client;
        Client.AccountNumber = AccountNumber;
        Client.PinNumber = input::ReadString("Enter PinCode? ");
        Client.Name = input::ReadString("Enter Name? ");
        Client.PhoneNumber = input::ReadString("Enter Phone Number? ");
        Client.AccountBalance = input::ReadNumber("Enter Account Balance? ", "Error, Enter a Valid Number? ");
        return Client;
    }

    bool UpdateClient(std::vector<stClient>& vClients) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tUpdate Client Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Account = input::ReadString("Please Enter Account Number? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (stClient& Client : vClients) {
            if (Client.AccountNumber == Account) {
                std::cout << "The following are the client details:\n\n";
                PrintClient(Client);
                input::ReadChar("\n\nAre you sure you want to update this client? y/n?");
                if (tolower(Vertificate) == 'y') {
                    Client = UpdateClientRecord(Account);
                    Pause();
                    return true;
                }
            }
        }
        Pause();
        return false;
    }

    bool FindClient(std::vector<stClient>& vClients, std::string Account, stClient& C) {
        for (stClient& Client : vClients) {
            if (Client.AccountNumber == Account && !(Client.Delete)) {
                C = Client;
                return true;
            }
        }
        return false;
    }

    bool FindClient(std::vector<stClient>& vClients, std::string Account) {
        for (stClient& Client : vClients) {
            if (Client.AccountNumber == Account && !(Client.Delete)) {
                return true;
            }
        }
        return false;
    }

    void FindClients(std::vector<stClient>& vClients) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tDelete Client Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Account = input::ReadString("Please Enter Account Number? ");
        std::cout << "\n";

        stClient Client;

        if (FindClient(vClients, Account, Client)) {
            std::cout << "The following are the client details:\n\n";
            PrintClient(Client);
        } else {
            std::cout << "Client with Account Number (" << Account << ") Not Found!";
        }

        Pause();
    }

    stClient ReadClientRecord(std::vector<stClient>& vClients) {
        stClient Client;

        Client.AccountNumber = input::ReadString("Enter Account Number? ");
        while (FindClient(vClients, Client.AccountNumber))
            Client.AccountNumber = input::ReadString("Client with [" + Client.AccountNumber + "] already exists, Enter another one? ");
        Client.PinNumber = input::ReadString("Enter PinCode? ");
        Client.Name = input::ReadString("Enter Name? ");
        Client.PhoneNumber = input::ReadString("Enter Phone Number? ");
        Client.AccountBalance = input::ReadNumber("Enter Account Balance? ", "Error, Enter a Valid Number? ");
        return Client;
    }

    void AddClients(std::vector<stClient>& vClients) {
        char Again = 'y';
        std::cout << "----------------------------------------\n";
        std::cout << "\tAdd New Client Screen\n";
        std::cout << "----------------------------------------\n";
        do {
            std::cout << "\nAdding New Client:\n\n";
            vClients.push_back(ReadClientRecord(vClients));
            Again = input::ReadChar("\nClient Added Successfully, do you want to add more clients? y/n?");
        } while (tolower(Again) == 'y');

        Pause();
    }
}