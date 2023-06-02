#include<bits/stdc++.h>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    int begin = price;
    long long t = price;
    long long s = money;
    
    for(int i = 1; i<=count; i++)
        t += begin*i;
    
    s -= (t - begin);
    
    if(s >=0)
        return 0;
    else
        return -s;
    
    return answer;
}