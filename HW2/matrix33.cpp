#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include "matrix33.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::exit;

//****************************************************//
//  You need to implement the following functions !!  //
//****************************************************//

/* constructors */
// default constructor
matrix33::matrix33()
{
        vector3 init(0,0,0);
        (*this)[0] = init;
        (*this)[1] = init;
        (*this)[2] = init;
}

// constructor with initializing float values
matrix33::matrix33(const vector3 &v2_0, const vector3 &v2_1, const vector3 &v2_2)
{
        set(v2_0, v2_1, v2_2);
}

// constructor with initializing matrix33
matrix33::matrix33(const matrix33 &m2)
{
        set(m2.v0, m2.v1, m2.v2);
}


/* Operators */

// access element
vector3 &matrix33::operator [] (unsigned int index)
{
        if ( index < 0 || index >= 3 ) {
                cerr << "\nError: index " << index
                     << " out of range" << endl;
                exit( 1 ); // terminate program; index out of range
        } // end if
        if(index == 0) return (*this).v0;
        if(index == 1) return (*this).v1;
        if(index == 2) return (*this).v2;
}
const vector3 &matrix33::operator [] (unsigned int index) const
{
        if ( index < 0 || index >= 3 ) {
                cerr << "\nError: index " << index
                     << " out of range" << endl;
                exit( 1 ); // terminate program; index out of range
        } // end if
        if(index == 0) return (*this).v0;
        if(index == 1) return (*this).v1;
        if(index == 2) return (*this).v2;
}

matrix33 &matrix33::operator =  (const matrix33 &m2)
{
        if((*this) != m2) {
                (*this) = m2;
        }
        return (*this);
}
matrix33 &matrix33::operator += (const matrix33 &m2)
{
        (*this)[0] += m2[0];
        (*this)[1] += m2[1];
        (*this)[2] += m2[2];
        return (*this);
}
matrix33 &matrix33::operator -= (const matrix33 &m2)
{
        (*this)[0] -= m2[0];
        (*this)[1] -= m2[1];
        (*this)[2] -= m2[2];
        return (*this);
}
matrix33 &matrix33::operator *= (const matrix33 &m2)
{
        matrix33 m3;

        m3[0][0] = ((*this)[0][0] * m2[0][0] + (*this)[1][0] * m2[0][1] + (*this)[2][0] * m2[0][2]);
        m3[1][0] = ((*this)[0][0] * m2[1][0] + (*this)[1][0] * m2[1][1] + (*this)[2][0] * m2[1][2]);
        m3[2][0] = ((*this)[0][0] * m2[2][0] + (*this)[1][0] * m2[2][1] + (*this)[2][0] * m2[2][2]);

        m3[0][1] = ((*this)[0][1] * m2[0][0] + (*this)[1][1] * m2[0][1] + (*this)[2][1] * m2[0][2]);
        m3[1][1] = ((*this)[0][1] * m2[1][0] + (*this)[1][1] * m2[1][1] + (*this)[2][1] * m2[1][2]);
        m3[2][1] = ((*this)[0][1] * m2[2][0] + (*this)[1][1] * m2[2][1] + (*this)[2][1] * m2[2][2]);

        m3[0][2] = ((*this)[0][2] * m2[0][0] + (*this)[1][2] * m2[0][1] + (*this)[2][2] * m2[0][2]);
        m3[1][2] = ((*this)[0][2] * m2[1][0] + (*this)[1][2] * m2[1][1] + (*this)[2][2] * m2[1][2]);
        m3[2][2] = ((*this)[0][2] * m2[2][0] + (*this)[1][2] * m2[2][1] + (*this)[2][2] * m2[2][2]);

        (*this) = m3;

        return (*this);
}
matrix33 &matrix33::operator *= (float f)
{
        vector3 v0 = (*this)[0] * f;
        vector3 v1 = (*this)[1] * f;
        vector3 v2 = (*this)[2] * f;
        set(v0, v1, v2);
        return (*this);
}

/* Methods */

// set values (e.g. x = xIn, ...)
void matrix33::set(const vector3 &v2_0, const vector3 &v2_1, const vector3 &v2_2)
{
        (*this)[0] = v2_0;
        (*this)[1] = v2_1;
        (*this)[2] = v2_2;
}

// print matrix using std::cout
void matrix33::printMatrix() const
{
        cout << (*this)[0][0] << " " << (*this)[1][0] << " " << (*this)[2][0] << endl;
        cout << (*this)[0][1] << " " << (*this)[1][1] << " " << (*this)[2][1] << endl;
        cout << (*this)[0][2] << " " << (*this)[1][2] << " " << (*this)[2][2] << endl;
}

matrix33 matrix33::transpose()
{
        matrix33 m2;
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                        m2[i][j] = (*this)[j][i];
                }
        }
        return m2;
}

matrix33 matrix33::adjugate()
{
        matrix33 m2;

        m2[0][0] =  ((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]);
        m2[1][0] = -((*this)[0][1] * (*this)[2][2] - (*this)[2][1] * (*this)[0][2]);
        m2[2][0] =  ((*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2]);

        m2[0][1] = -((*this)[1][0] * (*this)[2][2] - (*this)[2][0] * (*this)[1][2]);
        m2[1][1] =  ((*this)[0][0] * (*this)[2][2] - (*this)[2][0] * (*this)[0][2]);
        m2[2][1] = -((*this)[0][0] * (*this)[1][2] - (*this)[1][0] * (*this)[0][2]);

        m2[0][2] =  ((*this)[1][0] * (*this)[2][1] - (*this)[2][0] * (*this)[1][1]);
        m2[1][2] = -((*this)[0][0] * (*this)[2][1] - (*this)[2][0] * (*this)[0][1]);
        m2[2][2] =  ((*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1]);

        return m2.transpose();
}

matrix33 matrix33::invert()
{
        if((*this).determinant() != 0)
        {
                matrix33 m2 = (*this).adjugate();
                m2 *= 1/(*this).determinant();
                return m2;
        } else {
                cout << "Warning: det = 0" << endl;
        }
}

void matrix33::identity()
{
        vector3 v2_0(1, 0, 0);
        vector3 v2_1(0, 1, 0);
        vector3 v2_2(0, 0, 1);
        set(v2_0, v2_1, v2_2);
}

float matrix33::determinant() const
{
        float det = 0;
        float a = ((*this)[0][0]) * ((*this)[1][1] * (*this)[2][2] - (*this)[2][1] * (*this)[1][2]);
        float b = ((*this)[1][0]) * ((*this)[0][1] * (*this)[2][2] - (*this)[2][1] * (*this)[0][2]);
        float c = ((*this)[2][0]) * ((*this)[0][1] * (*this)[1][2] - (*this)[1][1] * (*this)[0][2]);
        det = a - b + c;
        return det;
}

// friend functions

bool operator == (const matrix33 &a, const matrix33 &b)
{
        if ( a.v0 != b.v0 || a.v1 != b.v1 || a.v2 != b.v2 )
                return false;
        return true;
}
bool operator != (const matrix33 &a, const matrix33 &b)
{
        return !(a == b);
}
matrix33 operator - (const matrix33 &a)
{
        matrix33 m;
        m.set(-(a.v0), -(a.v1), -(a.v2));
        return m;
}
matrix33 operator + (const matrix33 &a, const matrix33 &b)
{
        matrix33 m;
        vector3 v2_0 = a.v0 + b.v0;
        vector3 v2_1 = a.v1 + b.v1;
        vector3 v2_2 = a.v2 + b.v2;
        m.set(v2_0, v2_1, v2_2);
        return m;
}
matrix33 operator - (const matrix33 &a, const matrix33 &b)
{
        matrix33 m;
        vector3 v2_0 = a.v0 - b.v0;
        vector3 v2_1 = a.v1 - b.v1;
        vector3 v2_2 = a.v2 - b.v2;
        m.set(v2_0, v2_1, v2_2);
        return m;
}
matrix33 operator * (const matrix33 &m1, const matrix33 &m2)
{
        matrix33 m3;

        m3[0][0] = (m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2]);
        m3[1][0] = (m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2]);
        m3[2][0] = (m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2]);

        m3[0][1] = (m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2]);
        m3[1][1] = (m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2]);
        m3[2][1] = (m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2]);

        m3[0][2] = (m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2]);
        m3[1][2] = (m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2]);
        m3[2][2] = (m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2]);

        return m3;
}
matrix33 operator * (const matrix33 &m, float f)
{
        matrix33 m2;
        vector3 v2_0 = m[0] * f;
        vector3 v2_1 = m[1] * f;
        vector3 v2_2 = m[2] * f;
        m2.set(v2_0, v2_1, v2_2);
        return m2;
}
matrix33 operator * (float f, const matrix33 &m)
{
        matrix33 m2;
        vector3 v2_0 = f * m[0];
        vector3 v2_1 = f * m[1];
        vector3 v2_2 = f * m[2];
        m2.set(v2_0, v2_1, v2_2);
        return m2;
}
matrix33 operator / (const matrix33 &m, float f)
{
        matrix33 m2;
        vector3 v2_0 = m[0] / f;
        vector3 v2_1 = m[1] / f;
        vector3 v2_2 = m[2] / f;
        m2.set(v2_0, v2_1, v2_2);
        return m2;
}
