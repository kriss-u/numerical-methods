
#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter the number of variables in the equations : ";
    cin >> num;

    double **a = new double *[num], *c = new double[num], *x = new double[num];
    cout << "Enter the coefficients of the variables  and constants :" << endl;
    for (int i = 0; i < num; i++) {
        a[i] = new double[2 * num];
        for (int j = 0; j < num; j++) {
            cin >> a[i][j];
            if(i == j )
                a[i][j + num] = 1;
            else
                a[i][j + num] = 0;
        }
        cin >> c[i];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (j == i) {
                double denominator = a[i][i];
                for (int k = 0; k < 2 * num; k++)
                    a[j][k]  /= denominator;
                continue;
            }
            double numerator = a[j][i];
            for (int k = 0; k < 2 * num; k++)
                a[j][k]  -= a[i][k] * numerator / a[i][i];
        }
    }

    for (int i = 0; i < num; i++) {
        x[i] = 0;
        for (int j = 0; j < num; j++)
            x[i] += a[i][j + num] * c[j];
        cout << "x" << i << " = " << x[i] << endl;
    }

    delete[]a;
    delete[]x;
    delete[]c;
    
    return 0;
}
