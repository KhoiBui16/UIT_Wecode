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

void insertHead(List& list, int x)
{
    if (list.head == NULL)
    {
        Node *p = getNode(x);
        list.head = list.tail = p;
    }
    else
    {
        Node *p = getNode(x);
        p->next = list.head;
        list.head = p;
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
        insertHead(L, y);
    }
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        cout << p->info << " ";
    }
}