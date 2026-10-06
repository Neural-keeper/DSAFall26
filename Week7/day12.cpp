/*
start - questions + incentives introduction
end - more questions
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue> // for level order traversal
#include <algorithm> // for max function

using namespace std;

// going back to not so secure tree for simplicity
struct Node {
    int val; // stores integer value
    vector<Node*> children;

    Node(int value) : val(value) {}
};

class NaryTree {
private:
    void deleteSubtree(Node* node) {
        if (node == nullptr) return; // base case

        for (Node* child : node->children) {
            deleteSubtree(child); // recursive call for every child
        }

        delete node; // delete the current node after its children have been deleted
    }
public:
    Node* root;

    // constructor
    NaryTree() : root(nullptr) {}

    // destructor
    ~NaryTree() {
        deleteSubtree(root);
    }

    void printPostOrder(Node* node) {
        if (node == nullptr) return; // base case

        for (Node* child : node->children) {
            printPostOrder(child); // recursive call for every child
        }

        cout << node->val << " "; // print the current node's value after its children have been printed
        // fundementally dfs - post order traversal - children first, then me
    }

    /*
    Leetcode 559 - Maximum Depth of N-ary Tree
    Given a n-ary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
    */
    // depth first search (DFS) to find the maximum depth of the tree
    int maxDepth(Node* node) {
        if (node == nullptr) return 0;

        int maxChildDepth = 0;
        for (Node* child : node->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(child));
        }

        return 1 + maxChildDepth;
    }

    // level order traversal (BFS) to print the tree level by level - iterative
    void levelOrderTraversal(Node* node) {
        if (node == nullptr) return; // base case - empty tree

        vector<Node*> currentLevel;
        currentLevel.push_back(node);

        while (!currentLevel.empty()) {
            vector<Node*> nextLevel;

            for (Node* currentNode : currentLevel) {
                cout << currentNode->val << " ";
                
                for (Node* child : currentNode->children) {
                    nextLevel.push_back(child);
                }
            }

            cout << endl;
            currentLevel = nextLevel;
        }
    }

    // /*
    // Leetcode 543 - Diameter of N-ary Tree
    // Given a n-ary tree, you need to compute the length of the diameter of the
    // tree. The diameter of a n-ary tree is the length of the longest path between any two nodes 
    // in the tree. This path may or may not pass through the root.
    // */
    // int diameter(Node* node) {
    //     if (node == nullptr) return 0;

    //     int maxDiameter = 0;
    //     int firstMaxDepth = 0;
    //     int secondMaxDepth = 0;

    //     for (Node* child : node->children) {
    //         int childDepth = maxDepth(child);

    //         if (childDepth > firstMaxDepth) {
    //             secondMaxDepth = firstMaxDepth;
    //             firstMaxDepth = childDepth;
    //         } else if (childDepth > secondMaxDepth) {
    //             secondMaxDepth = childDepth;
    //         }

    //         maxDiameter = max(maxDiameter, diameter(child));
    //     } 

    //     return max(maxDiameter, firstMaxDepth + secondMaxDepth);
    // }
};


int main() {
    NaryTree tree;

    // Create a sample N-ary tree
    tree.root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    tree.root->children.push_back(child1);
    tree.root->children.push_back(child2);
    tree.root->children.push_back(child3);

    child1->children.push_back(new Node(5));
    child1->children.push_back(new Node(6));

    child2->children.push_back(new Node(7));

    /*
           1
        /  |  \
       2   3   4
      / \  |
     5   6 7
    */


    // Print the tree in post-order
    cout << "Post-order traversal: ";
    tree.printPostOrder(tree.root);
    cout << endl;

    // Find the maximum depth of the tree
    int depth = tree.maxDepth(tree.root);
    cout << "Maximum depth of the tree: " << depth << endl; // expect value : 3

    // Perform level order traversal
    cout << "Level order traversal: ";
    tree.levelOrderTraversal(tree.root);
    cout << endl;

    // // Find the diameter of the tree
    // int dia = tree.diameter(tree.root);
    // cout << "Diameter of the tree: " << dia << endl;

    return 0;
}