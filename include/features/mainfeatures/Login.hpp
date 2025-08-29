#pragma once
#include <iostream>
#include <vector>
#include "../../lib/Client.hpp"
#include "../../lib/User.hpp"
#include "../../lib/Data.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

namespace nsLogin
{

        bool ShowLoginScreen(string UsersFileName, stUserInfo &User)
        {

                cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
                cout << "------------------------------------------------------Login Screen-----------------------------------------------------------------------\n";
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

                stUserInfo LoginUser;

                vector<stUserInfo> vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

                string UserName = nsUser::ReadUserName();

                if (nsUser::CheckUserByUser(vUsers, UserName))
                {

                        string Password = nsUser::ReadPassword();

                        if (nsUser::CheckUserByPassword(vUsers, Password))
                        {
                                if (nsUser::FindUserByUserNameAndPassword(UserName, Password, vUsers, User))
                                {
                                        cout << "Login Successfully .\n";
                                        return true;
                                }
                                else
                                {
                                        cout << "Login Faild !\n";
                                        return false;
                                }
                        }

                        else
                        {
                                cout << "Invalid Password !\n";
                                return false;
                        }
                }

                else
                {
                        cout << "Invalid UserName !\n";
                        return false;
                }
                return false;
        }

}