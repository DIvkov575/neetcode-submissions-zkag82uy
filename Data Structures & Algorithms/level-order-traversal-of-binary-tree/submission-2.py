# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root: return []

        trv=[[]]

        queue = [(root,0)]
        while len(queue) != 0:
            elt,level = queue.pop(0)

            if len(trv) < level+1: trv += [[]] 

            trv[level].append(elt.val) 
                    
            if elt.left: queue.append((elt.left, level+1))
            if elt.right: queue.append((elt.right, level+1))

        return trv
		
        
