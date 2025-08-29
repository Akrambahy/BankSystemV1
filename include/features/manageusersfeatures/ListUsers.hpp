#pragma once
#include <iostream>
#include <vector>
#include "../../lib/User.hpp"
#include "../../lib/Data.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

namespace nsListUsers
{

    void ShowListUsersScreen(string UsersFileName)
    {

        vector<stUserInfo> vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

        cout << "                           Users List (" << vUsers.size() << ") User(s)                              \n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| " << setw(15) << left << "UserName";
        cout << "| " << setw(10) << left << "Password";
        cout << "| " << setw(12) << left << "Balance";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------\n";

        for (stUserInfo User : vUsers)
        {
            nsUser::PrintUserDataLine(User);
            cout << endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
    }

}
