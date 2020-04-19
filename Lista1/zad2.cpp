#include <iostream>

double funkcja(double x)
{
    return x - 0.5; //trywialny przyklad, pierwiastkiem jest 0.5
}

int main()
{
    //warunki poczatkowe
    double x0 = -3;
    double x1 = 3;
    double epsilon = 0; //dokladnosc mozna zmieniac, mozna tez ustawic zero

    double f0 = funkcja(x0);
    double f1 = funkcja(x1);

    double x = (x0 + x1) / 2;
    double f = funkcja(x);

    //petla programu
    while (abs(f) > epsilon)
    {
        if( f0 * f < 0) //jesli lewa granica i srodek maja rozne znaki
        {
            x1 = x; //to prawa granica sie przesuwa w miejsce srodka
        }
        else
        {
            x0 = x; //i odwrotnie
        }
        x = (x0 + x1) / 2;
        f = funkcja(x);
    }
    std::cout << "pierwiastkiem funkcji jest:" << x << std::endl;
    return 0;
}
