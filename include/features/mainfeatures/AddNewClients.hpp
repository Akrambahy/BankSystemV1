#pragma once
#include <iostream>
#include <vector>
#include "../../lib/Client.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsAddNewClients
{
    void AddNewClient(string FileName)
    {
        stClientInfo Client;

        Client = nsClient::ReadNewClient(FileName);
        nsData::AddDataLineToFile(FileName, nsConvert::ConvertDataFromeRecordToLine(Client));
    }
    void ShowAddNewClientsScreen(string FileName)
    {

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Add New Client(s) Screen----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        char AddMore = 'Y';
        do
        {

            cout << "Adding New Client:\n\n";
            AddNewClient(FileName);

            cout << "\nClient Added Successfully, do you want to add more clients ? Y / N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');
    }
}
