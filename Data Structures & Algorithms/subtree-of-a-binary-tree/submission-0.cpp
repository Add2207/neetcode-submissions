/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to check if two trees (p and q) are exactly identical
    bool areIdentical(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are identical at this point
        if (!p && !q) {
            return true;
        }
        // If one node is null and the other is not, they are not identical
        if (!p || !q) {
            return false;
        }
        // If current node values are different, they are not identical
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return areIdentical(p->left, q->left) && areIdentical(p->right, q->right);
    }

    // Main function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is null, it's always considered a subtree of any tree (empty tree is a subtree)
        if (!subRoot) {
            return true;
        }
        
        // If root is null but subRoot is not null, subRoot cannot be a subtree
        if (!root) {
            return false;
        }
        
        // 1. Check if the tree starting at 'root' is identical to 'subRoot'
        if (areIdentical(root, subRoot)) {
            return true;
        }
        
        // 2. If not, recursively check if 'subRoot' is a subtree of 'root->left'
        // OR if 'subRoot' is a subtree of 'root->right'
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
