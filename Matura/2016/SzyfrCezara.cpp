#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2016/formula_od_2015/MIN-R2_1P-162.pdf
int main()
{
    int k = 107;

    ifstream input("dane_6_1.txt");
    ofstream output("odp_6_1.txt");
    string line;
    while (getline(input, line)) {
        for (int i = 0; i < line.length(); i++) {
            line[i] = ((line[i] - 'A' + k) % ('Z' - 'A' + 1)) + 'A';
        }
        //cout << line << '\n';
        output << line << '\n';
    }
    input.close();
    output.close();


    ifstream input2("dane_6_2.txt");
    ofstream output2("odp_6_2.txt");
    int key;
    while (input2 >> line >> key) {
        key %= ('Z' - 'A' + 1);
        for (int i = 0; i < line.length(); i++) {
            line[i] = line[i] - key;
            if (line[i] < 'A')
                line[i] += ('Z' - 'A' + 1);
        }
        //cout << line << '\n';
        output2 << line << '\n';
    }
    input2.close();
    output2.close();


    ifstream input3("dane_6_3.txt");
    ofstream output3("odp_6_3.txt");
    string worda, wordb;
    while (input3 >> worda >> wordb) {
        int key = wordb[0] - worda[0];
        for (int i = 1; i < worda.length(); i++) {
            if (abs(wordb[i] - worda[i]) + abs(key) != 26 && key != wordb[i] - worda[i]) {
                //cout << worda << '\n';
                output3 << worda << '\n';
                break;
            }
        }
        
    }
    input3.close();
    output3.close();
}
