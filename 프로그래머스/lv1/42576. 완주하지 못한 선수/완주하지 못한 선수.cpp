#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    map<string, int> mp;
    
    for(auto& v : participant)
        mp[v]++;
    
    for(auto& v : completion)
        mp[v]--;
    
    for(auto& v : mp)
    {
        if(v.second >= 1)
            return v.first;
    }
        
    return answer;
}