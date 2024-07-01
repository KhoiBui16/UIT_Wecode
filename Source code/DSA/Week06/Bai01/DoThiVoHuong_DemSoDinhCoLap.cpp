/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> G(m);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
        if (G[i].empty())
            cnt++;
    cout << cnt;
    return 0;
}