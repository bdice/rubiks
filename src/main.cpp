#include <iostream>
#include <random>
#include "Rubiks.h"

using namespace std;

int main()
{
    auto cube = Rubiks();
    default_random_engine generator;
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

    for (auto it = move_history.rbegin(); it != move_history.rend(); it++)
    {
        cube.move(Rubiks::reverseMove(*it));
    }

    cout << "Unscrambled cube:" << endl;
    cube.printCube();
    cout << "Done." << endl;
}
