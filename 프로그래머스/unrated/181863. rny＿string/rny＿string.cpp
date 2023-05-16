#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for(auto& v : rny_string)
    {
        if(v == 'm')
        {
            answer += 'r';
            answer += 'n';
        }
            
        
        else
            answer += v;
            
    }
    return answer;
}