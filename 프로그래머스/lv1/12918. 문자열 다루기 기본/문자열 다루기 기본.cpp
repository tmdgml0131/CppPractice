#include <bits/stdc++.h>

using namespace std;

bool solution(string s) 
{
    bool answer = true;
    
    if(s.size() == 4 || s.size() == 6)
    {
        for(auto&v : s)
        {
            if(!isdigit(v))
                return false;
        }
    }
    else
        return false;
    
    return answer;
}