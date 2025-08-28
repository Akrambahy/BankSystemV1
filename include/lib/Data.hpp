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

    void AddDataLineToFile(string FileName, string ClientDataLine)
    {

        fstream MyFile;

        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << ClientDataLine << endl;

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

                Client = nsConvert::ConvertDataFromeLineToRecord(Line);

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
                    Line = nsConvert::ConvertDataFromeRecordToLine(Client);
                    MyFile << Line << endl;
                }
            }

            MyFile.close();
        }

        return vClients;
    }

}