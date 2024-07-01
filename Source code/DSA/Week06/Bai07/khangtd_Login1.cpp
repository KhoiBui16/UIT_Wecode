#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    while (n--) {
        string s, t;
        cin >> s >> t;
        mp[s] = t;
    }
    while (q--)
    {
        string x;
        cin >> x;
        if (mp.find(x) != mp.end())
            cout << mp[x] << endl;
        else
            cout << "Chua Dang Ky!" << endl;
        }
    return 0;
}
