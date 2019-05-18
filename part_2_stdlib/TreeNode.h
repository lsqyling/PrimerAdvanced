//
// Created by shiqing on 18-10-11.
//

#ifndef PRIMER_TREENODE_H
#define PRIMER_TREENODE_H

#include <string>

// Value like `TreeNode`. When we copy a `TreeNode`, we copy all the subtree
// from current node.
class TreeNode {
public:
    TreeNode() : count(0), left(nullptr), right(nullptr) {}
    TreeNode(const std::string &s, int c)
            : value(s), count(c), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &);

    ~TreeNode();

    TreeNode &operator=(const TreeNode &);

    // insert
    // remove
    // tranverse

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
    // Note that the valid state for the `left` and `right` pointer is either
    // `nullptr` or a subtree node. So that we must check these pointers every
    // time before dereferencing them.

// First version: helper funtion for copy constructor and destructor *
  static void copyTree(TreeNode *, const TreeNode *);
  static void destroyTree(TreeNode *);
};



#endif //PRIMER_TREENODE_H
