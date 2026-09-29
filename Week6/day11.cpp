/*
Topic 1: How was your exam? Any lingering doubts from it? Or maybe you have feedback for me?
*/

/*
In other news, Arendil has defeated the shadow monster. Thalamir IV was impressed and lets him 
leave on his journey home, but not without a gift. He gives Arendil an apparatus that can 
allegedly teach him any skill, and a book along with it. Seeing the progression of 
pre-requisites for the specific ability was tiresome, so Arendil decides to build a tree 
of skills to visualize the dependencies. All skills start from the core skill, "Courage," which 
he's already accomplished. Now, we will build a tree to hold these skills. Each skill is 
a node, with a name and a list of children skills that depend on it, along with a "achieved?" 
boolean flag. 
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
            cout << "    ";
        }
        cout << (skill->achieved ? "[X] " : "[ ] ") << skill->name << endl;
        for (Skill* child : skill->children) {
            printTree(child, level + 1);
        }
    }
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

    cout << "Skill Tree v2:" << endl;
    skillTree.printTree(skillTree.root);

    return 0;
}