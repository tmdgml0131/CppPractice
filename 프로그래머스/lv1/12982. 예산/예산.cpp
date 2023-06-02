#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0;
    sort(d.begin(), d.end());
    
    for(auto& v : d)
    {
        if(v > budget)
            break;
        
        budget -= v;
        answer++;
    }
    return answer;
}