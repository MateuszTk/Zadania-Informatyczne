#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        float vt, v = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> vt;
            v += 1.0f / vt;
        }
        cout << roundf((float)n / v) << '\n';
    }

    return 0;
}

/*
2
2 50 50
2 60 40

*/