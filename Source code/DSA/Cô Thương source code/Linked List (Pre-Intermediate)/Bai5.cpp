/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct Node
{
    int info;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

void initialList(List& L)
{
    L.head = L.tail = NULL;
}

Node* getNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(List& L, Node *p)
{
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List& L, Node *p)
{
    if (L.head == NULL) L.tail = L.head = p;
    else 
    {
        L.tail->next = p;
        L.tail = p;
    }
}

Node* searching(List L, int a)
{
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        if (p->info == a) return p;
    }
    return NULL;
}

void addAfter(List& L, int a, int b)
{
    Node* k = searching(L, a);
    Node* q = getNode(b);
    if (k == NULL) addHead(L, q);
    else
    {
        q->next = k->next;
        k->next = q;
        if (k == L.tail) L.tail = q;
    }
}

void deleteHead(List& L)
{
    if (L.head == NULL) return;
    Node *p = L.head;
    L.head = p->next;
    p->next = NULL;
    delete p;
    if (L.head == NULL) L.tail == NULL;
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
        if (x == 6) break;
        switch (x)
        {
            case 0:
            {
                cin >> y;
                p = getNode(y);
                addHead(L, p);
                break;
            }
            case 1:
            {
                cin >> y;
                p = getNode(y);
                addTail(L, p);
                break;
            }
            case 2:
            {
                cin >> y >> z;
                addAfter(L, y, z);
                break;
            }
            case 5:
            {
                deleteHead(L);
                break;
            }
        }
    }
    if (L.head == NULL) cout << "blank";
    else
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        cout << p->info << " ";
    }
}