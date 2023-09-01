#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) 
{
    int answer = 0;
    sort(arr.begin(), arr.end());
    int start = arr[arr.size()-1];
    
    for(int i = start;; i++)
    {
        int remCount = 0;
        
        for(auto& v : arr)
        {
            if(i%v == 0)
                remCount++;
            else
                break;
        }
        if(remCount == arr.size())
            return i;
    }
    
    return answer;
}