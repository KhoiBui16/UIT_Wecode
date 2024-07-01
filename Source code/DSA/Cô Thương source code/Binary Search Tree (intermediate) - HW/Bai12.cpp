/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

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

void inputNode(Tree &T, int x)
{
    if (T)
    {
        if (x < T->info) inputNode(T->left, x);
        else if (x > T->info) inputNode(T->right, x);
    }
    else T = getNode(x);
}

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        inputNode(T, x);
    }
}

Tree CeilingNode(Tree T, int x)
{
    Tree p = NULL;
    while (T) {
        if (T->info == x) return T;
        if (T->info < x)
        {
            p = T;
            T = T->right;
        } 
        else T = T->left;
    }
    return p;
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    int x; cin >> x;
    Node* res = CeilingNode(T, x);
    if (res) cout << res->info;
    else cout << 201;
}