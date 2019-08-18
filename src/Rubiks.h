#include <vector>

using namespace std;

class Rubiks
{
    public:
        Rubiks();
        void printFaces();
        void printCube();
        void rotateFace(vector<int> &face, bool clockwise);
        void move(int type);
        double fractionCorrect();
        static int reverseMove(int type);

    private:
        vector<vector<int>> m_faces;
};
