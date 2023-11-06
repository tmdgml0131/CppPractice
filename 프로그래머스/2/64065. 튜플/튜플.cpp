#include <bits/stdc++.h>

using namespace std;

static bool comp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second > b.second;
}

vector<int> solution(string s) 
{
    vector<int> answer;
    map<int, int> ms;
    string tmp = "";
    
    for(auto& v : s)
    {
        if(v-'0' >=0 && v-'0' <=9)
            tmp += v;
        else
        {
            if(!tmp.empty())
            {
                int tt = stoi(tmp);
                ms[tt]++;
            }
                
            
            tmp.clear();
        }
    }
    
    vector<pair<int,  int>> v(ms.begin(), ms.end());
    sort(v.begin(), v.end(), comp);
    
    for(auto& va : v)
        answer.push_back(va.first);
    
    return answer;
}