#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    if (flag == true) return a + b;
    else return a - b;
}