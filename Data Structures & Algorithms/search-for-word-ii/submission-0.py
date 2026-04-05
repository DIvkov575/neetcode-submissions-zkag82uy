from typing import List

class Trie:
    class Node:
        def __init__(self):
            self.children = {}
            self.word_end = False  # mark the end of a word

    def __init__(self):
        self.root = Trie.Node()

    def add(self, word: str):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = Trie.Node()
            node = node.children[char]
        node.word_end = True  # mark complete word

    def check(self, word: str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.word_end  # must be a complete word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m = len(board)
        n = len(board[0])
        directions = [(1,0), (-1,0), (0,1), (0,-1)]
        max_len = 10  # as you said

        trie = Trie()

        # DFS to build all paths on the board up to length max_len
        for i in range(m):
            for j in range(n):
                visited = set()
                path = []

                def dfs(x, y):
                    path.append(board[x][y])
                    visited.add((x, y))

                    trie.add("".join(path))  # insert current path

                    if len(path) == max_len:
                        visited.remove((x, y))
                        path.pop()
                        return

                    for dx, dy in directions:
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited:
                            dfs(nx, ny)

                    visited.remove((x, y))
                    path.pop()

                dfs(i, j)

        # check each word in the Trie
        output = []
        for word in words:
            if trie.check(word):
                output.append(word)

        return output