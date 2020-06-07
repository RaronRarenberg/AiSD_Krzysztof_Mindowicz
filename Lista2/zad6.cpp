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



void wypisz(Lista* lista)
{
    while (lista != nullptr)
    {
        std::cout << lista->klucz << " ";
        lista = lista->nastepny;
    }
    std::cout << "\n";
}

Lista* merge(Lista* l1, Lista* l2)  // różno-elementowe listy
{
	Lista* wynik = nullptr;
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    

   
	
	if(l1->klucz <= l2->klucz)
	{
		wynik = l1; //do wynikowej listy wrzucamy wartosc z l1
		wynik->nastepny = merge(l1->nastepny,l2); //i porównujemy kolejny element listy l1  z  tym samym elementem l2
	}	
	else
	{
		wynik = l2;
		wynik->nastepny = merge(l1,l2->nastepny);
	}
	return(wynik);
}

int main()
{
    Lista* lista = nullptr;
    Lista* lista2 = nullptr;
    dodaj(lista, 8);
    dodaj(lista2, 7);
    dodaj(lista, 6);
    dodaj(lista2, 5);
    dodaj(lista, 4);
    dodaj(lista2, 3);
    dodaj(lista, 2);
    dodaj(lista2, 1);

    //wypisz(lista);
    //wypisz(lista2);
    auto wynik = merge(lista, lista2);
    wypisz(wynik);
    return 0;
}