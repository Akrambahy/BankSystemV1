#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "../lib/utils/SplitString.hpp"
#include "../lib/utils/Convert.hpp"
#include "../../data/model/Types.hpp"

using namespace std;

namespace nsData
{

    void AddDataLineToFile(string FileName, string DataLine)
    {

        fstream MyFile;

        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }
    }

    vector<stClientInfo> LoadClientsDataFromFile(string FileName) // To Load  Client Data Info From File
    {
        vector<stClientInfo> vClientsData;

        fstream MyFile;

        MyFile.open(FileName, ios::in);

        if (MyFile.is_open())
        {

            string Line;
            stClientInfo Client;

            while (getline(MyFile, Line))
            {

                Client = nsConvert::ConvertClientDataFromeLineToRecord(Line);

                vClientsData.push_back(Client);
            }

            MyFile.close();
        }

        return vClientsData;
    }

    vector<stClientInfo> SaveClientDataToFile(string FileName, vector<stClientInfo> vClients) // To Delete Client are Deletable and save file
    {
        fstream MyFile;

        string Line;

        MyFile.open(FileName, ios::out);

        if (MyFile.is_open())
        {

            for (stClientInfo Client : vClients)
            {

                if (Client.Deletable == false)
                {
                    Line = nsConvert::ConvertClientDataFromeRecordToLine(Client);
                    MyFile << Line << endl;
                }
            }

            MyFile.close();
        }

        return vClients;
    }

    vector<stUserInfo> LoadUsersDataFromFile(string FileName) // To Load  Users Data Info From File
    {
        vector<stUserInfo> vUsersData;

        fstream MyFile;

        MyFile.open(FileName, ios::in);

        if (MyFile.is_open())
        {

            string Line;
            stUserInfo User;

            while (getline(MyFile, Line))
            {

                User = nsConvert::ConvertUserDataFromeLineToRecord(Line);

                vUsersData.push_back(User);
            }

            MyFile.close();
        }

        return vUsersData;
    }

    vector<stUserInfo> SaveUsersDataToFile(string FileName, vector<stUserInfo> vUsers) // To Delete By User are Deletable and save file
    {
        fstream MyFile;

        string Line;

        MyFile.open(FileName, ios::out);

        if (MyFile.is_open())
        {

            for (stUserInfo User : vUsers)
            {

                if (User.Deletable == false)
                {
                    Line = nsConvert::ConvertUserDataFromeRecordToLine(User);
                    MyFile << Line << endl;
                }
            }

            MyFile.close();
        }

        return vUsers;
    }

}