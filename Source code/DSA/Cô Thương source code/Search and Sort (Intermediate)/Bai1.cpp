#include <bits/stdc++.h>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

void inputArray(int* a, int n)
{
    for (int i=0; i<n; i++) cin >> a[i];
}

void qs(int *a, int l, int r, int &cnt)
{
    int i = l, j = r, mid = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] > mid) i++;
        while (a[j] < mid) j--;
        if (i<=j) 
        {
            cnt++;
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) qs(a, l, j, cnt);
    if (i < r) qs(a, i, r, cnt);
}

void outputArray(int *a, int n)
{
    for (int i=0; i<n; i++) cout << a[i] << " ";
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];
    inputArray(a, n);
    int l = 0, r = n-1, cnt = 0;
    qs(a, l, r, cnt);
    cout << "Sorted Array: ";
    outputArray(a, n);
    cout << "\nNumber of times to swap 2 numbers: " << cnt;
}