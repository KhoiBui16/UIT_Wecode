#include <bits/stdc++.h>
using namespace std;

void Sorted(vector<pair<long, long>>& point,int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (point[j].first > point[j + 1].first)
            {

                swap(point[j], point[j + 1]);
            }
            else if (point[j].first == point[j + 1].first && point[j].second < point[j + 1].second)
            {
                swap(point[j], point[j + 1]);
            }
        }
    }
}

int main()   // chỉ đúng 20 test
{
    int n;
    cin >> n;
    vector<pair<long, long>> point, temp;
    for (int i = 0; i < n; i++)
    {
        long x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }

    Sorted(point, n);

    for (auto it : point)
        cout << it.first << " " << it.second << "\n";
    return 0;
}
