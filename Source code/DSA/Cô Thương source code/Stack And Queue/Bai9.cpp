#include <bits/stdc++.h>

using namespace std;

void Solve(string math, queue<int> &q, stack<int> &s)
{
    map <char, int> mp;
    mp['('] = mp[')'] = 0;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp[':'] = 2;
    for (char c: math)
    {
        if (isdigit(c)) q.push((c-'0'));
        else
        {
            if (s.empty()) s.push(c);
            else if (c == '(') s.push(c);
            else if (c == ')') 
        }
    }
}

int main()
{
    string math; cin >> math;
    queue<int> q;
    stack<char> s;
    Solve(math, q, s);
}