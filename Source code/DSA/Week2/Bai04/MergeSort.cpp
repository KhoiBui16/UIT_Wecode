#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
    int m = left; // this is idx for the left subArray
    int n = mid + 1; // this is the idx for the right subArray
    int k = 0;  // this is idx for them  all together
    int* temp = new int[right - left + 1];

    while (!((m > mid) && (n > right)))
    {
        if ((arr[m] < arr[n] && m <= mid && n <= right) || (n > right))
        {
            temp[k++] = arr[m++];
        }
        else
        {
            temp[k++] = arr[n++];
        }
    }

    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
    delete[] temp;
}

void MergeSort(int arr[], int left, int right, int n)
{
    // base case
    if (left < right)
    {
        int mid = (left + right) / 2;   
        // this is the subArray on the left
        MergeSort(arr, left, mid, n);  

        // this is the subArray on the right
        MergeSort(arr, mid + 1, right, n); 

        // After sort the subArray of two  parts, merge them into one part.
        Merge(arr, left, mid, right); 
        
        for (int i = 0; i < n; i++)
        {
            if (i == left)
            {
                cout << "[ ";
                
            }
            cout << arr[i] << " ";
            if (i == right)
                cout << "] ";
        }
        cout << endl;       
    } 
}

void MergeSort(int arr[], int n)
{
    MergeSort(arr, 0, n - 1, n);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, n);

    return 0;
}