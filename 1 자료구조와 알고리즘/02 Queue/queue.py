class Queue:

    """ 배열 기반의 연속 방식 """

    def __init__(self):
        self.in_stack = []
        self.out_stack = []

    def is_empty(self):
        return not (bool(self.in_stack) or bool(self.out_stack))

    def _transfer(self):
        while self.in_stack:
            self.out_stack.append(self.in_stack.pop())

    def enqueue(self, data):
        self.in_stack.append(data)

    def dequeue(self):
        if not self.out_stack:
            self._transfer()

        if self.out_stack:
            return self.out_stack.pop()
        else:
            print("Queue is empty.")

    def peek(self):
        if not self.out_stack:
            self._transfer()

        if self.out_stack:
            return self.out_stack[-1]
        else:
            print("Queue is empty.")

    def size(self):
        return len(self.in_stack) + len(self.out_stack)

    def __repr__(self):
        if not self.out_stack:
            self._transfer()

        if self.out_stack:
            return repr(self.out_stack)
        else:
            print("Queue is empty.")


if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(3)
    queue.enqueue(5)
    queue.enqueue(7)
    queue.enqueue(8)
    queue.enqueue(11)
    print(queue)
    queue.dequeue()
    queue.dequeue()
    print(queue)


"""
[출력 결과]
[11, 8, 7, 5, 3, 1]
[11, 8, 7, 5]
"""
