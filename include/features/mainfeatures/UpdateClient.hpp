#pragma once
#include <iostream>
#include "../../lib/Client.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"
#include "../../lib/Permissions.hpp"

using namespace std;

namespace nsUpdateClient
{

    void ShowUpdateClientScreen(string FileName, stUserInfo CurrentUser)
    {
        if (!nsPermissions::CheckAccessPermisson(enMainMenuePermissions::pUpdateClient, CurrentUser))
        {
            nsPermissions::ShowAccesDenaidMassage();
            return;
        }

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Update Client(s) Screen-----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        vector<stClientInfo> vClients;
        vClients = nsData::LoadClientsDataFromFile(FileName);

        string AccountNumber;
        AccountNumber = nsClient::ReadAccountNumber();
        nsClient::UpdateClientByAccountNumber(FileName, AccountNumber, vClients);
    }

}