/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};

//###INSERT CODE HERE -

void init(DList& L)
{
    L.pHead = L.pTail = NULL;
}

DNode* getNode(int x)
{
    DNode* p = new DNode;
    if (p == NULL) return NULL;
    p->info = x;
    p->pPrev = p->pNext = NULL;
    return p;
}

void printList(DList L)
{
    if (L.pHead == NULL) cout << "List is empty";
    DNode *p = L.pHead;
    while (p)
    {
        cout << p->info << " ";
        p=p->pNext;
    }
}

void addTail(DList& L, int x)
{
    DNode *p = getNode(x);
    if (L.pHead == NULL) L.pHead = L.pTail = p;
    else
    {
        p->pPrev = L.pTail;
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void addHead(DList& L, int x)
{
    DNode *p = getNode(x);
    if (L.pHead == NULL) L.pHead = L.pTail = p;
    else
    {
        p->pNext = L.pHead;
        L.pHead->pPrev = p;
        L.pHead = p;
    }
}

void createList(DList& L)
{
    int x; cin >> x;
    while (x != -1)
    {
        addTail(L, x);
        cin >> x;
    }
}

void addAfter(DList& L, int x, int y)
{
    if (L.pHead == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    DNode *p = L.pHead;
    while (p)
    {
        if (p->info == x) break;
        p = p->pNext;
    }
    if (p == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    DNode *q = getNode(y);
    q->pNext = p->pNext;
    q->pPrev = p;
    if (p->pNext != NULL) p->pNext->pPrev = q; 
    p->pNext = q;
}

void addBefore(DList& L, int x, int y)
{
    if (L.pHead == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    if (L.pHead == NULL) return;
    DNode *p = L.pHead;
    while (p)
    {
        if (p->info == x) break;
        p = p->pNext;
    }
    if (p == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    DNode *q = getNode(y);
    q->pNext = p;
    q->pPrev = p->pPrev;
    if (p->pPrev != NULL) p->pPrev->pNext = q;
    else L.pHead = q;
    p->pPrev = q;
}

void addAfterMulti(DList& L, int x, int y)
{
    bool ok = 0;
    if (L.pHead == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    DNode *p = L.pHead;
    while (p)
    {
        if (p->info == x) 
        {
            ok = 1;
            DNode *q = getNode(y);
            q->pNext = p->pNext;
            q->pPrev = p;
            if (p->pNext != NULL) p->pNext->pPrev = q; 
            p->pNext = q;
        }
        p = p->pNext;
    }
    if (!ok) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
}

void addBeforeMulti(DList& L, int x, int y)
{
    bool ok = 0;
    if (L.pHead == NULL) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    if (L.pHead == NULL) return;
    DNode *p = L.pHead;
    while (p)
    {
        if (p->info == x) 
        {
            ok = 1;
            DNode *q = getNode(y);
            q->pNext = p;
            q->pPrev = p->pPrev;
            if (p->pPrev != NULL) p->pPrev->pNext = q;
            else L.pHead = q;
            p->pPrev = q;
        }
        p = p->pNext;
    }
    if (!ok) 
    {
        cout << "\nCan't find the value " << x;
        return;
    }
}

void removeHead(DList &L)
{
    if (L.pHead == NULL) 
    {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the first element?(y/n): ";
    char select;
    cin >> select;
    if (select == 'n' || select == 'N') return;
    DNode *p = L.pHead;
    L.pHead = p->pNext;
    if (L.pHead) L.pHead->pPrev = NULL;
    else L.pTail = NULL;
    delete p;
    if (L.pHead == NULL) cout << "\nThe list becomes empty";
}

void removeTail(DList &L)
{
    if (L.pHead == NULL) 
    {
        cout<<"\nList is empty. Can't delete";
        return;
    }
    cout<<"\nDo you want to delete the last element?(y/n): ";
    char select;
    cin >> select;
    if (select == 'n' || select == 'N') return;
    DNode *p = L.pTail;
    L.pTail = p->pPrev;
    if (L.pTail) L.pTail->pNext = NULL;
    else L.pHead = NULL;
    delete p;
    if (L.pHead == NULL) cout << "\nThe list becomes empty";
}

int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
