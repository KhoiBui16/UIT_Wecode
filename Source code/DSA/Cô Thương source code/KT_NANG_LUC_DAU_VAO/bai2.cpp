#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void inputArray(int a[], int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void outputArray(int a[], int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

bool scp(int x)
{
    int a = sqrt(x);
    return a*a == x;
}

int main()
{
    init();
    int n; cin >> n;
    if (n < 1)
    {
        cout << "Mang rong.";
        return 0;
    }
    int a[n];
    inputArray(a, n);
    outputArray(a, n);
    cout << endl;
    int j = 0, cnt = 0;
    int b[n];
    for (int i=0; i<n; i++)
    {
        if (scp(a[i]) && (i%2 & 1))
        {
            cnt++;
            b[j++] = a[i];
        }
    }
    if (cnt == 0) cout << "Mang khong chua so chinh phuong." << endl;
    else
    {
        for (int i=0; i<j; i++) cout << b[i] << " ";
        cout << endl << cnt << endl;
    }
}
