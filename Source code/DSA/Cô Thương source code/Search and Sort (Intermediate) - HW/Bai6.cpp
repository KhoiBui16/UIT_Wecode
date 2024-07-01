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


int main()
{
    int n; cin >> n;
    vector <string> a;
    for (int i=0; i<n; i++)
    {
        string ma; cin >> ma;
        bool check = 0;
        for (auto i: a)
        {
            if (ma == i) 
            {
                check = 1;
                break;
            }
        }
        if (!check) a.push_back(ma);
    }
    cout << a.size();
}