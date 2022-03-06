#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int factorial(int n) {
    int fact = 1;
    while(n > 0) {
        fact *= n;
        n--;
    }
    return fact;
}

int nwd(int a, int b) {
    /*if (a == 1 || b == 1) return 1;
    for (int i = max(a, b); i > 0 ; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;*/
    int k = 0;
    while (b != 0) {
        k = b;
        b = a % b;
        a = k;
    }
    return a;
}

int main()
{
    //ifstream input("przyklad.txt");
    ifstream input("liczby.txt");
    ofstream output("wyniki4.txt");

    int q1 = 0;
    vector<int> q2;

    vector<int> values;

    int num;
    while (input >> num) {
        values.push_back(num);
        int tmp = num;
        while (tmp % 3 == 0)
            tmp /= 3;
        if (tmp == 1) q1++;

        int l = log10(num) + 1;
        int sum = 0;
        tmp = num;
        while (l-- > 0) {
            sum += factorial(tmp % 10);
            tmp /= 10;
        }
        if (sum == num) q2.push_back(num);       
    }

    cout << "4.1: " << q1 << '\n' << "4.2:\n";
    output << "4.1: " << q1 << '\n' << "4.2:\n";

    for (int v : q2) {
        cout << v << '\n';
        output << v << '\n';
    }

    int max_length = 0;
    int first = 0;
    int qnwd = 0;
    int size = values.size();
    for (int x = 0; x < size; x++) {
        int nwdv = values[x];
        int length = 1;
        int n = x + 1;
        while (n < size) {
            int tmp_nwdv = nwd(nwdv, values[n]);
            if (tmp_nwdv > 1) {
                nwdv = tmp_nwdv;
                length++;
            }
            if (tmp_nwdv <= 1 || n == size - 1) {
                if (length > max_length) {
                    max_length = length;
                    qnwd = nwdv;
                    first = values[x];
                }
                break;
            }
            
            n++;
        }
    }

    cout << "4.3: (pierwsza liczba ciagu): " << first << " (dlugosc ciagu): " << max_length << " (najwiekszy wspolny dzielnik): " << qnwd << '\n';
    output << "4.3: (pierwsza liczba ciagu): " << first << " (dlugosc ciagu): " << max_length << " (najwiekszy wspolny dzielnik): " << qnwd << '\n';

    input.close();
    output.close();
}
