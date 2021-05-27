#include <iostream>

using namespace std;

#define index( x, y, k ) ( y * k + x )

int main()
{
	int t;
	cin >> t;
	while (t-- > 0) {
		int l, k;
		cin >> l >> k; //y x
		int* arr = new int[l * k];
		for (int y = 0; y < l; y++) {
			for (int x = 0; x < k; x++) {
				cin >> arr[index(x, y, k)];
			}
		}

		//cout << '\n';
		float centx = (k - 1) * 0.5f;
		for (int y = 0; y < l; y++) {
			for (int x = 0; x < k; x++) {
				int xo = x, yo = y;
				int st = (yo > (float)((l - 1) * 0.5f)) ? (l - 1 - y) : y;
				if (yo < (float)((l - 1) * 0.5f)) {
					if (xo + 1 < k)
						xo++;
				}
				else if (yo > (float)((l - 1) * 0.5f)) {
					if (xo > 0)
						xo--;
				}

				if (x <= st && x != y) {
					xo = x;
					yo--;
				}
				if (x >= k - st - 1 && y != l - (k - x)) {
					xo = x;
					yo++;
				}

				if (centx == (float)x && y >= centx && y < l - centx) {
					xo = x;
					yo = y;
				}

				cout << arr[index(xo, yo, k)] << ' ';
			}
			cout << '\n';
		}

		delete[] arr;
	}
	return 0;
}

//tests

/*1
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/

/*
1
5 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
*/

/*
1
5 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
17 18 19 20
*/

/*
1
4 5
0 1 2 3 4
5 6 7 8 9
10 11 12 13 14
15 16 17 18 19
*/
