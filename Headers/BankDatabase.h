//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_BANKDATABASE_H
#define ATM_BANKDATABASE_H
#include<vector>
#include "Account.h"

class BankDatabase {
public:
BankDatabase();
bool authenticateUser(int,int);
double getAvailableBalance(int);
double getTotalBalance(int);
void credit(int, double);
void debit(int, double);
private:
    std::vector<Account> accounts;
    Account* getAccount(int);
};
#endif //ATM_BANKDATABASE_H
