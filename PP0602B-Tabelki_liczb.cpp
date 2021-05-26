#include <iostream>

using namespace std;

#define index( x, y, k ) ( y * k + x )

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        int l, k;
        cin >> l >> k;//y x
        int* arr = new int[l * k];
        for (int y = 0; y < l; y++) {
            for (int x = 0; x < k; x++) {
                cin >> arr[index(x, y, k)];
            }
        }

        for (int y = 0; y < l; y++) {
            for (int x = 0; x < k; x++) {
                int xo = x, yo = y;
                /*if (yo < (float)((l - 1) * 0.5f)) {
                    if(xo + 1 < k)
                        xo++; 
                }
                else if (yo > (float)((l - 1) * 0.5f)) {
                    if (xo > 0)
                        xo--; 
                }*/

                if (x == 0 && y > 0) {
                    xo = 0;
                    yo--;
                }
                if (x == k - 1 && y < l - 1) {
                    xo = k - 1;
                    yo++;
                }
                if (y == l - 1 && x > 0) {
                    xo--;
                    yo = l - 1;
                }
                if (y == 0 && x < k - 1) {
                    yo = 0;
                    xo++;
                }


                cout << arr[index(xo, yo, k)] << ' ';
            }
            cout << '\n';
        }


        delete[] arr;
    }
    return 0;
}
/*1
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/