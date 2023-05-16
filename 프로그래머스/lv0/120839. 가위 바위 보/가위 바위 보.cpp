#include <string>
#include <vector>

using namespace std;
// 2 0 5
// 0 5 2
string solution(string rsp) {
    string answer = "";
    for(auto& v: rsp)
    {
        if(v == '2')
        {
            answer += '0';
        }
        else if(v == '0')
        {
            answer += '5';
        }
        else if(v == '5')
        {
            answer += '2';
        }
    }
    return answer;
}