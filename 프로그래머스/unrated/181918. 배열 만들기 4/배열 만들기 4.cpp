#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> stk;
    for(int i = 0; i<arr.size();)
    {
        if(stk.empty())
        {
            stk.push_back(arr[i]);
            i++;
            continue;
        }
        
        if(stk[stk.size() - 1] < arr[i])
        {
            stk.push_back(arr[i]);
            i++;
            continue;
        }
        
        if(stk[stk.size() - 1] >= arr[i])
        {
            stk.pop_back();
            continue;
        }
        
    }
    return stk;
}