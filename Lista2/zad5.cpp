#include <iostream>

struct Lista
{
    int klucz;
    Lista* nastepny ;
};

void dodaj(Lista*& oryginalna, int kluczyk)
{
    auto lista = new Lista; //tworzymy sobie strukture
    lista->nastepny = oryginalna; //przekazujemy jej wskaznik
    lista->klucz = kluczyk; //pole uzupelniamy wartoscia
    oryginalna = lista; //doczepiamy wagonik
}

void reverse(Lista*& oryginalna)
{
    if (oryginalna == nullptr || oryginalna->nastepny == nullptr) return;
    Lista* nastepna = nullptr;
    Lista* poprzednia = nullptr; 

    while (oryginalna != nullptr)//az do ostatniego wagonika
    {
        nastepna = oryginalna->nastepny;
        oryginalna->nastepny = poprzednia;
        poprzednia = oryginalna;
        oryginalna = nastepna;
    }
    oryginalna = poprzednia;
    std::cout << "obrocilem: ";
}

void wypisz(Lista* lista)
{
    while (lista != nullptr)
    {
        std::cout << lista->klucz << " ";
        lista = lista->nastepny;
    }
    std::cout << "\n";
}
int main()
{
    Lista* lista = nullptr;
    dodaj(lista, 3);
    dodaj(lista, 4);
    dodaj(lista, 5);
    dodaj(lista, 6);

    wypisz(lista);
    reverse(lista);
    wypisz(lista);
    return 0;
}