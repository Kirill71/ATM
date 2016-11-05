//
// Created by Kirill Zharenkov on 04.11.2016.
//
#include "../Headers/ATM.h"
#include "../Headers/Transaction.h"
#include "../Headers/BalanceInquiry.h"
#include "../Headers/Withdrawal.h"
#include "../Headers/Deposit.h"

enum   MenuOption {BALANCE_INQUIRY = (unsigned)1, WITHDRAWAL, DEPOSIT, EXIT = (unsigned)4};

ATM::ATM() : userAuthenticated(false),
             currentAccountNumber(0) {

}

void ATM::run() {
    while (true) {
        while (!userAuthenticated) {
            screen.displayMessageLine("\nWelcome!");
            authenticateUser();
        }
        performTransactions();
        userAuthenticated = false;
        currentAccountNumber = 0;
        screen.displayMessageLine("\n Thank you! GoodBuy!/");
    }
}

void ATM::authenticateUser() {
    screen.displayMessage("\nPlease enter your account: ");
    unsigned accountNumber = keypad.getInput(); // ввести номер счета.
    screen.displayMessage("\n Enter your PIN: "); // Запросить PIN
    unsigned  pin = keypad.getInput(); // ввести PIN
    userAuthenticated = bankDatabase.authenticateUser(accountNumber,pin);

    if (userAuthenticated){
        currentAccountNumber = accountNumber;
    }
    else{
        screen.displayMessageLine("\n Invalid account nummber or PIN. Please try again");
    }
}

void ATM::performTransactions() {
    Transaction *currentTransactionPtr;
    bool userExisted(false);
    unsigned mainMenuSelection;
    while (!userExisted){
         mainMenuSelection = displayMainMenu();
        switch(mainMenuSelection){
            case MenuOption :: BALANCE_INQUIRY:
            case MenuOption :: WITHDRAWAL:
            case MenuOption ::DEPOSIT:
            {
             currentTransactionPtr =
                createTransaction(mainMenuSelection);
             currentTransactionPtr->execute();

              delete currentTransactionPtr;
                break;}
            case MenuOption::EXIT:
            {
                screen.displayMessageLine("\n Existing the system...");
                userExisted = true;
                break;}
            default:{
                screen.displayMessageLine("\n You did not enter a valid selection. Try again...");
                break;
            }
        }
    }
}

unsigned ATM::displayMainMenu() const {
    screen.displayMessageLine( "\nMain menu:" );
    screen.displayMessageLine( "1 - View my balance" );
    screen.displayMessageLine( "2 - Withdraw cash" );
    screen.displayMessageLine( "3 - Deposit funds" );
    screen.displayMessageLine( "4 - Exit\n" );
    return keypad.getInput();
}

Transaction* ATM::createTransaction(unsigned type) {
    Transaction* tempPtr(nullptr);
    switch (type) {
        case MenuOption ::BALANCE_INQUIRY:
        {
            tempPtr = new BalanceInquiry
                    (currentAccountNumber, screen, bankDatabase);
            break;
        }
        case  MenuOption::WITHDRAWAL:
        {
                    tempPtr = new Withdrawal
                            (currentAccountNumber, screen, bankDatabase, keypad, cashDispenser);
                    break;
        }
    }
    return tempPtr;
}