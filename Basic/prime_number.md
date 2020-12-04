## 소수 찾기 에라토스테네스의 체

- Python
```python
def prime_numbers(n: int) -> list:
	sieve = [True] * n # 에라토스테네스의 채 초기화
	m = int(n ** 0.5) # 최소 탐색 범위 지정
	for i in range(2, m+1):
		if sieve[i] == True:
			for j in range(i+i, n, i):
				sieve[j] = False
	return [i for i in range(2, n) if sieve[i]]

print(prime_numbers(1)) # []
print(prime_numbers(5)) # [2, 3]
print(prime_numbers(10)) # [2, 3, 5, 7]
```

