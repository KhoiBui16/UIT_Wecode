/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
map
multi_set
unordered_map
merge
###End banned keyword*/

//###INSERT CODE HERE -

#include <bits/stdc++.h>

using namespace std;

void Merge(vector <string> &a, int l, int mid, int r)
{
    mid = (l + r) / 2;
    vector <string> c(r - l + 1);
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j]) c[k] = a[i++];
        else c[k] = a[j++];
        k++;
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int i=0; i<k; i++) a[l+i] = c[i];
}

void MergeSort(vector <string> &a, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}

void Merge2(vector<pair<string, int>> &list, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<pair<string, int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = list[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].second > R[j].second) list[k] = L[i++];
        else if (L[i].second == R[j].second) {
            if (L[i].first.size() < R[j].first.size() || (L[i].first.size() == R[j].first.size() && L[i].first <= R[j].first)) 
                list[k] = L[i++];
            else list[k] = R[j++];
        }
        else list[k] = R[j++];
        k++;
    }

    while (i < n1) list[k++] = L[i++];

    while (j < n2) list[k++] = R[j++];
}

void MergeSort2(vector<pair<string, int>> &list, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort2(list, l, m);
        MergeSort2(list, m + 1, r);
        Merge2(list, l, m, r);
    }
}

int main()
{
    int n; cin >> n;
    vector <string> a;
    vector <pair<string, int>> b;
    for (int i=0; i<n; i++)
    {
        string ma; cin >> ma;
        a.push_back(ma);
    }
    MergeSort(a, 0, n-1);
    int cnt = 1;
    for (int i=1; i<=n; i++)
    {
        if (a[i] == a[i-1]) cnt++;
        else
        {
            b.push_back(make_pair(a[i-1], cnt));
            cnt = 1;
        }
    }
    MergeSort2(b, 0, b.size()-1);
    for (auto i: b) cout << i.first << " " << i.second << endl;
}