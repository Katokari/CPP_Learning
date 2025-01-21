#include <iostream>
#include <vector>
#include "InputLib.h"
#include "Bank.h"

void PrintMainMenu() {
    std::cout << "======================================================\n";
    std::cout << "\t\tMain Menu Screen\n";
    std::cout << "======================================================\n";
    std::cout << "\t[1] Show Clients List.\n";
    std::cout << "\t[2] Add New Client.\n";
    std::cout << "\t[3] Delete Client.\n";
    std::cout << "\t[4] Update Client Info.\n";
    std::cout << "\t[5] Find Client.\n";
    std::cout << "\t[6] Transaction.\n";
    std::cout << "\t[7] Manage Users.\n";
    std::cout << "\t[8] Logout.\n";
    std::cout << "======================================================\n";
}

void PrintTransactionsMenu() {
    std::cout << "======================================================\n";
    std::cout << "\t\tTransactions Menu Screen\n";
    std::cout << "======================================================\n";
    std::cout << "\t[1] Deposit.\n";
    std::cout << "\t[2] Withdraw.\n";
    std::cout << "\t[3] Total Balances.\n";
    std::cout << "\t[4] Main Menu.\n";
    std::cout << "======================================================\n";
}

void PrintManageUsersMenu() {
    std::cout << "======================================================\n";
    std::cout << "\t\tManage Users Menu Screen\n";
    std::cout << "======================================================\n";
    std::cout << "\t[1] List Users.\n";
    std::cout << "\t[2] Add New User.\n";
    std::cout << "\t[3] Delete User.\n";
    std::cout << "\t[4] Update User.\n";
    std::cout << "\t[5] Find User.\n";
    std::cout << "\t[6] Main Menu.\n";
    std::cout << "======================================================\n";
}

void ManageUsersMenu(std::vector<bank::stUser>& vUsers, bank::stUser& User) {
    bool NoExit = true;
    if (!(User.Permissions == -1 || bank::CheckPermission(User, bank::enPermission::ManageUsers))) {
        bank::AccessDenied();
        bank::Pause();
        NoExit = false;
    }

    while (NoExit) {
        std::system("clear");
        PrintManageUsersMenu();

        switch (input::ReadNumberInRange("Choose what do you want to do? [1 to 6]? ", "Error, please enter a valid number: ", 1, 6))
        {
        case 1:
            std::system("clear");
            bank::ListUsers(vUsers);
            break;
        
        case 2:
            std::system("clear");
            bank::AddUsers(vUsers);
            break;

        case 3:
            std::system("clear");
            bank::DeleteUser(vUsers);
            break;

        case 4:
            std::system("clear");
            bank::UpdateUsers(vUsers);
            break;

        case 5:
            std::system("clear");
            bank::FindUsers(vUsers);
            break;

        case 6:
            NoExit = false;
            break;
        }
    }
}

void TransactionsMenu(std::vector<bank::stClient>& Data, bank::stUser& User) {
    bool NoExit = true;
    if (!(User.Permissions == -1 || bank::CheckPermission(User, bank::enPermission::Transactions))) {
        bank::AccessDenied();
        bank::Pause();
        NoExit = false;
    }
    
    while (NoExit) {
        std::system("clear");
        PrintTransactionsMenu();

        switch (input::ReadNumberInRange("Choose what do you want to do? [1 to 4]? ", "Error, please enter a valid number: ", 1, 4))
        {
        case 1:
            std::system("clear");
            ext::Deposit(Data);
            break;
        
        case 2:
            std::system("clear");
            ext::Withdraw(Data);
            break;

        case 3:
            std::system("clear");
            ext::PrintAllClientsBalance(Data);
            break;

        case 4:
            NoExit = false;
            break;
        }
    }
}

void MainMenu(bank::stUser& CurrentUser, std::vector<bank::stUser>& vUsers) {
    std::vector<bank::stClient> Data = bank::LoadClientsFromFile("Clients.txt");
    bool NoExit = true;
    while (NoExit)
    {
        std::system("clear");
        PrintMainMenu();
        
        switch (input::ReadNumberInRange("Choose what do you want to do? [1 to 8]? ", "Error, please enter a valid number: ", 1, 8))
        {
        case 1:
            std::system("clear");
            bank::PrintAllClientsData(Data, CurrentUser);
            break;
        
        case 2:
            std::system("clear");
            bank::AddClients(Data, CurrentUser);
            break;

        case 3:
            std::system("clear");
            bank::DeleteClient(Data, CurrentUser);
            break;

        case 4:
            std::system("clear");
            bank::UpdateClient(Data, CurrentUser);
            break;

        case 5:
            std::system("clear");
            bank::FindClients(Data, CurrentUser);
            break;

        case 6:
            std::system("clear");
            TransactionsMenu(Data, CurrentUser);
            break;

        case 7:
            std::system("clear");
            ManageUsersMenu(vUsers, CurrentUser);
            break;

        case 8:
            NoExit = false;
            break;
        }
    }
    bank::SaveUsersToFile(vUsers, "Users.txt");
    bank::SaveClientsToFile(Data, "Clients.txt");
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

        bank::stUser User;
        User.Username = input::ReadString("Enter Username? ");
        User.Password = input::ReadString("Enter Password? ");

        std::vector<bank::stUser> vUsers = bank::LoadUsersFromFile("Users.txt");

        if (bank::ValidateUser(User, vUsers)) {
            MainMenu(User, vUsers);
            FailedLogin = false;
        }

        FailedLogin = true;
        std::system("clear");
    }
}

int main() {
    Login();
    return 0;
}