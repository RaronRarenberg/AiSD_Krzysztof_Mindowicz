#include <iostream>
#include <cmath>

double oblicz(double wspolczynniki[], int stopien, double x)
{
    double wynik = 0;
    for (int i = stopien - 1; i >= 0; i--)
    {
        wynik = (wynik * x) + wspolczynniki[i];
    }
    return wynik;
}

int main()
{
    const int stopien_wielomianu = 2;
    double wspolczynniki[stopien_wielomianu + 1] = { 0, 0, 1 }; //    0*x^0 + 0*x^1 + 1*x^2 
    std::cout << oblicz(wspolczynniki, 3, 2) << std::endl;

    return 0;
}
