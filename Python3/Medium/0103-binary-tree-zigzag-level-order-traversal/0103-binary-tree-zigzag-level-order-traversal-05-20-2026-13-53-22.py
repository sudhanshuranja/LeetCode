# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def traverse(temp, depth):
            if not temp:
                return
            if len(arr) == depth:
                arr.append([])
            if depth % 2 == 0:
                arr[depth].append(temp.val)
            else:
                arr[depth].insert(0, temp.val)
            traverse(temp.left, depth + 1)
            traverse(temp.right, depth + 1)
        
        arr = []
        traverse(root, 0)
        return arr