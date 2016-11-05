//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_ATM_H
#define ATM_ATM_H
#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "DepositSlot.h"
#include "BankDatabase.h"

class Transaction;

class ATM{
public:
    ATM();
    void run();

private:
    bool userAuthenticated;
    unsigned currentAccountNumber;
    Screen screen;
    Keypad keypad;
    CashDispenser cashDispenser;
    BankDatabase bankDatabase;

    void authenticateUser();
    void  performTransactions();
    unsigned  displayMainMenu() const;
    Transaction *createTransaction(unsigned);
};
#endif //ATM_ATM_H
