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
// struct Tree
// {
//     Node* root; //disgusting
// };

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}


void inputTreeNode(Tree &T, int x) //(Node* T)
{
    if (T != NULL) 
    {
        if (x == T->info) cout << "Unavailable";
        else if (x < T->info) 
            inputTreeNode(T->left, x);
        else 
            inputTreeNode(T->right, x);
    }
    else //cây đang rỗng (hoặc T = NULL)
        T = getNode(x);
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

//Node - Left - Right method of output:
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

//Right - Left - Node method of output:
void RLN(Tree T)
{
    if (T)
    {
        RLN(T->right);
        RLN(T->left);
        cout << T->info << " ";
    }
}

//Left - Right - Node method of output:
void LRN(Tree T)
{
    if (T)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
    }
}

//Left - Node - Right method of output:
void LNR(Tree T)
{
    if (T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}
