#pragma once

#include <iostream>
#include "../../data/model/Types.hpp"

namespace nsPermissions
{

    int ReadPermissionToSet() // To Ask user about permission You Want
    {
        int Permissions = 0;

        char Answer = 'N';

        cout << "Dou You Want To Five Full Access ? [Y]/[N] : ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            return -1;
        }
        else
        {
            cout << "Dou You Want To Give Access To : \n";
            cout << "\nShow Client List ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pShowClientList;
            }
            cout << "\nAdd New Client ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pAddNewClient;
            }
            cout << "\nDelete Client ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pDeleteClient;
            }

            cout << "\nUpdate Client ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pUpdateClient;
            }
            cout << "\nFind Client ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pFindClient;
            }
            cout << "\nTransactions ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pTransactions;
            }
            cout << "\nManage Users ? [Y]/[N] :";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                Permissions += enMainMenuePermissions::pManageUsers;
            }
        }

        return Permissions;
    }

    bool CheckAccessPermisson(enMainMenuePermissions Permission, stUserInfo CurrentUser) // to Check User Have All Permission or Specific Permission Or Nothing
    {
        if (CurrentUser.Permissions == enMainMenuePermissions::pAll)
            return true;

        if ((Permission & CurrentUser.Permissions) == Permission)
        {
            return true;
        }
        else
        {
            return false;
        }

        return false;
    }

    void ShowAccesDenaidMassage() // if Print Massage Denied User Have`t Permission
    {

        cout << "You Dont Have Access To Do This !! \nConnect With Admin To Give It. \n";
    }

}