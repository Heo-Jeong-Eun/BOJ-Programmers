# 완전탐색

'''
알파벳 A, E, I, O ,U만을 사용해 만들 수 있는 길이 5 이하 단어가 수록되어 있는 사진이 있다. 
가장 첫번째 단어는 "A"이고 마지막 단어는 "UUUUU"이다. 
단어 하나 word가 매개변수로 주어질 때 이 단어가 사전에서 몇 번째 단어인지 return 
'''

from itertools import product

def solution(word):
    w = []

    for i in range(1, 6):
        for j in product(['A', 'E', 'I', 'O', 'U'], repeat = i):
            w.append(''.join(list(j)))
    
    w.sort()

    return w.index(word) + 1