#include <iostream>
#include <stdexcept>
#include <vector>
#include "Rubiks.h"

using namespace std;

/* Face layout:
 *      [   ]
 *      [ 0 ]
 *      [   ]
 * [   ][   ][   ][   ]
 * [ 4 ][ 1 ][ 2 ][ 3 ]
 * [   ][   ][   ][   ]
 *      [   ]
 *      [ 5 ]
 *      [   ]
 *
 *  0: Top (z+)
 *  1: Front (x+)
 *  2: Right (y+)
 *  3: Back (x-)
 *  4: Left (y-)
 *  5: Bottom (z-)
 *
 * Face indexing:
 *      [012]
 *      [345]
 *      [678]
 * [012][012][012][012]
 * [345][345][345][345]
 * [678][678][678][678]
 *      [012]
 *      [345]
 *      [678]
 *
 */

Rubiks::Rubiks() : m_faces()
{
    for (int face_index = 0; face_index < 6; face_index++)
        {
        vector<int> face_colors;
        for (int square = 0; square < 9; square++)
        {
            face_colors.push_back(face_index);
        }
        m_faces.push_back(face_colors);
        }
}

Rubiks::Rubiks(vector<vector<int>> faces) : m_faces(faces)
{
}

void Rubiks::printFaces()
{
    for (int face_index = 0; face_index < m_faces.size(); face_index++)
    {
        if (face_index == 0)
            cout << "Top (z+)" << endl;
        else if (face_index == 1)
            cout << "Front (x+)" << endl;
        else if (face_index == 2)
            cout << "Right (y+)" << endl;
        else if (face_index == 3)
            cout << "Back (x-)" << endl;
        else if (face_index == 4)
            cout << "Left (y-)" << endl;
        else if (face_index == 5)
            cout << "Bottom (z-)" << endl;
        auto face = m_faces[face_index];
        cout << "[" << face[0] << face[1] << face[2] << "]" << endl;
        cout << "[" << face[3] << face[4] << face[5] << "]" << endl;
        cout << "[" << face[6] << face[7] << face[8] << "]\n" << endl;
    }
}

void Rubiks::printCube()
{
    cout << "     [";
    cout << m_faces[0][0] << m_faces[0][1] << m_faces[0][2];
    cout << "]\n";
    cout << "     [";
    cout << m_faces[0][3] << m_faces[0][4] << m_faces[0][5];
    cout << "]\n";
    cout << "     [";
    cout << m_faces[0][6] << m_faces[0][7] << m_faces[0][8];
    cout << "]\n";

    cout << "[";
    cout << m_faces[4][0] << m_faces[4][1] << m_faces[4][2];
    cout << "][";
    cout << m_faces[1][0] << m_faces[1][1] << m_faces[1][2];
    cout << "][";
    cout << m_faces[2][0] << m_faces[2][1] << m_faces[2][2];
    cout << "][";
    cout << m_faces[3][0] << m_faces[3][1] << m_faces[3][2];
    cout << "]\n";
    cout << "[";
    cout << m_faces[4][3] << m_faces[4][4] << m_faces[4][5];
    cout << "][";
    cout << m_faces[1][3] << m_faces[1][4] << m_faces[1][5];
    cout << "][";
    cout << m_faces[2][3] << m_faces[2][4] << m_faces[2][5];
    cout << "][";
    cout << m_faces[3][3] << m_faces[3][4] << m_faces[3][5];
    cout << "]\n";
    cout << "[";
    cout << m_faces[4][6] << m_faces[4][7] << m_faces[4][8];
    cout << "][";
    cout << m_faces[1][6] << m_faces[1][7] << m_faces[1][8];
    cout << "][";
    cout << m_faces[2][6] << m_faces[2][7] << m_faces[2][8];
    cout << "][";
    cout << m_faces[3][6] << m_faces[3][7] << m_faces[3][8];
    cout << "]\n";

    cout << "     [";
    cout << m_faces[5][0] << m_faces[5][1] << m_faces[5][2];
    cout << "]\n";
    cout << "     [";
    cout << m_faces[5][3] << m_faces[5][4] << m_faces[5][5];
    cout << "]\n";
    cout << "     [";
    cout << m_faces[5][6] << m_faces[5][7] << m_faces[5][8];
    cout << "]\n" << endl;
}

void Rubiks::rotateFace(vector<int> &face, bool clockwise)
{
    auto old_face = face;
    if (clockwise)
    {
        face[0] = old_face[6];
        face[1] = old_face[3];
        face[2] = old_face[0];
        face[3] = old_face[7];
        face[4] = old_face[4];
        face[5] = old_face[1];
        face[6] = old_face[8];
        face[7] = old_face[5];
        face[8] = old_face[2];
    }
    else
    {
        face[0] = old_face[2];
        face[1] = old_face[5];
        face[2] = old_face[8];
        face[3] = old_face[1];
        face[4] = old_face[4];
        face[5] = old_face[7];
        face[6] = old_face[0];
        face[7] = old_face[3];
        face[8] = old_face[6];
    }
}

void Rubiks::move(int type)
{
    auto old_faces = m_faces;
    if (type == 0)
    {
        // Move top face clockwise
        rotateFace(m_faces[0], true);
        m_faces[1][0] = old_faces[4][0];
        m_faces[1][1] = old_faces[4][1];
        m_faces[1][2] = old_faces[4][2];
        m_faces[2][0] = old_faces[1][0];
        m_faces[2][1] = old_faces[1][1];
        m_faces[2][2] = old_faces[1][2];
        m_faces[3][0] = old_faces[2][0];
        m_faces[3][1] = old_faces[2][1];
        m_faces[3][2] = old_faces[2][2];
        m_faces[4][0] = old_faces[3][0];
        m_faces[4][1] = old_faces[3][1];
        m_faces[4][2] = old_faces[3][2];
    }
    else if (type == 1)
    {
        // Move top face counterclockwise
        rotateFace(m_faces[0], false);
        m_faces[1][0] = old_faces[2][0];
        m_faces[1][1] = old_faces[2][1];
        m_faces[1][2] = old_faces[2][2];
        m_faces[2][0] = old_faces[3][0];
        m_faces[2][1] = old_faces[3][1];
        m_faces[2][2] = old_faces[3][2];
        m_faces[3][0] = old_faces[4][0];
        m_faces[3][1] = old_faces[4][1];
        m_faces[3][2] = old_faces[4][2];
        m_faces[4][0] = old_faces[1][0];
        m_faces[4][1] = old_faces[1][1];
        m_faces[4][2] = old_faces[1][2];
    }
    else if (type == 2)
    {
        // Move front face clockwise
        rotateFace(m_faces[1], true);
        m_faces[0][6] = old_faces[4][8];
        m_faces[0][7] = old_faces[4][5];
        m_faces[0][8] = old_faces[4][2];
        m_faces[2][0] = old_faces[0][6];
        m_faces[2][3] = old_faces[0][7];
        m_faces[2][6] = old_faces[0][8];
        m_faces[5][0] = old_faces[2][6];
        m_faces[5][1] = old_faces[2][3];
        m_faces[5][2] = old_faces[2][0];
        m_faces[4][2] = old_faces[5][0];
        m_faces[4][5] = old_faces[5][1];
        m_faces[4][8] = old_faces[5][2];
    }
    else if (type == 3)
    {
        // Move front face counterclockwise
        rotateFace(m_faces[1], false);
        m_faces[4][8] = old_faces[0][6];
        m_faces[4][5] = old_faces[0][7];
        m_faces[4][2] = old_faces[0][8];
        m_faces[0][6] = old_faces[2][0];
        m_faces[0][7] = old_faces[2][3];
        m_faces[0][8] = old_faces[2][6];
        m_faces[2][6] = old_faces[5][0];
        m_faces[2][3] = old_faces[5][1];
        m_faces[2][0] = old_faces[5][2];
        m_faces[5][0] = old_faces[4][2];
        m_faces[5][1] = old_faces[4][5];
        m_faces[5][2] = old_faces[4][8];
    }
    else if (type == 4)
    {
        // Move right face clockwise
        rotateFace(m_faces[2], true);
        m_faces[0][2] = old_faces[1][2];
        m_faces[0][5] = old_faces[1][5];
        m_faces[0][8] = old_faces[1][8];
        m_faces[1][2] = old_faces[5][2];
        m_faces[1][5] = old_faces[5][5];
        m_faces[1][8] = old_faces[5][8];
        m_faces[3][0] = old_faces[0][8];
        m_faces[3][3] = old_faces[0][5];
        m_faces[3][6] = old_faces[0][2];
        m_faces[5][2] = old_faces[3][6];
        m_faces[5][5] = old_faces[3][3];
        m_faces[5][8] = old_faces[3][0];
    }
    else if (type == 5)
    {
        // Move right face counterclockwise
        rotateFace(m_faces[2], false);
        m_faces[1][2] = old_faces[0][2];
        m_faces[1][5] = old_faces[0][5];
        m_faces[1][8] = old_faces[0][8];
        m_faces[5][2] = old_faces[1][2];
        m_faces[5][5] = old_faces[1][5];
        m_faces[5][8] = old_faces[1][8];
        m_faces[0][8] = old_faces[3][0];
        m_faces[0][5] = old_faces[3][3];
        m_faces[0][2] = old_faces[3][6];
        m_faces[3][6] = old_faces[5][2];
        m_faces[3][3] = old_faces[5][5];
        m_faces[3][0] = old_faces[5][8];
    }
    else if (type == 6)
    {
        // Move back face clockwise
        rotateFace(m_faces[3], true);
        m_faces[0][0] = old_faces[2][2];
        m_faces[0][1] = old_faces[2][5];
        m_faces[0][2] = old_faces[2][8];
        m_faces[2][2] = old_faces[5][8];
        m_faces[2][5] = old_faces[5][7];
        m_faces[2][8] = old_faces[5][6];
        m_faces[5][6] = old_faces[4][0];
        m_faces[5][7] = old_faces[4][3];
        m_faces[5][8] = old_faces[4][6];
        m_faces[4][0] = old_faces[0][2];
        m_faces[4][3] = old_faces[0][1];
        m_faces[4][6] = old_faces[0][0];
    }
    else if (type == 7)
    {
        // Move back face counterclockwise
        rotateFace(m_faces[3], false);
        m_faces[2][2] = old_faces[0][0];
        m_faces[2][5] = old_faces[0][1];
        m_faces[2][8] = old_faces[0][2];
        m_faces[5][8] = old_faces[2][2];
        m_faces[5][7] = old_faces[2][5];
        m_faces[5][6] = old_faces[2][8];
        m_faces[4][0] = old_faces[5][6];
        m_faces[4][3] = old_faces[5][7];
        m_faces[4][6] = old_faces[5][8];
        m_faces[0][2] = old_faces[4][0];
        m_faces[0][1] = old_faces[4][3];
        m_faces[0][0] = old_faces[4][6];
    }
    else if (type == 8)
    {
        // Move left face clockwise
        rotateFace(m_faces[4], true);
        m_faces[0][0] = old_faces[3][8];
        m_faces[0][3] = old_faces[3][5];
        m_faces[0][6] = old_faces[3][2];
        m_faces[1][0] = old_faces[0][0];
        m_faces[1][3] = old_faces[0][3];
        m_faces[1][6] = old_faces[0][6];
        m_faces[5][0] = old_faces[1][0];
        m_faces[5][3] = old_faces[1][3];
        m_faces[5][6] = old_faces[1][6];
        m_faces[3][2] = old_faces[5][6];
        m_faces[3][5] = old_faces[5][3];
        m_faces[3][8] = old_faces[5][0];
    }
    else if (type == 9)
    {
        // Move left face counterclockwise
        rotateFace(m_faces[4], false);
        m_faces[3][8] = old_faces[0][0];
        m_faces[3][5] = old_faces[0][3];
        m_faces[3][2] = old_faces[0][6];
        m_faces[0][0] = old_faces[1][0];
        m_faces[0][3] = old_faces[1][3];
        m_faces[0][6] = old_faces[1][6];
        m_faces[1][0] = old_faces[5][0];
        m_faces[1][3] = old_faces[5][3];
        m_faces[1][6] = old_faces[5][6];
        m_faces[5][6] = old_faces[3][2];
        m_faces[5][3] = old_faces[3][5];
        m_faces[5][0] = old_faces[3][8];
    }
    else if (type == 10)
    {
        // Move bottom face clockwise
        rotateFace(m_faces[5], true);
        m_faces[1][6] = old_faces[4][6];
        m_faces[1][7] = old_faces[4][7];
        m_faces[1][8] = old_faces[4][8];
        m_faces[2][6] = old_faces[1][6];
        m_faces[2][7] = old_faces[1][7];
        m_faces[2][8] = old_faces[1][8];
        m_faces[3][6] = old_faces[2][6];
        m_faces[3][7] = old_faces[2][7];
        m_faces[3][8] = old_faces[2][8];
        m_faces[4][6] = old_faces[3][6];
        m_faces[4][7] = old_faces[3][7];
        m_faces[4][8] = old_faces[3][8];
    }
    else if (type == 11)
    {
        // Move bottom face counterclockwise
        rotateFace(m_faces[5], false);
        m_faces[1][6] = old_faces[2][6];
        m_faces[1][7] = old_faces[2][7];
        m_faces[1][8] = old_faces[2][8];
        m_faces[2][6] = old_faces[3][6];
        m_faces[2][7] = old_faces[3][7];
        m_faces[2][8] = old_faces[3][8];
        m_faces[3][6] = old_faces[4][6];
        m_faces[3][7] = old_faces[4][7];
        m_faces[3][8] = old_faces[4][8];
        m_faces[4][6] = old_faces[1][6];
        m_faces[4][7] = old_faces[1][7];
        m_faces[4][8] = old_faces[1][8];
    }
    else
    {
        throw std::out_of_range("Invalid move number.");
    }
}

double Rubiks::fractionCorrect()
{
    double correct = 0;
    double total = 0;
    for (int face_index = 0; face_index < m_faces.size(); face_index++)
    {
        for (auto square : m_faces[face_index])
        {
            if (square == face_index)
                correct++;
            total++;
        }
    }
    return correct/total;
}

int Rubiks::reverseMove(int type)
{
    bool clockwise = (type % 2 == 0);
    if (clockwise)
        return type + 1;
    else
        return type - 1;
}
