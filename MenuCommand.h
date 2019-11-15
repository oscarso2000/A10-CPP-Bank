//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019

#ifndef _MENU_COMMAND_H_
#define _MENU_COMMAND_H_

#include <iostream>
#include "MenuItem.h"
using namespace std;

class MenuCommand : public MenuItem 
{
 public:
  // A MenuCommand takes a command character and title
  //MenuCommand(char commandChar,std::string title,bool(f)());
  MenuCommand(char commandChar,std::string title,function<bool()> f);

  // Declare the methods we must implement if we derive from MenuItem
  bool select();
  void display();
  function<bool()> menuCommand;
};


#endif
