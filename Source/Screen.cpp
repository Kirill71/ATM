//
// Created by Kirill Zharenkov on 04.11.2016.
//
#include <iostream>
#include <iomanip>
#include "../Headers/Screen.h"


void Screen::displayMessage(std::string message) const {
    std::cout << message;
}

void Screen::displayMessageLine(std::string message) const {
    displayMessage(message);
    std::cout<<std::endl;
}

void Screen::displayDollarAmount(double amount) const {
    std::cout << std::fixed << std::setprecision(2) << "$" << amount;
}

