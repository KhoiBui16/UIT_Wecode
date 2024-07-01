#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node *next, *prev;
};

struct List
{   
    Node *head, *tail;
};

Node* getNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = p->prev = NULL;
    return p;
}

void init(List &L)
{
    L.head = L.tail = NULL;
}

void Nhap(List &L, int n)
{
    for (int i=1; i<=n; i++)
    {
        Node* p = getNode(i);
        if (!L.head) L.head = L.tail = p;
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void moveFront(List& L, int x)
{
    Node *p = L.head, *k = NULL;
    while (p->info != x)
    {
        k = p;
        p = p->next;        
    }
    if (!k) 
    {
        p = k = NULL;
        delete p, k;
        return;
    }
    if (p == L.tail) 
    {
        k->next = NULL;
        L.tail = k;
        p->next = L.head;
        L.head = p;
    }
    else
    {
        k->next = p->next;
        p->next = L.head;
        L.head = p;
    }
    p = k = NULL;
    delete p, k;
}

int main()
{
    int n, m;
    cin >> n >> m;
    List L;
    init(L);
    Nhap(L, n);
    while (m--)
    {
        int x; cin >> x;
        moveFront(L, x);
        //for (Node *p = L.head; p != NULL; p = p->next) cout << p->info << " ";
        cout /*<< endl */<< L.tail->info << " ";
    }
}