class Queue:

    """ 배열 기반의 연속 방식 """

    def __init__(self):
        self.is_stack = []
        self.out_stack = []

    def _transfer(self):
        while self.in_stack:
            self.out_stack.append(self.in_stack.pop())

    def enqueue(self):
        pass


if __name__ == "__main__":
    pass


'''
[출력 결과]

'''