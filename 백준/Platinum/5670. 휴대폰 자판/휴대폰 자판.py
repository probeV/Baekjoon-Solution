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
        curr_node = self.head.children[string[0]]
        count=1
        for char in string[1:]:
            if len(curr_node.children)==1 and not curr_node.data:
                curr_node=curr_node.children[char]
                pass
            else:
                curr_node=curr_node.children[char]
                count+=1
        return count
    
while True:
    try:
        N=int(input())
        Dict=[]
        result=0
        trie=Trie()
        for _ in range(N):
            temp=input().strip()
            trie.insert(temp)
            Dict.append(temp)
        for string in Dict:
            result+=trie.search(string)
        result=result/len(Dict)
        print('%.2f' %round(result,2))
    except:
        break