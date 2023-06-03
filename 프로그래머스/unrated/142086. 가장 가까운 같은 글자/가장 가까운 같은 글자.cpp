#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    vector<string> vs;
    
    for(int i = 0; i<s.size(); i++)
    {
        string tmp = "";
        tmp += s[i];
        
        if(find(vs.begin(), vs.end(), tmp) == vs.end())
        {
            answer.push_back(-1);
            vs.push_back(tmp);
        }
        else
        {
            for(int j = i-1; j>=0; j--)
            {
                if(s[i] == s[j])
                {
                    answer.push_back(i-j);
                    break;
                }
            }
            vs.push_back(tmp);
        }
            
    }
    
    return answer;
}