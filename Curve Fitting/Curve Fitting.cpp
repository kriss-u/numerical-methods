#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   // Declaring variables and prompting for the number of inputs.
   int N;
   float sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0;
   cout << "How many inputs do you want to enter for x and y? << ";
   cin >> N;

   // Creating dynamic array
   float *x = new float[N];
   float *y = new float[N];

   //Entering data for x and Y
   cout << "---------Enter Data For x and Y separated by a space or a new line------------" << endl;
   for (int i = 0; i < N; ++i) {
      cin >> x[i];
      cin >> y[i];
      sumx += x[i];
      sumy += y[i];
      sumxy += x[i] * y[i];
      sumx2 += x[i] * x[i];
   }
   delete[] x;
   delete[] y;

   /*Solving using Cramer Rule
   Creating variables det1, det2, det for determinants of Cramer Rule */

   float det1, det2, det;
   float a, b;
   det1 = sumy * sumx2 - sumx * sumxy;
   det2 = N * sumxy - sumx * sumy;
   det = N * sumx2 - sumx * sumx;

   a = det1 / det;
   b = det2 / det;

   cout << "The values of a and b are: " << a << ", " << b << endl;

   //Displaying Output
   //cout << "The linear equation is: << Y = " << b << "x" << " + " << a << endl;
   //cout << "The exponential equation is: << y = " << a << "e^(" << b << "x)" << endl;

   return 0;
}

