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

struct Hash
{
    int n, m;
    Node **buckets;
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
    H.n = 0;
    H.buckets = new Node*[H.m];
    for (int i=0; i<H.m; i++) H.buckets[i] = NULL;
}

int hashFunc(Hash H, int x)
{
    return x % H.m;
}

void addHead(Hash &H, Node* add, int idx)
{
    if (!H.buckets[idx]) H.buckets[idx] = add;
    else
    {
        add->next = H.buckets[idx];
        H.buckets[idx] = add;
    }
}

void addAfter(Hash &H, Node* add, Node* k)
{
    if (!k->next) k->next = add;
    else
    {
        add->next = k->next;
        k->next = add;
    }
}

void insertHash(Hash &H, int x)
{
    int i = hashFunc(H, x);
    Node *p = H.buckets[i], *add = getNode(x), *q = NULL;
    while (p && x > p->info) 
    {
        q = p;
        p = p->next;
    }
    if (!q) addHead(H, add, i);
    else addAfter(H, add, q);
}

void traverse(Hash H, int idx)
{
    for (Node *p = H.buckets[idx]; p != NULL; p = p->next) cout << p->info << " ";
}

void traverseAllHash(Hash H)
{
    for (int i=0; i<H.m; i++)
    {
        cout << "Bucket " << i << ": ";
        if (H.buckets[i]) traverse(H, i);
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

