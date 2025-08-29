#pragma once

#include <iostream>
#include "../../data/model/Types.hpp"
#include "MainMenue.cpp"

#include "../features/manageusersfeatures/ListUsers.hpp"
#include "../features/manageusersfeatures/AddNewUser.hpp"
#include "../features/manageusersfeatures/DeleteUser.hpp"
#include "../features/manageusersfeatures/UpdateUser.hpp"
#include "../features/manageusersfeatures/FindUser.hpp"
using namespace std;

namespace nsManageUsersMenue
{

    short ReadManageUsersMenueElement()
    {
        cout << "Choose what do you want to do? [1 to 6] : \n";
        short Choice = 0;
        cin >> Choice;
        return Choice;
    }

    enManageUsersMenueElement ShowManageUsersMenueScreen()
    {

        cout << "===========================================\n";
        cout << "=========Manage Users Menue Screen=========\n";
        cout << "===========================================\n";
        cout << "   [1] Lits Users.                         \n";
        cout << "   [2] Add New User.                       \n";
        cout << "   [3] Delete User.                        \n";
        cout << "   [4] Update User.                        \n";
        cout << "   [5] Find User.                          \n";
        cout << "   [6] Main Menue.                         \n";
        cout << "===========================================\n";
        return enManageUsersMenueElement(ReadManageUsersMenueElement());
    }

    void PerformManageUsersMenue(string UsersFileName)
    {

        switch (ShowManageUsersMenueScreen())
        {
        case enManageUsersMenueElement::ListUsers:
            nsListUsers::ShowListUsersScreen(UsersFileName);
            PerformManageUsersMenue(UsersFileName);
            break;
        case enManageUsersMenueElement::AddNewUser:
            nsAddNewUser::ShowAddNewUserScreen(UsersFileName);
            system("clear");
            PerformManageUsersMenue(UsersFileName);
            break;
        case enManageUsersMenueElement::DeleteUser:
            nsDeleteUser::ShowDeleteUserScreen(UsersFileName);
            system("clear");
            PerformManageUsersMenue(UsersFileName);
            break;
        case enManageUsersMenueElement::UpdateUser:
            nsUpdateClient::ShowUpdateUserScreen(UsersFileName);
            system("clear");
            PerformManageUsersMenue(UsersFileName);
            break;
        case enManageUsersMenueElement::FindUserUser:
            nsFindUser::ShowFindUserScreen(UsersFileName);
            system("clear");
            PerformManageUsersMenue(UsersFileName);
            break;
        case enManageUsersMenueElement::MainMenue:
            break;

        default:
            break;
        }
    }

}