#include <iostream>
using namespace std;
int main()
{
   int num;
   
   cout << "Enter the number of variables: ";
   cin >> num;

   double **a = new double*[num];
   cout << "Enter the coefficients and constants: " << endl;

   for(int i = 0; i < num; ++i) {
      a[i] = new double [num+1];
      for(int j = 0; j <= num; ++j)
         cin >> a[i][j];
   }
   double *x = new double[num];

   for(int i = 0; i < num; ++i) {
      for(int j = 0; j < num; ++j) {
         if(j == i)
            continue;
         double numerator = a[j][i];
         
         for(int k = 0; k <= num; ++k)
            a[j][k] = a[j][k] - a[i][k] * numerator / a[i][i];
      }
   }
   
   for(int i = 0; i < num; ++i)
      cout << "x" << i << " = " << a[i][num] / a[i][i] << endl;
   
   delete []*a;
   delete [] a;
   delete [] x;
   
   return 0;
}
