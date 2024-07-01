#include <bits/stdc++.h>
#define pb push_back

using namespace std;
typedef long long ll;


int binarySearch(int *a, int x, int l, int r)
{
    while (l <= r)
    {
        int m = l+(r-l)/2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m+1;
        else r=m-1;
    }
    return l;
}

int main()
{
    int *a = new int[10000001];
    vector <int> position;
    int n = 0;
    while (1)
    {
        int choice, x;
        cin >> choice;
        if (!choice) break;
        cin >> x;
        if (choice == 1)
        {
            int loc = binarySearch(a, x, 0, n-1);
            if (loc == n || a[loc] != x) 
            {
                for (int i=n-1; i>= loc; i--)
                {
                    a[i+1] = a[i];
                }
                a[loc] = x;
                n++;
            }
        }
        else if (choice == 2)
        {
            int loc = binarySearch(a, x, 0, n-1);
            if (loc < n && a[loc] == x) 
                position.pb(loc+1);
            else position.pb(0);
        }
    }
    for (auto x: position) cout << x << "\n";
}