#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, string> a, pair<string, string> b) 
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

vector<string> solution(vector<string> strings, int n) 
{
    vector<string> answer;
    vector<pair<string, string>> mp;
    
    for(auto& v: strings)
    {
        string tmp = "";
        tmp += v[n];
        mp.push_back(make_pair(v, tmp));
    }
    
    sort(mp.begin(), mp.end(), compare);
    
    for(auto& p: mp)
    {
        answer.push_back(p.first);
    }
    return answer;
}