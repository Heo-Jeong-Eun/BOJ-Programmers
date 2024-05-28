'''
달리기 경주, 바로 앞 선수를 추월할 때 해설진이 추월한 선수의 이름을 부른다. 
players : 선수 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 
callings : 해설진이 부른 이름을 담은 문자열 배열
경주가 끝났을 때, 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return  

방법 1. swap 
callings의 최대 길이가 1,000,000이고 players의 최대길이가 50,000이므로 
index 하나를 구하기 위해 1,000,000 X 50,000번 반복해야하므로 시간 초과

방법 2. dict
index 구하는 시간을 줄이기 위해 선수 : 등수 형태로 구성된 dict을 제작
answer에는 호명될 때마다 바뀌는 선수 별 등수를 저장하고, 이를 사용해 호명되는 선수의 현재 등수, 즉 index를 구한다.

callings 담긴 선수들의 이름을 하나씩 가져온다. 
해당 선수가 현재 몇등인지 answer에 찾아 index에 저장한다. 
호명된 선수는 앞사람 추월이므로 -1로 앞으로 이동, 추월당한 선수는 +1로 뒤로 이동한다.
두 선수의 바뀐 위치를 swap을 이용해 players에 저장한다. 
'''

def solution(players, callings):
    answer = {players : i for i, players in enumerate(players)} # 선수 : 등수

    for who in callings:
        index = answer[who] # 호명된 선수의 현재 등수
        answer[who] -= 1 # -1로 하나 앞 등수로 바꿔준다 
        answer[players[index - 1]] += 1 # 앞에 위치한 선수는 +1을 해 뒤로 보낸다.
        players[index - 1], players[index] = players[index], players[index - 1] # 위치 swap
    
    return players