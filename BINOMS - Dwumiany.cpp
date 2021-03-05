//https://pl.spoj.com/problems/BINOMS/

#include <iostream>

using namespace std;

typedef unsigned int uint;

uint subsets(uint n, uint k)
{
    uint res = 1;
    for (uint i = 1; i <= k; i++)
    {
        res = (res * (n - i + 1)) / i;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    uint n, k;

    while (t-- > 0)
    {
        cin >> n >> k;
        cout << subsets(n, k) << '\n';
    }

    return 0;
}
