#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for (auto& s : myString)
    {
        s = toupper(s);
    }
    
    return myString;
}