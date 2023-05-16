#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 1;
    for(int i = 0; i < is_prefix.size(); i++)
    {
        if(my_string[i] != is_prefix[i])
            answer -=1;
    }
    if(answer <=0)
        answer =0;
    return answer;
}