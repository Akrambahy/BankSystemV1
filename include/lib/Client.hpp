#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "../../data/model/Types.hpp"
#include "Data.hpp"

using namespace std;

namespace nsClient
{

    void PrintClientDataLine(stClientInfo ClientData) // To PrintClientData
    {

        cout << "| " << setw(15) << left << ClientData.AccountNumber;
        cout << "| " << setw(10) << left << ClientData.PinCode;
        cout << "| " << setw(40) << left << ClientData.ClientName;
        cout << "| " << setw(12) << left << ClientData.Phone;
        cout << "| " << setw(12) << left << ClientData.Balance;
    }

    void PrintClientDataCard(stClientInfo Client)
    {
        cout << "\nThe following are the client details:\n";

        cout << "-----------------------------------";
        cout << "\nAccout Number: " << Client.AccountNumber;
        cout << "\nPin Code     : " << Client.PinCode;
        cout << "\nName         : " << Client.ClientName;
        cout << "\nPhone        : " << Client.Phone;
        cout << "\nAccount Balance: " << Client.Balance;
        cout << "\n-----------------------------------\n";
    }

    bool ClientExistsByAccountNumber(string FileName, string AccountNumber)
    {

        vector<stClientInfo> vClientsInfo = nsData::LoadClientsDataFromFile(FileName);

        for (stClientInfo Client : vClientsInfo)
        {
            if (Client.AccountNumber == AccountNumber)
            {
                return true;
            };
        }
        return false;
    }

    stClientInfo ReadNewClient(string FileName)
    {
        stClientInfo Client;

        do
        {
            cout << "Enter Account Number ? :";
            getline(cin >> ws, Client.AccountNumber);
        } while (ClientExistsByAccountNumber(FileName, Client.AccountNumber));

        cout << "\nEnter Pin Code ? :";
        getline(cin, Client.PinCode);
        cout << "\nEnter Client Name ? :";
        getline(cin, Client.ClientName);
        cout << "\nEnter Phone ? :";
        getline(cin, Client.Phone);
        cout << "\nEnter Balance ? :";
        cin >> Client.Balance;

        return Client;
    }

    string ReadAccountNumber() // To Aske User About Account Number And Take It
    {
        string AccountNumber;

        cout << "Pleas Enter Account Number : \n";
        cin >> AccountNumber;

        return AccountNumber;
    }

    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClientInfo> &vClients) // to search A Client With the Acoount Number And Make It Deletable
    {
        for (stClientInfo &C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.Deletable = true;
                return true;
            }
        }
        return false;
    }

    bool FindClientByAccountNumber(string AccountNumber, vector<stClientInfo> &vClients, stClientInfo &Client) // to Chack Client Are Find Use Account Number and if Yes Save Her Data In Client
    {

        for (stClientInfo C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }

    bool DeleteClientByAccountNumber(string FileName, string AccountNumber, vector<stClientInfo> &vClients) //  To Take AccountNumber And Chack It And Ask User Are Shoure to Delete It If Yes Delete And ReFresh File And and save New Data In Vector
    {
        stClientInfo Client;
        char Answer = 'N';

        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientDataCard(Client);

            cout << "\n\n Are You Sure You Want Delete This Client [Y]/[N] ?\n";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                nsData::SaveClientDataToFile(FileName, vClients);
                vClients = nsData::LoadClientsDataFromFile(FileName);
                cout << "\n\nClient Deleted Successfully\n";
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

    stClientInfo ChangeClientCard(string AccountNumber) // To Read Client Data Without Account Number
    {
        stClientInfo NewClientData;

        NewClientData.AccountNumber = AccountNumber;
        cout << "\nEnter Pin Code ? :";
        getline(cin >> ws, NewClientData.PinCode);
        cout << "\nEnter Client Name ? :";
        getline(cin, NewClientData.ClientName);
        cout << "\nEnter Phone ? :";
        getline(cin, NewClientData.Phone);
        cout << "\nEnter Balance ? :";
        cin >> NewClientData.Balance;

        return NewClientData;
    }

    bool UpdateClientByAccountNumber(string FileName, string AccountNumber, vector<stClientInfo> &vClients)
    {

        stClientInfo Client;

        char Answer = 'N';

        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {

            PrintClientDataCard(Client);

            cout << "\n\n Are You Sure You Want Update This Client [Y]/[N] ?\n";
            cin >> Answer;

            if (Answer == 'Y' || Answer == 'y')
            {
                for (stClientInfo &C : vClients)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientCard(AccountNumber);
                        break;
                    }
                }

                nsData::SaveClientDataToFile(FileName, vClients);
                return true;
            }
        }
        else
        {
            cout << "Client Wit Acoount Number (" << AccountNumber << ")  Not Found !\n";
            return false;
        }
        return false;
    }

}
