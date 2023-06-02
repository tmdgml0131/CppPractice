#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    vector<int> tmp;
    int answer = 0;
    
    while(n>=1)
    {
        tmp.push_back(n%3);
        n /=3;
    }
    
    
    reverse(tmp.begin(), tmp.end());
    
    for(int i = 0; i<tmp.size(); i++)
    {
        if(tmp[i] == 0)
            continue;
        
        int t = pow(3,i);
        
        answer += (t * tmp[i]);
    }
    
    return answer;
}