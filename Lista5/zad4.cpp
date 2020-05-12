#include<iostream>

int WezMaksimum(int arr[], int rozmiar)
{
    int maksimum = arr[0];
    for (int i = 0; i < rozmiar; i++)
    {
        if (arr[i] > maksimum)
            maksimum = arr[i];
    }
    return maksimum;
}

void SortowaniePrzezZliczanie(int arr[], int rozmiar, int div) //liczba div mowi czy sortujemy wedlug jednosci, dziesiatek, setek
{
    int* wyjsciowy = new int[rozmiar];
    int liczenie[10] = { 0 }; //dla systemu dziesiatkowego mamy 10 kubelkow

    for (int i = 0; i < rozmiar; i++)
    {
        liczenie[(arr[i] / div) % 10]++; //liczby wchodza do kubelka na podstawie liczby div
    }

    for (int i = 1; i < 10; i++)
    {
        liczenie[i] += liczenie[i - 1]; //akumulacja liczby wystapien cyfr
    }

    for (int i = rozmiar - 1; i >= 0; i--) //jadac od konca
    {
        wyjsciowy[liczenie[(arr[i] / div) % 10] - 1] = arr[i]; //w wyjsciowym pojawia sie posortowany array wejsciowy wedlug cyfry div
        liczenie[ (arr[i] / div) % 10 ]--;
    }

    for (int i = 0; i < rozmiar; i++)
    {
        arr[i] = wyjsciowy[i]; //posortowany array mozna przekopiowac do arrayu ktory podalismy jako argument funkcji
    }
    //tutaj konczy sie przebieg sortu
}

void SortowaniePozycyjne(int arr[], int rozmiar)
{
    
    int max = WezMaksimum(arr, rozmiar);
    //sortowanie przez zliczanie zostanie wywolane tyle razy ile cyfr ma najwieksza z liczb, w tym zadaniu 3 razy
    for (int div = 1; max / div > 0; div *= 10) //poniewaz mamy system dziesiatkowy, to mnozymy div przez 10 przy kazdym przejsciu
    {
        SortowaniePrzezZliczanie(arr, rozmiar, div);
    }
        
}
int main() {
    int arr[] = { 1, 34, 123, 321, 432, 132, 543, 651, 91,
    32, 987, 910, 643, 641, 12, 342, 498, 987, 965, 122, 121, 431, 350 }; 
    const int n = sizeof(arr) / sizeof(arr[0]);
    SortowaniePozycyjne(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    
    
}