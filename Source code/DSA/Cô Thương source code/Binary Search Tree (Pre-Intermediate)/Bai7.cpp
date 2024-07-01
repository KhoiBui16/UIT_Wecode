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

void NLR(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void standfor(Tree &k, Node* &p)
{
    if (k->left) standfor(k->left, p);
    else
    {
        p->info = k->info;
        if (p != k)
        {
            Node* temp = k;
            k = k->right;
            delete temp;
        }
        else
        {
            k = k->right;
        }
    }
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

void deleteRoot(Tree &T, int n)
{
    while (n--)
    {
        if (!T) return;
        if (!T->right) T = T->left;
        else
        {
            Node *p = T;
            standfor(T->right, p);
        }
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"NLR: "; NLR(T);
	int m; cout<<"\nEnter m: ";cin>>m;
	deleteRoot(T,m);
	cout<<"\nNLR: "; NLR(T);

	return 0;
}
