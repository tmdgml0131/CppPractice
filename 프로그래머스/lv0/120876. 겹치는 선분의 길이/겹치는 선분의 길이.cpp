#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> lines) 
{
    int answer = 0;
    map<int, int> m;
    
    for(auto &v: lines) 
    {
        for(int i=v[0];i<v[1];i++) 
            m[i]++;
    }
    
    for(auto& v: m) 
    {
        if(v.second>1) 
            answer++;
    }
    
    return answer;
}