#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for(int i = 0; i<arr.size(); i++)
    {
        int t = i+1;
        if((i+1) == arr.size())
            t = i;
        if(arr[i] != arr[t])
            answer.push_back(arr[t]);
    }

    return answer;
}