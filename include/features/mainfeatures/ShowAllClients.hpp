#pragma once
#include <iostream>
#include <vector>
#include "../../lib/Client.hpp"
#include "../../lib/Data.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"
#include "../../lib/Permissions.hpp"

namespace nsShowAllClients
{

    void ShowAllClientsScreen(string FileName, stUserInfo CurrentUser)
    {
        if (!nsPermissions::CheckAccessPermisson(enMainMenuePermissions::pShowClientList, CurrentUser))
        {
            nsPermissions::ShowAccesDenaidMassage();
            return;
        }

        vector<stClientInfo> vClients = nsData::LoadClientsDataFromFile(FileName);

        cout << "                           Client List (" << vClients.size() << ") Clients                              \n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| " << setw(15) << left << "AccountNumber";
        cout << "| " << setw(10) << left << "PinCode";
        cout << "| " << setw(40) << left << "ClientName";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(12) << left << "Balance";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";

        for (stClientInfo Client : vClients)
        {
            nsClient::PrintClientDataLine(Client);
            cout << endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
    }

}
