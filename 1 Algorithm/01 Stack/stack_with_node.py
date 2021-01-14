class Node:

    """ Node (Container) """

    def __init__(self, value=None, pointer=None):
        self.value = value
        self.pointer = pointer


class Stack:

    """ 포인터 기반의 연결 방식 """

    def __init__(self):
        self.head = None
        self.length = 0

    def is_empty(self):
        return self.length == 0

    def push(self, value):
        self.head = Node(value, self.head)
        self.length += 1

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            value = self.head.value
            self.head = self.head.pointer
            self.length -= 1
            return value

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.head.value

    def size(self):
        return self.length

    def show(self):
        node = self.head
        while node:
            print(node.value, end=" ")
            node = node.pointer
        print()


if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    stack.pop()
    print(stack.peek())
    stack.show()

"""
[출력결과]
3
3 2 1 
"""
