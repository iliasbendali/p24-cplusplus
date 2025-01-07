#include <iostream>
#include <stdexcept>
#include <stack>

class IntStack
{
private:
    int nb; 
    int size;
    int *tab;
    int tab[10];

public:
    IntStack(int taille_initiale = 10) : size(taille_initiale), nb(0){
        if (taille_initiale <= 0){
            throw std::invalid_argument("La capacité initiale doit être positive");
        }
        tab = new int[size];
    }
            
    ~IntStack(){
        delete [] tab;
    }

    IntStack (const IntStack& autre) {
        tab = new int[size]; 
        for (int i = 0; i < size; ++i) {
            tab[i] = autre.tab[i];  
        }
    }

    IntStack operator=(const IntStack& autre){
        size = autre.size;
        nb = autre.nb;
        tab = new int[size];
        for (int i = 0; i < size; ++i){
            tab[i] = autre.tab[i];
        }
    }

    bool is_empty()
    {
        if (nb == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_full()
    {
        if (nb == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int e)
    {
        if (is_full())
        {
            exit(0);
        }
        else
        {
            tab[nb] = e;
            nb = nb + 1;
        }
    }

    int get_top()
    {
        if (is_empty())
        {
            exit(0);
        }
        else
        {
            int a;
            a = tab[nb - 1];
            return a;
        }
    }

    int pop()
    {
        if (is_empty())
        {
            exit(0);
        }
        else
        {
            int a;
            a = tab[nb - 1];
            nb = nb - 1;
            return a;
        }
    }

    void print()
    {
        std::cout << "[";
        for (int i = 0; i < nb; i++)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << "] ";
    }
};

int main()
{
    IntStack i(10);
    IntStack j(i);
    j=i;
    j.operator=(i);
}