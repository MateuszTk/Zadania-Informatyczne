#include <iostream>

using namespace std;

int main()
{
    while (true) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;
        switch (op) {
        case '+':
            cout << a + b << '\n';
            break;

        case '-':
            cout << a - b << '\n';
            break;

        case '*':
            cout << a * b << '\n';
            break;

        case '/':
            cout << a / b << '\n';
            break;

        case '%':
            cout << a % b << '\n';
            break;

        default:
            break;
        }
    }
    return 0;
}

