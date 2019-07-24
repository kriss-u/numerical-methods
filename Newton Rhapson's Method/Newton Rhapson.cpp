#include <iostream>
#include <cmath>
using namespace std;
double f(double x);
double fprime(double x);
int main()
{
   double x, x1;
   cout << "Enter the initial guess << ";
   cin >> x1;

   do {
      if (fprime(x1) == 0) {
         cout << "The slope is zero, cannot calculate." << endl;
         return 0;
      }
      x = x1;
      x1 = x1 - (f(x1) / fprime(x1));
   } while (fabs(x1 - x) >= 0.00000001);
   cout << "The root of the equation is " << x1 << endl;
   return 0;
}

double f(double x)
{
   return x * sin(x) + cos(x) + log(x);
}

double fprime(double x)
{
   return x * cos(x) + 1 / x;
}
