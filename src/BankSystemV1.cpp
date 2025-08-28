#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "../include/menue/MainMenue.cpp"

using namespace std;

string ClientsDataFile = "../data/ClientsData.txt";

int main()
{

    nsMainMenue::PerformMainManue(ClientsDataFile);
}
