/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *pLeft;
    Node *pRight;
};
typedef struct Node* Tree;

Node *getNode(int x);
void insertNode(Tree & T, int x);
void inputTree(Tree &T);
void NLR(Tree T);
bool isSquare (int n);
void SearchStandFor(Node* &p, Node* &q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree &T);

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout<<"\nNLR: "; NLR(T);
    cout<<"\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout<<"\nNLR: "; NLR(T);

    return 0;
}
//###INSERT CODE HERE -

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

void NLR(Tree T)
{
    if (T)
    {
        cout << T->info << " ";
        NLR(T->pLeft);  
        NLR(T->pRight);
    }
}

bool isSquare(int n)
{
    int i = 0;
    while (i*i<=n)
    {
        if (i*i == n) return true;
        i++;
    }
    return false;
}

void SearchStandFor(Node* &p, Node* &q)
{
    if (p->pRight) SearchStandFor(p->pRight, q);
    else
    {
        q->info = p->info;
        q = p;
        p = p->pLeft;
    }
}

void deleteNode(Tree &T, int x)
{
    if (!T->pLeft) T = T->pRight;
    else if (!T->pRight) T = T->pLeft;
    else
    {
        Node *p = T;
        SearchStandFor(T->pLeft, p);
    }
}

void deleteSquareNumbers(Tree &T)
{
    if (T)
    {
        deleteSquareNumbers(T->pLeft);
        deleteSquareNumbers(T->pRight);
        if (isSquare(T->info)) deleteNode(T, T->info);
    }
}