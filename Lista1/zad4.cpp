

#include <iostream>
#include <vector>

struct lnode
{
    int key;
    lnode* next;

};

int nty(int n, lnode* L)
{
    if (n < 0) return 0;
    if (!L->next) return L->key;

    for (int i = 0; i < n; i++)
    {
        if (!L->next) return 0;
        else L = L->next;
    }
    return L->key;
}

int suma(lnode* L)
{
    if (!L->next) return L->key;
    int sum = 0;
    while (L->next)
    {
        sum += L->key;
        L = L->next;
    }
    return sum;
}

lnode* filter(lnode* L)
{
    if (!L->key && !L->next) return L;
    if (L->key < 0) return filter(L->next);
    lnode* L_to_return = L;
    lnode* next;
    while (L->next)
    {
        next = L->next;
        if (next->key < 0) {
            L->next = next->next;
            delete next;
        }
        else L = L->next;

    }
    return L_to_return;
}

int main()
{
    std::vector <int>tab;
    tab.push_back(0);      //0
    tab.push_back(2);       //1
    tab.push_back(3);       //2
    tab.push_back(2);      //3
    tab.push_back(-2);       //4
    tab.push_back(2);       //5
    tab.push_back(-2);       //6

    lnode* test = new lnode();

    lnode* current = new lnode();

    for (size_t i = 0; i < tab.size(); i++)
    {
        if (!test->next) {
            test->key = tab[i];
            test->next = new lnode();
            current = test->next;
        }
        else {
            current->key = tab[i];
            current->next = new lnode();
            current = current->next;
        }
    }
    std::cout << nty(2, test) << std::endl;
    std::cout << suma(test) << std::endl;
    test = filter(test);
    std::cout << suma(test) << std::endl;
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
