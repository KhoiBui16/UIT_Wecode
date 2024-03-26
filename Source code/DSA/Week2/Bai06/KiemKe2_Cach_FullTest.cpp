#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Merge(vector<string>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (L[i].size() < R[j].size() || (L[i].size() == R[j].size() && L[i] <= R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<string>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

void MergeSort(vector<string>& arr) {
    MergeSort(arr, 0, arr.size() - 1);
}

void Merge(vector<pair<string, int>>& list, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<pair<string, int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = list[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (L[i].second > R[j].second) {
            list[k] = L[i];
            i++;
        }
        else if (L[i].second == R[j].second) {
            if (L[i].first.size() < R[j].first.size() || (L[i].first.size() == R[j].first.size() && L[i].first <= R[j].first)) {
                list[k] = L[i];
                i++;
            } else {
                list[k] = R[j];
                j++;
            }
        }
        else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<pair<string, int>>& list, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        MergeSort(list, start, mid);
        MergeSort(list, mid + 1, end);
        Merge(list, start, mid, end);
    }
}

void MergeSort(vector<pair<string, int>>& list) {
    MergeSort(list, 0, list.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr);

    vector<pair<string, int>> list;

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        }
        else {
            list.push_back({arr[i - 1], count});
            count = 1;
        }
    }
    list.push_back({arr[n - 1], count});

    MergeSort(list);

    for (pair<string, int> it : list)
        cout << it.first << " " << it.second << "\n";

    return 0;
}
