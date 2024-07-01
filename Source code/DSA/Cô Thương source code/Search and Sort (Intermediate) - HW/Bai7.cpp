/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first) return p1.first < p2.first;
    else return p1.second > p2.second;
}

int partition(vector<pair<int, int>> &a, int l, int r)
{
    int i = l;
    pair <int, int> mid = a[r];
    for (int j=l; j<=r-1; j++)
    {
        if (comp(a[j], mid))
        swap(a[i++], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

void qs(vector <pair<int, int>> &a, int l, int r)
{
    if (l >= r) return;
    int p = partition(a, l, r);
    qs(a, l, p-1);
    qs(a, p+1, r);
}

void output(vector<pair<int, int>> a)
{
    for (auto i: a) cout << i.first << " " << i.second << endl;
}

int main()
{
    int n; cin >> n;
    vector <pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
    srand(time(NULL));
    qs(a, 0, n-1);
    output(a);
}