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

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
        }
        void printLinkedList() {
            SinglyLinkedListNode* p;
            p = head;
            while (p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
        }

};

// Complete the SinglyLinkedListNode* findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) function below.
/*
	 * For your reference:
	 *
	 * SinglyLinkedListNode {
	 *     int data;
	 *     SinglyLinkedListNode* next;
	 * };
	 * SinglyLinkedList {
     *    SinglyLinkedListNode *head;
     *    SinglyLinkedListNode *tail;
	 *
	 */
SinglyLinkedListNode* findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//###INSERT CODE HERE -
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}



int main()
{
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
    }

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist2->insert_node(llist_item);
    }

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (llist_count>0){
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
        if (llist2->head != nullptr)  llist2->tail->next = llist1->tail;
        else llist2->head = llist2->tail = llist1->tail;
    }
    for (int i = 1; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
    }
    llist2->tail = llist1->tail;
    SinglyLinkedListNode* p;
    p = findMergeNode(llist1->head,llist2->head);
    if (p == nullptr)
        cout<<"NA";
    else
        cout<<p->data;

    //free_singly_linked_list(llist1->head);
    //free_singly_linked_list(llist2->head);

    return 0;
}




