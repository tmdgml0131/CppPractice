#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) 
{
    vector<vector<int>> answer;
    vector<int> temp;
    
    if(arr.size() > arr[0].size())
    {
        int coun = arr[0].size();
        
        for(auto& v : arr)
        {
            for(int i = coun; i<arr.size(); i++)
            {
                v.push_back(0);
            }
        }
    }
    
    if(arr[0].size() > arr.size())
    {
        int count = arr[0].size();
        for(int i = count; i>0; i--)
            temp.push_back(0);
        
        for(int i = arr[0].size() - arr.size(); i>0; i--)
            arr.push_back(temp);
    }
    
    return arr;
}