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

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        input(T, x);
    }
}

void RNL(Tree T)
{
    if (T)
    {
        RNL(T->right);
        cout << T->info << " ";
        RNL(T->left);
    }
}

void nodesWithLevel(Tree T, int k)
{
    if (!T) return;
    if (!k) 
    {
        cout << T->info << " ";
        return;
    }
    nodesWithLevel(T->right, k-1);
    nodesWithLevel(T->left, k-1);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    int k; cout<<"Enter k: "; cin >>k;
    cout<<"\nList of nodes with level "<<k<<" (R->L) : ";
    nodesWithLevel(T, k);

	return 0;
}
