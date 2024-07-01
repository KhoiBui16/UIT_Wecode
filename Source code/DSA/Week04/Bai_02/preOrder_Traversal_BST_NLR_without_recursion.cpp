/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
preOrder
###End banned keyword*/

#include <bits/stdc++.h>
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

    void preOrder(Node *root) {
//###INSERT CODE HERE -
        if (root == nullptr)
            return;

        stack <Node*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node* nodeTree = nodeStack.top();
            nodeStack.pop();
            cout << nodeTree->data << " ";

            // Them node con phai vao stack truoc neu ton tai
            if (!(nodeTree->right == nullptr))
                nodeStack.push(nodeTree->right);

            // Them node con trai vao stack sau neu ton tai
            if (!(nodeTree->left == nullptr))
                nodeStack.push(nodeTree->left);
        }

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

    myTree.preOrder(root);

    return 0;
}