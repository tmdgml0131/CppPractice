#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    answer = num_list;
    
    if(num_list[num_list.size() - 1] > num_list[num_list.size() - 2])
    {
        int t = num_list[num_list.size() - 1] - num_list[num_list.size() - 2];
        answer.push_back(t);
    }
    else
        answer.push_back(num_list[num_list.size() - 1] * 2);
    
    return answer;
}