#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int N;
   cout << "Enter the order of matrix << ";
   cin >> N;

   double **A = new double *[N];
   for(int i = 0; i < N; ++i)
      A[i] = new double [N];
   double *x = new double [N];
   double *z = new double [N];
   double *e = new double [N];
   double zmax, emax;

   cout << "Enter the matrix A: " << endl;
   for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
         cin >> A[i][j];

   cout << "Enter the starting vector: " << endl;
   for(int i = 0; i < N; ++i)
      cin >> x[i];

   do {
      for(int i = 0; i < N; ++i) {
         z[i] = 0;
         for(int j = 0; j < N; ++j)
            z[i] += A[i][j] * x[j];
      }

      zmax = fabs(z[0]);
      for(int i = 1; i < N; ++i)
         if(fabs(z[i]) > zmax)
            zmax = fabs(z[i]);

      for(int i = 0; i < N; ++i) {
         z[i] /= zmax;
         e[i] = fabs(fabs(z[i]) - fabs(x[i]));
      }

      emax = e[0];
      for(int i = 1; i < N; ++i)
         if(e[i] > emax)
            emax = e[i];

      for(int i = 0; i < N; ++i)
         x[i] = z[i];
   } while (emax > 0.000001);

   for(int i = 0; i < N; ++i)
      delete[] A[i];
   delete[] A;
   delete[] x;
   delete[] e;
   cout << "The required eigenvalue is " << zmax << endl;
   cout << "The required eigenvector is: " << endl;
   for(int i = 0; i < N; ++i)
      cout << z[i] << endl;
   delete[] z;

   return 0;

}
