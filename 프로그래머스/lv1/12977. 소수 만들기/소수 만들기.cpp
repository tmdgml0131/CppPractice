#include <bits/stdc++.h>
using namespace std;

bool isFinite(int a)
{
    int count = 0;
    
    for(int i = 2; i<=a; i++)
    {
        if(a % i == 0)
            count++;
    }
    return count == 1? true:false;
}

int solution(vector<int> nums) 
{
    int answer = 0;
    for(int i = 0; i<nums.size(); i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            for(int k = j+1; k<nums.size(); k++)
            {
                int t = nums[i]+nums[j]+nums[k];
                if(isFinite(t))
                    answer++;
            }
        }
    }
    
    return answer;
}