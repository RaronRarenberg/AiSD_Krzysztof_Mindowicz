#include <iostream>
#include <vector>
#include <string>
#include <forward_list> //lista pojedynczo linkowana

struct Hashowanie
{
	size_t operator()(const std::string& s) const //funktor czyli wywolujemy obiekt jak funkcje
	{//przy okazji uzywam funkcji z zadania 1
		unsigned int h, i;

		h = 0;
		for (i = 0; i < s.length(); i++)
			h = 2 * h + 1 - (s[i] & 1);
		return h % 10;
	}
};

template<typename T, typename HashFunkcja = std::hash<T> > //elementy dowolnego typu T przechowam w kubelkach nizej
class HashLancuch
{
public:
	HashLancuch(size_t rozmiar_kubelka, HashFunkcja hash) :kubelki(rozmiar_kubelka), hash_funkcja{hash}
	{

	}
	~HashLancuch() = default;

	void wstaw(const T& wstawiany_elem)
	{
		auto indeks_hashowania = hash_funkcja(wstawiany_elem) % kubelki.size();//hash_funkcja korzysta z przeciazonego operatora
		kubelki[indeks_hashowania].push_front(wstawiany_elem);
	}

	const T* znajdz(const T& szukany_elem) const //zwracamy adres elementu lub nullptr
	{
		auto indeks_hashowania = hash_funkcja(szukany_elem) % kubelki.size();
		auto const& lista = kubelki[indeks_hashowania];
		for (const auto& element : lista)
		{
			if (element == szukany_elem) return &element;
		}
		return  nullptr;
	}

	void usun(const T& usuwany_elem)
	{
		auto indeks_hashowania = hash_funkcja(usuwany_elem) % kubelki.size();
		kubelki[indeks_hashowania].remove(usuwany_elem);
	}

private:
	std::vector<std::forward_list<T>> kubelki;
	const HashFunkcja hash_funkcja; //czyli tak naprawdę std::hash<T> hash_funkcja
};

template <typename T, typename HashFunkcja>
void sprawdz(const HashLancuch<T, HashFunkcja>& tablica, const std::string& sprawdzana_wartosc, bool spodziewana_wartosc)
{
	auto wskaznik = tablica.znajdz(sprawdzana_wartosc);
	if ((wskaznik == nullptr && spodziewana_wartosc == false) || (wskaznik != nullptr && spodziewana_wartosc != false))
		std::cout << "Zgadza się\n";
	else
		std::cout << "Nie zgadza się\n";
}

int main()
{
	HashLancuch<std::string, Hashowanie> tablica(1001, Hashowanie());//pusty nawias to zamiana klasy w objekt
	for (int i = 0; i < 1000; i++)
	{
		tablica.wstaw(std::to_string(i));
	}
	for (int i = 300; i < 500; i++)
	{
		tablica.usun(std::to_string(i));
	}

	sprawdz(tablica, "299", true);
	sprawdz(tablica, "500", true);
	sprawdz(tablica, "300", false);
}

