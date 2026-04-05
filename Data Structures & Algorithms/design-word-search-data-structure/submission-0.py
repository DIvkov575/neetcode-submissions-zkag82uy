from typing import *
class Node:
    def __init__(self):
        self.children: Dict[str, Node] = {}
        self.end: bool = False

class WordDictionary:

    def __init__(self):
        self.root = Node()
        

    def addWord(self, word: str) -> None:
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = Node()
            node = node.children[ch]
        node.end = True
        

                
        

    def search(self, word: str) -> bool:
        def dfs(idx, node):
            if idx == len(word): return node.end

            if word[idx] == ".":
                for node_key in node.children:
                    if dfs(idx+1, node.children[node_key]): return True
                return False
            elif word[idx] in node.children:
                return dfs(idx+1, node.children[word[idx]])
            else:
                return False
        return dfs(0, self.root)
        
