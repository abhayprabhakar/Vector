#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

struct arr{
    int vec[3][3];
};

struct vector{
    int v[3];
};

class Array{
    private:
        int* ptr;
    public:
        arr input();
        void output(struct arr);
        arr multiply(arr,arr);
};
arr Array::input()
{
    struct arr vect;
    for(int i=0; i < 3 ;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << "a[" << i <<"][" << j << "] = ";
            cin >> vect.vec[i][j];
        }
    }
    cout << endl;
    return vect;
}
void Array::output(struct arr dis)
{
    for(int i=0; i < 3 ;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << dis.vec[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}
arr Array::multiply(struct arr a, struct arr b)
{
    struct arr c;
    int sum = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                sum = sum + a.vec[i][k] * b.vec[k][j];
            }
            c.vec[i][j] = sum;
            sum = 0;
        }
    }
    return c;
}

class Vector{
    public:
        vector input();
        vector cross(vector,vector);
        int dot(vector,vector);
        vector add(vector,vector);
        vector subtract(vector,vector);
        float magnitude(vector);
        void display(vector);
        vector rot2d(vector,float);            //input vector and angle(in degrees) & output rotated matrix
};
vector Vector::input()
{
    struct vector y;
    for(int i=0; i < 3;i++)
    {
        cout << "a[" << i <<"] = ";
        cin >> y.v[i];
    }
    cout << endl;
    return y;
}
vector Vector::cross(struct vector a,struct vector b)
{
    struct vector c;
    c.v[0] = ((a.v[1])*(b.v[2]))-((a.v[2])*(b.v[1]));
    c.v[1] = (((a.v[0])*(b.v[2]))-((a.v[2])*(b.v[0])))*(-1);
    c.v[2] = ((a.v[0])*(b.v[1]))-((a.v[1])*(b.v[0]));
    return c;
}
int Vector::dot(struct vector a, struct vector b)
{
    int dot;
    dot = (a.v[0]*b.v[0])+(a.v[1]*b.v[1])+(a.v[2]*b.v[2]);
    return dot;
}
vector Vector::add(struct vector a,struct vector b)
{
    struct vector c;
    for(int i=0;i<3;i++)
    {
        c.v[i] = a.v[i] + b.v[i];
    }
    return c;
}
vector Vector::subtract(struct vector a, struct vector b)
{
    struct vector c;
    for(int i=0;i<3;i++)
    {
        c.v[i] = a.v[i] - b.v[i];
    }
    return c;
}
float Vector::magnitude(struct vector a)
{
    float mag = sqrt((a.v[0]*a.v[0])+(a.v[1]*a.v[1])+(a.v[2]*a.v[2]));
    return mag;
}
void Vector::display(struct vector p)
{
    for(int i=0;i<3;i++)
    {
        if(i == 0)
        cout << p.v[i] << " i + ";
        else if(i == 1)
        cout << p.v[i] << " j + ";
        else if(i == 2)
        cout << p.v[i] << " k " << endl;
    }
    cout << endl;
}
vector Vector::rot2d(struct vector a, float angle)
{
    angle = angle *	M_PI/180;
    struct vector c;
    c.v[0] = ((a.v[0]*cos(angle))-(a.v[1]*sin(angle)));
    c.v[1] = ((a.v[0]*sin(angle))+(a.v[1]*cos(angle)));
    c.v[2] = a.v[2];

    return c;
}


int main()
{
    struct vector a,b,c;
    Array l;
    Vector g;
    a = g.input();
    b = g.rot2d(a,90);
    g.display(b);
    return 0;
}