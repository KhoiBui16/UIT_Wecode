// đúng full bằng merge
#include <bits/stdc++.h>
using namespace std;

// Hàm merge hai mảng con của vector point
void merge(vector<pair<long, long>>& point, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tạo mảng tạm để lưu trữ hai mảng con
    vector<pair<long, long>> leftArr(n1), rightArr(n2);

    // Sao chép dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; i++)
        leftArr[i] = point[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = point[mid + 1 + j];

    // Hợp nhất hai mảng tạm vào mảng point
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].first < rightArr[j].first || (leftArr[i].first == rightArr[j].first && leftArr[i].second > rightArr[j].second)) {
            point[k++] = leftArr[i++];
        } else {
            point[k++] = rightArr[j++];
        }
    }

    // Sao chép các phần tử còn lại của leftArr vào point nếu cần
    while (i < n1) {
        point[k++] = leftArr[i++];
    }

    // Sao chép các phần tử còn lại của rightArr vào point nếu cần
    while (j < n2) {
        point[k++] = rightArr[j++];
    }
}

// Hàm sắp xếp mergeSort
void mergeSort(vector<pair<long, long>>& point, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(point, left, mid);
        mergeSort(point, mid + 1, right);
        merge(point, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<long, long>> point(n);

    for (int i = 0; i < n; i++) {
        long x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }

    // Sắp xếp mảng điểm
    mergeSort(point, 0, n - 1);

    for (auto it : point)
        cout << it.first << " " << it.second << "\n";
    return 0;
}


