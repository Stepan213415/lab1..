#include <iostream>
#include <cmath>

using namespace std;

double y(double x, int n) 
{
    if (x < 0) 
    {
        double product = 1.0;
        for (int j = 2; j <= n - 2; j++) 
        {
            product *= (j * j + x);
        }
        return product;
    } else 
    {
        double sum = 0.0;
        for (int i = 0; i <= n - 1; i++) 
        {
            double product = 1.0;
            for (int j = 0; j <= n - 1; j++) 
            {
                product *= (x + i * i + j);
            }
            sum += product;
        }
        return sum;
    }
}

bool readData(double &x_start, double &x_end, double &step, int &n) 
{
    cout << "Enter the initial value x: ";
    if (!(cin >> x_start)) {
        cout << "Error: Invalid input for x_start." << endl;
        return false;
    }
    
    cout << "Enter the final value x: ";
    if (!(cin >> x_end)) {
        cout << "Error: Invalid input for x_end." << endl;
        return false;
    }
    
    if (x_end < x_start) {
        cout << "Error: Final value x must be greater than or equal to initial value x." << endl;
        return false;
    }
    
    cout << "Enter the magnification step x: ";
    if (!(cin >> step)) {
        cout << "Error: Invalid input for step." << endl;
        return false;
    }
    
    if (step <= 0) {
        cout << "Error: Step must be positive." << endl;
        return false;
    }
    
    cout << "Enter the value n: ";
    if (!(cin >> n)) {
        cout << "Error: Invalid input for n." << endl;
        return false;
    }
    
    if (n <= 0) {
        cout << "Error: n must be positive." << endl;
        return false;
    }
    
    return true;
}

int main() 
{
    double x_start, x_end, step;
    int n;
    
    if (!readData(x_start, x_end, step, n)) {
        cout << "Program terminated due to invalid input." << endl;
        return 1;
    }
    
    cout << "result:" << endl;
    for (double x = x_start; x <= x_end + step / 2; x += step) // Додано step/2 для уникнення проблем з округленням
    {
        cout << "y(" << x << ", " << n << ") = " << y(x, n) << endl;
    }
    
    return 0;
}