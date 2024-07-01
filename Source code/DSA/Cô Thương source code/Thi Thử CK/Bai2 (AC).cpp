/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
[
]
###End banned keyword*/
#include <iostream>
#include <cmath>

using namespace std;
//###INSERT CODE HERE -

struct point
{
    long double x, y, z;
};

struct Node
{
    point info;
    Node *next;
};

struct List
{
    Node *head, *tail;
};

void init(List &L)
{
    L.head = L.tail = NULL;
}

Node* getNode(point x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addTail(List &L, point x)
{
    Node *p = getNode(x);
    if (!L.head) L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

int searching(List L, Node *p)
{
    int idx = 0;
    for (Node *q = L.head; q != NULL; q = q->next)
    {
        if (q->info.x == p->info.x && q->info.y == p->info.y && q->info.z == p->info.z) return idx;
        idx++;
    }
    return -1;
}

int n, m;

int main()
{
    cin >> n;
    List L;
    init(L);
    for (int i=0; i<n; i++)
    {
        point x; cin >> x.x >> x.y >> x.z;
        addTail(L, x);
    }
    List L2;
    init(L2);
    cin >> m;
    for (int i=0; i<m; i++)
    {
        point x; cin >> x.x >> x.y >> x.z;
        addTail(L2, x);
    }
    for (Node *p = L2.head; p != NULL; p = p->next)
    {
        int idx = searching(L, p);
        if (idx != -1) cout << idx << "\n";
        else cout << "KHONG\n";
    }
}