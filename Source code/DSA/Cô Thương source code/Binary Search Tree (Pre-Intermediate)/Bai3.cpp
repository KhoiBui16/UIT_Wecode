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

void output(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        output(T->left);
        output(T->right);
    }
}

void rotateLeft(Tree &T)
{
    if (!T || !T->right) return;
    Node *p = T, *q = T->right;
    p->right = q->left;
    q->left = p;
    T = q;
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
    cout << "NLR: "; output(T);
    if (!T) cout << "\nKhong the xoay vi cay rong";
    else if (!T->right) cout << "\nKhong the xoay trai vi khong co nut con ben phai";
    else rotateLeft(T);
    cout << "\nNLR: "; output(T);
}