#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> answer;
    for(auto& v : arr)
    {
        if(v%divisor == 0)
            answer.push_back(v);
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}