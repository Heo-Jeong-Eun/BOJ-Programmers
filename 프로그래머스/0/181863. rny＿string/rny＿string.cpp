#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {  
    string toSearch = "m";
    string replaceWith = "rn";
    
    size_t pos = rny_string.find(toSearch);
    while (pos != string::npos) 
    { 
        rny_string.replace(pos, toSearch.length(), replaceWith);
        pos = rny_string.find(toSearch, pos + replaceWith.length());
    }
    
    return rny_string;
}