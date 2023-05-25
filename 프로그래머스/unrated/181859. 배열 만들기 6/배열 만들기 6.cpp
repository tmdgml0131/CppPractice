#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector<int> stk;
    int i = 0;
    while(i < arr.size())
    {
        if(stk.empty())
        {
            stk.push_back(arr[i]);
            i++;
        }
        else if(stk[stk.size()-1] == arr[i])
        {
            stk.pop_back();
            i++;
        }
        else if(stk[stk.size()-1] != arr[i])
        {
            stk.push_back(arr[i]);
            i++;
        }
    }
    if(stk.empty())
    {
        answer.push_back(-1);
        return answer;
    }
    return stk;
}