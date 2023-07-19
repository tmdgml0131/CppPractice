#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int ma = max(n,m);
    // 최대공약 - 최소공배
    
    for(int i = ma; i>=1; i--)
    {
        if(n%i ==0 && m%i == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    
    for(int i = ma; i<=1000000; i++)
    {
        if(i%n == 0 && i%m == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    
    return answer;
}