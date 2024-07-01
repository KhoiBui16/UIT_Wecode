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

void insertNode(Tree & T, int x)
{
    if (T)
    {
        if (x < T->info) insertNode(T->left, x);
        else if (x > T->info) insertNode(T->right, x);
    }
    else T = getNode(x);
}

void inputTree(Tree &T)
{
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        insertNode(T, x);
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

int isFullBinaryTree(Tree T)
{
    if (!T) return 1;
    if ((!T->left && T->right) || (T->left && !T->right)) return 0;
    return isFullBinaryTree(T->left) && isFullBinaryTree(T->right);
}

int findLeafLevel(Tree T, int level) {
    if (!T) return -1;
    if (!T->left && !T->right) return level;
    int leftLevel = findLeafLevel(T->left, level + 1);
    int rightLevel = findLeafLevel(T->right, level + 1);
    if (leftLevel != -1 && rightLevel != -1 && leftLevel == rightLevel) return leftLevel;
    return -1;
}

int isCompleteBinaryTree(Tree T)
{
    if (!isFullBinaryTree(T)) return 0;
    int leafLevel = findLeafLevel(T, 0);
    return leafLevel != -1;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"LNR: "; LNR(T);
	int i=isCompleteBinaryTree (T);
	if(i==0) cout<<"\nThe tree is not a Complete Binary Tree";
    else cout<<"\nThe tree is a Complete Binary Tree";
	return 0;
}


