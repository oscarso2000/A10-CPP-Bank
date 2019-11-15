//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019

#include <iostream>
#include "bankaccounth.h"
using namespace std;

BankAccount::BankAccount(){
	mBalance = 0;
}
		
BankAccount::BankAccount(int initialBalance){
	mBalance = initialBalance;
}

int BankAccount::getBalance(){
	return mBalance;
}

void BankAccount::setBalance(int newBalance){
	mBalance = newBalance;
}

bool BankAccount::withdrawal(int amount){
	if (amount > 0 && mBalance >= amount){
		return true;
	}else{
		return false;
	}
}

void BankAccount::deposit(int amount){
	mBalance += amount;
}

void BankAccount::setName(string name){
	mName = name;
}

void BankAccount::setNumber(int number){
	mNumber = number;
}

string BankAccount::getName(){
	return mName;
}

int BankAccount::getNumber(){
	return mNumber;
}