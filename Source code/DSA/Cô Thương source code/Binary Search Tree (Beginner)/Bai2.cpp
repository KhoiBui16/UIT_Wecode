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
        if (x == T->info) cout << "Unavailable";
        else if (x < T->info) inputTreeNode(T->left, x);
        else inputTreeNode(T->right, x);
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

void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

Tree Search(Tree T, int x)
{
    if (!T) return NULL;
    if (T->info == x) return T;
    if (T->info > x) return Search(T->left, x);
    return Search(T->right, x);
}

int minValue(Tree T)
{
    Node *p = T;
    while (p->left != NULL) p=p->left;
    return p->info;
}

int maxValue(Tree T)
{
    Node *p = T;
    while (p->right != NULL) p=p->right;
    return p->info;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T); cout<<endl;


    int x; cout<<"\nEnter the element you want to find: ";cin>>x;
    Node *p=Search(T,x);
    if (p) cout<< "Found";
    else cout<<"Not found";
    cout<<"\nMinimum value in BTS is "<<minValue(T);
    cout<<"\nMinimax value in BTS is "<<maxValue(T);


	return 0;
}
