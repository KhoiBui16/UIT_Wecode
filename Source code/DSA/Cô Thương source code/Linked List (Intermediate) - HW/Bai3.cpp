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
    Node *pHead, *pTail;
};

Node* getNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputList(List& L, int n)
{
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        Node *p = getNode(x);
        if (L.pHead == NULL)
        {
            L.pHead = L.pTail = p;
        }
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
    for (Node *p = L.pHead; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
}

void moveLastToFront(List &L)
{
    if (L.pHead == NULL || L.pHead->next == NULL) return;
    Node *p = L.pHead, *k = NULL;
    while (p->next != NULL)
    {
        k = p;
        p = p->next;
    }
    L.pTail = k;
    L.pTail->next = NULL;
    p->next = L.pHead;
    L.pHead = p;
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

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout<<"Updated List after moving the last element to front of L: "<<endl;
    outputList(L);
    return 0;
}
