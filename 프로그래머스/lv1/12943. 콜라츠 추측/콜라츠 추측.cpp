#include <bits/stdc++.h>

using namespace std;

int solution(int num) 
{
    int answer = -1;
    long long t = num;
    
    if(t == 1)
        return 0;
    
    for(int i = 0; i<500; i++)
    {
        if(t%2 == 0)
            t/=2;
        else if(t%2 != 0)
            t = ((t*3) + 1);
        
        if(t == 1)
            return i+1;
    }
    return answer;
}