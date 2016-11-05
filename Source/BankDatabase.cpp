//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/BankDatabase.h"

#include "../Headers/BankDatabase.h"

BankDatabase::BankDatabase() {
    Account account1(12345, 54321, 1000.0, 1200.0);
    Account account2(98765, 56789, 200.0, 200.0);
    accounts.push_back(account1);
    accounts.push_back(account2);
}

Account* BankDatabase::getAccount(int accountNumber){
    unsigned  n = accounts.size();
    for (unsigned i = 0; i < n; ++i) {
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    }
    return nullptr;
}


bool BankDatabase::authenticateUser(int userAccountNumber, int userPIN){
    Account* const userAccountPtr = getAccount(userAccountNumber);
    return  userAccountPtr != nullptr?userAccountPtr->validatePIN(userPIN):false;
}

double BankDatabase::getAvailableBalance(int userAccountNumber) {
    Account* const userAccountPtr = getAccount(userAccountNumber);
    return userAccountPtr->getAvailableBalance();
}

double BankDatabase::getTotalBalance(int userAccountNumber){
    Account* const userAccountPtr = getAccount(userAccountNumber);
    return userAccountPtr->getTotalBalance();
}

void BankDatabase::credit(int  userAccountNumber, double amount){
    Account* const userAccountPtr = getAccount(userAccountNumber);
    userAccountPtr->credit(amount);
}

void BankDatabase::debit(int userAccountNumber, double amount)
{
    Account* const userAccountPtr = getAccount(userAccountNumber);
    userAccountPtr->debit(amount);
}

