#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = ""; 
    for(auto& v : my_string)
    {
        if(v == alp[0])
            answer += v - 32;
        else
            answer += v;
    }
    return answer;
}