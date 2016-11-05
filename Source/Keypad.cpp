//
// Created by Kirill Zharenkov on 04.11.2016.
//

#include <iostream>
#include "../Headers/Keypad.h"

unsigned Keypad::getInput() const {
    int input;
    std::cin>>input;
    return input;
}


