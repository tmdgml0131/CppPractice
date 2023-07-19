#include <bits/stdc++.h>

using namespace std;

string solution(string s, string skip, int index) 
{
    string answer = "";
    vector<char> vs;
    string temp = "";
    for(int i = 0; i<26; i++)
        vs.push_back(97+i);
    
    for(auto& v : skip)
    {
        for(auto& v2 : vs)
        {
            if(v == v2)
                v2 = '@';
        }
    }
    
    for(auto& v : vs)
    {
        if(v != '@')
            temp += v;
    }
    
    for (auto& v : s) 
    {
        int t = temp.find(v);
        if (t != string::npos) 
        {
            t = (t + index) % temp.size();
            answer += temp[t];
        }
    }

    
    return answer;
}