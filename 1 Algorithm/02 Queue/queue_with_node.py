class Node:

    """ Container """

    def __init__(self, value=None, pointer=None):
        self.value = value
        self.pointer = pointer


class Queue:

    """ 포인터 기반의 연결 방식 """

    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        return not bool(self.head)

    def enqueue(self, value):
        node = Node(value)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            self.tail.pointer = node
            self.tail = node
        self.count += 1

    def dequeue(self):
        if self.head:
            value = self.head.value
            self.head = self.head.pointer
            self.count -= 1
            return value
        else:
            print("Queue is empty.")

    def peek(self):
        return self.head.value

    def size(self):
        return self.count

    def show(self):
        node = self.head
        while node:
            print(node.value, end=" ")
            node = node.pointer
        print()


if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(3)
    queue.enqueue(5)
    queue.enqueue(7)
    queue.enqueue(8)
    queue.enqueue(11)
    queue.show()
    print(queue.peek())
    queue.dequeue()
    queue.dequeue()
    queue.show()


"""
[출력 결과]
1 3 5 7 8 11 
1
5 7 8 11 
"""
