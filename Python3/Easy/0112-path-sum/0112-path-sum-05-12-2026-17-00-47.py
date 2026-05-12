# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        
        # Tree empty ah irundha valid path irukadhu
        if root == None:
            return False

        # Current node leaf node ah check panrom
        # (left um right um illa na leaf node)
        if root.left == None and root.right == None:
            
            # Leaf node value target sum ku equal ah irundha answer True
            if targetSum == root.val:
                return True
            else:
                return False

        # Current node value ah target la irundhu subtract panni
        # remaining sum ah next nodes ku anuprom
        remaining = targetSum - root.val

        # Left subtree la valid path iruka nu check panrom
        LEFTresult = self.hasPathSum(root.left, remaining)

        # Right subtree la valid path iruka nu check panrom
        RIGHTresult = self.hasPathSum(root.right, remaining)

        # Left or right edhavadhu oru path match aana pothum
        return LEFTresult or RIGHTresult