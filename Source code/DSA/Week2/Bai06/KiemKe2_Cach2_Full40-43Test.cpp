#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string code;
    int count;
};

void Swap(Item& a, Item& b)
{
    Item temp = a;
    a = b;
    b = temp;
}

// Phân chia dựa trên số lượng giảm dần, sau đó theo thứ tự từ điển tăng dần nếu số lượng bằng nhau
int Partition(vector<Item>& arr, int start, int end) {
    int pivotCount = arr[start].count;
    string pivotCode = arr[start].code;
    int i = start, j = end;
    while (i <= j) {
        while (arr[i].count > pivotCount || (arr[i].count == pivotCount && arr[i].code > pivotCode)) {
            i++;
        }
        while (arr[j].count < pivotCount || (arr[j].count == pivotCount && arr[j].code < pivotCode)) {
            j--;
        }
        if (i <= j) {
            Swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return j;
}

void QuickSort(vector<Item>& arr, int start, int end) {
    if (start < end) {
        int p = Partition(arr, start, end);
        QuickSort(arr, start, p);
        QuickSort(arr, p + 1, end);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].code;
        items[i].count = 1;
    }

    QuickSort(items, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0 && items[i].code == items[i - 1].code) {
            items[i].count += items[i - 1].count;
            items[i - 1].count = 0;
        }
    }

    for (const auto& item : items) {
        if (item.count > 0) {
            cout << item.code << " " << item.count << endl;
        }
    }

    return 0;
}

// còn bị TLE 3 test