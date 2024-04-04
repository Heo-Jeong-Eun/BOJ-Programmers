#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for (size_t i = 0; i < strArr.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (auto& ch : strArr[i])
            {
                ch = tolower(ch);
            }
        }
        else 
        {
            for (auto& ch : strArr[i])
            {
                ch = toupper(ch);
            }
        }
    }
    return strArr;
}