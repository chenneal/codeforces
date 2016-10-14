#include <iostream>
#include <cstdio>
#include <cmath>

#define D double
#define PI acos(-1)
#define S(x) (x)*(x)
#define ABS(x) ((x)>0 ? (x) : -(x))
#define DIS(X1, Y1, X2, Y2) sqrt(pow(X1-X2, 2)+pow(Y1-Y2, 2))
#define EXP 1e-4

using namespace std;
D gcd(D X, D Y) {
    if (fmod(X, Y) < EXP)
        return Y;
    else
        return gcd(Y, fmod(X, Y));
}

int main() {
    D x1, y1, x2, y2, x3, y3, angle;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        D angle1, angle2, angle3;
        D r, p, s, a, b, c, help;
        a = DIS(x1, y1, x2, y2);
        b = DIS(x2, y2, x3, y3);
        c = DIS(x1, y1, x3, y3); 
        p = (a+b+c)/2.0;
        s = sqrt(p*(p-a)*(p-b)*(p-c));
        r = (a*b*c)/(4*s);
        angle1 = 2*asin(a/(2*r));
        angle2 = 2*asin(b/(2*r));
        angle3 = 2*PI-angle1-angle2;
        if (angle1 >= angle2 && angle1 >= angle3) {
            angle = gcd(angle2, angle3);
        }
        else if(angle2 >= angle1 && angle2 >= angle3) {
            angle = gcd(angle2, angle3);
        }
        else {
            angle = gcd(angle1, angle3);
        }
        help = gcd(angle2, angle3);
        angle = gcd(angle1, help);
        printf("%.8lf", (PI*r*r*sin(angle))/angle);
    }
    return 0;
}
