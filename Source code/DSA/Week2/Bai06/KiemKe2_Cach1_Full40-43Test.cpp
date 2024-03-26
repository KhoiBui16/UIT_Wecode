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

int Partition(vector<Item>& arr, int start, int end) {
    int pivotCount = arr[start].count;
    string pivotCode = arr[start].code;
    int i = start;
    for (int j = start + 1; j <= end; j++) {
        // So sánh theo số lượng giảm dần
        if (arr[j].count > pivotCount) {
            i++;
            swap(arr[i], arr[j]);
        }
        // Nếu số lượng bằng nhau, thì so sánh độ dài của mã số trước
        else if (arr[j].count == pivotCount) {
            if (arr[j].code.size() < pivotCode.size() || (arr[j].code.size() == pivotCode.size() && arr[j].code < pivotCode)) {
                i++;
                Swap(arr[i], arr[j]);
            }
        }
    }
    Swap(arr[start], arr[i]);
    return i;
}

void QuickSort(vector<Item>& arr, int start, int end) {
    if (start < end) {
        int p = Partition(arr, start, end);
        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    Item* items = new Item[n];
    // vector<Item> items;
    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;
        bool found = false;
        for (auto& item : items) {
            if (item.code == code) {
                item.count++;
                found = true;
                break;
            }
        }
        if (!found) {
            items.push_back({code, 1});
        }
    }

    QuickSort(items, 0, items.size() - 1);

    for (const auto& item : items) {
        cout << item.code << " " << item.count << endl;
    }

    return 0;
}

// còn bị TLE 3 test