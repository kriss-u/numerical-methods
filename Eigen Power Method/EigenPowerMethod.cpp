// Eigen Power Method for Eigen Value and Eigen Vector
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
   int N;
   float temp, MAX = 0;
   cout << "Enter the order of Matrix << ";
   cin >> N;

   float **mat = new float * [N];
   float *x = new float [N];
   float *z = new float [N];
   for(int i = 0; i < N; ++i)
      mat[i] = new float [N];

   cout << "Enter the coefficient of matrix: " << endl;
   for(int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
         cin >> mat[i][j];

   cout << "Enter the starting vector: " << endl;
   for(int i = 0; i < N; ++i)
      cin >> x[i];

   do {
      for(int i = 0; i < N; ++i) {
         z[i] = 0;
         for(int j = 0; j < N; ++j)
            z[i] += mat[i][j] * x[j];
      }
      temp = MAX;
      MAX = z[0];
      for(int i = 0; i < N; ++i) {
         if(z[i] > MAX)
            MAX = z[i];
      }
      for(int i = 0; i < N; ++i)
         z[i] /= MAX;

      for(int i = 0; i < N; ++i)
         x[i] = z[i];
   } while(fabs(MAX - temp) > 0.0000001);

   cout << "Eigenvalue = " << MAX << endl;
   cout << "Eigenvector: " << endl;
   for(int i = 0; i < N; ++i)
      cout << x[i] << endl;

   return 0;
}
