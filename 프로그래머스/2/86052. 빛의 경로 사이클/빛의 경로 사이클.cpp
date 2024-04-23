// DFS

/*
하나의 격자에서 빛을 쏘면 내부에서 사이클을 이룬다. = 하나의 길로 들어간다. = DFS

bool cache[r][c][dir]
r, c 격자에 dir 방향으로 방향으로 들어온 적이 있는지 확인하는 배열
dir 방향이 들어온 적이 있다면 그에 해당하는 사이클이 존재한다는 의미
아직 방문하지 않은 경로를 시작점으로 탐색, 이미 탐색한 경로를 갈 일은 X

bool &ret = cache[r][c][in];
// if (ret != fasle) return;
ret = ture;
위 코드에서 주석을 해제하면 이미 탐색한 경로로 넘어간다. 
해당 문제에서 주석처리 된 부분을 그대로 둬도 정답으로 판별한다.
즉, 이미 탐색한 경로를 건드리지 않는다는 가정이 성립

DFS 인자 
void dfs(vector<string> &grid, int sr, int sc, int si, int r, int c, int in, int cnt)
매개변수 in은 현재 좌표로 들어오는 방향을 의미

DFS 움직임 구현
// 0, 1, 2, 3
// 오, 왼, 아, 위
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int LEFT[4] = {3, 2, 0, 1};
int RIGHT[4] = {2, 3, 1, 0};

...
    int out;
    
    if(grid[r][c] == 'S'){
        out = in;
    }
    else if(grid[r][c] == 'L'){
        out = LEFT[in];
    }
    else if(grid[r][c] == 'R'){
        out = RIGHT[in];
    }

    int nr = r + dr[out];
    int nc = c + dc[out];

    if(nr < 0) nr = R-1;
    if(nc < 0) nc = C-1;
    if(nr >= R) nr = 0;
    if(nc >= C) nc = 0;
    
    dfs(grid, sr, sc, si, nr, nc, out, cnt+1);
}
out은 나가는 방향을 의미하는 변수 

현재 좌표가 S인 경우 나가는 방향을 in과 같게 설정한다.
현재 좌표가 L인 경우 나가는 방향, in을 LEFT 배열에 넣은 방향으로 설정한다. 
dr, dc 배열은 <오른쪽, 왼쪽, 아래, 위> 나가는 순서로 배열이 저장되어 있다. 

만약 L칸으로 들어온 방향이 아래인 경우라면 빛이 위에서 아래 L로 들어온 것이다. 
따라서 빛은 L칸의 오른쪽으로 가야하고, dr[0]과 dc[0]을 사용해야 한다. 
아래 방향인 2는 0ㅇ으로 매핑된다. 

위 동작과 같이 RIGHT, LEFT 매핑 배열을 만들었다. 

in에 맞춰 out을 설정하고 격자 바깥으로 나갔다면 되돌아오도록 nr, nc를 설정한다. 
그리고 다음 격자로 DFS 탐색을 계속한다.

값 도출 조건
if(r == sr && c == sc && si == in && cnt != 0)
{
    a = cnt;
    return;
}
최종적으로 현재 좌표가 시작 좌표와 동일하고, 시작할 때 들어왔던 방향과 일치하면 
현재까지 움직인 거리를 답에 저장하고 오름차순으로 return 
*/

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

bool cache[501][501][4];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int LEFT[4] = {3, 2, 0, 1};
int RIGHT[4] = {2, 3, 1, 0};

int R, C;
// bool check = false;
int a;

void dfs(vector<string> &grid, int sr, int sc, int si, int r, int c, int in, int cnt) {
    
    if (r == sr && c == sc && si == in && cnt != 0) {
        a = cnt;

        return;
    }
    
    bool &ret = cache[r][c][in];
    // if(ret != false) return;
    ret = true;
    
    int out;
    
    if (grid[r][c] == 'S') {
        out = in;
    }
    else if (grid[r][c] == 'L') {
        out = LEFT[in];
    }
    else if (grid[r][c] == 'R') {
        out = RIGHT[in];
    }

    int nr = r + dr[out];
    int nc = c + dc[out];

    if (nr < 0) nr = R-1;
    if (nc < 0) nc = C-1;
    if (nr >= R) nr = 0;
    if (nc >= C) nc = 0;
    
    dfs(grid, sr, sc, si, nr, nc, out, cnt+1);
}

vector<int> solution(vector<string> grid) {
    memset(cache, 0, sizeof(cache));
    R = grid.size();
    C = grid[0].size();
    vector<int> answer;
    
    int ans;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            for (int k = 0; k < 4; k++) {
                if (!cache[i][j][k]) {
                    dfs(grid, i, j, k, i, j, k, 0);
                    answer.push_back(a);
                    a = 0;
                }
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    vector<string> grid = {"SL", "LR"};
    vector<int> result = solution(grid);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}