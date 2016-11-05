//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/Transaction.h"
#include "../Headers/Screen.h"
#include "../Headers/BankDatabase.h"

Transaction::Transaction(int userAccountNumber, Screen & atmScreen, BankDatabase & atmBankDatabase):
accountNumber(userAccountNumber),
screen(atmScreen),
bankDatabase(atmBankDatabase)
{}

int Transaction::getAccountNumber() const {
    return accountNumber;
}

Screen& Transaction::getScreen() const {
    return screen;
}

BankDatabase& Transaction::getBankDatabase() const {
    return bankDatabase;
}