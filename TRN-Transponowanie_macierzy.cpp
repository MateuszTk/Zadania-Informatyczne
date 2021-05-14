#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    const int len = n * m;
    int* matrix = new int[len];
    for (int i = 0; i < len; i++)
        cin >> matrix[i];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++)
            cout << matrix[y + x * n] << ' ';
        cout << '\n';
    }
    return 0;
}
