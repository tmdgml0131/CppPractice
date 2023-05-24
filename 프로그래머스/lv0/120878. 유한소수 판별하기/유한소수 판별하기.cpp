#include <bits/stdc++.h>

using namespace std;
// 유한소수면 1, 무한소수면 2
int solution(int a, int b) 
{
    int answer = 1;
    int max_div = 1;
    int range = min(a,b);
    
    for(int i = range; i>1; i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            max_div = i;
            break;
        }
    }
    
    b /= max_div;
    
    while(1)
    {
        if(b % 2 == 0)
            b /= 2;
        else if(b % 5 == 0)
            b /= 5;
        else
            break;
    }
    
    if(b == 1)
        return 1;
    else
        return 2;
}