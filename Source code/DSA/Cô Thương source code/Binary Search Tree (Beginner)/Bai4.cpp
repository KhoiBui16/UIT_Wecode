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

int countNodes(Tree T)
{
    if (!T) return 0;
    return 1 + countNodes(T->left) + countNodes(T->right);
}

int countLeafs(Tree T)
{
    if (!T) return 0;
    else 
    {
        if (!T->left && !T->right) return 1;
        return countLeafs(T->left) + countLeafs(T->right);
    }
}

int countInternalNodes(Tree T)
{
    int k = 0;
    if (!T) return 0;
    else
    {
        if ((T->left || T->right) && k != 0) return 1;
        else
        {
            k++;
            return countInternalNodes(T->left) + countLeafs(T->right);
        }
    }
}

int countOneChild(Tree T)
{
    if (!T) return 0;
    else 
    {
        if ((!T->left && T->right) || (T->left && !T->right)) return 1;
        return countOneChild(T->left) + countOneChild(T->right);
    }
}

int countTwoChildren(Tree T)
{
    if (!T) return 0;
    else 
    {
        if (T->left && T->right) return 1;
        return countTwoChildren(T->left) + countTwoChildren(T->right);
    }
}

int countLess(Tree T, int x)
{

}

int countBetweenValues(Tree T, int x, int y)
{

}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	// int x;cout<<"Enter x: ";cin>>x;
	// cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	// int y; cout<<"Enter x,y: ";cin>>x>>y;
	// cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
