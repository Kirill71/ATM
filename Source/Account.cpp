//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/Account.h"

Account::Account(int theAccountNumber, int thePIN, double theAvailebleBalance, double theTotalBalance)
        : accountNumber(theAccountNumber),pin(thePIN),
        availableBalance(theAvailebleBalance), totalBalance(theTotalBalance)
{

}

bool Account::validatePIN(int userPIN) const{

    return (userPIN ==  pin)?true: false;
}


double Account::getAvailableBalance() const {
    return availableBalance;
}

double Account::getTotalBalance() const {
    return totalBalance;
}

void Account::credit(double amount) {
    totalBalance += amount;
}

void Account::debit(double amount){
    availableBalance -= amount;
    totalBalance -= amount;
}

int Account::getAccountNumber() const {
    return accountNumber;
}