#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            swapped = true;
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        if (swapped == false)
            return;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    BubbleSort(arr, n);

    return 0;
}