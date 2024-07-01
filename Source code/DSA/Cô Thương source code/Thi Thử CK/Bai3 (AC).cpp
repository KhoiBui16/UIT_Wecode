/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
###End banned keyword*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

//###INSERT CODE HERE -

int depth(TREE T)
{
    if (!T) return 0;
    return max(1 + depth(T->left), 1 + depth(T->right));
}

void Fun(TREE root)
{
    if (!root) 
    {
        cout << "Empty Tree";
        return;
    }
    int l_Height = depth(root->left), r_Height = depth(root->right);
    if (l_Height - r_Height > 0) 
    {
        cout << -1;
        return;
    }
    else if (l_Height - r_Height < 0) 
    {
        cout << 1;
        return;
    }
    else 
    {
        cout << 0;
        return;
    }
}


int main() {
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num=duyetNLR.size()-1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
