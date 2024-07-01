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

void initialList(List& L)
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

void addHead(List& L, int x)
{
    Node *p = getNode(x);
    if (L.head == NULL) L.head = L.tail = p;
    else
    {
        p->next = L.head;
        L.head = p;
    }
}

void addTail(List& L, Node *p)
{
    if (L.head == NULL) L.tail = L.head = p;
    else 
    {
        L.tail->next = p;
        L.tail = p;
    }
}

Node* searching(List L, int a)
{
    for (Node *p = L.head; p != NULL; p=p->next)
    {
        if (p->info == a) return p;
    }
    return NULL;
}


void deleteHead(List& L)
{
    if (L.head == NULL) return;
    Node *p = L.head;
    L.head = p->next;
    p->next = NULL;
    delete p;
    if (L.head == NULL) L.tail == NULL;
}

void deleteTail(List& L)
{
    if (L.head == NULL) return;
    Node *k = NULL;
    Node *p = L.head;
    while (p != L.tail)
    {
        k = p;
        p=p->next;
    }
    L.tail = k;
    L.tail->next = NULL;
    delete p;
}

void deleteElement(List& L, int a)
{
    if (L.head == NULL) return;
    Node *p = L.head;
    Node* k = NULL;
    while (p)
    {
        if (p->info == a) break;
        k = p;
        p=p->next;
    }
    if (p == NULL) return;
    if (k == NULL) 
    {
        deleteHead(L);
        return;
    }
    if (p == L.tail) 
    {
        deleteTail(L);
        return;
    }
    k->next = p->next;
    p->next = NULL;
    delete p;
}


void outputList(List L)
{
    for (Node *p = L.head; p != NULL; p = p->next) cout << p->info << " ";
}

int main()
{
    int n, m; cin >> n >> m;
    List L;
    initialList(L);
    for (int i=1; i<=n; i++) 
    {
        Node *p = getNode(i);
        addTail(L, p);
    }
    while (m--)
    {
        int x; cin >> x;
        deleteElement(L, x);
        addHead(L, x);
    }
    outputList(L);
}

/*
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* head = NULL, *tail = NULL;

void addNode(int value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void removeNode(int value) {
  Node* prev = NULL, *current = head;

  while (current != NULL && current->value != value) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) return;

  if (prev == NULL) {
    head = head->next;
  } else {
    prev->next = current->next;
  }

  if (current == tail) {
    tail = prev;
  }

  delete current;
}

void insertAtHead(int value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = head;

  head = newNode;

  if (tail == NULL) {
    tail = newNode;
  }
}

void printList() {
  Node* current = head;
  while (current != NULL) {
    cout << current->value << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    addNode(i);
  }

  vector<int> students(m);
  for (int i = 0; i < m; i++) {
    cin >> students[i];
  }

  for (int i = 0; i < m; i++) {
    removeNode(students[i]);
    insertAtHead(students[i]);
  }

  printList();

  return 0;
}

*/