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

    struct stUser {
        std::string Username;
        std::string Password;
        int Permissions = 0;
        bool Delete = false;
    };

    enum enPermission { ShowClientList = 1, AddNewClient = 2, DeleteClient2 = 4, UpdateClient2 = 8, 
    FindClient2 = 16, Transactions = 32, ManageUsers = 64}; 

    bool CheckPermission(stUser& User, enPermission Permission);
    void AccessDenied();
    
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

    bool PrintAllClientsData(std::vector<stClient>& vClients, stUser& User)
    {
        if (!(User.Permissions == -1 || CheckPermission(User, enPermission::ShowClientList))) {
            AccessDenied();
            Pause();
            return false;
        }

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
        return true;
    }

    void PrintClient(stClient Client) {
        std::cout << "Account Number: " << Client.AccountNumber << std::endl;
        std::cout << "Pin Code      : " << Client.PinNumber << std::endl;
        std::cout << "Name          : " << Client.Name << std::endl;
        std::cout << "Phone Number  : " << Client.PhoneNumber << std::endl;
        std::cout << "Account Balance: " << Client.AccountBalance << std::endl;
    }

    bool DeleteClient(std::vector<stClient>& vClients, stUser& User) {
        if (!(User.Permissions == -1 || CheckPermission(User, enPermission::DeleteClient2))) {
            AccessDenied();
            Pause();
            return false;
        }

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
                Vertificate = input::ReadChar("\n\nAre you sure you want to delete this client? y/n?");
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

    bool UpdateClient(std::vector<stClient>& vClients, stUser& User) {
        if (!(User.Permissions == -1 || CheckPermission(User, enPermission::UpdateClient2))) {
            AccessDenied();
            Pause();
            return false;
        }

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
                Vertificate = input::ReadChar("\n\nAre you sure you want to update this client? y/n?");
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

    bool FindClients(std::vector<stClient>& vClients, stUser& User) {
        if (!(User.Permissions == -1 || CheckPermission(User, enPermission::FindClient2))) {
            AccessDenied();
            Pause();
            return false;
        }

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
        return true;
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

    bool AddClients(std::vector<stClient>& vClients, stUser& User) {
        if (!(User.Permissions == -1 || CheckPermission(User, enPermission::AddNewClient))) {
            AccessDenied();
            Pause();
            return false;
        }

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
        return true;
    }

    stUser ConvertLineToUser(std::string Line, std::string Delim) {
        std::vector<std::string> vData = bank::SplitString(Line, "#//#");
        stUser User;
        User.Username = vData.at(0);
        User.Password = vData.at(1);
        User.Permissions = std::stoi(vData.at(2));
        return User;
    }
    
    std::string ConvertUserToLine(stUser User, std::string Delim) {
        std::string Line = "";
        Line += User.Username + Delim;
        Line += User.Password + Delim;
        Line += std::to_string(User.Permissions) + Delim;
        return Line;
    }

    bool ValidateUser(stUser& User, std::vector<stUser> vUsers) {
        for (stUser& U : vUsers) {
            if (User.Username == U.Username) {
                if (User.Password == U.Password) {
                    User.Permissions = U.Permissions;
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<stUser> LoadUsersFromFile(std::string Path) {
        std::vector<stUser> vUsers;
        std::fstream File;
        File.open(Path, std::ios::in);

        if (File.is_open()) {
            std::string Line;

            while (getline(File, Line)) {
                vUsers.push_back(ConvertLineToUser(Line, "#//#"));
            }

            File.close();
        }

        return vUsers;
    }

    void SaveUsersToFile(std::vector<stUser>& vUsers, std::string Path) {
        std::fstream File;
        File.open(Path, std::ios::out);

        while (File.is_open())
        {
            for (stUser& User : vUsers) {
                if (User.Delete != true) {
                    File << ConvertUserToLine(User, "#//#") << "\n";
                }
            }

            File.close();
        }
    }

    void PrintUserInfo(stUser User)
    {
        std::cout << "| " << std::setw(25) << std::left << User.Username;
        std::cout << "| " << std::setw(40) << std::left << User.Password;
        std::cout << "| " << std::setw(24) << std::left << User.Permissions;
    }

    void ListUsers(std::vector<stUser>& vUsers)
    {
        std::cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ")User(s).";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        std::cout << "| " << std::left << std::setw(25) << "Username";
        std::cout << "| " << std::left << std::setw(40) << "Password";
        std::cout << "| " << std::left << std::setw(24) << "Permissions";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        
        for (stUser& User : vUsers)
        {
            if (!User.Delete) {
                PrintUserInfo(User);
                std::cout << std::endl;
            }
        }

        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        bank::Pause();
    }

    bool FindUser(std::vector<stUser>& vUsers, std::string Username) {
        for (stUser& User : vUsers) {
            if (User.Username == Username && !(User.Delete)) {
                return true;
            }
        }
        return false;
    }

    int GetPermission() {
        int Perm = 0;
        char Answer = input::ReadChar("Do you want to give full access? y/n? ");
        if (tolower(Answer) == 'y') {
            return -1;
        }
        std::cout << "\nDo you want to give access to :\n\n";
        Answer = input::ReadChar("Show Client List? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 1;
        }
        Answer = input::ReadChar("Add New Client? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 2;
        }
        Answer = input::ReadChar("Delete Client? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 4;
        }
        Answer = input::ReadChar("Update Client? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 8;
        }
        Answer = input::ReadChar("Find Client? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 16;
        }
        Answer = input::ReadChar("Transactions? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 32;
        }
        Answer = input::ReadChar("Manage Users? y/n? ");
        if (tolower(Answer) == 'y') {
            Perm += 64;
        }
        return Perm;
    }

    bool CheckPermission(stUser& User, enPermission Permission) {
        int Perm = User.Permissions;
        switch (Permission)
        {
        case enPermission::ShowClientList:
            return (Perm & (1 << 0)) ? true : false;
        
        case enPermission::AddNewClient:
            return (Perm & (1 << 1)) ? true : false;

        case enPermission::DeleteClient2:
            return (Perm & (1 << 2)) ? true : false;

        case enPermission::UpdateClient2:
            return (Perm & (1 << 3)) ? true : false;

        case enPermission::FindClient2:
            return (Perm & (1 << 4)) ? true : false;

        case enPermission::Transactions:
            return (Perm & (1 << 5)) ? true : false;

        case enPermission::ManageUsers:
            return (Perm & (1 << 6)) ? true : false;
        }
    }

    stUser ReadUser(std::vector<stUser>& vUsers) {
        stUser User;

        User.Username = input::ReadString("Enter Username? ");
        while (FindUser(vUsers, User.Username))
            User.Username = input::ReadString("Client with [" + User.Username + "] already exists, Enter another one? ");
        User.Password = input::ReadString("Enter Password? ");
        User.Permissions = GetPermission();
        return User;
    }

    void AddUsers(std::vector<stUser>& vUsers) {
        char Again = 'y';
        std::cout << "----------------------------------------\n";
        std::cout << "\tAdd New Users Screen\n";
        std::cout << "----------------------------------------\n";
        do {
            std::cout << "\nAdding New User:\n\n";
            vUsers.push_back(ReadUser(vUsers));
            Again = input::ReadChar("\nUser Added Successfully, do you want to add more users? y/n?");
        } while (tolower(Again) == 'y');

        bank::Pause();
    }

    void PrintUser(stUser User) {
        std::cout << "----------------------------------------\n";
        std::cout << "Username     : " << User.Username << std::endl;
        std::cout << "Password     : " << User.Password << std::endl;
        std::cout << "Permissions  : " << User.Permissions << std::endl;
        std::cout << "----------------------------------------\n";
    }

    bool DeleteUser(std::vector<stUser>& vUsers) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tDelete User Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Username = input::ReadString("Please Enter Username? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (stUser& User : vUsers) {
            if (User.Username == Username) {
                std::cout << "The following are the user details:\n\n";
                PrintUser(User);
                Vertificate = input::ReadChar("\n\nAre you sure you want to delete this user? y/n?");
                if (tolower(Vertificate) == 'y') {
                    User.Delete = true;
                    return true;
                }
            }
        }
        return false;
    }

    stUser UpdateUser(std::string Username) {
        stUser User;
        User.Username = Username;
        User.Password = input::ReadString("Enter Password? ");
        User.Permissions = GetPermission();
        return User;
    }

    bool UpdateUsers(std::vector<stUser>& vUsers) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tUpdate User Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Username = input::ReadString("Please Enter Username? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (stUser& User : vUsers) {
            if (User.Username == Username) {
                std::cout << "The following are the user details:\n\n";
                PrintUser(User);
                Vertificate = input::ReadChar("\n\nAre you sure you want to update this client? y/n?");
                if (tolower(Vertificate) == 'y') {
                    User = UpdateUser(Username);
                    bank::Pause();
                    return true;
                }
            }
        }
        bank::Pause();
        return false;
    }

    bool FindUser(std::vector<stUser>& vUsers, std::string Username, stUser& U) {
        for (stUser& User : vUsers) {
            if (User.Username == Username && !(User.Delete)) {
                U = User;
                return true;
            }
        }
        return false;
    }

    void FindUsers(std::vector<stUser>& vUsers) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tFind User Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Username = input::ReadString("Please Enter Username? ");
        std::cout << "\n";

        stUser User;

        if (FindUser(vUsers, Username, User)) {
            std::cout << "The following are the client details:\n\n";
            PrintUser(User);
        } else {
            std::cout << "Client with Account Number (" << Username << ") Not Found!";
        }

        bank::Pause();
    }

    void AccessDenied() {
        std::cout << "----------------------------------------\n";
        std::cout << "Access Denied\n";
        std::cout << "You dont Have Permission To Do This,\n";
        std::cout << "Please Contact Your Admin\n";
        std::cout << "----------------------------------------\n";
    }
}

namespace ext {
    bool Deposit(std::vector<bank::stClient>& vClients) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tDeposit Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Account = input::ReadString("Please Enter Account Number? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (bank::stClient& Client : vClients) {
            if (Client.AccountNumber == Account) {
                std::cout << "The following are the client details:\n\n";
                PrintClient(Client);
                int DepositAmount = input::ReadNumber("Please enter deposit amount? ", "Please enter a valid number? ");
                input::ReadChar("\n\nAre you sure you want to perform this transaction? y/n?");
                if (tolower(Vertificate) == 'y') {
                    Client.AccountBalance += DepositAmount;
                    return true;
                }
            }
        }
        return false;
    }

    bool Withdraw(std::vector<bank::stClient>& vClients) {
        std::cout << "----------------------------------------\n";
        std::cout << "\tWithdraw Screen\n";
        std::cout << "----------------------------------------\n";
        std::string Account = input::ReadString("Please Enter Account Number? ");
        std::cout << "\n";
        char Vertificate = 'y';
        for (bank::stClient& Client : vClients) {
            if (Client.AccountNumber == Account) {
                std::cout << "The following are the client details:\n\n";
                PrintClient(Client);
                int WithdrawAmount = input::ReadNumberInRange("Please enter the withdraw amount? ", "Amount exceeds the balance, you can withdraw up to : " + std::to_string(Client.AccountBalance), 1, Client.AccountBalance);
                input::ReadChar("\n\nAre you sure you want to perform this transaction? y/n?");
                if (tolower(Vertificate) == 'y') {
                    Client.AccountBalance -= WithdrawAmount;
                    return true;
                }
            }
        }
        return false;
    }

    void PrintClientBalance(bank::stClient Client)
    {
        std::cout << "| " << std::setw(25) << std::left << Client.AccountNumber;
        std::cout << "| " << std::setw(40) << std::left << Client.Name;
        std::cout << "| " << std::setw(24) << std::left << Client.AccountBalance;
    }

    void PrintAllClientsBalance(std::vector<bank::stClient>& vClients)
    {
        std::cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        std::cout << "| " << std::left << std::setw(25) << "Accout Number";
        std::cout << "| " << std::left << std::setw(40) << "Client Name";
        std::cout << "| " << std::left << std::setw(24) << "Balance";
        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        
        for (bank::stClient& Client : vClients)
        {
            if (!Client.Delete) {
                PrintClientBalance(Client);
                std::cout << std::endl;
            }
        }

        std::cout << "\n________________________________________________________________________________________________\n" << std::endl;
        bank::Pause();
    }
}
