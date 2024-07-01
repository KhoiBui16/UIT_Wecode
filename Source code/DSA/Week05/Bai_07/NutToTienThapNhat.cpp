/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
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

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    Node *lca(Node *root, int v1,int v2) {
//###INSERT CODE HERE -
        while (root != nullptr) {
            if (root->data < v1 && root->data < v2)
                root = root->right;
            else if (root->data > v1 && root->data > v2)
                root = root->left;
            else
                break; // day la node to tien khi 1 trong 2 node v1 và v2 nam o 2 phia cua root
        }
        return root;
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

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);
    
    std::cout << ans->data;

    return 0;
}
