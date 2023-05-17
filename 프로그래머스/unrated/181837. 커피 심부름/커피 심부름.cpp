#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) 
{
    int answer = 0;
    for(auto& v : order)
    {
        if(v.find("americano") != string::npos)
            answer += 4500;
        else if(v.find("anything") != string::npos)
            answer += 4500;
        else
            answer += 5000;
    }
    return answer;
}