#include <bits/stdc++.h>

using namespace std;

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
    int m, n;
    float load;
    List *buckets;
};

Node* getNode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void initList(List &L)
{
    L.head = L.tail = NULL;
}

void initHash(Hash &H)
{
    H.buckets = new List[H.m];
    for (int i=0; i<H.m; i++) initList(H.buckets[i]);
    H.n = 0;
}

int Hashing(int k, int m)
{
    return k % m;
}

void insertHash(Hash &H, int x)
{
    if ((H.n+1.0)/H.m > H.load) return;
    int i = Hashing(x, H.m);
    Node* p = getNode(x);
    if (!H.buckets[i].head) H.buckets[i].head = H.buckets[i].tail = p;
    else
    {
        H.buckets[i].tail->next = p;
        H.buckets[i].tail = p;
    }
    H.n++;
}

int main()
{
    Hash H;
    cin >> H.m >> H.load;
    initHash(H);
    int n; cin >> n;
    while (n--)
    {
        int x; cin >> x;
        insertHash(H, x);
    }
    int n2; cin >> n2;
    vector <int> key(n2);
    for (int i=0; i<n2; i++) cin >> key[i];
    bool ok = 0;
    for (auto x: key)
    {
        int idx = Hashing(x, H.m);
        for (Node *p = H.buckets[idx].head; p != NULL; p = p->next)
        {
            if (p->info == x) 
            {
                ok = 1;
                break;
            }
        }
        (ok) ? cout << idx << '\n' : cout << "KHONG\n";
    }
}