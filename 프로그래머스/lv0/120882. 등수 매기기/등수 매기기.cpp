#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> score) 
{
    map<int, int> mp;
    vector<int> answer;
    vector<int> ts, cpy;
    int rank = 1;
    
    for(auto& v : score)
        ts.push_back(v[0] + v[1]);
    
    cpy = ts;
    
    sort(cpy.begin(), cpy.end(), greater<>());
    
    for(int i =0; i<cpy.size(); i++)
    {
        if(mp.find(cpy[i]) == mp.end())
            mp[cpy[i]] = rank;
        rank++;
    }
    
    for(int i = 0; i<ts.size(); i++)
        answer.push_back(mp[ts[i]]);
    
    
    return answer;
}