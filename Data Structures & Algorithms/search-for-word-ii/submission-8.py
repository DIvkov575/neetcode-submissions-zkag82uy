from typing import List

class Trie:
    class Node:
        def __init__(self):
            self.children = {}
            self.word_end = None  # store word at end node for easy collection

    def __init__(self):
        self.root = Trie.Node()

    def add(self, word: str):
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = Trie.Node()
            node = node.children[c]
        node.word_end = word  # store complete word for easy output


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m, n = len(board), len(board[0])
        trie = Trie()
        for word in words:
            trie.add(word)
        output = []

        def dfs(x, y, node):
            char = board[x][y]
            if char not in node.children:
                return
            child = node.children[char]

            if child.word_end:  # word found
                output.append(child.word_end)
                child.word_end = None  # avoid duplicates

            board[x][y] = '#'  # mark visited

            for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
                nx, ny = x+dx, y+dy
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] != '#':
                    dfs(nx, ny, child)

            board[x][y] = char  # unmark

        for i in range(m):
            for j in range(n):
                dfs(i, j, trie.root)

        return output