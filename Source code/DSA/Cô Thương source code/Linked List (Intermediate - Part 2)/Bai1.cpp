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

void addHead(List &L, Pro x)
{
    Node *p = getNode(x);
    if (!L.pHead) L.pHead = L.pTail = p;
    else
    {
        p->next = L.pHead;
        L.pHead = p;
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

Node* searching(List L, string s)
{
    for (Node *p = L.pHead; p != NULL; p = p->next) if (p->info.name == s) return p;
    return NULL;
}

void addAfter(List& L, string s, Pro x)
{
    Node* k = searching(L, s);
    Node* q = getNode(x);
    if (k == NULL) addHead(L, x);
    else
    {
        q->next = k->next;
        k->next = q;
        if (k == L.pTail) L.pTail = q;
    }
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
        cout << "Enter the name to search:" << endl;
        getline(cin, s);
        if (searching(L, s)) 
        {
            Pro x;
            cout << "Input a new province:" << endl;
            inputProvince(x);
            addAfter(L, s, x);
            cout << "Updated List:" << endl;
            cout << "ID\t|Province\t|Population\t|Area" << endl;
            outputListProvinces(L);
        }
        else cout << "Not found";
    }
}