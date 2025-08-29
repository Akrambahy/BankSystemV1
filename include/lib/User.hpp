#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "../../data/model/Types.hpp"
#include "Data.hpp"
#include "Permissions.hpp"

using namespace std;

namespace nsUser
{

    string ReadUserName()
    {
        string UserName;

        cout << "Pleas Enter Your User Name : \n";
        cin >> UserName;

        return UserName;
    }

    string ReadPassword()
    {
        string Password;

        cout << "Pleas Enter Your Password : \n";
        cin >> Password;

        return Password;
    }

    bool CheckUserByUser(vector<stUserInfo> vUsers, string UserName)
    {

        for (stUserInfo User : vUsers)
        {
            if (User.UserName == UserName)
            {
                return true;
            };
        }
        return false;
    }

    bool CheckUserByPassword(vector<stUserInfo> vUsers, string Password)
    {

        for (stUserInfo User : vUsers)
        {
            if (User.Password == Password)
            {
                return true;
            };
        }
        return false;
    }

    bool FindUserByUserNameAndPassword(string UserName, string Password, vector<stUserInfo> &vUsers, stUserInfo &User)
    {

        for (stUserInfo U : vUsers)
        {
            if (U.UserName == UserName && U.Password == Password)
            {
                User = U;
                return true;
            }
        }
        return false;
    }

    bool FindUserByUserName(string UserName, vector<stUserInfo> &vUsers, stUserInfo &User)
    {

        for (stUserInfo U : vUsers)
        {
            if (U.UserName == UserName)
            {
                User = U;
                return true;
            }
        }
        return false;
    }

    void PrintUserDataLine(stUserInfo UserInfo) // To PrintUserData
    {

        cout << "| " << setw(15) << left << UserInfo.UserName;
        cout << "| " << setw(10) << left << UserInfo.Password;
        cout << "| " << setw(12) << left << UserInfo.Permissions;
    }

    bool UserExistsByUserName(string UsersFileName, string UserName)
    {

        vector<stUserInfo> vUsers = nsData::LoadUsersDataFromFile(UsersFileName);

        for (stUserInfo User : vUsers)
        {
            if (User.UserName == UserName)
            {
                return true;
            };
        }
        return false;
    }

    stUserInfo ReadNewUser(string UsersFileName)
    {
        stUserInfo User;

        do
        {
            cout << "Enter UserName ? :";
            getline(cin >> ws, User.UserName);
        } while (UserExistsByUserName(UsersFileName, User.UserName));

        cout << "\nEnterPassword ? :";
        getline(cin, User.Password);

        User.Permissions == nsPermissions::ReadPermissionToSet();
        return User;
    }

    void PrintUserDataCard(stUserInfo User)
    {
        cout << "\nThe following are the User details:\n";

        cout << "-----------------------------------";
        cout << "\nUser Namr    : " << User.UserName;
        cout << "\nPassword     : " << User.Password;
        cout << "\nPermission   : " << User.Permissions;
        cout << "\n-----------------------------------\n";
    }

    bool MarkUserForDeleteByUserName(string UserName, vector<stUserInfo> &vUsers) // to search A Client With the Acoount Number And Make It Deletable
    {
        for (stUserInfo &U : vUsers)
        {
            if (U.UserName == UserName)
            {
                U.Deletable = true;
                return true;
            }
        }
        return false;
    }

    bool DeleteUserByUserName(string UsersFileName, string UserName, vector<stUserInfo> &vUsers) //  To Take AccountNumber And Chack It And Ask User Are Shoure to Delete It If Yes Delete And ReFresh File And and save New Data In Vector
    {
        stUserInfo User;
        char Answer = 'N';

        if (FindUserByUserName(UserName, vUsers, User))
        {
            PrintUserDataCard(User);

            cout << "\n\n Are You Sure You Want Delete This User [Y]/[N] ?\n";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                MarkUserForDeleteByUserName(UserName, vUsers);
                nsData::SaveUsersDataToFile(UsersFileName, vUsers);
                vUsers = nsData::LoadUsersDataFromFile(UsersFileName);
                cout << "\n\nUser Deleted Successfully\n";
                return true;
            }
        }

        else
        {

            cout << "The User With Account Number (" << UserName << ") Not Found!\n";
            return false;
        }
        return false;
    }

    stUserInfo ChangeUserData(string UserName) // To Read New User Data
    {
        stUserInfo NewUserData;

        NewUserData.UserName = UserName;
        cout << "\nEnter New Password ? :";
        getline(cin >> ws, NewUserData.Password);

        NewUserData.Permissions = nsPermissions::ReadPermissionToSet();

        return NewUserData;
    }

    bool UpdateUserByUserName(string UsersFileName, string UserName, vector<stUserInfo> &vUsers)
    {

        stUserInfo User;

        char Answer = 'N';

        if (FindUserByUserName(UserName, vUsers, User))
        {

            PrintUserDataCard(User);

            cout << "\n\n Are You Sure You Want Update This User [Y]/[N] ?\n";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                for (stUserInfo &U : vUsers)
                {
                    if (U.UserName == UserName)
                    {
                        U = ChangeUserData(UserName);
                        break;
                    }
                }

                nsData::SaveUsersDataToFile(UsersFileName, vUsers);
                return true;
            }
        }
        else
        {
            cout << "User With UserName (" << UserName << ")  Not Found !\n";
            return false;
        }
        return false;
    }

}
