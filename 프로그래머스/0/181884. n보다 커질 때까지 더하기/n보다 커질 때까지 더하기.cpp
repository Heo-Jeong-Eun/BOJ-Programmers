#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int sum = 0;
    
    for (auto& num : numbers)
    { 
        sum += num;
        
        if (sum > n) return sum;
    }
    
    return sum;
}