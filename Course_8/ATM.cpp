#include <iostream>
#include <vector>
#include <fstream>
#include "InputLib.h"

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

bool ValidateClient(stClient& Client, std::vector<stClient> vClient) {
    for (stClient& C : vClient) {
        if (C.AccountNumber == Client.AccountNumber && C.PinNumber == Client.PinNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

void CheckBalanceScreen(stClient& Client) {
    std::cout << "======================================================\n";
    std::cout << "\t\tCheck Balance Screen\n";
    std::cout << "======================================================\n";
    std::cout << "Your Balance is " << Client.AccountBalance << std::endl;
    Pause();
}

int WithdrawnAmount(int Choose) {
    switch (Choose)
    {
    case 1:
        return 20;
        break;

    case 2:
        return 50;
        break;

    case 3:
        return 100;
        break;

    case 4:
        return 200;
        break;

    case 5:
        return 400;
        break;
    
    case 6:
        return 600;
        break;

    case 7:
        return 800;
        break;

    case 8:
        return 1000;
        break;
    }
}

bool Withdraw(int WithdrawAmount, stClient& Client) {
    if (WithdrawAmount > Client.AccountBalance) {
        std::cout << "\nThe amount exceeds your balance, make another choice.\n";
        Pause();
        return false;
    }

    char Answer = input::ReadChar("Are you sure you want to perform this transaction? y/n? ");
    if (Answer != 'y') {
        return false;
    }

    Client.AccountBalance -= WithdrawAmount;
    std::cout << "Done successfully, new balance is: " << Client.AccountBalance;
    Pause();
    return true;
}

void QuickWithdraw(stClient& Client) {
    std::cout << "======================================================\n";
    std::cout << "\t\tQuick Withdraw\n";
    std::cout << "======================================================\n";
    std::cout << "\t[1] 20  \t[2] 50\n\t[3] 100 \t[4] 200\n\t[5] 400 \t[6] 600\n\t[7] 800 \t[8] 1000\n\t[9] Exit";
    std::cout << "======================================================\n";
    std::cout << "Your Balance is " << Client.AccountBalance << std::endl;
    int Choose = input::ReadNumberInRange("Choose what to withdraw from [1] to [8] ? ", "Error please enter a valid number? ", 1, 8);
    
    if (Choose == 9)
        return;

    int WithdrawAmount = WithdrawnAmount(Choose);

    if (!Withdraw(WithdrawAmount, Client))
        return;
}

void Withdraw(stClient& Client) {
    std::cout << "======================================================\n";
    std::cout << "\t\tNormal Withdraw Screen\n";
    std::cout << "======================================================\n";
    int WithdrawAmount;
    do {
        WithdrawAmount = input::ReadNumber("Enter an amount multiple of 5's ? ", "Please enter a valid number ? ");
    } while (WithdrawAmount % 5 != 0);

    
    if (!Withdraw(WithdrawAmount, Client))
        return;

}

void Deposit(stClient& Client) {
    std::cout << "======================================================\n";
    std::cout << "\t\tDeposit Screen\n";
    std::cout << "======================================================\n";

    int DepositAmount;
    do {
        DepositAmount = input::ReadNumber("Enter a positive deposit amount? ", "Please enter a valid number ? ");
    } while (DepositAmount < 0);

    Client.AccountBalance += DepositAmount;
    std::cout << "Done successfully, new balance is: " << Client.AccountBalance;
    Pause();
}

void Balance(stClient& Client) {
    std::cout << "======================================================\n";
    std::cout << "\t\tCheck Balance Screen\n";
    std::cout << "======================================================\n";
    std::cout << "Your balance is: " << Client.AccountBalance << std::endl;
    Pause();
}

void SaveClientData(stClient& Client, std::vector<stClient>& vClient) {
    for (stClient& C : vClient) {
        if (Client.AccountNumber == C.AccountNumber)
            C = Client;
    }
    SaveClientsToFile(vClient, "Clients.txt");
}

void PrintMainMenu() {
    std::cout << "======================================================\n";
    std::cout << "\t\tATM Main Menu Screen\n";
    std::cout << "======================================================\n";
    std::cout << "\t[1] Quick Withdraw.\n";
    std::cout << "\t[2] Normal Withdraw.\n";
    std::cout << "\t[3] Deposit.\n";
    std::cout << "\t[4] Check Balance.\n";
    std::cout << "\t[5] Logout.\n";
    std::cout << "======================================================\n";
}

void MainMenu(stClient& Client, std::vector<stClient>vClients) {

    bool NoExit = true;
    while (NoExit)
    {
        std::system("clear");
        PrintMainMenu();
        
        switch (input::ReadNumberInRange("Choose what do you want to do? [1 to 5]? ", "Error, please enter a valid number: ", 1, 5))
        {
        case 1:
            system("clear");
            QuickWithdraw(Client);
            break;

        case 2:
            system("clear");
            Withdraw(Client);
            break;

        case 3:
            system("clear");
            Deposit(Client);
            break;
        
        case 4:
            system("clear");
            Balance(Client);
            break;

        case 5:
            NoExit = false;
            break;
        }
    }

    SaveClientData(Client, vClients);
}

void Login() {
    bool FailedLogin = false;
    while (true)
    {
        std::cout << "----------------------------------------\n";
        std::cout << "\tLogin Screen\n";
        std::cout << "----------------------------------------\n";

        if (FailedLogin)
            std::cout << "Invalid Username/Password!\n";

        stClient Client;
        Client.AccountNumber = input::ReadString("Enter Account Number? ");
        Client.PinNumber = input::ReadString("Enter PIN? ");

        std::vector<stClient> vClients = LoadClientsFromFile("Clients.txt");

        if (ValidateClient(Client, vClients)) {
            MainMenu(Client, vClients);
            FailedLogin = false;
        } else {
            FailedLogin = true;
        }

        std::system("clear");
    }
}

int main() {
    Login();
    return 0;
}