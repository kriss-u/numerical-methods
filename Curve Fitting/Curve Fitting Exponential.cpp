
// A program for exponentialcurve fitting


#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Declaring variables and prompting for the number of inputs.
   int N;
   float sumx = 0, sumY = 0, sumxY = 0, sumx2 = 0;
   cout << "How many inputs do you want to enter for x and y? << ";
   cin >> N;
   
   // Creating dynamic array
   float *x = new float[N];
   float *y = new float[N];
   float *Y = new float[N];

   //Entering data for x and Y
   cout << "---------Enter Data For x and Y separated by a space or a new line------------" << endl;
   for (int i = 0; i < N; ++i) {
      cin >> x[i];
      cin >> y[i];
      Y[i] = log(y[i]);
      sumx += x[i];
      sumY += Y[i];
      sumxY += x[i] * Y[i];
      sumx2 += x[i] * x[i];
   }

   delete[] x;
   delete[] y;
   delete[] Y;

   /*Solving using Cramer Rule
   Creating variables det1, det2, det for determinants of Cramer Rule */

   float det1, det2, det;
   float A, b;
   det1 = sumY * sumx2 - sumx * sumxY;
   det2 = N * sumxY - sumx * sumY;
   det = N * sumx2 - sumx * sumx;

   A = det1 / det;
   b = det2 / det;

   //Declaring the original variable a in the equation
   float a;

   a = exp(A);

   //Displaying Output
   cout << "The linear equation is: << Y = " << b << "x" << " + " << A << endl;
   cout << "The exponential equation is: << y = " << a << "e^(" << b << "x)" << endl;

   return 0;
}

