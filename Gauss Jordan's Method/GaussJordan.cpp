/************************
**Gauss Jordan Method****
************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
   int N;
   cout << "Enter the number of equations << ";
   cin >> N;

   //dynamic array creation
   float **mat = new float *[N];

   for(int i = 0; i < N; ++i)
      mat[i] = new float[N+1];
   cout << "Enter the values of A, B, C and D of equation Ax1 + Bx2 + Cx3 = D for all equations" << endl;

   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N + 1; ++j) {
         cout << "A" << i + 1 << j + 1 << ": ";
         cin >> mat[i][j];
      }
      cout << endl;
   }

   //filling values of equations' parameters
   cout << "Your matrix is: " << endl;
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N + 1; ++j) {
         cout << setw(5) << mat[i][j];
         if(j == N - 1)
            cout << "  ";
      }
      cout << endl;
   }

   float m, n;
   for(int i = 0; i < N; ++i) {
      m = mat[i][i];
      for(int j = 0; j < N + 1; ++j) {
         if (i != j) {
            n = mat[j][i];
            for(int k = 0; k < N + 1; ++k)
               mat[j][k] -= (n/m) * mat[i][k];
         }
      }
   }

   cout << "The final augmented matrix: " << endl;
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N + 1; ++j) {
         cout << setw(5) << mat[i][j];
         if(j == N - 1)
            cout << "  ";
      }
      cout << endl;
   }

   float *x = new float [N];
   for(int i = 0; i < N; ++i) {
      x[i] = mat[i][N] / mat[i][i];;
      cout << x[i] << endl;
   }


   //dynamic array deletion
   for(int i = 0; i < N; ++i)
      delete[] mat[i];
      
   delete[] mat;
   delete[] x;

   return 0;
}
