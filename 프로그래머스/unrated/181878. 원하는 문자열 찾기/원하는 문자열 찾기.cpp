#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(auto& v : myString)
    {
        if(v >= 65 && v < 97)
            v += 32;
    }
    for(auto& v : pat)
    {
        if(v >= 65 && v < 97)
            v += 32;
    }
    
    answer = myString.find(pat) != string::npos;
    return answer;
}