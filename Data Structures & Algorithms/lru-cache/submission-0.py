class LRUCache:
    NULL = -1

    def __init__(self, capacity: int):
        self.cap = capacity
        # node = [key, val, next, prev]
        self.arr = [[None, None, self.NULL, self.NULL] for _ in range(capacity)]
        self.free = list(range(capacity))  # allocator
        self.pos = {}                      # key -> index
        self.head = self.NULL
        self.tail = self.NULL

    # ---------- helpers ----------
    def _remove(self, i: int):
        nxt, prv = self.arr[i][2], self.arr[i][3]
        if prv != self.NULL:
            self.arr[prv][2] = nxt
        else:
            self.head = nxt
        if nxt != self.NULL:
            self.arr[nxt][3] = prv
        else:
            self.tail = prv

    def _add_front(self, i: int):
        self.arr[i][3] = self.NULL
        self.arr[i][2] = self.head
        if self.head != self.NULL:
            self.arr[self.head][3] = i
        self.head = i
        if self.tail == self.NULL:
            self.tail = i

    # ---------- API ----------
    def get(self, key: int) -> int:
        if key not in self.pos:
            return -1
        i = self.pos[key]
        self._remove(i)
        self._add_front(i)
        return self.arr[i][1]

    def put(self, key: int, value: int) -> None:
        if key in self.pos:
            i = self.pos[key]
            self.arr[i][1] = value
            self._remove(i)
            self._add_front(i)
            return

        # evict if full
        if not self.free:
            i = self.tail
            self._remove(i)
            del self.pos[self.arr[i][0]]
        else:
            i = self.free.pop()

        self.arr[i] = [key, value, self.NULL, self.NULL]
        self.pos[key] = i
        self._add_front(i)
