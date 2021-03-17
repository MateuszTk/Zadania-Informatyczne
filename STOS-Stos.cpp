#include <iostream>
#include <vector>

using namespace std;

#define SUCCESS ":)"
#define FAILURE ":("

int main()
{
    vector<int> stack;
    while (true) {
        char op;
        cin >> op;
        if (op == '+') {
            int value;
            cin >> value;
            if (stack.size() < 10) {
                stack.push_back(value);
                cout << SUCCESS << '\n';
            }
            else {
                cout << FAILURE << '\n';
            }
        }
        else { //'-'
            if (stack.size() > 0) {
                auto endIt = stack.end() - 1;
                cout << *endIt << '\n';
                stack.erase(endIt);
            }
            else {
                cout << FAILURE << '\n';
            }
        }
    }
    return 0;
}
