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
    int height(TreeNode* node)
    {
        int diameter = 0;

        if(!node) return 0;

        int lHeight = height(node->left);
        int rHeight = height(node->right);

        return 1 + max(lHeight, rHeight);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;
        if(!root) return 0;

        int lHt = height(root->left);
        int rHt = height(root->right);
        return max(diameter, lHt + rHt);
    }
};
