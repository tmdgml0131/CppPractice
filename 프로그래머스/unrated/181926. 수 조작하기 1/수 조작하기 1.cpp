#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    for(auto&v : control)
    {
        if(v =='w')
            answer += 1;
        else if(v =='s')
            answer -= 1;
        else if(v =='d')
            answer += 10;
        else if(v =='a')
            answer -= 10;
    }
    return answer;
}