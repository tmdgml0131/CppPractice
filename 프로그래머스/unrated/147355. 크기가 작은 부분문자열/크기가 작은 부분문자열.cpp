#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    vector<long long> vs;
    
    for(int i = 0; i<=t.size() - p.size(); i++)
    {
        string tmp = t.substr(i, p.size());
        long long t = stoll(tmp);
        vs.push_back(t);
    }
    
    for(auto& v : vs)
    {
        if(v <= stoll(p))
            answer++;
    }
    return answer;
}