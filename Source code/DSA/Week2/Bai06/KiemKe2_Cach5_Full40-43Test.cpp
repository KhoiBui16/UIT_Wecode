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

// Hàm sắp xếp mảng arr theo yêu cầu của đề bài
void SortByRequirement(vector<pair<string, int>>& arr) {
    QuickSort(arr, 0, arr.size() - 1); // Sắp xếp mảng bằng thuật toán QuickSort
    // Sắp xếp kết quả theo thứ tự giảm dần của tần suất
    // Nếu tần suất bằng nhau thì sắp xếp theo thứ tự tăng dần của mã số
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i].second < arr[j].second ||
                (arr[i].second == arr[j].second && arr[i].first.size() > arr[j].first.size()) ||
                (arr[i].second == arr[j].second && arr[i].first.size() == arr[j].first.size() && arr[i].first > arr[j].first)) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    // Đọc dữ liệu và đếm tần suất xuất hiện
    vector<pair<string, int>> arr;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool found = false;
        for (auto& p : arr) {
            if (p.first == s) {
                p.second++;
                found = true;
                break;
            }
        }
        if (!found) {
            arr.push_back({s, 1});
        }
    }

    // Sắp xếp kết quả và in
    SortByRequirement(arr);
    for (const auto& p : arr) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
