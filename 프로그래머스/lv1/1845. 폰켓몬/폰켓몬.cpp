#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    // n/2 선택
    int answer = 0;
    int max = nums.size() / 2;
    unordered_map<int, int> um;
    
    for(auto& v : nums)
        um[v]++;
    
    if(um.size() >= max)
        return max;
    else
        return um.size();
    
    return answer;
}