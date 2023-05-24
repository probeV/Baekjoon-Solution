from collections import deque
import sys
input=sys.stdin.readline

class Node(object):
    def __init__(self, key, data=None):
        self.key=key
        self.data=data
        self.children ={}
        self.fail = None

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


    def fail(self):
        queue=deque([self.head])
        self.head.fail=self.head

        while queue:
            curr_node=queue.popleft()
            for next in curr_node.children:
                child = curr_node.children[next]
                if curr_node is self.head: # 루트 바로 다음 노드
                    child.fail = self.head
                else:
                    f = curr_node.fail
                    while f is not self.head and next not in f.children:
                        f = f.fail

                    if next in f.children:
                        f = f.children[next]
                    child.fail = f

                queue.append(child)

    def search(self, string):
        curr_node=self.head
        for char in string:
            #정석 루트, 가다가 없으면 fail로 돌아가기
            while curr_node is not self.head and char not in curr_node.children:
                curr_node=curr_node.fail
            if char in curr_node.children: #찾으려 했던게 있을 때
                curr_node=curr_node.children[char]

            t=curr_node # 중간에 fail로 가는 곳에 답이 있는 지 체크
            while t.fail is not self.head:
                t=t.fail
                if t.data:
                    return True
                
            if curr_node.data:
                return True
        return False

                     
N=int(input())
trie=Trie()
for _ in range(N):
    trie.insert(input().strip())

Q=int(input())
arr=[]
for _ in range(Q):
    arr.append(input().strip())

trie.fail()
for string in arr:
    if trie.search(string):
        print("YES")
    else:
        print("NO")