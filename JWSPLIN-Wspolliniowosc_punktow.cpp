#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        float x, y, xa, ya, xb, yb;
        cin >> x >> y;
        cin >> xa >> ya;
        cin >> xb >> yb;
        xa = abs(x - xa);
        ya = abs(y - ya);
        xb = abs(x - xb);
        yb = abs(y - yb);

        if ((ya == 0 && yb == 0) || xa / ya == xb / yb) {
            cout << "TAK\n";
        }
        else {
            cout << "NIE\n";
        }

    }

    return 0;
}

/*
5
1 2 3 4 5 6
1 3 1 4 1 -3
1 2 -3 4 3 9
2 -1 3 -1 -4 -1
0 0 0 0 0 0
*/
