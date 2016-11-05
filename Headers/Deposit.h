//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_DEPOSIT_H
#define ATM_DEPOSIT_H

#include "Transaction.h"

class Keypad;
class DepositSlot;

class Deposit : public Transaction
{
public:
    Deposit(int, Screen&, BankDatabase&, Keypad&, DepositSlot&);
    virtual void execute();
private:
    double amount;
    Keypad &keypad;
    DepositSlot & depositSlot;
    double promptForDepositAmount() const;
};

#endif //ATM_DEPOSIT_H
