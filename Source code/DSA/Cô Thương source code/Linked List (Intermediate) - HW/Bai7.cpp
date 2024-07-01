/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
classs
###End banned keyword*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}

//###INSERT CODE HERE -

Node* getNode(int x)
{
    Node *p = new Node;
    p->val = x;
    p->next = NULL;
    return p;
}

void add_tail(List& L, int x)
{
    Node *p = getNode(x);
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        L.tail->next = p;
        L.tail = p;
    }
}

void copy(List L1, List& L2)
{
    Node *p = L1.head;
    while (p != NULL)
    {
        int x = p->val;
        add_tail(L2, x);
        p = p->next;
    }
}


int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    List l; list_initializing(l);
    //Read list
    int x;
    do{
        cin >> x;
        add_tail(l, x);
    } while(x != 0);

    List l2; list_initializing(l2);
    copy(l, l2);

    Node*p = l.head, *q = l2.head;
    while(p != NULL){
    	if (p == q || p->val != q->val) cout << "WRONG";
    	cout << p->val << endl;
    	p = p->next;
    	q = q->next;
    }

    return 0;
}
