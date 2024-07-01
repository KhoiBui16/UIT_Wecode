/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

// ###INSERT CODE HERE -

#include <bits/stdc++.h>

using namespace std;

void input(vector<int> &a, int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void qs(vector<int> &a, int l, int r)
{
    int i = l, j = r;
    int m = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(a, l, j);
    if (i < r) qs(a, i, r);
}

int main()
{
    int n;
    vector<int> a(100001);
    input(a, n);
    int mex = 0;
    qs(a, 0, n-1);
    for (int i=0; i<n; i++) if (a[i] == mex) mex++;
    cout << mex;
}