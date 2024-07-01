/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
set
map
multi_set
unordered_map
merge
###End banned keyword*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//###INSERT CODE HERE -

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return (a.first < b.first) || ((a.first == b.first) && (a.second > b.second));
}


int main()
{
    int n; cin >> n;
    vector <pair<int, int>> a(n);
    for (int i=0; i<n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    stable_sort(a.begin(), a.end(), cmp);
    for (int i=0; i<n; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}