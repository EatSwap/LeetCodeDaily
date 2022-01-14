#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	~TreeNode() { delete this->left; delete this->right; }
};

/**
 * 701. Insert into a Binary Search Tree
 * You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 * Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
 */

class Solution {
public:
	static TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root)
			return new TreeNode(val);
		if (val > root->val) {
			if (root->right) {
				insertIntoBST(root->right, val);
			} else {
				root->right = new TreeNode(val);
			}
		} else if (val < root->val) {
			if (root->left) {
				insertIntoBST(root->left, val);
			} else {
				root->left = new TreeNode(val);
			}
		} else {
			return nullptr;
		}
		return root;
	}
};