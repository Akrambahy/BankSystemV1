#pragma once
#include <iostream>
#include "../data/model/Types.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "../include/lib/Data.hpp"
#include "../include/menue/MainMenue.cpp"
#include "../include/menue/TransactiosMenue.cpp"
#include "../data/model/Types.hpp"
#include "../include/lib/Client.hpp"
using namespace std;

namespace nsBankSystem
{

    void BankSystem(string ClientsFileName, string UsersFileName)
    {
        stUserInfo CurrentUser;
        bool Login = nsLogin::ShowLoginScreen(UsersFileName, CurrentUser);
        if (Login == true)
            nsMainMenue::PerformMainManue(ClientsFileName, UsersFileName, CurrentUser);
        else
            cout << "System Error !\n";
    }

}