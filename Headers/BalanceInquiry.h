//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_BALANCEINQUIRY_H
#define ATM_BALANCEINQUIRY_H

#include "Transaction.h"
class BalanceInquiry: public Transaction {
public:
    BalanceInquiry(int, Screen &, BankDatabase &);
    virtual void execute();
};


#endif //ATM_BALANCEINQUIRY_H
