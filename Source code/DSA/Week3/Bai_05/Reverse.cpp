/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

//###INSERT CODE HERE -
void insert_node(SinglyLinkedList* llist,int item) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(item);
    if (llist->head == nullptr) {
        llist->head = node;
    }
    else {
        llist->tail->next = node;
    }
    llist->tail = node;
}

void reverseLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode *p; p = nullptr;
    SinglyLinkedListNode *cur; cur = llist->head;
    SinglyLinkedListNode *nxt;
    while (cur != nullptr)
    {
        nxt = cur->next;
        cur->next = p;
        p = cur;
        cur = nxt;
    }
    llist->head = p;
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode *node;
    node = llist->head;
    while (node != nullptr) {
        cout << node->data << ' ';
        node = node->next;
    }

}

//##Template's footer, These lines will goes after your code
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
