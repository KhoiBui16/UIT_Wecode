#include <bits/stdc++.h>
using namespace std;


typedef struct PROVINCE
{
    int id;
    string name;
    int pop;
    float area;
} Pro;

struct Node
{
    Pro info;
    Node *next;
};

struct List
{
    Node *pHead, *pTail;
};

Node* getNode(Pro x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void Init(List &L)
{
    L.pHead = L.pTail = NULL;
}

void inputProvince(Pro& x)
{
    cin >> x.id;
    cin.ignore(); getline(cin, x.name);
    cin >> x.pop >> x.area;
}

void addTail(List &L, Pro x)
{
    Node *p = getNode(x);
    if (!L.pHead) L.pHead = L.pTail = p;
    else
    {
        L.pTail->next = p;
        L.pTail = p;
    }
}

void inputListProvinces(List &L)
{
    int n; cin >> n;
    Pro x;
    while (n--)
    {
        inputProvince(x);
        addTail(L, x);
    }
}

Pro searching(List L)
{
    Pro maxN = L.pHead->info;
    for (Node *p = L.pHead; p != NULL; p = p->next) if (p->info.area > maxN.area) maxN = p->info;
    return maxN;
}

void outputProvince(Pro x)
{
    cout << x.id << "\t" << x.name << "\t" << x.pop << "\t" << x.area << "\n";
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    if (L.pHead)
    {
        bool ok = 0;
        string s;
        cin.ignore();
        getline(cin, s);
        Pro maxProv = searching(L);
        //outputProvince(maxProv);
        string ans = maxProv.name.substr(maxProv.name.length() - s.length());
        (ans == s) ? cout << "YES" : cout << "NO";
    }
}