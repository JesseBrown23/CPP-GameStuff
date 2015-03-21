#ifndef MONSTER_H
#define MONSTER_H
#include <string>

using namespace std;

//Constructor, ran when object init
class Monster
{
    public:
        Monster(string name);

        void printName();
    private:
        string _name;
};

#endif // MONSTER_H
