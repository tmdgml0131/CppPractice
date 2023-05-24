#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int k) 
{
    vector<int> answer;
    
    for(auto& v : arr)
    {
        if(find(answer.begin(), answer.end(), v) == answer.end())
            answer.push_back(v);
    }
    
    if(answer.size() > k)
    {
        int count = answer.size() - k;
        for(count; count>0; count--)
            answer.pop_back();
    }
    else if(answer.size() < k)
    {
        int count = k - answer.size();
        for(int i = 0; i<count; i++)
            answer.push_back(-1);
    }
    
    return answer;
}