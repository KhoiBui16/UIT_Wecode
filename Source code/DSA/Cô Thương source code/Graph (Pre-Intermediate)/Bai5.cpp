//Thuat toan tim kiem theo chieu sau Depth-First Search (DFS)
#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<vector<int>> matrix;
    map<string, int> v_idx;
    vector<string> v_name;
public:
    void input(int v)
    {
        matrix = vector<vector<int>>(v, vector<int>(v));
        v_name = vector<string>(v, "");
        for (int i=0; i<v; i++) 
        {
            string x; cin >> x;
            v_name[i] = x;
            v_idx[x] = i;
        }
        for (int i=0; i<v; i++)
        {
            for (int j=0; j<v; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    vector<string> adjNodes(string p, int v)
    {
        vector<string> res;
        for (int i=0; i<v; i++) if (matrix[v_idx[p]][i]) res.push_back(v_name[i]);
        return res;
    }
    void dfs(string s, string g, int v)
    {
        //Step 1: Khoi tao
        //Open = {s}, Close = {}
        map <string, string> parents;
        stack<string> open;
        vector<bool> close(v, 0);
        open.push(s);

        //Step 2: while (Open != {})
        int cnt = 0;
        bool found = 0;
        while (!open.empty())
        {
            //cnt = 0
            string p = open.top(); 
            if (!close[v_idx[p]]) cnt++;
             //  2.1 Chọn p thuộc Open có
            open.pop(); // xóa p ra khỏi Open
            // 2.2 Nếu p là đỉnh đích thì thoát
            if (p == g) 
            {
                found = true;
                break;
            }
            // 2.3 Bỏ p vào close
            close[v_idx[p]] = 1;
            // tạo vector q để lưu các đỉnh kề của p
            vector<string> q = adjNodes(p, v);
            for (int i=0; i<q.size(); i++) 
                if (!close[v_idx[q[i]]]) // 2.4 Nếu q không thuộc close thì bỏ q vào đầu Open
                {
                    open.push(q[i]);
                    parents[q[i]] = p;
                }
        }
        int length = 0;
        if (found) 
        {
            string cur = g;
            vector<string> path;
            //2.2 Nếu p là đỉnh đích thì xuất đường đi, kết thúc thuật toán
            while (true)
            {
                path.push_back(cur);
                if (cur == s) break;
                cur = parents[cur];
            }
            for (int i=path.size()-1; i>=0; i--)
            {
                if (i >= 1) length += matrix[v_idx[path[i]]][v_idx[path[i-1]]];
                cout << path[i] << " ";
            }
        }
        else cout << "-unreachable-\n";
        cout << "\n" << cnt << " " << length << "\n";
    }
};


int main()
{
    int v, n; cin >> v >> n;
    Graph G;
    G.input(v);
    while (n--)
    {
        string s, s1;
        cin >> s >> s1;
        G.dfs(s, s1, v);
    }
}