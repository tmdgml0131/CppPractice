#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    int t;
    for(int i = 0; i<seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
            t = i;
    }
    answer = "김서방은 " + to_string(t) + "에 있다";
    return answer;
}