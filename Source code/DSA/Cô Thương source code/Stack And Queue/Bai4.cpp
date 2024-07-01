/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
	List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head;
};

struct Stack
{
    List L;
};

void Init(Stack& S)
{
    S.L.head = NULL;
}

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Push(Stack& S, int x)
{
    Node *p = getNode(x);
    if (S.L.head == NULL) S.L.head = p;
    else
    {
        p->next = S.L.head;
        S.L.head = p;   
    }
}

void Pop(Stack& S)
{
    if (S.L.head == NULL) return;
    else if (S.L.head->next == NULL)
    {
        delete S.L.head;
        Init(S);
    }
    else
    {
        Node *p = S.L.head;
        S.L.head = p->next;
        p->next = NULL;
        delete p;
    }
}

void DecimaltoBinary1(int n, Stack& S)
{
    if (n == 0) 
    {
        Push(S, 0);
        return;
    }
    while (n>0)
    {
        Push(S, n%2);
        n/=2;
    }
}

void printStack(Stack S)
{
    for (Node *p = S.L.head; p != NULL; p = p->next) cout << p->info;
}

int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary1(n,S);
    printStack(S);
    return 0;
}

