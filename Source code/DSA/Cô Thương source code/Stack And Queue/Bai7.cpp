#include <bits/stdc++.h>

using namespace std;

void DecimaltoBinary(stack<int> &S, int n)
{
    if (n == 0) 
    {
        S.push(0);
        return;
    }
    while (n > 0)
    {
        S.push(n%2);
        n/=2;
    }
}


int main()
{
    int n; cin >> n;
    stack <int> S;
    DecimaltoBinary(S, n);
    while (!S.empty())
    {
        cout << S.top();
        S.pop();
    }
    return 0;
}