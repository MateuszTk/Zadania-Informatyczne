#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

inline int pos2Id(int x, int y)
{
    return y * 400 + x;
}

void createNLevelFan(char* fan, int n, bool direction)
{
    int ndir = (direction) ? n : 0;
    int ndir2 = (direction) ? 0 : n;
    for (int y = 0; y < n; y++)
    {
        fan[pos2Id(200 - n, y + 200 - ndir)] = '*';
    }   
    for (int y = 0; y < n; y++)
    {
        fan[pos2Id(200 + n - 1, y + 200 - ndir2)] = '*';
    }
    for (int x = 0; x < n; x++)
    {
        fan[pos2Id(x + 200 - ndir2, 200 - n)] = '*';
    }
    for (int x = 0; x < n; x++)
    {
        fan[pos2Id(x + 200 - ndir, 200 + n - 1)] = '*';
    }

}

void printFan(char* fan, int n)
{
    for (int x = 200 - n; x < 200 + n; x++)
    {
        for (int y = 200 - n; y <  200 + n; y++)
        {
            cout << fan[pos2Id(x, y)];
        }
        cout << '\n';
    }
}

int main()
{
    short r;
    const int fan_size = 400 * 400;
    char* fan = new char[fan_size];
    int prev_size = 0;

    while(true)
    {
        cin >> r;
        if (r == 0) break;
        memset(fan, '.', fan_size);
        //createNLevelFan(fan, r);
        const bool dir = (r / abs(r) == -1);
        r = abs(r);
        for (int i = 1; i <= r; i++)
        {
            createNLevelFan(fan, i, dir);
        }
        printFan(fan, r);
    }

    return 0;
}

