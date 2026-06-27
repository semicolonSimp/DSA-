#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Info {
public:
    int minVal;
    int maxVal;
    int size;
    bool isBST;

    Info(int mi, int ma, int sz, bool bst) {
        minVal = mi;
        maxVal = ma;
        size = sz;
        isBST = bst;
    }
};

int ans = 0;

Info helper(Node* root) {

    // Empty tree
    if (root == NULL) {
        return Info(INT_MAX, INT_MIN, 0, true);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    // Check BST condition
    if (left.isBST && right.isBST &&
        root->data > left.maxVal &&
        root->data < right.minVal) {

        int currMin = min(root->data, left.minVal);
        int currMax = max(root->data, right.maxVal);
        int currSize = left.size + right.size + 1;

        ans = max(ans, currSize);

        return Info(currMin, currMax, currSize, true);
    }

    // Not BST
    return Info(INT_MIN, INT_MAX, 0, false);
}

int LargestBST(Node* root) {
    helper(root);
    return ans;
}

int main() {

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(1);
    root->left->right = new Node(8);

    root->right->right = new Node(7);

    cout << LargestBST(root) << endl;

    return 0;
}