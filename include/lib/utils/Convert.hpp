#pragma once
#include <iostream>
#include <vector>
#include "../utils/SplitString.hpp"
#include "../../../data/model/Types.hpp"

using namespace std;

namespace nsConvert
{

    string ConvertDataFromeRecordToLine(stClientInfo ClientInfo, string Seperator = "-") // To Convert ClientData From Record (struct) To Line(String)
    {
        string ClientDataLine = "";

        ClientDataLine += ClientInfo.AccountNumber + Seperator;
        ClientDataLine += ClientInfo.PinCode + Seperator;
        ClientDataLine += ClientInfo.ClientName + Seperator;
        ClientDataLine += ClientInfo.Phone + Seperator;
        ClientDataLine += to_string(ClientInfo.Balance);

        return ClientDataLine;
    }

    stClientInfo ConvertDataFromeLineToRecord(string ClientDataLine, string Seperator = "-") // To Convert ClientData From Line(String) To Record (struct) Using SpletString
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

}
