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

void inputTreeNode(Tree &T, int x)
{
    if (T)
    {
        if (x < T->info) inputTreeNode(T->left, x);
        else if (x > T->info) inputTreeNode(T->right, x);
    }
    else T = getNode(x);
}

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--) 
    {
        int x; cin >> x;
        inputTreeNode(T, x);
    }
}

void NLR(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

Tree rotateRight(Tree &T)
{
    if (!T)
    {
        cout<< "\nKhong the xoay vi cay rong";
        return T;
    }
    else if (!T->left)
    {
        cout<< "\nKhong the xoay phai vi khong co nut con ben trai";
        return T;
    }
    Node *p = T, *q = T->left;
    p->left = q->right;
    q->right = p;
    T = q;
    return q;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	T=rotateRight(T);
	cout<<"\nUpdated Tree: \n";
	cout<<"NLR: "; NLR(T);
	return 0;
}



