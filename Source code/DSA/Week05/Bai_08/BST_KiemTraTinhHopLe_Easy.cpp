/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

                return root;
            }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
bool checkBST(Node* root) {
//###INSERT CODE HERE -
    if (root == nullptr)
        return true;
    if (root->left != nullptr && root->left->data > root->data)
        return false;
    if (root->right != nullptr && root->right->data < root->data)
        return false;
    if (!checkBST(root->left)) // kiem tra cay ben trai ko hop le
        return false;
    if (!checkBST(root->right)) // kiem tra cay ben phai ko hop le
        return false;
    return true;
    /*     this is the solution without recursion
        stack<Node*> nodes;
        Node* prev = nullptr;
        while (root != nullptr || !nodes.empty()) {
            while (root != nullptr) {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if (prev != nullptr && prev->data >= root->data)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    */
}


}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    std::cout<<myTree.checkBST(root);

    return 0;
}