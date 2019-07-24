// A program for polynomial curve fitting

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
   int i, j, k, n, N;

   cout << "Enter the no. of data pairs to be entered << ";
   cin >> N;

   double *x = new double[N];
   double *y = new double[N];

   cout << "Enter the x-axis values: " << endl;
   for(i = 0; i < N; i++)
      cin >> x[i];

   cout << "Enter the y-axis values: " << endl;
   for(i = 0; i < N; i++)
      cin >> y[i];

   cout << "What degree of Polynomial do you want to use for the fit? << ";
   cin >> n;

   double *X = new double[2 * n + 1];

   for(i = 0; i < 2 * n + 1; i++){
     X[i] = 0;
     for(j = 0; j < N; j++)
        X[i] += pow(x[j], i);
   }

   double B[n + 1][n + 2], a[n + 1];

   for(i = 0; i <= n; i++)
     for(j = 0; j <= n; j++)
        B[i][j] = X[i + j];

   double *Y = new double[n + 1];

   for(i = 0; i < n + 1; i++) {
     Y[i] = 0;
     for(j = 0; j < N; j++)
        Y[i] += pow(x[j], i) * y[j];
   }

   for(i = 0; i <= n; i++)
       B[i][n + 1] = Y[i];

   n = n + 1;

   cout << "The Normal(Augmented Matrix) is as follows: " << endl;

   for(i = 0; i < n; i++) {
     for(j = 0; j <= n; j++)
        cout << setw(16) << B[i][j] << setw(16);
     cout << endl;
   }

   for(i = 0; i < n; i++)
     for(k = i + 1; k < n; k++)
        if(B[i][i] < B[k][i])
           for (j = 0; j <= n; j++){
              double temp = B[i][j];
              B[i][j] = B[k][j];
              B[k][j] = temp;
           }

   for(i = 0; i < n - 1; i++)
     for(k = i + 1; k < n; k++) {
        double t = B[k][i] / B[i][i];
        for(j = 0 ;j <= n; j++)
           B[k][j] = B[k][j] - t * B[i][j];
     }

   for (i = n - 1; i >= 0; i--) {
     a[i] = B[i][n];
     for(j = 0; j < n; j++)
        if (j != i)
           a[i] -= B[i][j] * a[j];
     a[i] = a[i] / B[i][i];
   }

   cout << "The values of the coefficients are as follows: " << endl;
   for (i = 0; i < n; i++)
      cout << "x^" << i << " = " << a[i] << endl;

   cout << "Hence the fitted Polynomial is given by:\ny = ";
   for (i = 0; i < n; i++) {
      if(i != 0)
         cout << "+";
      cout << " (" << a[i] << ")" << "x^" << i << " ";
   }

   delete[]Y;
   delete[]X;
   delete[]y;
   delete[]x;

   return 0;
}
