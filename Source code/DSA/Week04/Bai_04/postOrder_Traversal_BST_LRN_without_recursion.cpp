/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
postOrder
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

    void postOrder(Node *root) {
//###INSERT CODE HERE -
        if (!root) return;
        stack <Node*> treeNode;
        stack <int> result;
        treeNode.push(root);
        while (!treeNode.empty()) {
            Node* node = treeNode.top();
            treeNode.pop();
            result.push(node->data);

            // Thêm node con trái trước để nó được duyệt cuối cùng
        if (node->left) 
            treeNode.push(node->left);

        // Thêm node con phải sau để nó được duyệt sau node con trái
        if (node->right)
            treeNode.push(node->right);
        }

        // In kết quả từ stack kết quả, ta sẽ được thứ tự post-order
        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
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

    myTree.postOrder(root);

    return 0;
}