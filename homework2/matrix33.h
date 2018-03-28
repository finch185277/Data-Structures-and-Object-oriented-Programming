#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33
{
private:
vector3 v0;
vector3 v1;
vector3 v2;

public:
/* constructors */
// default constructor -- don't do anything with it
matrix33();

// constructor with initializing float values
matrix33(const vector3 &v0, const vector3 &v1, const vector3 &v2);

// constructor with initializing matrix33
matrix33(const matrix33 &m);

public:
/* Operators */

// access element
vector3                 &operator [] (unsigned int index);
const vector3           &operator [] (unsigned int index) const;

matrix33               &operator =  (const matrix33 &v);
matrix33               &operator += (const matrix33 &v);
matrix33               &operator -= (const matrix33 &v);
matrix33               &operator *= (const matrix33 &v);
matrix33               &operator *= (float f);
matrix33               &operator /= (float f);
friend bool operator == (const matrix33 &a, const matrix33 &b);
friend bool operator != (const matrix33 &a, const matrix33 &b);
friend matrix33 operator - (const matrix33 &a);
friend matrix33 operator + (const matrix33 &a, const matrix33 &b);
friend matrix33 operator - (const matrix33 &a, const matrix33 &b);
friend matrix33 operator * (const matrix33 &a, const matrix33 &b);
friend matrix33 operator * (const matrix33 &v, float f);
friend matrix33 operator * (float f, const matrix33 &v);
friend matrix33 operator / (const matrix33 &v, float f);

public:
/* Methods */

// set values (e.g. x = xIn, ...)
void set(const vector3 &v0, const vector3 &v1, const vector3 &v2);

// print matrix using std::cout
void printMatrix() const;

matrix33 invert();

void identity();

float determinant() const;
};

#endif
