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
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    

    // odtąd l1 to wskaźnik na pierwszy wagonik z pierwotnego l1, którego miejsca w liście wynikowej nie jesteśmy pewni
    // odtąd l2 to wskaźnik na pierwszy wagonik z pierwotnego l2, którego miejsca w liście wynikowej nie jesteśmy pewni

    // chcę, by pierwszy wagonik był ma liście o nazwie l1; to nieco ułatwia myślenie o wstępnej fazie działania funkcji
    if (l2->klucz < l1->klucz) std::swap(l1, l2);

    // tworzymy jednowagonikową listę wynikową
    // head to początek listy wynikowej, zostnie zwrócony jako wartość funkcji, stąd const
    // tail pokazuje ostatnio doczepiony wagonik z danymi, jest więc miejscem,
    //   za którym doczepiamy kolejne wagoniki z list l1, l2
    Lista* const head = l1;  // to wiemy dzięki swap-owi powyżej
    Lista* tail = head;      // pierwszy wagonik jest też teraz ostatnim, o którym wiemy, że ma poprawną pozycję
    l1 = l1->nastepny;          // przesuwamy l1, bo dane w nim już obejrzeliśmy przy okazji ewentualnego swap-a

    while (l1 != nullptr && l2 != nullptr)
    {
        Lista* old_tail = tail;
        if (l1->klucz < l2->klucz)  // jeśli kolejna najmniejza liczba jest w l1
        {
            tail = l1;      // kolejny wagonik jest w l1
            l1 = l1->nastepny;  // l1->next jest pierwszym wagonikiem w l1, którego nie widzieliśmy
        }
        else  // symetrycznie
        {
            tail = l2;
            l2 = l2->nastepny;
        }
        old_tail->nastepny = tail;  // kluczowa instrukcja! Tu dołaczamy kolejny wagonik do "zmerdżowanej" listy
    }
    // po wyjściu z pętli jedna lista, l1 lub l2, na pewno jest już pusta (przejrzana),
    // ale być może zakończyliśmy pętlę z niepodpietą końcówką drugiej listy?
    if (l1 != nullptr) tail->nastepny = l1;
    if (l2 != nullptr) tail->nastepny = l2;

    return head;
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