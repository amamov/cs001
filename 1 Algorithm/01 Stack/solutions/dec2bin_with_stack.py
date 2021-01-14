import sys
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
sys.path.append(str(BASE_DIR))

# 스택을 활용한 괄호 짝 확인하기
from stack import Stack


def dec2bin_with_stack(decimal_number: int) -> str:
    stack = Stack()
    result = ""

    while decimal_number > 0:
        digit = str(decimal_number % 2)
        decimal_number = decimal_number // 2
        stack.push(digit)

    while not stack.is_empty():
        result += stack.pop()

    return result


assert dec2bin_with_stack(9) == "1001"
assert dec2bin_with_stack(13) == "1101"
