#include <bits/stdc++.h>

using namespace std;
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(vector<int> array) 
{
    int answer = 0;
    unordered_map<int, int> ms;
    for(auto& v : array)
        ms[v]++;
    
    int maxCount = -1;
    for(auto& v : ms)
    {
        if(v.second > maxCount)
        {
            maxCount = v.second;
            answer = v.first;
        }
    }
    
    
    vector<pair<int, int>> vs(ms.begin(), ms.end());
    sort(vs.begin(), vs.end(), compare);
    
    if(vs[0].second == vs[1].second)
        return -1;
    
    return answer;
}