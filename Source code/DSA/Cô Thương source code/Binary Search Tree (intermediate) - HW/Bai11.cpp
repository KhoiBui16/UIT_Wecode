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
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void insertNode(Tree & T, int x)
{
    if (T)
    {
        if (x < T->info) insertNode(T->pLeft, x);
        else if (x > T->info) insertNode(T->pRight, x);
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

void secondLargest(Tree T)
{
    if (!T) return;
    Tree p = T, q = NULL;
    while (p->pRight)
    {
        q = p;
        p = p->pRight;
    }
    if (p->pLeft)
    {
        p = p->pLeft;
        while (p->pRight) p = p->pRight;
        cout << "2nd largest value is " << p->info;
    }
    else if (q)
    {
        cout << "2nd largest value is " << q->info;
    }
    else return;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    secondLargest(T);
	return 0;
}
