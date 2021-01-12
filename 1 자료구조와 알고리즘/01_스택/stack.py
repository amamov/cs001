class Stack:

    """ 배열 기반의 연속 방식 """

    def __init__(self):
        self.values = []

    def is_empty(self):
        return not bool(self.values)

    def push(self, value):
        self.values.append(value)

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.values.pop()

    def peek(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            return self.values[-1]

    def size(self):
        return len(self.values)

    def __repr__(self):
        return repr(self.values)


if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.pop()
    print(stack.peek())
    print(stack)
