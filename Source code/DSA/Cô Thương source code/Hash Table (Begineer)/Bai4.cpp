/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
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

struct Hash
{
    int m;
    List *buckets;
};

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void initHash(Hash &H)
{
    H.buckets = new List[H.m];
    for (int i=0; i<H.m; i++)
    {
        H.buckets[i].head = H.buckets[i].tail = NULL;
    }
}

int Hashing(int k, int m)
{
    return k % m;
}

void insertHash(Hash &H, int x)
{
    int i = Hashing(x, H.m);
    Node* p = getNode(x);
    if (!H.buckets[i].head) H.buckets[i].head = H.buckets[i].tail = p;
    else
    {
        H.buckets[i].tail->next = p;
        H.buckets[i].tail = p;
    }
}

void Traverse(Hash H, int idx)
{
    for (Node *p = H.buckets[idx].head; p != NULL; p = p->next) cout << p->info << " ";
}

void sorting(Hash &H, int idx)
{
    if (!H.buckets[idx].head) return;
    bool ok;
    do
    {
        ok = false;
        Node *p = H.buckets[idx].head;
        Node *q = NULL;
        Node *i = p->next;
        while (i != NULL)
        {
            if (p->info > i->info)
            {
                ok = true;
                if (!q) H.buckets[idx].head = i;
                else q->next = i;
                p->next = i->next;
                i->next = p;
                q = i;
                i = p->next;
            }
            else
            {
                q = p;
                p = i;
                i = i->next;
            }
        }
    }
    while (ok);
}

void traverseAllHash(Hash H)
{
    for (int i=0; i<H.m; i++)
    {
        sorting(H, i);
        cout << "Bucket " << i << ": ";
        Traverse(H, i);
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin>>H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n,x;cin>>n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i<=n;i++)
    {
        cin>>x;
        insertHash(H,x); // them 1 gia tri du lieu vao bang bam
    }
    cout<<"Created Hash:"<<endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}

