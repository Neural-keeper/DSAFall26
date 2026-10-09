// UPDATED CODE IN DAY14.CPP, LOOK THERE FOR FULL FUNCTIONAL CODE


// an array sorted in ascending order
/*
input array = [10, 19, 71, 2, 25, 15, 46, 3]
sorted array = [2, 3, 10, 15, 19, 25, 46, 71]

Binary Search algorithm O(logn)
1st step - compare 46 to 15, greater than, look right
2nd step - compare 46 to 25, greater than, look right
3rd step - compare 46 to 46, equal to, value found
*/

/*
Binary Search Tree (BST)
These are the key properties and operations of a Binary Search Tree:

1. Properties:
   - Each node has a value, a left child, and a right child.
   - The left subtree of a node contains only nodes with values less than the node's value.
   - The right subtree of a node contains only nodes with values greater than the node's value.
   - Both the left and right subtrees must also be binary search trees.

2. Operations:
   - Insertion: Add a new node while maintaining the BST properties.
   - Deletion: Remove a node and rearrange the tree to maintain BST properties.
   - Search: Find a node with a specific value.
   - Traversal: Visit all nodes in a specific order (in-order, pre-order, post-order, level-order).
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}; 

class BinarySearchTree {
private:
    TreeNode* root;

    void traverseInOrder(TreeNode* node) const {
        if (!node) {
            return;
        }

        traverseInOrder(node->left);
        cout << node->val << " ";
        traverseInOrder(node->right);
    }

    void deleteTree(TreeNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        deleteTree(root);
    }

    TreeNode* getRoot() const {
        return root;
    }

    // insert a value val
    /*
    1. is root empty? if so, add as root
    2. start from root, traverse tree
    3. if val < current node val, go left
    4. if val > current node val, go right
    5. repeat 3 and 4 until appropriate position found
    6. insert at the found position
    */
    void insert(int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        TreeNode* current = root;
        while (true) { // "forever" while loop, condition check inside
            if (val < current->val) {
                if (!current->left) {
                    current->left = new TreeNode(val);
                    return;
                } 
                current = current->left;
            } else {
                if (!current->right) {
                    current->right = new TreeNode(val);
                    return;
                }
                current = current->right;
            }
        }
    }

    // search - find the node with value val
    /*
    1. start at root
    2. if current node value is null, val not present
    3. if current node value is val, found, return current node
    4. if val < current val, look left
    5. if not, look right
    */
    TreeNode* search(int val) const {
        TreeNode* current = root;
        while (current) {
            if (current->val == val) {
                return current;
            }

            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return nullptr;
    }

    // to remove a value, you must replace it with it's successor 
    // in-order successor - smallest value on the right subtree, will take it's place
    /*
    1. Find the node to be deleted
    2. 
    */
    void remove(int val) {
        return;
    }

    // traverse, call our in order printer
    void traverse() const {
        traverseInOrder(root);
        cout << "\n";
    }
};

int main() {
    BinarySearchTree bst;
    // input array = [10, 19, 71, 2, 25, 15, 46, 3]
    bst.insert(10);
    bst.insert(19);
    bst.insert(71);
    bst.insert(2);
    bst.insert(25);
    bst.insert(15);
    bst.insert(46);
    bst.insert(3);
    bst.traverse();

    /*
        10     
       /   \
      2     19
       \   /  \
        3 15  71
              /
             25
              \
              46
    */

    // bst.remove(10);
    // bst.traverse();
    // bst.remove(5);
    // bst.traverse();
    // bst.remove(15);
    // bst.traverse();
    // bst.traverse(); // Final check to ensure the tree is empty after all removals.
}