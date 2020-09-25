#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0, k, number;
    double x, a = 1, eps, left, sum = 0;
    cout << "Enter a number of signs after comma " << endl;
    cin >> number;
    cout << fixed << setprecision(number);
    cout << "Enter x between (-1; 1)" << endl;
    cin >> x;
    cout << "Enter natural number k" << endl;
    cin >> k;
    left = log((1 + x) / (1 - x));
    eps = pow(10, (-k));
    while (fabs(a) >= eps)
    {
        if (n % 2 == 1)
        {
            a = (2 * pow(x, n)) / n;
            sum += a;
            ++n;
        }
        else
        {
            n++;
        }
    }
    cout << "Left part = " << left << endl;
    cout << "Right part = " << sum << endl;
    return 0;
}
