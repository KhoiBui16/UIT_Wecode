/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

//###INSERT CODE HERE -

class Graph
{
private:
    vector<vector<int>> matrix;
    vector<string> vertises;
    map<string, int> idx;
public:
    Graph() {};
    ~Graph() {};
    void nhap(int v, int e)
    {
        matrix.resize(v+1, vector<int>(v+1, 0));
        vertises.resize(v+1, "");
        for (int i=1; i<=v; i++)
        {
            string c; cin >> c;
            vertises[i] = c;
            idx[c] = i;
        }
        while (e--)
        {
            string a, b; cin >> a >> b;
            matrix[idx[a]][idx[b]] = 1;
        }
    }
    void myProcess(int n)
    {
        while (n--)
        {
            int selection; cin >> selection;
            if (selection == 1)
            {
                string a, b; cin >> a >> b;
                (matrix[idx[a]][idx[b]]) ? cout << "TRUE\n" : cout << "FALSE\n";
            }
            else if (selection == 2)
            {
                bool ok = 0;
                string a; cin >> a;
                for (auto c: vertises)
                {
                    if (matrix[idx[a]][idx[c]]) 
                    {
                        ok = 1;
                        cout << c << " ";
                    }
                }
                if (!ok) cout << "NONE";
                cout << "\n";
            }
        }
    }
};

int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

