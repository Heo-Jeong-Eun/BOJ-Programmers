/*
비내림차순으로 정렬된 수열이 있을 때, 조건을 만족하는 부분 수열을 return

1. 기존 수열에서 임의의 두 index 원소와 그 사이 원소를 모두 포함하는 부분 수열
2. 부분 수열의 합 = k
3. 합이 k인 부분 수열이 여러 개인 경우 길이가 짧은 수열을 return 
4. 길이가 짧은 수열이 여러 개인 경우 앞쪽에 나오는, 즉 시작 index가 작은 수열을 return 

수열을 나타내는 정수 배열 sequence와 부분 수열의 합을 나타내는 k가 매개변수
조건을 만족하는 부분 수열의 시작 index와 마지막 index를 배열에 담아 return 

두 개의 포인터를 놓고 부분 수열의 합을 반복해 비교하며 위치를 옮기거나 확장
가장 짧은 길이의 부분 수열을 찾기 위해 더 큰 숫자가 위치한 뒷쪽 index부터 탐색
이때 sequence의 길이가 길기 때문에 sum()함수를 반복해서 사용하면 시간초과가 발생할 수 있으므로 부분합 변수를 만들어 갱신

1. i, j를 마지막 index로 초기화
2. total을 첫번째 원소 값으로 초기화
3. total이 k보다 작은 경우, j 포인터를 오른쪽으로 이동해 total을 증가
4. total이 k보다 큰 경우, i 포인터를 오른쪽으로 이동해 total을 증가
5. total = k의 경우, 현재 부분 수열의 길이를 확인, 최소 길이를 갱신 
*/

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int i = 0;  // 부분 수열의 시작을 가리키는 포인터
    int j = 0;  // 부분 수열의 끝을 가리키는 포인터
    int total = sequence[0];  // 초기 부분합, sequence의 첫 번째 원소로 초기화
    int min_length = numeric_limits<int>::max();  // 최소 길이를 무한대로 초기화
    vector<int> result;  // 결과를 저장할 벡터

    while (j < sequence.size()) {  // j가 sequence의 끝까지 탐색할 때까지 반복
        if (total < k) {  // 현재 부분합이 k보다 작으면
            j++;  // 끝 포인터를 오른쪽으로 이동
            if (j < sequence.size()) {  // j가 배열의 범위를 벗어나지 않으면
                total += sequence[j];  // 새로운 원소를 부분합에 더함
            }
        } else if (total > k) {  // 현재 부분합이 k보다 크면
            total -= sequence[i];  // 시작 포인터의 원소를 부분합에서 뺌
            i++;  // 시작 포인터를 오른쪽으로 이동
        } else {  // total == k, 현재 부분합이 k와 같으면
            if ((j - i) < min_length) {  // 현재 부분 수열의 길이가 최소 길이보다 작으면
                min_length = j - i;  // 최소 길이를 갱신
                result = {i, j};  // 결과를 현재 포인터 i, j로 갱신
            }
            total -= sequence[i];  // 다음 탐색을 위해 시작 포인터의 원소를 부분합에서 뺌
            i++;  // 시작 포인터를 오른쪽으로 이동
            j++;  // 끝 포인터를 오른쪽으로 이동
            if (j < sequence.size()) {  // j가 배열의 범위를 벗어나지 않으면
                total += sequence[j];  // 새로운 원소를 부분합에 더함
            }
        }
    }

    return result;  // 결과 반환
}