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
    std::cout << "\t[6] Exit.\n";
    std::cout << "======================================================\n";
}

void MainMenu() {
    std::vector<bank::stClient> Data = bank::LoadClientsFromFile("Clients.txt");
    bool NoExit = true;
    while (NoExit)
    {
        std::system("clear");
        PrintMainMenu();
        
        switch (input::ReadNumberInRange("Choose what do you want to do? [1 to 6]? ", "Error, please enter a valid number: ", 1, 6))
        {
        case 1:
            std::system("clear");
            bank::PrintAllClientsData(Data);
            break;
        
        case 2:
            std::system("clear");
            bank::AddClients(Data);
            break;

        case 3:
            std::system("clear");
            bank::DeleteClient(Data);
            break;

        case 4:
            std::system("clear");
            bank::UpdateClient(Data);
            break;

        case 5:
            std::system("clear");
            bank::FindClients(Data);
            break;

        case 6:
            NoExit = false;
            break;
        }
    }

    bank::SaveClientsToFile(Data, "Clients.txt");
}

int main() {
    MainMenu();
    return 0;
}