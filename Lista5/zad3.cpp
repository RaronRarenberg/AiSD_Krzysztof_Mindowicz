#include<iostream>

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


        

int main() {
    int arr[] = { 1, 34, 123, 321, 432, 132, 543, 651, 91,
    32, 987, 910, 643, 641, 12, 342, 498, 987, 965, 122, 121, 431, 350 }; 
    const int n = sizeof(arr) / sizeof(arr[0]);
    int c = 1; //1 oznacza sortowanie wedlug jednosci, 10 oznacza dziesiatki, 100 oznacza setki itd...
    SortowaniePrzezZliczanie(arr, n, c);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
}