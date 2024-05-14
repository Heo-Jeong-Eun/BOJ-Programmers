from functools import reduce

def mul(x, y):
    return x * y

def solution(num_list):
    if len(num_list) >= 11:
        return sum(num_list)
    else:
        return reduce(mul, num_list)