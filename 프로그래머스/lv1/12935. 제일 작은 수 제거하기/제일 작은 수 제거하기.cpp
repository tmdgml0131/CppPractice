#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int t = 10000000;
    
    for(auto& v : arr)
    {
        if(v < t)
            t = v;
    }
    
    for(auto&v :arr)
    {
        if(v != t)
            answer.push_back(v);
    }
        
        
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}