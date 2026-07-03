class Solution {
public:
    int diameter = 0;

    int height(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int lHeight = height(node->left);
        int rHeight = height(node->right);

        // Update the global diameter with the maximum diameter found so far.
        // The diameter at the current node is the sum of the heights of its left and right subtrees.
        diameter = std::max(diameter, lHeight + rHeight);

        // Return the height of the current subtree.
        return 1 + std::max(lHeight, rHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};