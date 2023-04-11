#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

struct complex{
    float r;
    float i;
};

class complexop{
    public:
        complex add(complex,complex);
        complex subtract(complex,complex);
        complex multiply(complex,complex);
        complex rotate(complex,float);                                         //provide angle in degree
        complex inputcmd();
        void output(complex);
};

complex complexop::add(complex a,complex b)
{
    struct complex c;
    c.r = a.r + b.r;
    c.i = a.i + b.i;

    return c;
}

complex complexop::subtract(complex a,complex b)
{
    struct complex c;
    c.r = a.r - b.r;
    c.i = a.i - b.i;

    return c;
}

complex complexop::multiply(complex a,complex b)
{
    struct complex c;
    c.r = (a.r * b.r) - (a.i * b.i);
    c.i = (a.r * b.i) + (b.r * a.i);

    return c;
}

complex complexop::rotate(complex a, float degree)                             //provide angle in degree
{
    float rad = degree * M_PI/180;
    struct complex b;
    b.r = cos(rad);
    b.i = sin(rad);

    return multiply(a,b);
}

complex complexop::inputcmd()
{
    struct complex a;
    cout << "Enter the real part: ";
    cin >> a.r;
    cout << "Enter the imaginary part: ";
    cin >> a.i;

    return a;
}

void complexop::output(complex a)
{
    if(a.i >= 0)
    cout << "(" << a.r << " + " << a.i << " i)" <<endl;

    else if(a.i < 0)
    cout << "(" << a.r << " - " << -(a.i) << " i)" <<endl;
}


int main()
{
    complexop c;
    struct complex a,b;
    float degree = 60;
    a.r = 1;
    a.i = 0;
    b.r = 2;
    b.i = 0;
    c.output(c.add(a,b));
    c.output(c.subtract(a,b));
    c.output(c.multiply(a,b));
    c.output(c.rotate(a,degree));
    c.output(c.rotate(b,degree));

    return 0;
}