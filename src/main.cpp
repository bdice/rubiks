#include <iostream>
#include "Rubiks.h"

using namespace std;

int main()
{
    auto cube = Rubiks();
    cube.move(0);
    cube.printFaces();
    cout << "Done." << endl;
}
