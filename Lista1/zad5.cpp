#include <iostream>

void max_min(int tablica[], int rozmiar_tablicy)
{
    int minimum = tablica[rozmiar_tablicy - 1];
    int maksimum = tablica[rozmiar_tablicy - 1];

    for (int i = 0; i < rozmiar_tablicy - 1; i++) 
    {
        if (tablica[i] > tablica[i + 1])
        {
            if (tablica[i] > maksimum)
            {
                maksimum = tablica[i];
            }
        }
        else
        {
            if (tablica[i] < minimum)
            {
                minimum = tablica[i];
            }
        }
    }
    std::cout << "najmniejsza liczba: " << minimum << ", najwieksza liczba:" << maksimum << std::endl;

}

int main()
{
    const int rozmiar = 6;
    int tablica[rozmiar] = { 48, -15, 9, 18, 27, -31 };
    max_min(tablica, rozmiar);
    return 0;
}