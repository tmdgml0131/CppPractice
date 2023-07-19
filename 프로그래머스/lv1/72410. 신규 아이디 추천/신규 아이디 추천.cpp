#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    vector<char> vc;
    for(auto& v : new_id)
    {
        if(v >= 65 && v<=90)
            v += 32;
        
        if((v >=97 && v <=122) || isdigit(v))
        {
            vc.push_back(v);
            continue;
        }
        
        if(v == '-' || v == '_' || v == '.')
            vc.push_back(v);
    }
    
    while(1)
    {
        while(1)
        {
            if(vc[vc.size()-1] == '.')
                vc.pop_back();
            else
                break;
        }
        
        if(!vc.empty())
        {
            if(vc[0] == '.')
                vc.erase(vc.begin());
        
            if(vc[0] != '.')
                break;    
        }
        else
        {
            vc.push_back('a');
        }
    }
    
    for(int i = 0; i<vc.size(); i++)
    {
        if(i+1 <= vc.size()-1)
        {
            if(vc[i] == '.' && vc[i+1] == '.')
            {
                vc.erase(vc.begin() + i+1);
                i--;
            }
        }
    }
    
    while(1)
    {
        if(vc.size() >= 16)
            vc.pop_back();
        
        if(vc[vc.size()-1] == '.')
            vc.pop_back();
        
        if(vc.size() <16 && vc[vc.size()-1] != '.')
            break;
    }
    
    char t = vc[vc.size()-1];
    
    while(vc.size() < 3)
    {
        vc.push_back(t);
    }
    
    for(auto& v : vc)
        answer += v;
    
    return answer;
}