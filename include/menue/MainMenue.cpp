#pragma once

#include <iostream>

#include "../../data/model/Types.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "../lib/Data.hpp"
#include "TransactiosMenue.cpp"
#include "../../data/model/Types.hpp"
#include "../lib/Client.hpp"
#include "../features/mainfeatures/ShowAllClients.hpp"
#include "../features/mainfeatures/AddNewClients.hpp"
#include "../features/mainfeatures/DeleteClient.hpp"
#include "../features/mainfeatures/UpdateClient.hpp"
#include "../features/mainfeatures/FindClient.hpp"
#include "../features/mainfeatures/Exit.hpp"

using namespace std;

namespace nsMainMenue
{

    short ReadMainMenueElement()
    {
        cout << "Choose what do you want to do? [1 to 6] : \n";
        short Choice = 0;
        cin >> Choice;
        return Choice;
    }

    enMainMenueElement ShowMainMenue()
    {

        cout << "===========================================\n";
        cout << "==============Main Menue Screen============\n";
        cout << "===========================================\n";
        cout << "   [1] Show Client List.                   \n";
        cout << "   [2] Add New Client.                     \n";
        cout << "   [3] Delete Client.                      \n";
        cout << "   [4] Update Client Info.                 \n";
        cout << "   [5] Find Client.                        \n";
        cout << "   [6] Transactions.                        \n";
        cout << "   [7] Exit.                               \n";
        cout << "===========================================\n";
        return enMainMenueElement(ReadMainMenueElement());
    }

    void PerformMainManue(string FileName)
    {

        switch (ShowMainMenue())
        {
        case enMainMenueElement::ShowAllClients:
            nsShowAllClients::ShowAllClientsScreen(FileName);
            PerformMainManue(FileName);
            break;
        case enMainMenueElement::AddNewClient:
            nsAddNewClients::ShowAddNewClientsScreen(FileName);
            PerformMainManue(FileName);
            break;
        case enMainMenueElement::DeleteClient:
            nsDeleteClient::ShowDeleteClientScreen(FileName);
            PerformMainManue(FileName);
            break;

        case enMainMenueElement::UpdateClientInfo:
            nsUpdateClient::ShowUpdateClientScreen(FileName);
            PerformMainManue(FileName);
            break;
        case enMainMenueElement::FindClient:
            nsFindClient::ShowFindClientScreen(FileName);
            PerformMainManue(FileName);
            break;
        case enMainMenueElement::Transactions:
            nsTransactionsMenue::PerformTransactionsManue(FileName);
            PerformMainManue(FileName);
            break;
        case enMainMenueElement::Exit:
            nsExit::ShowExitScreen();
            break;

        default:
            break;
        }
    }

}
