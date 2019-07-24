#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
   return (4 * exp(x)) / (1 + x * x * x);
}

int main()
{
   int n;
   double a, b, h;

   cout << "Enter the limits << ";
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

   for(int i = 1; i < n; i += 2)
      sum += 4.0 * y[i];

   for(int i = 2; i < n - 1; i += 2)
      sum += 2.0 * y[i];

   double integral = h / 3.0 * (y[0] + y[n] + sum);

   cout << "The value of integral = " << integral << endl;

   return 0;
}
