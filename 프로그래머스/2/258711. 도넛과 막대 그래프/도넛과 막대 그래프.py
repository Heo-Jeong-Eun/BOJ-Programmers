# 리스트의 길이가 길기 때문에 그래프를 완전 탐색과 같은 형태로 순회하는 것은 불가능
# 각 그래프에 대해 해당 그래프임을 판별할 수 있는 특정 조건을 가진 노드가 있는지 확인하도록 한다. 

# 조건
# 1. 생성된 정점은 나가는 간선의 수가 2 이상이고, 들어오는 간선의 수가 0이다.
# 2. 막대 모양 그래프의 수는 나가는 간선의 수가 0, 들어오는 간선의 수가 1인 노드의 갯수와 같다. 
# 3. 8자 모양 그래프의 수는 나가는 간선의 수가 2, 들어오는 간선의 수도 2인 노드의 갯수와 같다. 
# 4. 도넛 모양 그래프 = 생성된 정점의 나가는 간선의 수 - 막대 모양 그래프와 8자 모양 그래프의 갯수
# 이때 막대 모양 그래프와 8자 모양 그래프의 경우 생성된 정점에서 들어오는 간선이 존재하므로 각각 1이상 2 이상으로 조건 설정

# 동작
# 1. edges의 요소를 순회하면서 각 노드별로 들어오는 간선과 나가는 간선의 갯수를 표시
# 2. 각 노드별로 간선들의 수를 확인, 상기 조건에 맞는 노드의 갯수를 answer에 추가

def solution(edges):  
    # 딕셔너리 초기화, 각 노드에 대해 나가는 간선드리과 들어오는 간선의 수를 저장
    # 키 = 노드 번호, 값 = [출발 간선 수, 도착 간선 수] 형태의 리스트이다. 
    def count_edges(edges):
        edge_counts = {}

        for a, b in edges:
            # 각 노드별로 간선의 수를 추가할 딕셔너리를 생성, .get() 함수를 이용해 딕셔너리의 키 값 추가
            if not edge_counts.get(a):
                edge_counts[a] = [0, 0]
            if not edge_counts.get(b):
                edge_counts[b] = [0, 0]

            # output edge와 input edge의 개수를 추가
            edge_counts[a][0] += 1  # a는 n번 노드에서 나가는 간선
            edge_counts[b][1] += 1  # b는 n번 노드로 들어오는 간선

        return edge_counts

    def check_answer(egde_counts):
        answer = [0, 0, 0, 0]

        for key, counts in edge_counts.items():
            # 생성된 정점의 번호 확인
            if counts[0] >= 2 and counts[1] == 0:
                answer[0] = key
            # 막대 모양 그래프의 수 확인
            elif counts[0] == 0 and counts[1] > 0:
                answer[2] += 1
            # 8자 모양 그래프의 수 확인
            elif counts[0] >= 2 and counts[1] >= 2:
                answer[3] += 1

        # 도넛 모양 그래프의 수 확인
        answer[1] = (edge_counts[answer[0]][0] - answer[2] - answer[3])

        return answer

    edge_counts = count_edges(edges)
    answer = check_answer(edge_counts)

    return answer

# edges = [[2, 3], [4, 3], [1, 1], [2, 1]]
# print(solution(edges))