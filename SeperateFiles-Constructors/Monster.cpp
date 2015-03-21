#include "Monster.h"
#include <iostream>
#include <string>

//Function for name
Monster::Monster(string name)
{
    _name = name;
}


//function for printing name
void Monster::printName(){
    cout << _name << endl;
}
