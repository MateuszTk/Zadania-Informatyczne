#include <iostream>
#include <algorithm>

using namespace std;

int lis(int* arr, int n)
{
    int* lis_a = new int[n];

    lis_a[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis_a[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j])
                lis_a[i] = max(lis_a[j] + 1, lis_a[i]);
    }

    int ret = *max_element(lis_a, lis_a + n);
    delete lis_a;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    int* input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cout << lis(input, n);
    return 0;
}
