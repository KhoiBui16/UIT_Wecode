#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Parition(vector<string>& arr, int start, int end)
{
    string pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j].size() < pivot.size() || (arr[j].size() == pivot.size() && arr[j] < pivot))
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void QuickSort(vector<string>& arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int pivot = Parition(arr, start, end);
    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

void QuickSort(vector<string>& arr, int n)
{
    QuickSort(arr, 0, n - 1);
}

int Parition(vector<pair<string, int >>& list, int start, int end)
{
    pair <string, int> pivot = list[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (list[j].second > pivot.second)
        {
            i++;
            swap(list[i], list[j]);
        }
        else if (list[j].second == pivot.second)
        {
            if (list[j].first.size() < pivot.first.size() || (list[j].first.size() == pivot.first.size() && list[j].first < pivot.first))
            {
                i++;
                swap(list[i], list[j]);
            }
        }
    }
    i++;
    swap(list[i], list[end]);
    return i;
}

void QuickSort(vector<pair<string, int>>& list, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int pivot = Parition(list, start, end);
    QuickSort(list, start, pivot - 1);
    QuickSort(list, pivot + 1, end);
}

void QuickSort(vector<pair<string, int>>& list, int n)
{
    QuickSort(list, 0, list.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    QuickSort(arr, n);

    arr.push_back("\0");
    vector<pair<string, int>> list;

    int count = 1;
    for (int i = 1; i < n + 1; i++)
    {
        
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            list.push_back({arr[i - 1], count});
            count = 1;
        }
    }

    QuickSort(list, n);

    for (pair<string, int> it : list)
        cout << it.first << " " << it.second << "\n";

    return 0;
}

// còn bị TLE 3 test