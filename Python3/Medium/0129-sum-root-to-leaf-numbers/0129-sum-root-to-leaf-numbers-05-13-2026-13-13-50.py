# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def is_leaf(self, root: TreeNode) -> bool:
        if root.left is None and root.right is None:
            return True

        return False

    def root_to_leaf(self, root:Optional[TreeNode], curr: int) -> None:
        if root is None:
            return 

        if self.is_leaf(root):
            curr = curr * 10 + root.val
            self.sum_ += curr
            return

        curr = curr * 10 + root.val
        self.root_to_leaf(root.left, curr)
        self.root_to_leaf(root.right, curr)

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.sum_: int = 0
        curr: int = 0

        self.root_to_leaf(root, curr)

        return self.sum_
        