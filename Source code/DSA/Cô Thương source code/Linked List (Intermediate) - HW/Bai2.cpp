/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct Node
{
    string info;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

void Init(List& L)
{
    L.head = L.tail = NULL;
}

Node* getNode(string x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addHead(List& L, string x)
{
    Node *p = getNode(x);
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List& L, string x)
{
    Node *p = getNode(x);
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void delHead(List& L)
{
    if (L.head == NULL) return;
    else if (L.head->next == NULL) 
    {
        Node *p = L.head;
        L.head = L.tail = NULL;
        delete p;
    }
    else
    {
        Node *p = L.head;
        L.head = p->next;
        p->next = NULL;
        delete p;
        if (L.head == NULL) L.tail = NULL;
    }
}

void delTail(List& L)
{
    if (L.head == NULL) return;
    else if (L.head->next == NULL)
    {
        Node *p = L.head;
        L.head = L.tail = NULL;
        delete p;
    }
    else
    {
        Node *p = L.head;
        Node *k = NULL;
        while (p != L.tail)
        {
            k = p;
            p = p->next;
        }
        L.tail = k;
        L.tail->next = NULL;
        delete p;
    }
}

void outputList(List L)
{
    if (L.head == NULL) return;
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        if (p == L.tail) cout << p->info;
        else cout << p->info << " ";
    }
}

int main()
{
    List L;
    Init(L);
    int n; cin >> n;
    char x, y;
    string z;
    while (n--)
    {
        cin >> x >> y >> z;
        if (x == '+') 
        {
            if (y == 'H') addHead(L, z);
            else addTail(L, z);
        }
        else 
        {
            if (y == 'H') delHead(L);
            else delTail(L);
        }
    }
    outputList(L);
}