#include <iostream>

struct Lista
{
    int klucz;
    Lista* nastepny = nullptr;
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
    Lista* poprzednia = nullptr; //to tak naprawde sluzy do zerowania tymczasowej
    Lista* tymczasowa = oryginalna;

    while (tymczasowa != nullptr)//az do ostatniego wagonika
    {
        nastepna = tymczasowa->nastepny;
        tymczasowa->nastepny = poprzednia;
        poprzednia = tymczasowa;
        tymczasowa = nastepna;
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