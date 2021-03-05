#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string u, v;

int lcs_len(const int m, const int n)
{
	int** L = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		L[i] = new int[n + 1];
	}

    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (u[i - 1] == v[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
	i = L[m][n];
	for (int i = 0; i < m + 1; i++)
	{
		delete L[i];
	}
    return i;
}

int main()
{
	int n, m, mm;
	cin >> n;
	while (n-- > 0)
	{
		cin >> m;
		cin >> u;
		cin >> mm;
		cin >> v;

		cout << lcs_len(m, mm) << '\n';
	}
	return 0;
}
