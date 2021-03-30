#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int* memory = new int[10];
    memset(memory, 0, 10 * sizeof(int));
    while (true) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;
        switch (op) {
        case '+':
            cout << memory[a] + memory[b] << '\n';
            break;

        case '-':
            cout << memory[a] - memory[b] << '\n';
            break;

        case '*':
            cout << memory[a] * memory[b] << '\n';
            break;

        case '/':
            cout << memory[a] / memory[b] << '\n';
            break;

        case '%':
            cout << memory[a] % memory[b] << '\n';
            break;

        case 'z':
            memory[a] = b;
            break;
        }
    }

    return 0;
}

