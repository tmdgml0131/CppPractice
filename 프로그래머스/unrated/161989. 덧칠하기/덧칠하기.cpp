#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 1;
    
    int start = section[0];
    
    for(auto& v : section)
    {
        if(v < start + m)
            continue;
        else
        {
            start = v;
            answer++;
        }
    }
    
    return answer;
}
