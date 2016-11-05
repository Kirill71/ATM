//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_WITHDRAWAL_H
#define ATM_WITHDRAWAL_H

#include "Transaction.h"
class Keypad;
class CashDispenser;

class Withdrawal: public Transaction {

public:
    Withdrawal(int, Screen&, BankDatabase&, Keypad&, CashDispenser&);
    virtual void execute();

private:
    int amount;
    Keypad &keypad;
    CashDispenser &cashDispenser;
    int displayMenuOfAmounts() const ;
};


#endif //ATM_WITHDRAWAL_H
