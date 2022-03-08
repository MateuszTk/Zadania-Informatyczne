#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2020/formula_od_2015/informatyka/MIN-R2_1P-202.pdf
//https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2020/formula_od_2015/Zasady_oceniania/MIN-PR-202_zasady.pdf
//https://cke.gov.pl/egzamin-maturalny/egzamin-w-nowej-formule/arkusze/2020-2/

bool prime(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}


int main()
{
    //ifstream input("przyklad.txt");
    ifstream input("pary.txt");
    ofstream output("wyniki4.txt");
    int n;
    string s;
    
    string ans2 = "\n4.2:\n";

    cout << "4.1:\n";
    output << "4.1:\n";

    int minlen3 = 60;
    vector<pair<int, string>> vec3;

    while (input >> n) {
        input >> s;
        
        if (n % 2 == 0) {
            int maxv = 0, maxa = 0, maxb = 0;
            int tmp = 2;
            while (tmp <= n / 2) {
                int a = tmp;
                int b = n - tmp;
                if (a % 2 == 1 && b % 2 == 1 && prime(a) && prime(b)) {
                    if (maxv <= abs(a - b)) {
                        maxv = abs(a - b);
                        maxa = a;
                        maxb = b;
                    }

                }
                tmp++;
            }
            if (maxa > maxb) swap(maxa, maxb);
            cout << n << ' ' << maxa << ' ' << maxb << '\n';
            output << n << ' ' << maxa << ' ' << maxb << '\n';
        }

        int maxlen = 1;
        char rep = s[0];
        char max_rep = rep;
        int len = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == rep) {
                len++;
            }
            else {
                if (maxlen < len) {
                    maxlen = len;
                    max_rep = rep;
                }
                len = 1;
                rep = s[i];
            }
        }
        if (maxlen < len) {
            maxlen = len;
            max_rep = rep;
        }
        string ts;
        for (int i = 0; i < maxlen; i++) {
            ts += max_rep;
        }
        ans2 += ts + " ";
        ans2 += to_string(maxlen) + "\n";

        if (n == s.length()) {
            if (n < minlen3) {
                minlen3 = n;
                vec3.clear();
                pair<int, string> p(n, s);
                vec3.push_back(p);
            }
            else if(n == minlen3){
                pair<int, string> p(n, s);
                vec3.push_back(p);
            }
        }
    }

    cout << ans2;
    output << ans2;

    string minstr = vec3[0].second;
    for (auto p : vec3) {
        string s = p.second;
        if (s < minstr) minstr = s;
    }

    cout << "\n4.3:\n" << vec3[0].first << ' ' << minstr << '\n';
    output << "\n4.3:\n" << vec3[0].first << ' ' << minstr << '\n';

    input.close();
    output.close();
}
