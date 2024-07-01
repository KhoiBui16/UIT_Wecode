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

struct node
{
    int info;
    node *next;
};

struct List
{
    node *head, *tail;
};

void Init(List& L)
{
    L.head = L.tail = NULL;
}

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List &L, int n)
{
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        node *p = getNode(x);
        if (L.head == NULL) L.head = L.tail = p;
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void outputList(List L)
{
    if (L.head == NULL) 
    {
        cout << "List is empty";
        return;
    }
    for (node *p = L.head; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
}

int getSize(List L)
{
    int size = 0;
    node *p = L.head;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

node *findElementFromEnd(List L, int idx)
{
    if (L.head == NULL) 
    {
        cout << "List is empty";
        return NULL;
    }
    int res = getSize(L) - idx;
    if (res < 0) 
    {
        cout << "The index is invalid";
        return NULL;
    }
    node *p = L.head;
    while (res--) p = p->next;
    return p;
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    node *p = findElementFromEnd(L,i);
    if(p) cout<<p->info;


    return 0;
}
