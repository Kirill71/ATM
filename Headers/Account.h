//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H


class Account {
public:
    Account(int, int, double, double);
    bool validatePIN(int) const;
    double getAvailableBalance() const;
    double getTotalBalance() const;
    void credit(double);
    void debit(double);
    int getAccountNumber() const;
private:
    int accountNumber;
    int pin;
    double availableBalance;
    double totalBalance;
};


#endif //ATM_ACCOUNT_H
