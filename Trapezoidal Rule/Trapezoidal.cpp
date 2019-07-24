#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
   return x * sin(x) + cos(x);
}

int main()
{
   int n;
   double a, b, h;

   cout << "Enter the limits of the interval << ";
   cin >> a >> b;
   cout << "Enter the number of sub-intervals << ";
   cin >> n;

   double *x = new double [n + 1];
   double *y = new double [n + 1];

   h = (b - a) / n;
   double sum = 0;

   for(int i = 0; i <= n; ++i) {
      x[i] = a + i * h;
      y[i] = f(x[i]);
   }

   for(int i = 1; i < n; ++i) {
      sum += h * y[i];
   }

   double integral = h / 2.0 * (y[0] + y[n]) + sum;

   delete[] x;
   delete[] y;

   cout << "The value of integral = " << integral << endl;

   return 0;
}
