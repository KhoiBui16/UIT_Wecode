/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

// ###INSERT CODE HERE -

#include <bits/stdc++.h>

using namespace std;

int n, MAX = INT_MIN;
vector <int> a;
map <int, int> mp;

void input(vector <int> &a, int &n)
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
        mp[x] = 1;
        if (MAX < x) MAX = x;
    }
}

int main()
{
    input(a, n);
    int mex = 0;
    for (int i=0; i<=MAX; i++)
    {
        if (mp[i] == 1) mex++;
        else break;
    }
    cout << mex;
}