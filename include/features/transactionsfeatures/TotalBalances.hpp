#pragma once
#include <iostream>
#include "../../lib/Client.hpp"
#include "../../lib/ClientTransactions.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsTotalBalances
{

    void ShowTotalBalancesScreen(string FileName)
    {

        vector<stClientInfo> vClients = nsData::LoadClientsDataFromFile(FileName);

        long double TotalBalances = nsClientTranactions::CalaculetTotalBalances(vClients);

        cout << "                           Balances List (" << vClients.size() << ") Clients                              \n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| " << setw(15) << left << "AccountNumber";
        cout << "| " << setw(40) << left << "ClientName";
        cout << "| " << setw(12) << left << "Balance";

        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
        for (stClientInfo Client : vClients)
        {
            nsClientTranactions::PrintShortClientDataLine(Client);
            cout << endl;
        }
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n                                           Total Balances = " << TotalBalances << "                                                        \n";
    }

}