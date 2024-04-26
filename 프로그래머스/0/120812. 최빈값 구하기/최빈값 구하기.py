def solution(array):
    while len(array) != 0:
        for i, j in enumerate(set(array)):
            array.remove(j)
        if i == 0: 
            return j
    
    return -1    