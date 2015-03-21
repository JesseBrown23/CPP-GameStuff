#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    mt19937 randomGenerator(time(0));
    uniform_real_distribution<float> attackRoll(0.0f, 1.0f);

    cout << "I am attacking snake: " << attackRoll(randomGenerator) << endl;

    float attack = attackRoll(randomGenerator);

    if(attack <= 0.3f){
        cout << "Hit!" << endl;
    }else{
        cout << "Miss!" << endl;

    }


    return 0;
}
