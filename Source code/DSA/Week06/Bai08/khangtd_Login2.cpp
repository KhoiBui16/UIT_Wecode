#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    map<string, vector<string>> mp;
    while (n--) {
        string s, t;
        cin >> s >> t;
        mp[s].push_back(t);
    }
    while (q--) {
        string x;
        cin >> x;
        if (mp.find(x) != mp.end())
        {
            for (string it : mp[x])
                cout << it << " ";
            cout << endl;
        }
        else
            cout << "Chua Dang Ky!" << endl;
    }
    return 0;
}
