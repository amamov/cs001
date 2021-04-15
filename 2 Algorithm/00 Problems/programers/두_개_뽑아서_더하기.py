from itertools import combinations

def solution(numbers):
    result = list(set([sum(c) for c in combinations(numbers, 2)]))
    result.sort()
    return result