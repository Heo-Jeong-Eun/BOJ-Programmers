#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> sli;
    sli.assign(num_list.begin(), num_list.begin() + n); 
    return sli;
}