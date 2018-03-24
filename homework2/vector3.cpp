#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
#include "vector3.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

//****************************************************//
//  You need to implement the following functions !!  //
//****************************************************//

/* constructors */
// default constructor -- don't do anything with it
vector3::vector3()
{

}

// constructor with initializing float values
vector3::vector3(float inX, float inY, float inZ)
{
        set(inX, inY, inZ);
}

// constructor with initializing vector3
vector3::vector3(const vector3 &v)
{
        set(v.x, v.y, v.z);
}


/* Operators */

// access element
float &vector3::operator [] (unsigned int index)
{
        if ( index < 0 || index >= 3 ) {
                cerr << "\nError: index " << index
                     << " out of range" << endl;
                exit( 1 ); // terminate program; index out of range
        } // end if
        if(index == 0) return (*this).x;
        if(index == 1) return (*this).y;
        if(index == 2) return (*this).z;
}
const float &vector3::operator [] (unsigned int index) const
{
        if ( index < 0 || index >= 3 ) {
                cerr << "\nError: index " << index
                     << " out of range" << endl;
                exit( 1 ); // terminate program; index out of range
        } // end if
        if(index == 0) return (*this).x;
        if(index == 1) return (*this).y;
        if(index == 2) return (*this).z;
}

vector3 &vector3::operator =  (const vector3 &v)
{
        if((*this) != v) {
                set(v.x, v.y, v.z);
        }
        return (*this);
}
vector3 &vector3::operator += (const vector3 &v)
{
        float x2 = (*this).x + v.x;
        float y2 = (*this).y + v.y;
        float z2 = (*this).z + v.z;
        set(x2, y2, z2);
        return (*this);
}
vector3 &vector3::operator -= (const vector3 &v)
{
        float x2 = (*this).x - v.x;
        float y2 = (*this).y - v.y;
        float z2 = (*this).z - v.z;
        set(x2, y2, z2);
        return (*this);
}
vector3 &vector3::operator *= (float f)
{
        float x2 = (*this).x * f;
        float y2 = (*this).y * f;
        float z2 = (*this).z * f;
        set(x2, y2, z2);
        return (*this);
}
vector3 &vector3::operator /= (float f)
{
        float x2 = (*this).x / f;
        float y2 = (*this).y / f;
        float z2 = (*this).z / f;
        set(x2, y2, z2);
        return (*this);
}

/* Methods */

// set values (e.g. x = xIn, ...)
void vector3::set(float xIn, float yIn, float zIn)
{
        (*this).x = xIn;
        (*this).y = yIn;
        (*this).z = zIn;
}

// calculate length
float vector3::length() const
{
        return sqrt(pow((*this).x, 2) + pow((*this).y, 2) + pow((*this).z, 2));
}

// print matrix using std::cout
void vector3::printVector3() const
{
        cout << "(" << (*this).x << ", " << (*this).y << ", " << (*this).z << ")";
}

// friend functions

bool operator == (const vector3 &a, const vector3 &b)
{
        if ( a.x != b.x || a.y != b.y || a.z != b.z )
                return false;
        return true;
}
bool operator != (const vector3 &a, const vector3 &b)
{
        return !(a == b);
}
vector3 operator - (const vector3 &a)
{
        vector3 v;
        v.set(-(a.x), -(a.y), -(a.z));
        return v;
}
vector3 operator + (const vector3 &a, const vector3 &b)
{
        vector3 v;
        float x2 = a.x + b.x;
        float y2 = a.y + b.y;
        float z2 = a.z + b.z;
        v.set(x2, y2, z2);
        return v;
}
vector3 operator - (const vector3 &a, const vector3 &b)
{
        vector3 v;
        float x2 = a.x - b.x;
        float y2 = a.y - b.y;
        float z2 = a.z - b.z;
        v.set(x2, y2, z2);
        return v;
}
vector3 operator * (const vector3 &v, float f)
{
        vector3 v2;
        float x2 = v.x * f;
        float y2 = v.y * f;
        float z2 = v.z * f;
        v2.set(x2, y2, z2);
        return v2;
}
vector3 operator * (float f, const vector3 &v)
{
        vector3 v2;
        float x2 = f * v.x;
        float y2 = f * v.y;
        float z2 = f * v.z;
        v2.set(x2, y2, z2);
        return v2;
}
vector3 operator / (const vector3 &v, float f)
{
        vector3 v2;
        float x2 = v.x / f;
        float y2 = v.y / f;
        float z2 = v.z / f;
        v2.set(x2, y2, z2);
        return v2;
}
