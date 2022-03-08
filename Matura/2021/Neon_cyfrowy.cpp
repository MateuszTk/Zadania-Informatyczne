#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

int main() {
	//ifstream reader("przyklad.txt");
	ifstream reader("instrukcje.txt");
	ofstream output("wyniki4.txt");
	string line;
	string napis = "";

	string pinst = "";
	map<string, pair<int, int>> m = { {"DOPISZ", make_pair(0, 0)}, {"ZMIEN", make_pair(0, 0)}, {"USUN", make_pair(0, 0)}, {"PRZESUN", make_pair(0, 0)} };
	int dopisy[256];
	for (int i = 0; i < 256; i++)
		dopisy[i] = 0;
	string inst = "";
	while (getline(reader, line, '\n')) {
		inst = line.substr(0, line.find(' '));
		if (inst == pinst)
			m[inst].first++;
		else {
			if (m[inst].second < m[inst].first)
				m[inst].second = m[inst].first;
			m[inst].first = 1;
			pinst = inst;
		}

		if (inst == "DOPISZ") {
			char c = line[inst.length() + 1];
			napis += c;
			dopisy[(int)c]++;
		}

		else if (inst == "ZMIEN") {
			char c = line[inst.length() + 1];
			napis[napis.length() - 1] = c;
		}

		else if (inst == "USUN") {
			if (napis.length() > 0)
				napis.erase(napis.end() - 1);
		}

		else if (inst == "PRZESUN") {
			char c = line[inst.length() + 1];
			int pos = napis.find(c);
			if (pos >= 0) {
				c++;
				if (c > 'Z')
					c = 'A';
				napis[pos] = c;
			}
		}
	}
	if (m[inst].second < m[inst].first)
		m[inst].second = m[inst].first;
	reader.close();

	cout << "4.1: " << napis.length() << '\n';
	output << "4.1: " << napis.length() << '\n';
	int maxv = 0;
	string maxs;
	for (auto kv : m) {
		if (kv.second.second > maxv) {
			maxv = kv.second.second;
			maxs = kv.first;
		}
	}
	cout << "4.2: " << maxs << " " << maxv << '\n';
	output << "4.2: " << maxs << " " << maxv << '\n';
	char maxc = ' ';
	int maxp = 0;
	for (int i = 0; i < 256; i++) {
		if (maxp < dopisy[i]) {
			maxc = (char)i;
			maxp = dopisy[i];
		}
	}
	cout << "4.3: " << maxc << ' ' << maxp << '\n';
	output << "4.3: " << maxc << ' ' << maxp << '\n';

	cout << "4.4: " << napis;
	output << "4.4: " << napis;

	return 0;
}
