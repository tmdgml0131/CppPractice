#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) 
{
    int answer = 0;
    map<float, int> mp;
    
    
    for(int i = 0; i<dots.size(); i++)
    {
        for(int j = i+1; j<dots.size(); j++)
        {
            int deltaX = dots[j][0] - dots[i][0];
            int deltaY = dots[j][1] - dots[i][1];
            
            if(deltaY == 0)
                continue;
            
            float slope = static_cast<float>(deltaX)/deltaY;
            
            mp[slope]++;
        }
    }
    
    for(auto& v : mp)
    {
        if(v.second == 2 || v.second == 6)
            answer = 1;
    }
    
    return answer;
}