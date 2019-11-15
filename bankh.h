//CS 2024 -- A9
//Written by Oscar So (ons4)
//November 07, 2019

#pragma once
#include <iostream>
#include <map>
#include "bankaccounth.h"
using namespace std;

class Bank
{
public:
    //Bank();
    void newAccount();
    void listAccounts();
    void selectAccount();
    void showActive();
    BankAccount *getCurrentAccount()
    {
        return mCurrentAccount;
    }
    void freeAccounts();
private:
    map<int, BankAccount *> mAccounts;
    BankAccount *mCurrentAccount;
};