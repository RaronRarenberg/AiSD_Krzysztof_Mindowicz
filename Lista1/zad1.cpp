// AiSD_Lista1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int potega_rekurencyjna(int liczba, int potega)
{
    if (potega != 0)
    {
        return liczba * potega_rekurencyjna(liczba, potega - 1);
    }
    else
    {
        return 1;
    }
}

int potega_nierekurencyjna(int liczba, int potega)
{
    int wynik = 1;
    for (int i = 0; i < potega; i++)
    {
        wynik *= liczba;
    }
    return wynik;
}

int main()
{
    std::cout << "Hello World!\n";
    std::cout << potega_nierekurencyjna(3, 2) << std::endl;
    std::cout << potega_rekurencyjna(3, 0) << std::endl;
}

