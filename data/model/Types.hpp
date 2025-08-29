#pragma once

#include <iostream>

using namespace std;

// Enums

enum enMainMenueElement
{
    ShowAllClients = 1,
    AddNewClient = 2,
    DeleteClient = 3,
    UpdateClientInfo = 4,
    FindClient = 5,
    Transactions = 6,
    ManageUsers = 7,
    Logout = 8,
};

enum enTransacionsMenueElement
{
    Deposit = 1,
    WithDraw = 2,
    TotalBalances = 3,
    MainManue = 4
};
enum enManageUsersMenueElement
{
    ListUsers = 1,
    AddNewUser = 2,
    DeleteUser = 3,
    UpdateUser = 4,
    FindUserUser = 5,
    MainMenue = 6,
};

enum enMainMenuePermissions // to Take Permissions Numbers
{
    pAll = -1,
    pShowClientList = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64,
};

// Structs

struct stClientInfo
{
    string AccountNumber = "";

    string PinCode = "";

    string ClientName = "";

    string Phone = "";

    double Balance = 0;

    bool Deletable = false;
};

struct stUserInfo
{

    string UserName;

    string Password;

    int Permissions;

    bool Deletable = false;
};