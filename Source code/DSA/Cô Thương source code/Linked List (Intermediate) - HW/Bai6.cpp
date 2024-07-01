/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
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

void Init(List &L)
{
    L.head = L.tail = NULL;
}

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List &L, int n)
{
    while (n--)
    {
        int x; cin >> x;
        Node *p = getNode(x);
        if (!L.head) L.head = L.tail = p;
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void outputList(List L)
{
    if (!L.head) 
    {
        cout << "List is empty";
        return;
    }
    for (Node *p = L.head; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
}

void concate(List &L1, List L2)
{
    if (!L2.head) return;
    if (!L1.head)
    {
        L1.head = L2.head;
        L1.tail = L2.tail;
    }
    else
    {
        L1.tail->next = L2.head;
        L1.tail = L2.tail;
    }
}

int main()
{
    List L1, L2;
    Init(L1);Init(L2);

    int n; cin>>n;
    inputList(L1,n);
    cout<<"Created 1st List: "<<endl;
    outputList(L1);
    cout<<endl;

    cin>>n;
    inputList(L2,n);
    cout<<"Created 2nd List: "<<endl;
    outputList(L2);
    cout<<endl;

    concate(L1,L2); // Noi L2 vao L1
    cout<<"Updated L1: "<<endl;
    outputList(L1);

    return 0;
}
