//
// Created by shiqing on 18-10-11.
//

#include "TreeNode.h"


// First version: copy constructor and destructor *
void TreeNode::copyTree(TreeNode *lhs, const TreeNode *rhs) {
  // Both lhs and rhs must NOT be nullptr
  lhs->value = rhs->value;
  lhs->count = rhs->count;
  if (rhs->left) {
    lhs->left = new TreeNode;  // call default constructor of `TreeNode`
    copyTree(lhs->left, rhs->left);
  } else
    lhs->left = nullptr;
  if (rhs->right) {
    lhs->right = new TreeNode;  // call default constructor of `TreeNode`
    copyTree(lhs->right, rhs->right);
  } else
    lhs->right = nullptr;
}
void TreeNode::destroyTree(TreeNode *n) {
  // n can be a nullptr
  if (!n) return;
  destroyTree(n->left);
  n->left = nullptr;
  destroyTree(n->right);
  n->right = nullptr;
  delete n;  // This statement will cause delete subtree multiple times if we
             // forget to assign n->left and n->right to nullptr.
}
/*TreeNode::TreeNode(const TreeNode &n) {
  copyTree(this, &n);
}
TreeNode::~TreeNode() {
  destroyTree(left);
  destroyTree(right);
}*/

/* Second version: without helper function */
TreeNode::TreeNode(const TreeNode &n)
        : value(n.value), count(n.count), left(nullptr), right(nullptr) {
    if (n.left)
        left = new TreeNode(*n.left);  // recursively call copy constructor
    if (n.right)
        right = new TreeNode(*n.right);  // recursively call copy constructor
}

TreeNode::~TreeNode() {
    delete left;  // recursively call destructor on left subtree node
    delete right;  // recursively call destructor on right subtree node
    // Note that when left or right is nullptr, delete will do nothing, so that
    // the recursion will be stopped.
}

TreeNode &TreeNode::operator=(const TreeNode &n) {
    value = n.value;
    count = n.count;

    TreeNode *tmp = nullptr;
    if (n.left)
        tmp = new TreeNode(*n.left);  // recursively call copy constructor
    delete left;  // recursively call destructor
    left = tmp;

    tmp = nullptr;
    if (n.right)
        tmp = new TreeNode(*n.right);  // recursively call copy constructor
    delete right;  // recursively call destructor
    right = tmp;

    return *this;
}
