#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hàm Partition cho thuật toán QuickSort
int Partition(vector<pair<string, int>>& arr, int start, int end) {
    pair<string, int> pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j].second > pivot.second || (arr[j].second == pivot.second && arr[j].first.size() < pivot.first.size()) || 
            (arr[j].second == pivot.second && arr[j].first.size() == pivot.first.size() && arr[j].first < pivot.first)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

// Thuật toán QuickSort
void QuickSort(vector<pair<string, int>>& arr, int start, int end) {
    if (start >= end) // Trường hợp cơ bản của đệ quy
        return;

    int pivot = Partition(arr, start, end);
    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> arr;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        // Kiểm tra xem x đã có trong arr chưa
        bool found = false;
        for (auto &p : arr) {
            if (p.first == x) {
                found = true;
                p.second++;
                break;
            }
        }
        // Nếu chưa có thì thêm vào arr với count = 1
        if (!found) {
            arr.push_back({x, 1});
        }
    }

    // Sắp xếp mảng arr bằng QuickSort
    QuickSort(arr, 0, arr.size() - 1);

    // In kết quả
    for (const auto& p : arr) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

// còn bị TLE 3 test