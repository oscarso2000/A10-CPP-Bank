//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019

#include <iostream>

#include "MenuItem.h"
#include "Menu.h"
#include "MenuCommand.h"
#include "bankh.h"
using namespace std;


//
// Our main() is pretty simple for this assignment.   Just set up the menus and call
// select() on the top level menu
void withdrawal(BankAccount* b){
	cout<< "\nWithdrawal" <<endl;
	cout << "HOW MUCH DO YOU WANT TO WITHDRAWAL> ";
	int take;
	cin >> take;
	if (b -> withdrawal(take) == true){
		b -> deposit((-1)*(take));
		cout << "Withdrawal successful" << endl;
	}else{
		cout << "Withdrawal failed" << endl;
	}
}

void deposit(BankAccount* b){
	cout << "\nDeposit" << endl;
	cout << "HOW MUCH DO YOU WANT TO DEPOSIT> ";
	int dep; 
	cin >> dep;
	b -> deposit(dep);
}

int main(int argc, char *argv[])
{
  Bank bank;
  // Setup the submenu first
  MenuItem *accountMenuItems[] = {
      new MenuCommand('1', "Balance Inquiry", [&bank]() -> bool {cout << "Balance is " << bank.getCurrentAccount() -> getBalance() << endl; return true; }),
      new MenuCommand('2', "Deposit", [&bank]() -> bool {deposit(bank.getCurrentAccount()); return true; }),
      new MenuCommand('3', "Withdrawal", [&bank]() -> bool {withdrawal(bank.getCurrentAccount()); return true; }),
      new MenuCommand('b', "Back", []() -> bool { return false; })};

  Menu accountMenu(accountMenuItems, 4, '5', "Account");

  // Then set up the main menu
  MenuItem *mainMenuItems[] = {
      new MenuCommand('1', "List Accounts", [&bank]()->bool{bank.listAccounts();return true;}),
      new MenuCommand('2', "New Account", [&bank]() -> bool{bank.newAccount();return true;}),
      new MenuCommand('3', "Select Account", [&bank]() -> bool {bank.selectAccount(); return true; }),
      new MenuCommand('4', "Show Active Account", [&bank]() -> bool {bank.showActive(); return true; }),
      &accountMenu,
      new MenuCommand('b', "Quit", [&bank]() -> bool { bank.freeAccounts(); return false; })};

  Menu mainMenu(mainMenuItems, 6, '0', "Main");

  // Kick off the whole process by just calling select() on the top level menu
  bool keepGoing = mainMenu.select();


  std::cout << "Done" << std::endl;
}
