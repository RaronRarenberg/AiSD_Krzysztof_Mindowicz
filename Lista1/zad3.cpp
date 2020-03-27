#include <iostream>
#include <cmath>

double oblicz(double a[], int n, double x)
{
    double wynik = 0;
    for (int i = n; i >= 0; i--)
    {
        wynik = (wynik * x) + a[i];
    }
    return wynik;
}

int main()
{
    double wspolczynniki[3] = {0, 0, 1 }; //    x^2 
    std::cout << oblicz(wspolczynniki, 3, 2) << std::endl;

    return 0;
}
