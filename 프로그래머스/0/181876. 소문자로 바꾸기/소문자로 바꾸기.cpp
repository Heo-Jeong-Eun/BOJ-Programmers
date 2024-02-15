#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for (auto& it : myString)
    {
        it = tolower(it);
    }
    
    return myString;
}