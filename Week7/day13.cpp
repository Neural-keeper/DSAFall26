/*
binary trees
*/

// every node in a binary tree has 0, 1, or 2 children

/*
Characteristics:
1. Every node has at most 2 children
2. left child or right child

Types of binary tree:
Full: every node has either 0 or 2 children
Complete: all levels are full except potentially the last level
Perfect: all internal nodes have 2 children, and the leaf nodes are at the same level
Balanced: heights of left and right subtrees differ by at most one (true for every node)
*/

#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;


// no template because this is a simple tree to code, we'll oop it in the future
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
For binary tree nodes, we need a left child and a right child
*/

class BinaryTree {
private:
    TreeNode* root;

    // left -> self -> right
    void printInOrderHelper(TreeNode* node) {
        if (!node) return; // base case -> exit
        printInOrderHelper(node->left); // left
        cout << node->val << " "; // self
        printInOrderHelper(node->right); // right
    }

    // self -> left -> right
    void printPreOrderHelper(TreeNode* node) {
        if (!node) return; // base case -> exit
        cout << node->val << " "; // self
        printPreOrderHelper(node->left); // left
        printPreOrderHelper(node->right); // right
    }

    // left -> right -> self
    void printPostOrderHelper(TreeNode* node) {
        if (!node) return; // base case -> exit
        printPostOrderHelper(node->left); // left
        printPostOrderHelper(node->right); // right
        cout << node->val << " "; // self
    }

    void printLevelOrderHelper(TreeNode* node) {
        if (!node) return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // insert value - to the leftmost position on the last level
    void insert(int val) {
        // base case - empty tree
        if (!root) {
            root = new TreeNode(val);
            return;
        }

        queue<TreeNode*> q; // let's us level order traverse
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left) {
                node->left = new TreeNode(val);
                return;
            } else {
                q.push(node->left); // continue level order traversal
            }
            if (!node->right) {
                node->right = new TreeNode(val);
                return;
            } else {
                q.push(node->right); // continue level order traversal
            }
        }
    }

    void printLevelOrder() {
        printLevelOrderHelper(root);
    }

    void printInOrder() {
        printInOrderHelper(root);
    }

    void printPreOrder() {
        printPreOrderHelper(root);
    }

    void printPostOrder() {
        printPostOrderHelper(root);
    }
}; 

// now we test our code
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    /*
    Tree visual:

        10
       /  \
      5    15
     / \   / \
    3   7 12  18
    */

    cout << "Level Order: ";
    tree.printLevelOrder();
    cout << "\nIn Order: ";
    tree.printInOrder();
    cout << "\nPre Order: ";
    tree.printPreOrder();
    cout << "\nPost Order: ";
    tree.printPostOrder();
    cout << "\n\n";

    return 0;
}