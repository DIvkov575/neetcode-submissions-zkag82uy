class Node:
    def __init__(self):
        self.edges = {}
        self.end = False

class PrefixTree:
    

    def __init__(self):
        self.root = Node()
        

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch not in cur.edges:
                cur.edges[ch] = Node()
            cur = cur.edges[ch]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            if ch not in cur.edges:
                return False
            cur = cur.edges[ch]
        return cur.end
        

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            if ch not in cur.edges:
                return False

            cur = cur.edges[ch]
        return True
        
        