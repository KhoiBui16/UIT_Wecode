#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

void initialList(List& list)
{
    list.head = list.tail = NULL;
}

Node* getNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(List& list, Node *p)
{
    if (list.head == NULL) list.head = list.tail = p;
    else
    {
        p->next = list.head;
        list.head = p;
    }
}

void addTail(List& list, Node *p)
{
    if (list.head == NULL) list.tail = list.head = p;
    else 
    {
        list.tail->next = p;
        list.tail = p;
    }
}

int main()
{
    List L;
    initialList(L);
    int x, y;
    while (1)
    {
        cin >> x;
        if (x == 3) break;
        cin >> y;
        Node *p = getNode(y);
        (!x) ? addHead(L, p) : addTail(L, p);
    }
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        cout << p->info << " ";
    }
}