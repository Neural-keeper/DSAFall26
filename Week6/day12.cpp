/*
This session is supposed to be on Friday, but I will be out of town. 
So, this may or may not happen on Friday. It could be rescheduled to next week. 

More on Trees:
- Preorder Traversal
- Postorder Traversal
- Path Sum
- No. of leaf nodes
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Skill {
    string name;
    bool achieved;
    vector<Skill*> children = {}; // vector holds children pointers
    int numChildren;
    
    Skill(string skillName) : name(skillName), achieved(false), numChildren(0) {}
}; // using struct to create skill node type

class SkillTree {
private:
    void deleteTree(Skill* skill) {
        for (Skill* child : skill->children) {
            deleteTree(child);
        }
        delete skill;
    } // recursive deletion of nodes in a tree

public:
    Skill* root;

    SkillTree() {
        root = new Skill("Courage");
        root->achieved = true;
    }

    ~SkillTree() {
        deleteTree(root);
    }

    Skill* addSkill(Skill* parent, string skillName) {
        Skill* newSkill = new Skill(skillName);
        parent->children.push_back(newSkill);
        parent->numChildren++;
        return newSkill;
    }

    void markAchieved(Skill* skill) {
        skill->achieved = true;
    }

    void printTree(Skill* skill, int level = 0) {
        for (int i = 0; i < level; i++) {
            cout << " ";
        }
        cout << (skill->achieved ? "[X] " : "[ ] ") << skill->name << endl;
        for (Skill* child : skill->children) {
            printTree(child, level + 1);
        }
    }

    void printPreorder(Skill* skill) {
        if (skill == nullptr) return; // base case
        cout << skill->name << " ";
        for (Skill* child : skill->children) {
            printPreorder(child);
        }
    } // preorder - me first, then my childre

    void printPostorder(Skill* skill) {
        if (skill == nullptr) return;
        for (Skill* child : skill->children) {
            printPostorder(child);
        }
        cout << skill->name << " ";
    } // children first, then me

    int countLeafNode(Skill* skill) {
        if (skill == nullptr) return 0;
        if (skill->numChildren == 0) return 1;
        int leafCount = 0;
        for (Skill* child : skill->children) {
            leafCount += countLeafNode(child);
        }
        return leafCount;
    }

    // recursively implement hadPathSum method
    bool hasPathSum(Skill* skill, int targetSum, int currentSum) {
        // base case
        if (skill == nullptr) return false;
        currentSum += 1;
        // base case - leaf node
        if (skill->numChildren == 0) {
            return currentSum == targetSum; // return true if at leaf, target sum achieved
        }
        // look through children recursive call
        for (Skill* child : skill->children) {
            if (hasPathSum(child, targetSum, currentSum)) {
                return true;
            }
        }
        return false;
    }

    /*
    target1 = 3
    
          A         currentSumA = 1 A return True
        /   \
       B     C      currentSumB = 2 B return True
     /  \
    D    E          currentSumD = 3 D returns True
    */

    /*
    target2 = 5
    
          A         currentSumA = 1 A returns False
        /   \
       B     C      currentSumB = 2 B returns False -> A looks at C -> currentSumC = 2 C returns false
     /  \
    D    E          currentSumD = 3 D returns false -> B looks at E -> currentSumE = 3 E returns false
    */

}; // skill tree tree

int main() {
    SkillTree skillTree;

    /*
    Courage
        Bravery [X]
            Leadership
            Teamwork
        Resilience
            Adaptability [X]
            Problem Solving
    */

    // Adding skills to the tree
    Skill* courage = skillTree.root;
    Skill* bravery = skillTree.addSkill(courage, "Bravery");
    Skill* resilience = skillTree.addSkill(courage, "Resilience");

    skillTree.addSkill(bravery, "Leadership");
    skillTree.addSkill(bravery, "Teamwork");

    skillTree.addSkill(resilience, "Adaptability");
    skillTree.addSkill(resilience, "Problem Solving");

    // Marking some skills as achieved
    skillTree.markAchieved(bravery);
    skillTree.markAchieved(resilience->children[0]); // Adaptability

    // Printing the skill tree
    cout << "Skill Tree:" << endl;
    skillTree.printTree(skillTree.root);

    Skill* elemental = skillTree.addSkill(courage, "Elemental Powers");

    Skill* fire = skillTree.addSkill(elemental, "Fire");
    Skill* water = skillTree.addSkill(elemental, "Water");
    Skill* air = skillTree.addSkill(elemental, "Air");
    Skill* earth = skillTree.addSkill(elemental, "Earth");

    cout << "Elemental has " << elemental->numChildren << " children." << endl;

    Skill* fireCharge = skillTree.addSkill(fire, "Fire Charge");

    cout << "Skill Tree v2:" << endl;
    skillTree.printTree(skillTree.root);
    skillTree.printPreorder(skillTree.root);
    cout << "Now-" << endl;
    skillTree.printPostorder(skillTree.root);
    cout << "\n";
    cout << "Number of leaves in the skill tree: " << skillTree.countLeafNode(skillTree.root) << endl;

    cout << "Sub skill tree - Elemental Powers" << endl;
    skillTree.printTree(elemental);
    skillTree.printPreorder(elemental);
    cout << "\n";
    skillTree.printPostorder(elemental);
    
    cout << "\nNumber of leaf nodes" << skillTree.countLeafNode(skillTree.root) << endl;

    cout << "Is there a path with sum 8? " << (skillTree.hasPathSum(skillTree.root, 8, 0) ? "Yes" : "No") << endl;

    return 0;
}