#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b) 
{
    long long answer = 0;
    int start = 0;
    int end = 0;
    
    if(a==b)
        return a;
    
    if(a < b)
    {
        start = a;
        end = b;
    }
    else
    {
        start = b;
        end = a;
    }
        
    for(start; start<=end; start++)
        answer += start;
    return answer;
}