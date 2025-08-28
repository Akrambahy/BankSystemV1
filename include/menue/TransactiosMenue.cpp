#pragma once

#include <iostream>
#include "../../data/model/Types.hpp"
#include "MainMenue.cpp"

#include "../features/transactionsfeatures/Deposit.hpp"
#include "../features/transactionsfeatures/WithDraw.hpp"
#include "../features/transactionsfeatures/TotalBalances.hpp"

using namespace std;

namespace nsTransactionsMenue
{

    short ReadTransactionsMenueElement()
    {
        cout << "Choose what do you want to do? [1 to 4] : \n";
        short Choice = 0;
        cin >> Choice;
        return Choice;
    }

    enTransacionsMenueElement ShowTransactionsMenue()
    {

        cout << "===========================================\n";
        cout << "==========Transactios Menue Screen=========\n";
        cout << "===========================================\n";
        cout << "   [1] Deposit.                            \n";
        cout << "   [2] Withdraw.                           \n";
        cout << "   [3] Total Balances.                     \n";
        cout << "   [4] Main Menue.                         \n";
        cout << "===========================================\n";
        return enTransacionsMenueElement(ReadTransactionsMenueElement());
    }

    void PerformTransactionsManue(string FileName)
    {

        switch (ShowTransactionsMenue())
        {
        case enTransacionsMenueElement::Deposit:
            nsDeposit::ShowDepositScreen(FileName);
            PerformTransactionsManue(FileName);
            break;
        case enTransacionsMenueElement::WithDraw:
            nsWithDraw::ShowWithDrawScreen(FileName);
            PerformTransactionsManue(FileName);
            break;
        case enTransacionsMenueElement::TotalBalances:
            nsTotalBalances::ShowTotalBalancesScreen(FileName);
            PerformTransactionsManue(FileName);
            break;
        case enTransacionsMenueElement::MainManue:
            break;

        default:
            break;
        }
    }

}