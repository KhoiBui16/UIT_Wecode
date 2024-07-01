#include <bits/stdc++.h>
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
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

void Init(List& L)
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

void inputList(List& L, int n)
{
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        Node *p = getNode(x);
        if (L.head == NULL) L.head = L.tail = p;
        else
        {
            L.tail->next = p;
            L.tail = p;
        }
    }
}

void addList(List& L, int m)
{
    for (int i=0; i<m; i++)
    {
        int x; cin >> x;
        Node *p = getNode(x);
        if (L.head == NULL) L.head = L.tail = p;
        else
        {
            p->next = L.head;
            L.head = p;
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
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        cout << p->info << " "; 
    }
}

int main()
{
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    cout<<"\nEnter a number: "; int m; cin>>m; // Nhap so luong phan tu them vao dau ds
    cout<<"\nEnter a sequence of "<<m<<" numbers: ";
    addList(L,m); // Nhap 1 day gom m so va them phan tu moi vao dau ds
    cout<<"\nThe updated Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"

    return 0;
}
