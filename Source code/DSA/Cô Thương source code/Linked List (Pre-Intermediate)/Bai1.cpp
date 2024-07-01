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

Node* searching(List list, int a)
{
    for (Node *p = list.head; p != NULL; p=p->next)
    {
        if (p->info == a) return p;
    }
    return NULL;
}

void addAfter(List& list, int a, int b)
{
    Node* k = searching(list, a);
    Node* q = getNode(b);
    if (k == NULL) addHead(list, q);
    else
    {
        q->next = k->next;
        k->next = q;
        if (k == list.tail) list.tail = q;
    }
}

int main()
{
    List L;
    initialList(L);
    int x, y, z;
    Node *p;
    while (1)
    {
        cin >> x;
        if (x == 3) break;
        cin >> y;
        p = getNode(y);
        switch (x)
        {
            case 0:
            {
                addHead(L, p);
                break;
            }
            case 1:
            {
                addTail(L, p);
                break;
            }
            case 2:
            {
                cin >> z;
                addAfter(L, y, z);
                break;
            }
        }
    }
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        cout << p->info << " ";
    }
}