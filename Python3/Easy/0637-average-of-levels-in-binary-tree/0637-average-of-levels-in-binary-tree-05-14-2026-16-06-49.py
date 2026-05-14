# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if not root: return []
        res, queue = [], deque([root])

        while queue:
            level_sum = 0
            count = len(queue)

            for _ in range(count):
                node = queue.popleft()
                level_sum += node.val
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)

            res.append(level_sum / count)

        return res