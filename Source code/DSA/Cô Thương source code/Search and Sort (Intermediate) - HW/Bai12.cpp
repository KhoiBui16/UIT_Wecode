#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int res = 1;
    while (n >= res)
    {
        n -= res;
        res++;
    }
    cout << --res;
}