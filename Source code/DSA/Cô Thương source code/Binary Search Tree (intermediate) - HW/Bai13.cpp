#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};
typedef Node* Tree;

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void inputNodes(Tree &T, int x)
{
    if (T)
    {
        if (T->info < x) inputNodes(T->right, x);
        else inputNodes(T->left, x);
    }
    else T = getNode(x);
}

int main()
{
    int n; cin >> n;
    Tree T = NULL;
    while (n--)
    {
        int x; cin >> x;
        inputNodes(T, x);
    }
    
}