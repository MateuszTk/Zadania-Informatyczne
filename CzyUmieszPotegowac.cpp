#include <iostream>
#include <vector>

using namespace std;

struct liczby
{
    int a;
    int b;
};

int JednosciPotegi(int _a, int _b)
{
    int wynik = 1;
    while (_b-- > 0)
    {
        wynik = (wynik * _a) % 10;
    }
    return wynik;
}

int main()
{
    short d;

    cin >> d;
    vector<liczby> wyniki;
    liczby nowyZestaw;

    while (d-- > 0)
    {
        cin >> nowyZestaw.a;
        cin >> nowyZestaw.b;
        wyniki.push_back(nowyZestaw);
    }

    for (int i = 0; i < wyniki.size(); i++)
    {
        cout << JednosciPotegi(wyniki[i].a, wyniki[i].b) << endl;
    }
}


