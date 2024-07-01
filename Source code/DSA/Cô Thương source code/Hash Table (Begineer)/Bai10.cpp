#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    map <string, string> mp;
    map <string, int> Hash;
    for (int i=0; i<n; i++) 
    {
        string idx, s;
        cin >> idx >> s;
        Hash[idx] = 1;
        mp[idx] = s;
    }
    for (int i=0; i<q; i++) 
    {
        string s; cin >> s;
        if (Hash[s] == 1) cout << mp[s];
        else cout << "Chua Dang Ky!";
        cout << '\n';
    }
}