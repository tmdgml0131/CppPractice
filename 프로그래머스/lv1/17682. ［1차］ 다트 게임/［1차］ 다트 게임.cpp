#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    int num = 0;
    vector<int> vi;
    string tmp = "";
    
    for(auto&v : dartResult)
    {
        if(isdigit(v))
        {
            tmp += v;
            continue;
        }
        
        if(!tmp.empty())
            num = stoi(tmp);
        
        tmp.clear();
        
        if(v == 'D')
            num = pow(num, 2);
        else if(v == 'T')
            num = pow(num, 3);
        
        if(v == '*')
        {
            if(vi.size() == 3)
            {
                vi[2] *= 2;
                vi[1] *= 2;
                break;
            }
            
            for(int i = 0; i<vi.size(); i++)
            {
                vi[i] *= 2;
            }
            
            continue;
        }
        
        if(v == '#')
        {
            vi[vi.size()-1] *= -1;
            continue;
        }
        
        vi.push_back(num);
        num = 0;
    }
    
    for(auto& v : vi)
        answer += v;
    
    return answer;
}