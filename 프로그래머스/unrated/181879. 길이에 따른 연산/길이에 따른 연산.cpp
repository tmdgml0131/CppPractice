#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    if(num_list.size() >= 11)
    {
        for(const auto v : num_list)
        {
            answer += v;
        }
    }
    else if(num_list.size() <= 10)
    {
        answer = 1;
        for(const auto v : num_list)
        {
            answer *= v;
        }
    }
    return answer;
}