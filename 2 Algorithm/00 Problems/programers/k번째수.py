def solution(array, commands):
    answer = []
    for c in commands:
        first = c[0] - 1
        last = c[1] - 1
        k = c[2] - 1
        sample = array[first:last+1]
        sample.sort()
        answer.append(sample[k])
    return answer