#pragma once
#include <iostream>
#include "../../lib/Client.hpp"
#include "../../lib/ClientTransactions.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsDeposit
{

    void ShowDepositScreen(string FileName)
    {

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Deposit Screen--------------------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        vector<stClientInfo> vClients;
        vClients = nsData::LoadClientsDataFromFile(FileName);

        string AccountNumber;
        AccountNumber = nsClient::ReadAccountNumber();

        nsClientTranactions::DepositClientByAccountNumber(AccountNumber, FileName, vClients);
    }

}