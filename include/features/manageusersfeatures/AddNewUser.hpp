#pragma once
#include <iostream>
#include <vector>
#include "../../lib/Client.hpp"
#include "../../lib/User.hpp"
#include "../../lib/Permissions.hpp"
#include "../../lib/utils/Convert.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsAddNewUser
{

    void AddNewUser(string UsersFileName)
    {
        stUserInfo User;

        User = nsUser::ReadNewUser(UsersFileName);
        nsData::AddDataLineToFile(UsersFileName, nsConvert::ConvertUserDataFromeRecordToLine(User));
    }
    void ShowAddNewUserScreen(string UsersFileName)
    {

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "-------------------------------------------Add New User(s) Screen----------------------------------------------------------------------\n";
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";

        char AddMore = 'Y';
        do
        {

            cout << "Adding New User:\n\n";
            AddNewUser(UsersFileName);

            cout << "\nUser Added Successfully, do you want to add more Users ? Y / N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');
    }
}
