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
    Exit = 7,
};

enum enTransacionsMenueElement
{
    Deposit = 1,
    WithDraw = 2,
    TotalBalances = 3,
    MainManue = 4
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
