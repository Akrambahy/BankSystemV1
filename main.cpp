#include <iostream>

#include "src/BankSystemV1.cpp"

using namespace std;

string ClientsFileName = "data/ClientsData.txt";
string UsersFileName = "data/UsersData.txt";

int main()
{

    nsBankSystem::BankSystem(ClientsFileName, UsersFileName);
}