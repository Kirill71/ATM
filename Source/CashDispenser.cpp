//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include "../Headers/CashDispenser.h"

CashDispenser::CashDispenser(): count(INITIAL_COUNT)
{

}


void CashDispenser::dispenseCash(int amount){
    int billsRequired = amount / 20;
    count -= billsRequired;
}

bool CashDispenser::isSufficientCashAvailable(int amount) const {
    int billsRequared = amount/20;
    return count >= billsRequared? true: false;
}