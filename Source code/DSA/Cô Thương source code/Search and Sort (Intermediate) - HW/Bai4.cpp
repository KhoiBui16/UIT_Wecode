#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> a;
    int x, mxN = INT_MIN;
    do
    {
        cin >> x;
        if (x != -1 && x != -2)
        {
            if (a.size() < 100000) a.push_back(x);
        }
        else if (x == -1)
        {
            sort(a.begin(), a.end());
            mxN = a.back();
            while (a.back() == mxN) a.pop_back();
        }
    } while (x != -2);
    sort(a.begin(), a.end(), greater<int>());
    cout << a.size() << endl;
    for (auto x: a) cout << x << endl;
}