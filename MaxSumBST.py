# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class NodeVal:
    def __init__(self,isBST, minNode, maxNode, maxSum,maxSize):
        self.isBST = isBST
        self.minNode = minNode
        self.maxNode = maxNode
        self.maxSum = maxSum
        self.maxSize = maxSize


class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        
        res  = 0
        def postorder(node: TreeNode):
            if not node:
                return NodeVal(
                    isBST=True,
                    minNode=float("inf"),
                    maxNode=-1 * float("inf"),
                    maxSum=0,
                    maxSize=0
                )
            
            left = postorder(node.left)
            right = postorder(node.right)

            if left.isBST and right.isBST and left.maxNode < node.val < right.minNode:
                nonlocal res
                res = max(res,left.maxSum + right.maxSum + node.val)
                return NodeVal(
                isBST= True ,
                minNode=min(left.minNode, right.minNode,node.val),
                maxNode=max(left.maxNode, right.maxNode,node.val),
                maxSum=left.maxSum + right.maxSum + node.val,
                maxSize= left.maxSize + right.maxSize + 1
            )

            return NodeVal(
                isBST= False,
                minNode=min(left.minNode, right.minNode,node.val),
                maxNode=max(left.maxNode, right.maxNode,node.val),
                maxSum=left.maxSum + right.maxSum + node.val,
                maxSize=max(left.maxSize , right.maxSize)
            )

        r = postorder(root)
        print(r.isBST, " ", r.maxSize)
        return res
