#include <iostream>
#include <string>

using namespace std;

int s;

int Palindrome(int input)
{
	string tmp = "";
	string inputS = to_string(input);
	for (int i = inputS.length() - 1; i >= 0; i--)
	{
		tmp += inputS[i];
	}

	if (tmp == inputS)
	{
		return input;
	}
	else
	{
		int sum = atoi(tmp.c_str()) + input;
		s++;
		return Palindrome(sum);
	}

}

int main()
{
	string answer = "";
	short t;
	int n;
	cin >> t;

	while (t-- > 0)
	{
		s = 0;
		cin >> n;
		answer += to_string(Palindrome(n));
		answer += " " + to_string(s) + '\n';
	}
	cout << answer;
	return 0;
}

//https://pl.spoj.com/problems/BFN1/