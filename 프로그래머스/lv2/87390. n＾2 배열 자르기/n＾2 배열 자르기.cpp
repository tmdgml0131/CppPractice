#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    
    for(long long i = left; i<=right; i++)
    {
        long long count = i/n;
        long long remainder = i%n;
        long long big = 0;
        
        if(count >= remainder)
            big = count + 1;
        else
            big = remainder + 1;
        
        answer.push_back(big);
    }
    
    return answer;
}