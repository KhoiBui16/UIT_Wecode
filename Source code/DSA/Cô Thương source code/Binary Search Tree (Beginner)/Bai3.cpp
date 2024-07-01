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

void NLR(Tree T)
{
    if (T) //(T == NULL) ? return;
    {
        //xuất root node
        cout << T->info << " ";
        //xuất hết nhánh trái
        NLR(T->left);
        //xuất hết nhánh phải
        NLR(T->right);
    }
}

void LRN(Tree T)
{
    if (T)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
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

void listLeafs(Tree T)
{
    if (T)
    {
        listLeafs(T->left);
        listLeafs(T->right);
        if (!T->left && !T->right) cout << T->info << " ";
    }
}

void listInternalNodes(Tree T, int x)
{
    if (T)
    {
        if (T->left || T->right) 
        {
            if (x != 0)
                cout << T->info << " ";
        }
        listInternalNodes(T->left, 1);
        listInternalNodes(T->right, 1);
    }
}

void listNodesWithOneChild(Tree T)
{
    if (T)
    {
        if ((!T->left && T->right) || (T->left && !T->right)) cout << T->info << " ";
        listNodesWithOneChild(T->left);
        listNodesWithOneChild(T->right);
    }
}

void listNodesWithTwoChildren(Tree T)
{
    if (T)
    {
        if (T->left != NULL && T->right != NULL) cout << T->info << " ";
        listNodesWithTwoChildren(T->left);
        listNodesWithTwoChildren(T->right);
    }
    
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0);
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);
    
	return 0;
}
