#pragma once
#include <iostream>
#include <vector>
#include "../../lib/Client.hpp"
#include "../../lib/Data.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

namespace nsFindClient
{

    void ShowFindClientScreen(string FileName)
    {

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Find Client(s) Screen-----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        string AccountNumber = nsClient::ReadAccountNumber();

        vector<stClientInfo> vClients = nsData::LoadClientsDataFromFile(FileName);

        stClientInfo Client;

        if (nsClient::FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            nsClient::PrintClientDataCard(Client);
        }
        else
        {
            cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
        }
    }

}
