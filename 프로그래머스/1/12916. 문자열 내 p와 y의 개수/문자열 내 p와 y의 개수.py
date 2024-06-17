def solution(s):
    pcnt = 0
    ycnt = 0
    
    for i in s:
        if i in 'pP':
            pcnt += 1
        if i in 'yY':
            ycnt += 1
            
    if pcnt == ycnt or (pcnt == 0 and ycnt == 0):
        return True
    else: 
        return False