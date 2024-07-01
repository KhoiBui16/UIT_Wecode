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
    node *pHead, *pTail;
};

node *getNode(int x)
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List& L, int n)
{
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        node *p = getNode(x);
        if (L.pHead == NULL) L.pHead = L.pTail = p;
        else
        {
            L.pTail->next = p;
            L.pTail = p;
        }
    }
}

void outputList(List L)
{
    if (L.pHead == NULL) 
    {
        cout << "List is empty";
        return;
    }
    for (node *p = L.pHead; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
}

int getSize(List L)
{
    int size = 0;
    node *p = L.pHead;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

node *findMiddle(List L)
{
    int idx = getSize(L) / 2;
    node *p = L.pHead; 
    while (idx--)
    {
        p = p->next;
    }
    return p;
}

int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
