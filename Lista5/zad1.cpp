#include <iostream>
#include <cmath> // funkcja floor
int przypisanie_do_kubelka(int a, int b, int n, int x)
{
	int poczatek_przedzialu = a;
	int koniec_przedzialu = b;
	int ilosc_kubelkow = n;
	int sortowana_liczba = x;
	int ilosc_liczb_w_przedziale = (koniec_przedzialu - poczatek_przedzialu) + 1;
	int szerokosc_przedzialu_kubelka = ilosc_liczb_w_przedziale / ilosc_kubelkow;
	int numer_kubelka = floor ((sortowana_liczba - poczatek_przedzialu) / szerokosc_przedzialu_kubelka);
	return numer_kubelka;
	//czyli podsumowujac mamy wzor:
	//numer_kubelka = floor((x - a) / (((b-a) + 1) / n))  
}

int main()
{
	//przyklad: mam przedzial od 1 do 5
	//mam 5 kubelkow:
	//0. [1,2)
	//1. [2,3)
	//2. [3,4)
	//3. [4,5)
	//4. [5]
	//czyli liczba 2 powinna trafic do kubelka "1."
	int liczba_x = 2;
	std::cout << "liczba:" << liczba_x << " trafia do kubelka numer:" << przypisanie_do_kubelka(1,5,5, liczba_x);
	std::cout << std::endl;
	//przyklad 2: mam przedzial od 4 do 31
	//mam 4 kubelki:
	//0. [4,11)
	//1. [11,18)
	//2. [18,25)
	//3. [25,31)
	//czyli liczba 19 powinna trafic do kubelka "2."
	int liczba_x2 = 19;
	std::cout << "liczba:" << liczba_x2 << " trafia do kubelka numer:" << przypisanie_do_kubelka(4, 31, 4, liczba_x2);

}