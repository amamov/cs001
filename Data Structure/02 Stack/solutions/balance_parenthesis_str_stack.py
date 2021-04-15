import sys
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
sys.path.append(str(BASE_DIR))

# 스택을 활용한 괄호 짝 확인하기
from stack import Stack


def balance_par_with_stack(string: str) -> bool:
    stack = Stack()

    for char in string:
        if char == "(":
            stack.push(char)
        else:
            if stack.is_empty():
                return False
            stack.pop()

    if stack.is_empty():
        return True
    else:
        return False

    return True


assert balance_par_with_stack("(())") == True
assert balance_par_with_stack("((()))") == True
assert balance_par_with_stack("") == True
assert balance_par_with_stack("(()") == False
assert balance_par_with_stack("()))") == False
assert balance_par_with_stack("(()))") == False
