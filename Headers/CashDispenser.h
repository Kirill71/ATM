//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_CASHDISPENSER_H
#define ATM_CASHDISPENSER_H


class CashDispenser {
public:
    CashDispenser();
    void dispenseCash(int);
    bool isSufficientCashAvailable(int) const;
private:
    const static int INITIAL_COUNT = 500;
    int count;
};
#endif //ATM_CASHDISPENSER_H
