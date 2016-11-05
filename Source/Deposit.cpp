//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/Deposit.h"

#include "../Headers/Screen.h"
#include "../Headers/BankDatabase.h"
#include "../Headers/Keypad.h"
#include "../Headers/DepositSlot.h"

const static int CANCELED = 0;

Deposit::Deposit(int userAccountNumber, Screen & atmScreen, BankDatabase & atmBankDatabase, Keypad & atmKeypad, DepositSlot & atmDepositSlot):
Transaction(userAccountNumber, atmScreen, atmBankDatabase), keypad(atmKeypad), depositSlot(atmDepositSlot)
{}

void Deposit::execute() {
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();
    amount = promptForDepositAmount();

    if (amount != CANCELED){
        screen.displayMessage("\n Please insert a deposit envelope containing");
        screen.displayDollarAmount(amount);
        screen.displayMessageLine("in the deposit slot");
        bool envelopeReceived = depositSlot.isEnvelopeReceived();
        if ( envelopeReceived){
            screen.displayMessageLine("\n Your envelope has been received.\nNOTE: The money just will not be available"
                                              "until we\nverify the amount of any enclosed cash, and any enclosed check clear.");
            bankDatabase.credit(getAccountNumber(), amount);
        }
        else
        {
            screen.displayMessageLine("\n You did not insert an "
                                              "envelope, so the ATM has canceled your transaction.");
        }
    }
    else {
        screen.displayMessageLine("\n Canceling transaction...");
    }
}


double Deposit::promptForDepositAmount() const {
    Screen &screen = getScreen();

    screen.displayMessage("\nPlease enter a deposit amount in"
                                  "CENTS (or 0 to cancel) : ");
    int input = keypad.getInput();

    return (input == CANCELED)?CANCELED: static_cast<double>(input)/100;
}
