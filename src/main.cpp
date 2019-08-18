#include <chrono>
#include <iostream>
#include <random>
#include "Rubiks.h"

using namespace std;

int main()
{
    auto cube = Rubiks();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0, 11);

    vector<int> move_history;
    for (int i=0; i < 1000; i++)
    {
        int move = distribution(generator);
        move_history.push_back(move);
        cube.move(move);
    }

    cout << "Scrambled cube:" << endl;
    cube.printCube();
    cout << "Fraction correct: " << cube.fractionCorrect() << endl;

    for (auto it = move_history.rbegin(); it != move_history.rend(); it++)
    {
        cube.move(Rubiks::reverseMove(*it));
    }

    cout << "Unscrambled cube:" << endl;
    cube.printCube();
    cout << "Fraction correct: " << cube.fractionCorrect() << endl;
}
