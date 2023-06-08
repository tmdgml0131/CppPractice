#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    // 6 = 1등, 1~0 = 6등
    vector<int> answer;
    
    int count = 0;
    int zero = 0;
    
    for(auto& v : lottos)
    {
        if (v == 0)
        {
            count++;
            zero++;
            continue;
        }
        
        for(auto& v2 : win_nums)
        {
            if(v == v2)
                count++;
        }
    }
    
    int realCount = count - zero;
    int max = 7 - count;
    if(count < 2)
        max = 6;
    int min = 7 - realCount;
    if(realCount < 2)
        min = 6;
    
    
    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}