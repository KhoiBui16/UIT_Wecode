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
    long info;
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

node* getNode(int x)
{
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List& L, int n)
{
    for (int i=0; i<n; i++)
    {
        long x; cin >> x;
        node *p = getNode(x);
        if (L.head == NULL) L.tail = L.head = p;
        else 
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void outputList(List& L)
{
    if (L.head == NULL && L.tail == NULL) cout << "List is empty";
    else 
    {
        for (node *p = L.head; p != NULL; p=p->next) cout << p->info << " ";
    }
}

node* findMax(List L)
{
    if (L.head == NULL && L.tail == NULL) 
    {
        cout << "List is empty";
        return NULL;
    }
    long mxN = (long)(-2e9);
    node *mx = getNode(mxN);
    for (node *p = L.head; p!=NULL; p=p->next)
    {
        if (p->info > mx->info) mx->info = p->info;
    }
    return mx;
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


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    return 0;
}
