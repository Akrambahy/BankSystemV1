#pragma once
#include <iostream>
#include "../../lib/User.hpp"
#include "../../lib/Client.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../lib/Permissions.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsDeleteUser
{

    void ShowDeleteUserScreen(string UsersFileName) // To Print Delete Screen And Load Data Form File To Vector And Read Account Number And Performe Deleting
    {
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Delete User(s) Screen-----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        string UserName;
        UserName = nsUser::ReadUserName();

        vector<stUserInfo> vUsers;
        vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

        nsUser::DeleteUserByUserName(UsersFileName, UserName, vUsers);
    }

}