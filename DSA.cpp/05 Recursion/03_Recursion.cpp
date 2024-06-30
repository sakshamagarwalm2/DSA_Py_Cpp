#include <bits/stdc++.h>
using namespace std;

// Print number till n
// 1. decresing order
// 2. incresing order

void dec(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
    {
        return;
    }

    inc(n - 1);
    cout << n << " ";
}

int main()
{

    int n;
    cin >> n;

    dec(n);

    cout << endl;

    cin >> n;
    inc(n);

    return 0;
}