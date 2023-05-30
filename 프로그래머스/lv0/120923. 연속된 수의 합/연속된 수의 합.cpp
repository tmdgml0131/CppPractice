#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int num, int total) 
{
    vector<int> answer;
    int t = 0;
    int hint = 0;
    for(int i = -100; i < total; i++)
    {
        t = 0;
        for(int j = 0; j < num; j++)
            t += i+j;
        
        if(t == total)
        {
            hint = i;
            
            break;
        }
    }
    
    for(int i = 0; i<num; i++)
        answer.push_back(hint+i);
    
    if(num == 1)
    {
        answer.clear();
        answer.push_back(total);
    }
        
    
    return answer;
}