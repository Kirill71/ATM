//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/BalanceInquiry.h"
#include "../Headers/Screen.h"
#include "../Headers/BankDatabase.h"


BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen & atmScreen, BankDatabase & atmBankDatabase):
Transaction(userAccountNumber,atmScreen, atmBankDatabase)
{

}

void BalanceInquiry::execute() {
    BankDatabase &bankDatabase = getBankDatabase();
    Screen & screen = getScreen();

    double availableBalance =
            bankDatabase.getAvailableBalance(getAccountNumber());
    double totalBalance =
            bankDatabase.getTotalBalance(getAccountNumber());
    screen.displayMessage("\nBalance Information:");
    screen.displayMessage(" -Available balance: ");
    screen.displayDollarAmount(availableBalance);
    screen.displayMessage("\n - Total balance: ");
    screen.displayDollarAmount(totalBalance);
    screen.displayMessageLine(" ");
}