#include <iostream>

using namespace std;

int main() {
    int t, n, i;
    int arr[100];
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i < n; i += 2) {
            cout << arr[i] << ' ';
        }
        for (int i = 0; i < n; i += 2) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
