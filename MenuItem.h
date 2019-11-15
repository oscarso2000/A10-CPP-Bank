//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019

#pragma once
#ifndef _MENUITEM_H_
#define _MENUITEM_H_

#include <iostream>
#include "bankh.h"
using namespace std;

class MenuItem
{
public:
  // We define the constructor here because it's simple
  // and it saves us from needing a MenuItem.cpp file
  MenuItem(char commandChar, std::string title)
  {
    mCommandCharacter = commandChar;
    mTitle = title;
  }

  // Pure virtual functions that define the "interface"
  // for a MenuItem
  virtual bool select() = 0;
  virtual void display() = 0;

  // We'll need to have a getter to retrieve the command char
  char getCommandChar() { return mCommandCharacter; }

  string getTitle() { return mTitle; }

protected:
  char mCommandCharacter;
  std::string mTitle;
};

#endif
