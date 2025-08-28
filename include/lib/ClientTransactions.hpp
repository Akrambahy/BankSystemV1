#pragma once
#include <iostream>
#include <vector>
#include "utils/SplitString.hpp"
#include "Client.hpp"
#include "../../data/model/Types.hpp"

using namespace std;

namespace nsClientTranactions
{

    double ReadDepositNumber()
    {
        double Deposit;
        cout << "Pleas Enter Deposit Amount : ";
        cin >> Deposit;

        return Deposit;
    }

    bool IncreaseAccoutBalanceByAccountNumber(string AccountNumber, vector<stClientInfo> &vClients, double DepositNumber)
    {

        for (stClientInfo &C : vClients)
        {

            if (C.AccountNumber == AccountNumber)
            {
                C.Balance += DepositNumber;
                return true;
            }
        }

        return false;
    }

    bool DepositClientByAccountNumber(string AccountNumber, string FileName, vector<stClientInfo> vCliets)
    {

        stClientInfo Client;
        double DepositAmount;
        char Answer = 'N';

        if (nsClient::FindClientByAccountNumber(AccountNumber, vCliets, Client))
        {
            nsClient::PrintClientDataCard(Client);

            DepositAmount = ReadDepositNumber();

            cout << "Are You Sure Want Perform This Transaction ? [Y]/[N] : ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                IncreaseAccoutBalanceByAccountNumber(AccountNumber, vCliets, DepositAmount);
                nsData::SaveClientDataToFile(FileName, vCliets);
                vCliets = nsData::LoadClientsDataFromFile(FileName);
                return true;
            }
        }
        else
        {
            cout << "The Client With Account Number (" << AccountNumber << ") Not Found!\n";
            return false;
        }

        return false;
    }

    double ReadWithDrawNumber()
    {
        double WithDraw;
        cout << "Pleas Enter WithDraw Amount : ";
        cin >> WithDraw;

        return WithDraw;
    }

    bool DecreaseAccoutBalanceByAccountNumber(string AccountNumber, vector<stClientInfo> &vClients, double WithDrawNumber)
    {

        for (stClientInfo &C : vClients)
        {

            if (C.AccountNumber == AccountNumber)
            {
                C.Balance -= WithDrawNumber;
                return true;
            }
        }

        return false;
    }

    bool WithDrawClientByAccountNumber(string AccountNumber, string FileName, vector<stClientInfo> vCliets)
    {

        stClientInfo Client;
        double WithDrawAmount;
        char Answer = 'N';

        if (nsClient::FindClientByAccountNumber(AccountNumber, vCliets, Client))
        {
            nsClient::PrintClientDataCard(Client);

            WithDrawAmount = ReadWithDrawNumber();

            cout << "Are You Sure Want Perform This Transaction ? [Y]/[N] : ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                DecreaseAccoutBalanceByAccountNumber(AccountNumber, vCliets, WithDrawAmount);
                nsData::SaveClientDataToFile(FileName, vCliets);
                vCliets = nsData::LoadClientsDataFromFile(FileName);
                return true;
            }
        }
        else
        {
            cout << "The Client With Account Number (" << AccountNumber << ") Not Found!\n";
            return false;
        }

        return false;
    }

    void PrintShortClientDataLine(stClientInfo ClientData) // To PrintClientData
    {

        cout << "| " << setw(15) << left << ClientData.AccountNumber;
        cout << "| " << setw(40) << left << ClientData.ClientName;
        cout << "| " << setw(12) << left << ClientData.Balance;
    }

    long double CalaculetTotalBalances(vector<stClientInfo> vClients)
    {

        long double TotalBalances = 0;

        for (stClientInfo C : vClients)
        {
            TotalBalances += C.Balance;
        }

        return TotalBalances;
    }

}