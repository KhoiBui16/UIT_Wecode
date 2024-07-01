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

typedef struct PROVINCE{
    int id;
    string name;
    int pop;
    float area;
}Pro;

struct node
{
    Pro info;
    node* next;
};

struct List
{
    node *head, *tail;
};

void Init(List& L)
{
    L.head = L.tail = NULL;
}

node* getNode(Pro x)
{
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void inputProvince(Pro& x)
{
    cin >> x.id;
    cin.ignore();
    getline(cin, x.name);
    cin >> x.pop >> x.area;
}

void addTail(List& L, Pro x)
{
    node *p = getNode(x);
    if (L.head == NULL) L.head = L.tail = p;
    else 
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputListProvinces(List& L)
{
    int n; cin >> n;
    for (int i=1; i<=n; i++)
    {
        Pro x;
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
    for (node *p=L.head; p!=NULL; p=p->next)
    {
        outputProvince(p->info);
    }
}

void outputProvincesMore1MillionPop(List L)
{
    for (node *p=L.head; p!=NULL; p=p->next)
    {
        if (p->info.pop > 1000) outputProvince(p->info);    
    }
}

node* findProMaxArea(List L)
{
    node* mx = L.head;
    for (node *p=L.head; p!=NULL; p=p->next)
    {
        if (p->info.area > mx->info.area) mx = p;
    }
    return mx;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}



