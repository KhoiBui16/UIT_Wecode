#include <bits/stdc++.h>

using namespace std;

int main()
{
    int e, n;
    cin >> e >> n;
    map<string, set<string>> G;
    for (int i = 0; i < e; i++)
    {
        string s, s1;
        cin >> s >> s1;
        G[s].insert(s1);
    }
    while (n--)
    {
        int selection;
        cin >> selection;
        if (selection == 1)
        {
            string s, s1;
            cin >> s >> s1;
            //(G[s].count(s1)) ? cout << "TRUE\n" : cout << "FALSE\n";
            set <string> list = G[s];
            auto it = list.find(s1);
            (it == list.end()) ? cout << "FALSE\n" : cout << "TRUE\n";
        }
        else if (selection == 2)
        {
            string s;
            cin >> s;
            cout << G[s].size() << '\n';
        }
    }
}