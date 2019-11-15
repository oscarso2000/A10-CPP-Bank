//CS 2024 -- A9
//Written by Oscar So (ons4) 
//November 07, 2019

#include <iostream>

#include "MenuItem.h"
MenuItem::MenuItem(char commandChar, std::string title, bool (f)())
{
  mCommandCharacter = commandChar;
  mTitle = title;
  mBool = f;
}

MenuItem::MenuItem(char commandChar, std::string title, function<bool(Bank &bank)> *f)
{
  mCommandCharacter = commandChar;
  mTitle = title;
  mBool = f;
}
