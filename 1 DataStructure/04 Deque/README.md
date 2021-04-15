## 데크(deque)

- 데크는 스책과 큐의 결합체로 볼 수 있다. 양쪽 끝에서 항목의 조회, 삽입, 삭제가 가능하다.
- 파이썬에서 제공하는 collections 패키지의 deque 모듈을 사용하여 구현할 수 있다.
  - 동적 배열이 아닌 양방향 연결 리스트를 기반으로 한다.

```python
from collections import deque

dq = deque([17, 283, 29, 31])

print(dq)  # deque([17, 283, 29, 31])
print(type(dq))  # <class 'collections.deque'>

## push
dq.append(199)
print(dq)  # deque([17, 283, 29, 31, 199])

## enqueue
dq.appendleft(789)
print(dq)  # deque([789, 17, 283, 29, 31, 199])

## pop
dq.pop()
print(dq)  # deque([789, 17, 283, 29, 31])

## dequeue
dq.popleft()
print(dq)  # deque([17, 283, 29, 31])

## 데크의 크기를 지정한다.
dq = deque(maxlen=4)
print(dq)  # deque([], maxlen=4)

dq.append(1)
dq.append(2)
dq.append(3)
dq.append(4)
dq.append(5)
print(dq)  # deque([2, 3, 4, 5], maxlen=4)

## rotate(n) : n > 0 이면 오른쪽으로, n < 0 이면 왼쪽으로 n만큰 쉬프트 시킨다.
dq.rotate(1)
print(dq)  # deque([5, 2, 3, 4], maxlen=4)

dq.rotate(2)
print(dq)  # deque([3, 4, 5, 2], maxlen=4)

dq.rotate(-2)
print(dq)  # deque([5, 2, 3, 4], maxlen=4)
```