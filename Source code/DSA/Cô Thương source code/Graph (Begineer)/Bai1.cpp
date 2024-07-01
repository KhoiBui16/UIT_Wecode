/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được


//###INSERT CODE HERE -
    G = new bool*[v+1];
    for (int i=1; i<=v; i++) 
    {
        G[i] = new bool[v+1];
        for (int j=1; j<=v; j++) G[i][j] = 0;
    }
    inputGraph(G, e);
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
            int u; cin >> u;
            process(G, u, v);
            cout << "\n";
        }
    }
}

void inputGraph(bool *G[], int e)
{
    while (e--)
    {
        int u, i; cin >> u >> i;
        G[u][i] = 1;
    }
}

void process(bool *G[], int u, int v)
{
    bool ok = 0;
    for (int i=1; i<=v; i++)
    {
        if (G[u][i])
        {
            ok = 1;
            cout << i << " ";
        }
    }
    if (!ok) 
    {
        cout << "NONE\n";
        return;
    }
}