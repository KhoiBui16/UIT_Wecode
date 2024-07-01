#include <bits/stdc++.h>

using namespace std;


void Solve(int n, queue<int> &q, vector <int> a)
{
    int cnt_pair = 1;
    q.push(a[0]);
    for (int i=1; i<n; i++)
    {
        if (a[i] > q.top()) cnt_pair++;
    }
    cout << cnt_pair;
}

int main()
{
    int n; cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    queue<int> h;
    Solve(n, h, a);
}