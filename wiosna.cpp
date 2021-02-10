#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Item
{
    short id;
    short value;
    short size;
    bool used = false;

    Item(short _value, short _size, short _id)
    {
        id = _id;
        value = _value;
        size = _size;
    }
};

struct Backpack
{
    vector<Item> backpack;
    int size = 0;
    int value = 0;
};

void pack(vector<Item>& items, Backpack& bp1)
{
    unsigned long long mask = 0, combination = 0;
    int max = 0;
    int value = 0, size = 0;
    int ii = pow(2, items.size());
    //looping through each item
    while (mask != ii)
    {
        mask++;
        value = 0;
        size = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].used == false && (((mask >> i) & 1) == 1))
            {
                value += items[i].value;
                size += items[i].size;
            }
        }

        if (size > bp1.size) continue;
        if (value > max)
        {
            max = value;
            combination = mask;
        }
    }
    for (int i = 0; i < items.size(); i++)
    {
        if (((combination >> i) & 1) == 1)
        {
            bp1.backpack.push_back(items[i]);
            bp1.value += items[i].value;
            items[i].used = true;
        }
    }
}

int main()
{
    Backpack bpS, bpJ;
    short n;
    cin >> n >> bpJ.size >> bpS.size;
    vector<Item> items, backpackS, backpackJ;
    items.reserve(n);

    short value, size;
    for (int i = 0; i < n; i++)
    {
        cin >> value >> size;
        items.emplace_back(value, size, i + 1);
    }

    pack(items, bpJ);
    pack(items, bpS);

    cout << bpJ.value + bpS.value << '\n';
    for (Item it : bpJ.backpack)
    {
        cout << it.id << ' ';
    }
    cout << '\n';
    for (Item it : bpS.backpack)
    {
        cout << it.id << ' ';
    }
    return 0;
}
