# 구현, 시뮬레이션, DFS

# S : 직진, L : 좌회전, R : 우회전 
# 빛이 격자 끝을 넘어가는 경우 : 반대쪽으로 다시 돌아온다. 
# 격자 내 빛이 이동할 수 있는 경로 사이클이 몇 개 있고, 각 사이클의 길이를 구해야 한다. 
# 경로 사이클 : 빛이 이동하는 순환 경로 
# 주어진 격자를 통해 만들어지는 경로 사이클의 모든 길이를 배열에 담고 오른차순으로 정렬해 return  

# 가능한 모든 경로와 방향을 시작으로 사이클을 탐색한다. 
# 이미 방문한 방향, 노드는 탐색하지 않는다. 
# 사이클이 만들어지지 않는 경우 X : 서로 다른 사이클을 구한다. 

# 1. 방문 표시를 위해 각 좌표 별 4 방향을 체크하는 3차원 배열을 만든다. 
#    visited[r][c][d] : (r, c)에서 d 방향으로 이동한 적이 있는지 
# 2. 모든 노드와 방향에 대해 방문한 적이 없다면 사이클을 탐색한다. 
# 3. 출발점으로 다시 돌아올 때까지 탐색한다. 

# def move() : 모듈러 연산으로 좌표를 넘어가면 다시 처음으로 돌아오도록 한다. 
# def rotate() : 다음 노드가 R, L인 경우 방향 회전

def move(r, c, d):
    global directions, n, m
    dx, dy = directions[d]

    return (r + dx) % n, (c + dy) % m

def roatate(d, node):
    if node == 'R':
        d = (d + 1) % 4
    elif node == 'L':
        d = (d - 1) % 4
    
    return d

def solution(grid):
    global directions, n, m, answer
    answer = []
    n, m = len(grid), len(grid[0])

    visited = [[[False for _ in range(4)] for _ in range(m)] for _ in range(n)]
    directions = [[1, 0], [0, -1], [-1, 0], [0, 1]] # D, L, U, R

    for r in range(n):
        for c in range(m):
            for d in range(4):
                if not visited[r][c][d]:
                    cx, cy, cd = r, c, d
                    cnt = 0

                    while not visited[cx][cy][cd]:
                        visited[cx][cy][cd] = True
                        cnt += 1
                        cx, cy = move(cx, cy, cd)
                        cd = roatate(cd, grid[cx][cy])
                    
                    answer.append(cnt)
                    
    return sorted(answer)