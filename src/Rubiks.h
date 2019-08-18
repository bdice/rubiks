#include <vector>

using namespace std;

class Rubiks
{
    public:
        Rubiks();
        Rubiks(vector<vector<int>> faces);
        void printFaces();
        void printCube();
        void rotateFace(vector<int> &face, bool clockwise);
        void move(int type);
        double fractionCorrect();
        static int reverseMove(int type);

        vector<vector<int>> getFaces()
        {
            return m_faces;
        }
    private:
        vector<vector<int>> m_faces;
};
