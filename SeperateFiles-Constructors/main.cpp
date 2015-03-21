#include <iostream>
#include <string>

//Including the monster header
#include "Monster.h"

using namespace std;



int main()
{
    //init object
    Monster monster1("Fred");

    //calling printName
    monster1.printName();

    return 0;
}
