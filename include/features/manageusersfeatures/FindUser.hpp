#pragma once
#include <iostream>

#include "../../../data/model/Types.hpp"
#include "../../lib/User.hpp"
#include "../../lib/Data.hpp"

namespace nsFindUser
{

        void ShowFindUserScreen(string UsersFileName)
        {

                cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
                cout << "-------------------------------------------Find User(s) Screen-----------------------------------------------------------------------\n";
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

                stUserInfo User;

                vector<stUserInfo> vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

                string UserName = nsUser::ReadUserName();

                nsUser::FindUserByUserName(UserName, vUsers, User);

                nsUser::PrintUserDataCard(User);
        }

}