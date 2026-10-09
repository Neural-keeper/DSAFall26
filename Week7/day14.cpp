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

    // helper to find in-order successor of a node
    TreeNode* findMin(TreeNode* node) const { // technically findMin
        // note - we're finding the minimum value in the subtree with the given node as the root
        // minimum value - leftmost with no left child
        TreeNode* current = node;
        while (current && current->left) {
            current = node->left;
        }
        return current;
    }

    TreeNode* removeNode(TreeNode* node, int val) {
        // empty tree 
        if (!node) {
            return nullptr;
        }

        // find node to delete and remove at the same time
        if (val < node->val) {
            // go left - update left
            node->left = removeNode(node->left, val);
        } else if (val > node->val) {
            // go right - right right
            node->right = removeNode(node->right, val);
        } else if (!node->left && !node->right) {
            // case 1 - no children
            delete node;
            return nullptr; 
        } else if (!node->left) {
            // case 2 (a) - one child - only right child
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild; 
        } else if (!node->right) {
            // case 2 (b) - one child - only left child
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        } else {
            // find in-order successor to replace ndoe
            TreeNode* successor = findMin(node->right);
            node->val = successor->val;
            node->right = removeNode(node->right, successor->val);
        }

        return node;
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
    2. If the node has no children, simply remove it
    3. If the node has one child, replace the node with its child
    4. If the node has two children, find the in-order successor, replace the node's value with the successor's value, and delete the successor
    */
    void remove(int val) {
        root = removeNode(root, val); // we're using a helper because removing a node can change the root itself 
        // the helper circumvents this by returning the new root after deletion
    }

    // traverse, call our in order printer
    void traverse() const {
        traverseInOrder(root);
        cout << endl; // flush output
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

    bst.remove(10);
    bst.traverse();
    bst.remove(19);
    bst.remove(71);
    bst.remove(2);
    bst.remove(3);
    bst.traverse();
    bst.remove(25);
    bst.remove(46);
    bst.traverse();
    bst.remove(15);
    bst.traverse(); // Final check to ensure the tree is empty after all removals.

    return 0;
}