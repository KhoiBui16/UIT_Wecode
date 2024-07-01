#include <bits/stdc++.h>


using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};
typedef Node* Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void input(Tree &T, int x)
{
    if (!T) 
    {
        T = getNode(x);
        return;
    }
    if (T->info > x) input(T->left, x);
    else if (T->info < x) input(T->right, x);
}

Node *Search(Tree T, int x)
{
    Node *p = NULL;
    if (!T) return NULL;
    if (T->info == x) return T;
    p = Search(T->left, x);
    if (!p) p = Search(T->right, x);
    return p;
}

void path(Tree T, int x)
{
    if (T->info == x)
    {
        cout << x;
        return;
    }
    cout << T->info << " ";
    if (T->info > x) path(T->left, x);
    else if (T->info < x) path(T->right, x);
}

int main()
{
    int n; cin >> n;
    Tree T = NULL;
    while (n--)
    {
        int x; cin >> x;
        input(T, x);
    }
    int x; cin >> x;
    if (!Search(T, x)) cout << "Not found";
    else 
    {
        cout << "Found. Path: ";
        path(T, x);
    }
}