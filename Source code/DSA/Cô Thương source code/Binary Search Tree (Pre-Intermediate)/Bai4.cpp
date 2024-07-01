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

int depth(Tree T)
{
    if (!T) return 0;
    return max(1 + depth(T->left), 1 + depth(T->right));
}

bool isAVL(Tree T)
{
    if (!T) return true;
    int left = depth(T->left), right = depth(T->right);
    if (abs(left-right) > 1) return 0;
    return isAVL(T->left) && isAVL(T->right);
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    cout<<isAVL(T);
	return 0;
}
