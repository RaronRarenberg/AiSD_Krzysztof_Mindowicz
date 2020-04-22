#include <iostream>

void przesuniecie_cykliczne(int tablica[], int rozmiar)
{
    int zmienna_pomocnicza = tablica[rozmiar - 1];
    for (int i = rozmiar - 1; i > 0; i--)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = zmienna_pomocnicza;
}

int main()
{
    const int tabSize = 9;
    int a[tabSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int k = 5;
    for (int i = 0; i < k; i++) //przesuniecie o k miejsc w prawo
    {
        przesuniecie_cykliczne(a, tabSize);
    }
    
    for (int i = 0; i < tabSize; i++)
    {
        std::cout << a[i];
    }
    return 0;
}