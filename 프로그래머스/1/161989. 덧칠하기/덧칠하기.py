'''
페인트가 칠해진 길이가 n미터인 벽이 있을 때, 페인트가 벗겨진 곳에 덧칠을 할 예정
벽을 1미터 길이의 구역 n개로 나누고, 각 구역 왼쪽부터 순서대로 1번 n번까지 번호가 있다. 
페인트를 칠하는 롤러의 길이는 m, 롤러로 페인트를 칠할 때 
롤러의 좌우측 끝을 구역의 경계선 혹은 벽 좌우측 끝부분에 맞춰 롤러를 움직이며 칠한다. 
벽을 한번 칠한 것으로 간주

이때 한 구역에 페인트를 여러번 칠해도 되고, 다시 칠해야 할 곳이 아닌 구역에 칠해도 되지만 
다시 칠하기로 한 구역은 적어도 한번 페인트칠을 해야한다. 

롤러로 페인트칠하는 최소 횟수를 return 
'''

def solution(n, m, section):
    answer = 0
    paint = 0 # 처음 벽부터 어디까지 페인트칠이 되어있는지 저장 

    for s in section:
        # secetion의 번호, 즉 s가 paint보다 작거나 같으면 이미 페인트칠이 되어있는 상태 
        # 반대로 큰 경우, 페인트칠이 되어있지 않은 상태
        if s > paint:
            # s번 벽을 기준으로 한번 칠할 경우 s + m - 1만큼 페인트칠이 된다. 
            # 칠할 때마다 paint에 값 갱신 
            paint = s + m - 1
            # 페인트칠 횟수 누적 
            answer += 1

    return answer