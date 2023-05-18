#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    for(auto& v : numbers)
    {
        answer += v;
        if(answer > n)
            break;
    }
    
    return answer;
}