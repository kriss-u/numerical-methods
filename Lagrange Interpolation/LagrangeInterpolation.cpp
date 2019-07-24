#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
   int i, j, N;
   double mul, sum = 0, X, Y;

   cout << "How many data pairs do you want to enter? << ";
   cin >> N;
   double *x = new double[N];
   double *y = new double[N];

   cout << "Enter the x-axis values: " << endl;
   for(i = 0; i < N; ++i)
      cin >> x[i];

   cout << "Enter the y-axis values: " << endl;
   for(i = 0; i < N; ++i)
      cin >> y[i];

   cout << "Enter the value of x for calculation << ";
   cin >> X;

   for(i = 0; i <= N - 1; ++i) {
      mul = 1;
      for(j = 0; j <= N - 1; ++j) {
         if(j != i)
            mul *= (X - x[j]) / (x[i] - x[j]);
      }
      sum += mul * y[i];
   }

   Y = sum;
   delete[] x;
   delete[] y;

   cout << "The estimated value of y for x = " << X << " is " << Y << endl;
   return 0;
}
