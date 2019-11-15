//CS 2024 -- A9
//Written by Oscar So (ons4)
//November 07, 2019

#include <iostream>
#include <vector>
#include "bankaccounth.h"
#include "bankh.h"
using namespace std;

void Bank::newAccount()
{
    //BankAccount account;
    BankAccount *account = new BankAccount;
    int number;
    string name;
    int balance;
    cout << "NEW ACCOUNT: " << endl;
    cout << "ENTER ACCOUNT NUMBER: ";
    cin >> number;
    cout << "ENTER ACCOUNT NAME: ";
    cin >> name;
    cout << "ENTER OPENING BALANCE: ";
    cin >> balance;
    account->setBalance(balance);
    account->setName(name);
    account->setNumber(number);
    mAccounts.insert(pair<int, BankAccount *>(number, account));
}

void Bank::listAccounts()
{
    cout << "ACCT# : NAME : BALANCE" << endl;
    map<int, BankAccount *>::iterator it = mAccounts.begin();
    // Iterate over the map using Iterator till end.
    for_each(mAccounts.begin(), mAccounts.end(),
             [](pair<int, BankAccount *> element) {
                 // Accessing KEY from element
                 int i = element.first;
                 // Accessing VALUE from element.
                 BankAccount *b = element.second;
                 cout << b->getNumber() << " : " << b->getName()
                      << " : " << b->getBalance() << endl;
             });
}

void Bank::selectAccount()
{
    cout << "Enter an Account Number to Select: ";
    int number;
    cin >> number;
    map<int, BankAccount *>::iterator it = mAccounts.begin();
    while (it != mAccounts.end())
    {
        if (it->first == number)
        {
            mCurrentAccount = it->second;
            break;
        }
        it++;
    }
}

void Bank::showActive()
{
    if (mCurrentAccount != nullptr)
    {
        cout << "Selected Account Number: " << mCurrentAccount->getNumber() << endl;
    }
    else
    {
        cout << "No Account Selected" << endl;
    }
}

void Bank::freeAccounts()
{
    map<int, BankAccount *>::iterator it = mAccounts.begin();
    for_each(mAccounts.begin(), mAccounts.end(),
             [](pair<int, BankAccount *> element) {
                 delete element.second;
             });
}