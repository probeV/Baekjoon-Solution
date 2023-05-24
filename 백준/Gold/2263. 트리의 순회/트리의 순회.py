import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

parent = [0] * (n + 1)
for i in range(n):
    parent[inorder[i]] = i

def preorder(inorder_start, inorder_end, postorder_start, postorder_end):
    if (inorder_start > inorder_end) or (postorder_start > postorder_end):
        return
    
    root = postorder[postorder_end]
    
    leftNode = parent[root] - inorder_start
    rightNode = inorder_end - parent[root]
    
    print(root, end = " ")
    preorder(inorder_start, inorder_start + leftNode - 1, postorder_start, postorder_start + leftNode - 1)
    preorder(inorder_end - rightNode + 1, inorder_end, postorder_end - rightNode, postorder_end - 1)

preorder(0, n - 1, 0, n - 1)