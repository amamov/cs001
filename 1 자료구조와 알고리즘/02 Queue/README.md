## 큐(queue)

- 큐는 스택과 다르게 데이터가 들어온 순서대로 접근이 가능하다.
- 먼저 들어온 데이터가 먼저 나가는 **FIFO(First In, First Out)** 구조이다.
- 배열의 인덱스 접근이 제한된다.
- 시간복잡도는 모두 O(1)이다.

<br>

- 스택의 동작
  - `enqueue` : 큐 뒤쪽에 데이터를 삽입한다.
  - `dequeue` : 큐 앞쪽의 데이터을 반환하고, 제거한다.
  - `peek/front` : 큐 앞쪽의 데이터를 조회한다.
  - `empty` : 스택이 비어 있는지 확인한다.
  - `size` : 스택 크기를 확인한다.

<br>

<img src="../../images/1/queue.png"  alt="queue" />

<br>
<br>

```python
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
```

아래의 코드는 노드(객체)의 컨테이너로 큐를 구현한 것이다.

```python
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
```
