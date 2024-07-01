#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    init();
    int n; cin >> n;
    char a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    vector <char> b(27, 0);
    for (int i=0; i<n; i++)
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) b[(int)(toupper(a[i]) - 'A')+1]++;
    }
    int cnt = 26;
    for (int i=1; i<=26; i++)
    {
        if (b[i] != 0) cnt--;
    }
    cout << cnt;
}
