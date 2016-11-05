//
// Created by Kirill Zharenkov on 04.11.2016.
//

#ifndef ATM_SCREEN_H
#define ATM_SCREEN_H

#include <string>

class Screen {

public:
    void displayMessage(std::string) const;
    void displayMessageLine( std::string) const;
    void displayDollarAmount( double) const;
};

#endif //ATM_SCREEN_H
