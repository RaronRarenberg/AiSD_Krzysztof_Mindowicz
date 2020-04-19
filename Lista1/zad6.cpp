#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


void PobierzDane(std::string nazwa_pliku, std::vector<int> &wspolczynniki)
{
    std::ifstream plik(nazwa_pliku);
    std::string slowo;

    while (plik >> slowo)
    {
        wspolczynniki.push_back(std::stoi(slowo));
    }
    plik.close();
}

void ZapiszDane(std::vector<int> wektor)
{
    std::ofstream plik("c.txt");
    for (auto liczba : wektor)
    {
        plik << liczba << " ";
    }
}

int main()
{
   int stopien = 0;
   std::vector<int> wspolczynniki;

   int stopien2 = 0;
   std::vector<int> wspolczynniki2;

   PobierzDane("a.txt",wspolczynniki);
   PobierzDane("b.txt", wspolczynniki2);

   stopien = wspolczynniki[0];
   stopien2 = wspolczynniki2[0];
   wspolczynniki.erase(wspolczynniki.begin());
   wspolczynniki2.erase(wspolczynniki2.begin());
   
   std::vector<int> wspolczynniki3;
   int stopien3 = wspolczynniki.size() + wspolczynniki2.size() - 1;
   wspolczynniki3.resize(stopien3, 0);
   for (int i = 0; i < wspolczynniki.size(); i++)
   {
       for (int j = 0; j < wspolczynniki2.size(); j++)
       {
           wspolczynniki3[i + j] += wspolczynniki[i] * wspolczynniki2[j];
       }
   }
   
   wspolczynniki3.insert(wspolczynniki3.begin(), stopien3);
   ZapiszDane(wspolczynniki3);
   std::cout << "Mozesz obejrzec swoj nowy plik o nazwie c.txt";
   return 0;
}