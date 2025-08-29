#pragma once
#include <iostream>
#include "../../lib/Client.hpp"
#include "../../lib/User.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"
#include "../../lib/Permissions.hpp"

using namespace std;

namespace nsUpdateClient
{

    void ShowUpdateUserScreen(string UsersFileName)
    {

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Update User(s) Screen-----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        vector<stUserInfo> vUsers;
        vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

        string UserName;
        UserName = nsUser::ReadUserName();
        nsUser::UpdateUserByUserName(UsersFileName, UserName, vUsers);
    }

}