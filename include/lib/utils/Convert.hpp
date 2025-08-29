#pragma once
#include <iostream>
#include <vector>
#include "../utils/SplitString.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsConvert
{

    string ConvertClientDataFromeRecordToLine(stClientInfo ClientInfo, string Seperator = "/") // To Convert ClientData From Record (struct) To Line(String)
    {
        string ClientDataLine = "";

        ClientDataLine += ClientInfo.AccountNumber + Seperator;
        ClientDataLine += ClientInfo.PinCode + Seperator;
        ClientDataLine += ClientInfo.ClientName + Seperator;
        ClientDataLine += ClientInfo.Phone + Seperator;
        ClientDataLine += to_string(ClientInfo.Balance);

        return ClientDataLine;
    }

    stClientInfo ConvertClientDataFromeLineToRecord(string ClientDataLine, string Seperator = "/") // To Convert ClientData From Line(String) To Record (struct) Using SpletString
    {
        stClientInfo ClientInfo;

        vector<string> vClientsDataLine;

        vClientsDataLine = nsSplitString::SplitString(ClientDataLine, Seperator);

        ClientInfo.AccountNumber = vClientsDataLine[0];
        ClientInfo.PinCode = vClientsDataLine[1];
        ClientInfo.ClientName = vClientsDataLine[2];
        ClientInfo.Phone = vClientsDataLine[3];
        ClientInfo.Balance = stod(vClientsDataLine[4]);

        return ClientInfo;
    }

    string ConvertUserDataFromeRecordToLine(stUserInfo UserInfo, string Seperator = "/") // To Convert ClientData From Record (struct) To Line(String)
    {
        string UserDataLine = "";

        UserDataLine += UserInfo.UserName + Seperator;
        UserDataLine += UserInfo.Password + Seperator;
        UserDataLine += to_string(UserInfo.Permissions);

        return UserDataLine;
    }

    stUserInfo ConvertUserDataFromeLineToRecord(string UserDataLine, string Seperator = "/") // To Convert ClientData From Line(String) To Record (struct) Using SpletString
    {
        stUserInfo UserInfo;

        vector<string> vUsersDataLine;

        vUsersDataLine = nsSplitString::SplitString(UserDataLine, Seperator);

        UserInfo.UserName = vUsersDataLine[0];
        UserInfo.Password = vUsersDataLine[1];
        UserInfo.Permissions = stoi(vUsersDataLine[2]);

        return UserInfo;
    }

}
