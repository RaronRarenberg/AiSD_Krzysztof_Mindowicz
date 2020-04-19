#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream arg_0;
    int tab[256]{ 0 };
    char znak;
    arg_0.open("zad7.txt");

    while (arg_0 >> znak)
    {
        tab[(int)znak]++;
    }
    for (int i = 0; i < 256; i++)
    {
        cout << (char)i << " " << tab[i] << endl;
    }
    return 0;
}