#include <iostream>
#include <fstream>
#include <string>

//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2018/formula_od_2015/informatyka/MIN-R2_1P-182.pdf
//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2018/formula_od_2015/Zasady_oceniania/MIN-R2_1P-182_zasady_oceniania.pdf

using namespace std;

int main() {
    //ifstream input("przyklad.txt");
    ifstream input("sygnaly.txt");
    ofstream output("wyniki4.txt");

    string word;
    int line_n = 0;

    string word_max;
    int characters = 0;
    int rep[0xff];

    string answer3;

    string line;
    while (getline(input, line)) {
        line_n++;
        if (line_n % 40 == 0) word += line[9];

        int dif = 0;
        fill_n(rep, 0xff, 0);
        for (char c : line) {
            if (rep[c] == 0) dif++;
            rep[c]++;
        }
        if (characters < dif) {
            characters = dif;
            word_max = line;
        }

        bool b = true;
        for (char c : line)
            for (char cc : line)
                if (abs(c - cc) > 10) { b = false; goto exit; }
    exit:
        if (b) answer3 += line + "\n";
    }

    cout << "4.1: " << word << '\n';
    output << "4.1: " << word << '\n';

    cout << "4.2: " << word_max << ' ' << characters << '\n';
    output << "4.2: " << word_max << ' ' << characters << '\n';

    cout << "4.3:\n" << answer3 << '\n';
    output << "4.3:\n" << answer3 << '\n';

    output.close();
    input.close();
}
