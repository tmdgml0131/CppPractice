#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(vector<int> numlist, int n) 
{
    vector<int> answer;
    vector<pair<int, int>> vs;
    
    sort(numlist.begin(), numlist.end(), greater<>());
    
    for(auto& v : numlist)
        vs.push_back(make_pair(abs(n - v), v));
    
    sort(vs.begin(), vs.end(), compare);
    
    for(auto& v : vs)
        answer.push_back(v.second);
    
    return answer;
}