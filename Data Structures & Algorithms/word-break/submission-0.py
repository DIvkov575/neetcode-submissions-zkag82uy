from functools import cache
class Trie:
    class Node():
        def __init__(self, end=False):
            self.children = {}
            self.end = end

    def __init__(self):
        self.root = Trie.Node()

    def add(self,word: str):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Trie.Node()
            node = node.children[char]
        node.end = True
    def check_prefix(self,word:str):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            else:
                node = node.children[char]
        return True
    def check(self,word:str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            else:
                node = node.children[char]
        return node.end

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        n = len(s)
        trie = Trie()
        for word in wordDict:
            trie.add(word)

        @cache
        def dp(idx):
            if idx > n:
                pass
            elif idx == n:
                return True
            
            for length in range(n-idx+1):
                if not trie.check_prefix(s[idx: idx+length]):
                    break
                if trie.check(s[idx:idx+length]) and dp(idx+length):
                    return True
            return False


        return dp(0)