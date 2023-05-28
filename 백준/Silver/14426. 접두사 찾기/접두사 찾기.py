import sys
input=sys.stdin.readline

class Node(object):
    def __init__(self, key, data=None):
        self.key=key
        self.data=data
        self.children ={}

class Trie(object):
    def __init__(self):
        self.head=Node(None)

    def insert(self, string):
        curr_node=self.head

        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)
            curr_node=curr_node.children[char]
        curr_node.data=string

    def search(self, string):
        curr_node = self.head
        for char in string:
            if char in curr_node.children:
                curr_node=curr_node.children[char]
            else:
                return False

        if curr_node.children or curr_node.data:
            return True
        else:
            return False

N,M=map(int, input().split())
count=0
trie=Trie()
for _ in range(N):
    trie.insert(list(input().strip()))

for _ in range(M):
    temp=list(input().strip())
    if trie.search(temp):
        count+=1
print(count)