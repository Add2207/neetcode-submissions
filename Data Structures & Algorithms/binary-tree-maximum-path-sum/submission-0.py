# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxi = -float('inf')
        def maxSum(node, summ):
            nonlocal maxi
            if not node:
                return 0
            lSum = maxSum(node.left, maxi)
            rSum = maxSum(node.right, maxi)
            maxi = max(maxi, lSum + rSum + node.val)
            return node.val + max(lSum, rSum)
        maxSum(root, 0)
        return maxi
