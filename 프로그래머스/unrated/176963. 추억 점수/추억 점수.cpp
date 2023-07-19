#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    vector<int> answer;
    map<string, int> mp;
    
    for(int i = 0; i<name.size(); i++)
    {
        mp[name[i]] = yearning[i];
    }
    
    for(auto& v : photo)
    {
        int score = 0;
        for(int i =0; i<v.size(); i++)
        {
            score += mp[v[i]];
        }
        answer.push_back(score);
    }
    return answer;
}