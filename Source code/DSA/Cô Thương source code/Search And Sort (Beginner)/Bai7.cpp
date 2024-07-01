#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *a, int n)
{
    for (int i=0; i<n; i++)
    {
        int min_idx = i;
        for (int j=i+1; j<n; j++)
        {
            if (a[min_idx] > a[j]) min_idx = j;
        }
        swap(a[i], a[min_idx]);
    }
}

int main()
{
    int n; cin >> n;
    int *a = new int[n];
    for (int i=0; i<n; i++) cin >> a[i];
    clock_t start = clock();
    selectionSort(a, n);
    clock_t finish = clock();
    cout << "Time: " << (finish-start)/CLOCKS_PER_SEC << "ms\n";
    for (int i=0; i<n; i++) cout << a[i] << " ";
}