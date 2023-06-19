#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;
    
    for(auto& v : targets)
    {
        int sum = 0;
        for(auto& v2 : v)
        {
            vector<int> temp;
            int min_Val = 10000;
            int zeroCount = 0;
            
            for(auto& map :keymap)
            {
                int index = map.find(v2) + 1;
                temp.push_back(index);    
            }
            
            for(auto& val : temp)
            {
                if(val == 0)
                    zeroCount++;
                else if(val < min_Val)
                    min_Val = val;
                
                if(zeroCount == keymap.size())
                {
                    min_Val = -1;
                    break;
                }
            }
            if(min_Val != -1)
                sum += min_Val;
            else if(min_Val == -1)
            {
                sum = -1;
                break;
            }
                
        }
        answer.push_back(sum);
    }
    
    
    return answer;
}
