/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -

void inputGraph(vector<vector<int>>& G, int v, int e)
{
    G.resize(v+1, vector<int>(v+1, 0));
    while (e--)
    {
        int u, i; cin >> u >> i;
        G[u][i] = 1;
    }
}

void process(vector<vector<int>> G, int v, int n)
{
    while (n--)
    {
        int selection; cin >> selection;
        if (selection == 1) 
        {
            int u, i; cin >> u >> i;
            (G[u][i]) ? cout << "TRUE\n" : cout << "FALSE\n";
        }
        else if (selection == 2)
        {
            bool ok = 0;
            int u; cin >> u;
            for (int i=1; i<=v; i++)
            {
                if (G[u][i]) 
                {
                    ok = 1;
                    cout << i << " ";
                }
            }
            if (!ok) cout << "NONE";
            cout << "\n";
        }
    }
}

int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
