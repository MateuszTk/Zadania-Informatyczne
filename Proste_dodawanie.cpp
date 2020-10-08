#include <iostream>
#include <string>

using namespace std;

int main()
{
	short c;
	int n;
	cin >> c;
	long long int wynik;
	long long int tmp;
	string output = "";

	while (c-- > 0)
	{
		cin >> n;
		wynik = 0;
		while (n-- > 0)
		{
			cin >> tmp;
			wynik += tmp;
		}
		output += to_string(wynik) + '\n';
	}
	cout << output;
}

//https://pl.spoj.com/problems/RNO_DOD/







