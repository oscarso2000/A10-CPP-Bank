//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019
#pragma once
#include <iostream>
using namespace std;


class BankAccount {
	public:
		BankAccount();
		BankAccount(int initialBalance);
		int getBalance();
		void setBalance(int newBalance);
		bool withdrawal(int amount);
		void deposit(int amount);
		void setName(string name);
		void setNumber(int number);
		string getName();
		int getNumber();
	private:
		int mBalance;
		string mName;
		int mNumber;
};
