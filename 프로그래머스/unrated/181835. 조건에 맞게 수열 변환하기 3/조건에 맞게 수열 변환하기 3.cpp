#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    if(k & 1)
    {
        for(auto& v : arr)
        {
            answer.push_back(v * k);
        }
    }
    else
    {
        for(auto& v : arr)
        {
            answer.push_back(v + k);
        }
    }
    return answer;
}