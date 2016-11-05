//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/Withdrawal.h"
#include "../Headers/Screen.h"
#include "../Headers/BankDatabase.h"
#include "../Headers/Keypad.h"
#include "../Headers/CashDispenser.h"


const static int CANCELED = 6;


Withdrawal::Withdrawal(int userAccountNumber, Screen & atmScreen, BankDatabase & atmBankDatabase, Keypad & atmKeypad,
                       CashDispenser & atmCashDispenser): Transaction(userAccountNumber, atmScreen, atmBankDatabase),
                                                          keypad(atmKeypad), cashDispenser(atmCashDispenser)
{
}

void Withdrawal::execute() {
    bool cashDispensed(false);
    bool transactionCanceled(false);
    BankDatabase &bankDatabase = getBankDatabase();
    Screen &screen = getScreen();
    int selection;
    do {
        selection = displayMenuOfAmounts();
        if (selection != CANCELED) {
            amount = selection;
            double availableBalance =
                    bankDatabase.getAvailableBalance(getAccountNumber());
            if (amount <= availableBalance) {
                if (cashDispenser.isSufficientCashAvailable(amount)) {
                    bankDatabase.debit(getAccountNumber(), amount);
                    cashDispenser.dispenseCash(amount);
                    cashDispensed = true;
                    screen.displayMessageLine("\nPlease take your cash from the cash dispenser.");
                } else {
                    screen.displayMessageLine("\nInsufficient cash available in the ATM."
                                                      "\n\nPlease choose a smaller amount");
                }
            } else {
                screen.displayMessageLine("\n Insufficient funds in your account.\n\n Please choose a smaller amount");
            }
        } else {
            screen.displayMessageLine("\nCanceling transaction...");
            transactionCanceled = true;
        }

    } while (!cashDispensed && !transactionCanceled);
}

int Withdrawal::displayMenuOfAmounts() const {
    int userChoice = 0, input;
    Screen &screen = getScreen();
    int amounts[]{0,20, 40,60, 100,200};
    while( userChoice == 0){
        screen.displayMessageLine("\n Withdrawal options:" );
        screen.displayMessageLine(" 1 - $20" );
        screen.displayMessageLine(" 2 - $40" );
        screen.displayMessageLine(" 3 - $60" );
        screen.displayMessageLine(" 4 - $100" );
        screen.displayMessageLine(" 5 - $200" );
        screen.displayMessageLine("6 - Cancel transaction");
        screen.displayMessage("\n Choose a withdrawal option (1-6):");

       input = keypad.getInput();
        switch(input){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:{
                userChoice = amounts[input];
                break;
            }
            case CANCELED:{
                userChoice = CANCELED;
                break;
            }
            default:
                screen.displayMessageLine("\n Invalid selection. Try again.");
        }
    }
}