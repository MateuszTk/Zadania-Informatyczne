#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i = 0, p = 42, n;
    while (i < 3) {
        cin >> n;
        if (n == 42 && p != 42) i++;
        v.push_back(n);
        p = n;
    }
    cout << '\n';
    for (int e : v) {
        cout << e << '\n';
    }
    return 0;
}
