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

void outputProvince(Pro x)
{
    cout << x.id << "\t" << x.name << "\t" << x.pop << "\t" << x.area << "\n";
}

void outputListProvinces(List L)
{
    if (!L.pHead) 
    {
        cout << "List is empty";
        return;
    }
    for (Node *p = L.pHead; p != NULL; p = p->next)
    {
        outputProvince(p->info);
    }
}

void delHead(List &L)
{
    if (!L.pHead) return;
    if (!L.pHead->next) 
    {
        delete L.pHead;
        Init(L);
    }
    else 
    {
        Node *p = L.pHead;
        L.pHead = p->next;
        p->next = NULL;
        delete p;
    }
}

int removeProvince(List &L, string s)
{
    if (!L.pHead) return 0;
    if (L.pHead->info.name == s)
    {
        delHead(L);
        return 1;
    }
    Node *p = L.pHead;
    Node *k = NULL;
    while (p)
    {
        if (p->info.name == s) break;
        k = p;
        p = p->next;
    }
    if (!p) return 0;
    if (p == L.pTail)
    {
        L.pTail = k;
        L.pTail->next = NULL;
        delete p;
        return 1;
    }
    k->next = p->next;
    p->next = NULL;
    delete p;
    return 1;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);

    if (L.pHead)
    {
        string s;
        cin.ignore();
        cout << "Enter the name of the province you want to delete:" << endl;
        getline(cin, s);
        int i = removeProvince(L, s);
        if (!i) cout << "Not found";
        else
        {
            cout << "Updated List:" << endl;
            cout << "ID\t|Province\t|Population\t|Area" << endl;
            outputListProvinces(L);
        }
    }
}