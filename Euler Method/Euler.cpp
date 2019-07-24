// Euler's Method for solving the differential equation

#include <iostream>
#include <cmath>
using namespace std;
double df(double x, double y)
{
   return x + y;
}
int main()
{
   double x0, y0, x, y, h;

   cout << "Enter the initial values of x and y << ";
   cin >> x0 >> y0;

   cout << "Enter the value of x << ";
   cin >> x;

   cout << "Enter the width of the sub interval: ";
   cin >> h;

   while (fabs(x - x0) > 0.000000001) {
      y = y0 + (h * df(x0, y0));
      x0 += h;
      y0 = y;
      
      cout << x0 << "\t" << y0 << "\t" << y << endl;
   }

   cout  << "The approximate value of y is " << y << endl;
   return 0;
}
