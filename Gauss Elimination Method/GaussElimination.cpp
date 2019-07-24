// Solving the equation using Gauss Elimination
#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Enter the number of variables in the equations : ";
    cin >> num;

    double **a = new double *[num];
    double *x = new double [num];

    cout << "Enter the coefficients of the variables  and constants :" << endl;

    for (int i = 0; i < num; i++) {
        a[i] = new double[num + 1];
        for (int j = 0; j <= num; j++)
            cin >> a[i][j];
    }

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            double numerator = a[j][i];
            for (int k = 0; k <= num; k++)
                a[j][k] = a[j][k] - a[i][k] * numerator / a[i][i];
        }
    }

    cout << endl;

    for (int i = num - 1; i >= 0; i--) {
        x[i] = 0;
        double subtrand = 0;

        for (int j = i + 1; j < num; j++)
            subtrand += a[i][j] * x[j];
        x[i] = (a[i][num] - subtrand) / a[i][i];

        cout << "x" << i << " = " << x[i] << endl;
    }

    delete []*a;
    delete [] a;
    delete [] x;
    
    return 0;
}
