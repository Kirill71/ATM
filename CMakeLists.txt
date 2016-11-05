cmake_minimum_required(VERSION 3.6)
project(ATM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Headers/ATM.h Source/ATM.cpp Source/Screen.cpp Headers/Screen.h Source/Keypad.cpp Headers/Keypad.h Source/CashDispenser.cpp Headers/CashDispenser.h Source/DepositSlot.cpp Headers/DepositSlot.h Source/Account.cpp Headers/Account.h Source/BankDatabase.cpp Headers/BankDatabase.h Source/Transaction.cpp Headers/Transaction.h Source/BalanceInquiry.cpp Headers/BalanceInquiry.h Source/Withdrawal.cpp Headers/Withdrawal.h Source/Deposit.cpp Headers/Deposit.h)
add_executable(ATM ${SOURCE_FILES})