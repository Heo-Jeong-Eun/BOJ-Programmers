#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> answer;
    
    for (int i = 0; i < players.size(); ++i) {
        answer[players[i]] = i;
    }

    for (const string& who : callings) {
        int index = answer[who]; // 호명된 선수의 현재 등수
        
        if (index == 0) continue; // 이미 1등인 선수는 무시

        // 위치 swap
        answer[who] -= 1; // -1로 하나 앞 등수로 바꿔준다 
        answer[players[index - 1]] += 1; // 앞에 위치한 선수는 +1을 해 뒤로 보낸다.
        swap(players[index], players[index - 1]);
    }

    return players;
}