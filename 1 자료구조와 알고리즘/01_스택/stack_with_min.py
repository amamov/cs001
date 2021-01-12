# 스택에서 최솟값 O(1)로 조회하기


class Node:

    """ Node (Container) """

    def __init__(self, value=None, pointer=None, minimun=None):
        self.value = value
        self.pointer = pointer
        self.minimun = minimun


class Stack:

    """ Stack with minimun """

    def __init__(self):
        self.head = None
        self.length = 0
        self.minimun = 99999

    def is_empty(self):
        return self.length == 0

    def push(self, value):
        if self.is_empty():
            self.head = Node(value, self.head, value)
            self.minimun = value
            self.length += 1
        elif value < self.minimun:
            self.head = Node(value, self.head, value)
            self.minimun = value
            self.length += 1
        else:
            self.head = Node(value, self.head, self.minimun)
            self.length += 1

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            value = self.head.value
            self.head = self.head.pointer
            self.minimun = self.head.minimun
            self.length -= 1
            return value

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.head.value

    def peek_minimun(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.minimun

    def size(self):
        return self.length

    def show(self):
        node = self.head
        print("-- Stack 최상단 --")
        while node:
            print(node.value, end="\n")
            node = node.pointer
        print("-- Stack 최하단 --")


if __name__ == "__main__":
    stack = Stack()
    stack.push(5)
    stack.push(2)
    stack.push(1)
    stack.push(4)
    stack.push(99)
    print(stack.peek_minimun())
    print(stack.peek())
    stack.pop()
    stack.show()

"""
[출력결과]
1
99
-- Stack 최상단 --
4
1
2
5
-- Stack 최하단 --
"""
