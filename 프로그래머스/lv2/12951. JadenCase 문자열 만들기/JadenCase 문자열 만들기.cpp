#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    string answer = "";
    string temp = "";
    vector<string> vs;
    
    for(auto& v : s)
    {
        if(v != ' ')
        {
            temp += v;
        }
        else if(v == ' ')
        {
            vs.push_back(temp);
            vs.push_back(" ");
            temp.clear();
        }
    }
    vs.push_back(temp);
    
    for(auto& v : vs)
    {
        if(islower(v[0]))
            v[0] = toupper(v[0]);
        
        for(int i = 1; i<v.size(); i++)
        {
            if(isupper(v[i]))
                v[i] = tolower(v[i]);
        }
    }
    
    for(auto& v : vs)
        answer += v;
    
    
    return answer;
}