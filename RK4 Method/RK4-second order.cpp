/**************************************************************
**RK-4 Method for solving Second order differential equations**
***************************************************************/
#include <iostream>
//#include <iomanip>
#include <cmath>
using namespace std;
//Function definition
double f(double x, double y,double z)
{
   return cos(x) - x * sin(x);
}
int main()
{
   double x0, y0, z0, h, x, y, z, k1, l1, k2, l2, k3, l3, k4, l4, k, l; // Define all variables
   //Prompt for initial values of x and y
   cout << "Enter the initial values of x, y and z << ";
   cin >> x0 >> y0 >> z0;
   //Prompt for the value of x whose corresponding
   //y is to be calculated
   cout << "Enter the value of x << ";
   cin >> x;
   //Prompt for width of sub-interval
   cout << "Enter the width of sub-interval << ";
   cin >> h;
   //Calculations and displaying values
   //cout << x0 << setw(20) << y0 << setw(20) << z0 << endl;
   do {
      k1 = h * z0;
      l1 = h * f(x0, y0, z0);
      k2 = h * (z0 + 0.5 * l1);
      l2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1, z0 + 0.5 * l1);
      k3 = h * (z0 + 0.5 * l2);
      l3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2, z0 + 0.5 * l2);
      k4 = h * (z0 + l3);
      l4 = h * f(x0 + h, y0 + k3, z0 + l3);
      k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
      l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
      x0 += h;
      y = y0 + k;
      y0 = y;
      z = z0 + l;
      z0 = z;
  //    cout << x0 << setw(20) << y << setw(20) << z << endl;
   } while (fabs(x0 - x) >= 0.00000001);
   cout << "The approximate value of y at x = " << x << " is " << y << endl;

   return 0;
}
