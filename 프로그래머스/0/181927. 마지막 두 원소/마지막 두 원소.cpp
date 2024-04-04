#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    if (num_list.size() <= 1) 
    {
        return num_list;
    }
    
    int lastEle = num_list.back();
    int secEle = *(num_list.end() - 2);
    
    if (lastEle > secEle) num_list.emplace_back(lastEle - secEle);
    else num_list.emplace_back(lastEle * 2);
    
    return num_list;
}