#include <iostream>
#include <string>

using namespace std;

const char symbols[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

string fromInt(int i, int to) {
	string res;
	char sign = '+';
	if (i < 0) { sign = '-'; i *= -1; }

	for (int ii = 0; i > 0; ii++) {
		res += (symbols[(i % to)]);
		i /= to;
	}
	if (sign == '-') res += sign;
	res = string(res.rbegin(), res.rend());

	return res;
}

int main()
{
    int a, b;
	cin >> a;
	while (a-- > 0) {
		std::cin >> b;
		std::cout << fromInt(b, 16) << ' ' << fromInt(b, 11) << '\n';
	}
	return 0;
}
