#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) 
{
    long long answer = -1;
    // sqrt(25) == 5
    // pow(3,2) == 9
    
    for(int i = 1; i<50000000; i++)
    {
        if(i == sqrt(n))
            answer = pow(i+1, 2);
    }
        
    
    return answer;
}