#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, x, y;
        cin >> n >> x >> y;
        for (int i = x; i < n; i += x) {
            if (i % y != 0) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
