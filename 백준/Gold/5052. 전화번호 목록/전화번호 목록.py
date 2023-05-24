import sys
input=sys.stdin.readline

t=int(input())

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
            curr_node=curr_node.children[char]

        if curr_node.children:
            return False
        else:
            return True


for _ in range(t):
    n=int(input())
    number=[]

    trie=Trie()
    for i in range(n):
        temp=list(input().strip())
        number.append(temp)
        trie.insert(temp)

    l=True
    number.sort()
    for num in number:
        if not trie.search(num):
            l=False
            break
    
    if l:
        print("YES")
    else:
        print("NO")