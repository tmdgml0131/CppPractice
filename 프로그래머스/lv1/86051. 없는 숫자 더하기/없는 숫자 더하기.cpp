#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) 
{
    int answer = 0;
    map<int, int> mp;
    
    for(int i = 0; i<=9; i++)
        mp[i]++;
    
    for(auto& v : numbers)
        mp[v]++;
    
    for(auto& v : mp)
    {
        if(v.second == 1)
            answer += v.first;
    }
    
    return answer;
}