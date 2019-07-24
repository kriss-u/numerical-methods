#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f (double x, double y)
{
   return x - y;
}
int main()
{
   double x0, y0, h, xn, yn, m1, m2, m3, m4, m;
   double tempx;
   cout << "Enter  the initial values for x0 and y0 << ";
   cin >> x0 >> y0;
   cout << "Enter the value of h << ";
   cin >> h;
   cout << "Enter the value of x << ";
   cin >> xn;
   cout << x0 << setw(10) << y0 << endl;
   do {
      m1 = h * f(x0, y0);
      m2 = h * f(x0 + (h/2), y0 + (m1/2));
      m3 = h * f(x0 + (h/2), y0 + (m2/2));
      m4 = h * f(x0 + h, y0 + m3);
      m = (m1 + 2 * m2 + 2 * m3 + m4) / 6.0;
      y0 = y0 + m;
      x0 = x0 + h;
      yn = y0;
      cout << x0 << setw(10) << y0 << endl;
   } while (x0 <= xn);
   cout << "The value of y is " << yn << endl;
   return 0;
}
