#include <iostream>

using namespace std;

char Solutions(const float a, const float b, const float c)
{
    const float delta = (b * b - 4 * a * c);
    if (delta > 0)
        return '2';
    else if (delta == 0)
        return '1';
    else
        return '0';
}

int main()
{
    while (true)
    {
        float a, b, c;
        cin >> a >> b >> c;
        cout << Solutions(a, b, c) << '\n';
    }
    return 0;
}
