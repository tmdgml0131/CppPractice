#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mult = 1;
    int sqrt = 0;
    for(auto& v:num_list)
    {
        mult *= v;
        sqrt += v;
    }
    
    sqrt *= sqrt;
    
    if(mult < sqrt)
        answer = 1;
    return answer;
}