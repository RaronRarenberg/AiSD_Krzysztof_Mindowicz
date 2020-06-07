
#include <iostream>
#include <algorithm>
#include <array>
//deklarowana tylko jedna zmienna oraz n - 1 porownan
int maks(int t[], int n)
{
    int x = t[n];
    while (n--)
    {
        if ( x < t[n])
        {
        x = t[n];
        }
    }
    return x;
}

int maksRek(int tablica[], int indeks)
{
    if (indeks == 0)
    {
        return tablica[0];
    }
    else
    {
        return std::max(tablica[indeks], maksRek(tablica, indeks - 1));
    }
}
int main()
{
    const int rozmiar = 5;
    int tablica[rozmiar] = {33,45,21,41,16};
    std::cout << maks(tablica, rozmiar) << std::endl;
    std::cout << maksRek(tablica, rozmiar - 1);

}
