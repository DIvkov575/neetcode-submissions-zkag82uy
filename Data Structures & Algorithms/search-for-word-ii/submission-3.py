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
        return node.word_end

    def starts_with(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        output = set()  # use set to avoid duplicates
        m, n = len(board), len(board[0])
        directions = [(1,0), (-1,0), (0,1), (0,-1)]
        max_len = 10

        trie = Trie()
        for word in words:
            trie.add(word)

        def dfs(x, y, visited, cur_word):
            cur_word += board[x][y]
            visited.add((x, y))

            if not trie.starts_with(cur_word):  # prune paths early
                visited.remove((x, y))
                return

            if trie.check(cur_word):
                output.add(cur_word)

            if len(cur_word) < max_len:
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in visited:
                        dfs(nx, ny, visited, cur_word)

            visited.remove((x, y))

        for i in range(m):
            for j in range(n):
                dfs(i, j, set(), "")

        return list(output)