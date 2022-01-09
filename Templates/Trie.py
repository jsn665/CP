class Node:
    def __init__(self):
        self.children = [None] * 26
        self.terminal = False

class Trie:
    def __init__(self):
        self.root = Node()

    def add_word(self, word: str) -> None:
        curr = self.root
        for i in range(len(word)):
            if not curr.children[ord(word[i]) - 97]:
                curr.children[ord(word[i]) - 97] = Node()
            curr = curr.children[ord(word[i]) - 97]
        curr.terminal = True

    def search(self, word: str) -> bool:
        curr = self.root
        for i in range(len(word)):
            if curr.children[ord(word[i]) - 97]:
                curr = curr.children[ord(word[i]) - 97]
            else:
                return False
        return curr.terminal

    def prefix_exist(self, prefix: str) -> bool:
        curr = self.root
        for i in range(len(prefix)):
            if curr.children[ord(prefix[i]) - 97]:
                curr = curr.children[ord(prefix[i]) - 97]
            else:
                return False
        return True
