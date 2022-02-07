
#include <iostream>
#include <fstream>
#include <algorithm>

//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2017/formula_od_2015/informatyka/MIN-R2_1P-172.pdf

using namespace std;

int main()
{
    //ifstream input("przyklad.txt");
	ifstream input("dane.txt");
	int minv = 255, maxv = 0;
	int pix[320][200] = {0};
	int ln2 = 0;
	for (int y = 0; y < 200; y++) {
		bool b = true;
		for (int x = 0; x < 320; x++) {
			int v;
			input >> v;
			minv = min(v, minv);
			maxv = max(v, maxv);

			pix[x][y] = v;
			if (x >= 320 / 2 && pix[320 - x - 1][y] != v && b) {
				ln2++;
				b = false;
			}
		}
	}
	input.close();

	cout << "Zad 6.1:\n" << "najciemniejszy: " << minv << "\nnajjasniejszy: " << maxv << '\n';
	cout << "Zad 6.2: " << ln2 << '\n';

	int c3 = 0;
	for (int y = 0; y < 200; y++) {
		for (int x = 0; x < 320; x++) {
			bool b = false;
			if (x > 0 && abs(pix[x][y] - pix[x - 1][y]) > 128) b = true;
			if (x < 319 && abs(pix[x][y] - pix[x + 1][y]) > 128) b = true;
			if (y > 0 && abs(pix[x][y] - pix[x][y - 1]) > 128) b = true;
			if (y < 199 && abs(pix[x][y] - pix[x][y + 1]) > 128) b = true;
			if (b) c3++;
		}
	}

	cout << "Zad 6.3: " << c3 << '\n';

	int len4 = 1;
	for (int x = 0; x < 320; x++) {
		int v = pix[x][0];
		int len = 1;
		for (int y = 1; y < 200; y++) {
			if (pix[x][y] == v) len++;
			else {
				len4 = max(len, len4);
				len = 1;
				v = pix[x][y];
			}
		}
	}

	cout << "Zad 6.4: " << len4 << '\n';

	return 0;
}
