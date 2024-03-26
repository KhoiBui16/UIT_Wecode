#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i; 
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        
        if (arr[min] < arr[i])
        {
            swap(arr[i], arr[min]);
            for (int i = 0; i < n; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SelectionSort(arr, n);

    return 0;
}