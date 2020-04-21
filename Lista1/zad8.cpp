#include <iostream>

bool* sito_erastotenesa(int rozmiar)
{
    bool* prime = new bool[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= rozmiar; i++) //2 to pierwsza z liczb pierwszych i chcemy dotrzec do sqrt(rozmiar)
    {
        if (prime[i]) // == true
        {
            for (int j = i * i; j < rozmiar; j += i) //wielokrotnosci tej liczby nie sa liczbami pierwszymi
                prime[j] = false; //wiec dostaja flage false
        }
    }
    return prime;
}
int main()
{
    const int rozmiar = 40;
    auto wynik = sito_erastotenesa(rozmiar);
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << i << " = " << wynik[i] << std::endl;
    }
    return 0;
}