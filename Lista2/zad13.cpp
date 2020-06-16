#include <iostream>
#include <vector>

struct BST_drzewo
{
    int klucz;
    BST_drzewo* lewe_dziecko = nullptr;
    BST_drzewo* prawe_dziecko = nullptr;
    BST_drzewo(int klucz, BST_drzewo* lewe_dziecko = nullptr, BST_drzewo* prawe_dziecko = nullptr)
        : klucz{klucz}, lewe_dziecko{lewe_dziecko}, prawe_dziecko{prawe_dziecko}
    {
    }
};

template <typename Funkcja>//szablon przyjmujący funkcję dowolnego typu danych
void wykonaj_in_order(BST_drzewo* bst_drzewo, Funkcja funkcja)
{
    if (bst_drzewo == nullptr) return;
    //inorder czyli zasada Left Visit Right, lewe poddrzewo, węzeł, prawe poddrzewo
    wykonaj_in_order(bst_drzewo->lewe_dziecko, funkcja);
    funkcja(bst_drzewo->klucz);
    wykonaj_in_order(bst_drzewo->prawe_dziecko, funkcja);
}

void insert(BST_drzewo*& bst_drzewo, const int wstawiany_klucz)
{
    if (bst_drzewo == nullptr)
    {
        bst_drzewo = new BST_drzewo{wstawiany_klucz, nullptr, nullptr};
        return;
    }
    auto wezel = bst_drzewo;
    while (wezel != nullptr)
    {
        if (wstawiany_klucz < wezel->klucz) //jeśli wstawiany klucz jest mniejszy od węzła to idziemy w lewo
        {
            if (wezel->lewe_dziecko != nullptr)
                wezel = wezel->lewe_dziecko;
            else
            {
                wezel->lewe_dziecko = new BST_drzewo{wstawiany_klucz, nullptr, nullptr};
                return;
            }
        }
        else //a jeśli większy to w prawo
        {
            if (wezel->prawe_dziecko != nullptr)
                wezel = wezel->prawe_dziecko;
            else
            {
                wezel->prawe_dziecko = new BST_drzewo{wstawiany_klucz, nullptr, nullptr};
                return;
            }
        }
    }
}

int main()
{
    
    BST_drzewo* drzewo = nullptr;
    insert(drzewo, 12);
    insert(drzewo, 6);
    insert(drzewo, 3);
    insert(drzewo, 9);
    insert(drzewo, 2);
    insert(drzewo, 4);
    wykonaj_in_order(drzewo, [](int klucz) { std::cout << klucz << " "; });
    std::cout << "\n";
    wykonaj_in_order(drzewo, [](int& klucz) { klucz = -klucz; });
    wykonaj_in_order(drzewo, [](int klucz) { std::cout << klucz << " "; });
    std::cout << "\n";
}
