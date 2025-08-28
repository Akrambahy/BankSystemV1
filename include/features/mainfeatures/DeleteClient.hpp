#pragma once
#include <iostream>
#include "../../lib/Client.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsDeleteClient
{

    void ShowDeleteClientScreen(string FileName) // To Print Delete Screen And Load Data Form File To Vector And Read Account Number And Performe Deleting
    {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Delete Client(s) Screen-----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        string AccountNumber;
        AccountNumber = nsClient::ReadAccountNumber();

        vector<stClientInfo> vClients;
        vClients = nsData::LoadClientsDataFromFile(FileName);

        nsClient::DeleteClientByAccountNumber(FileName, AccountNumber, vClients);
    }
}