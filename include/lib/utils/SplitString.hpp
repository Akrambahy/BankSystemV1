#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace nsSplitString
{

    vector<string> SplitString(string S1, string Delim)
    {

        vector<string> vString;

        short Pos = 0;
        string SWord;

        while ((Pos = S1.find(Delim)) != std::string::npos)
        {

            SWord = S1.substr(0, Pos);

            if (SWord != "")
            {
                vString.push_back(SWord);
            }

            S1.erase(0, Pos + Delim.length());
        }
        if (S1 != "")
        {
            vString.push_back(S1);
        }

        return vString;
    };

}