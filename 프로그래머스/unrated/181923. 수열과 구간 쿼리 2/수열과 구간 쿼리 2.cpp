#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) 
{
    vector<int> answer;
    vector<int> temp;
    // v[0] == s, v[1] == e, v[2] == k
    for(auto& v : queries)
    {
        // s~e 까지 모든 수 저장하는 배열 만들기
        for(int i = v[0]; i<=v[1]; i++)
            temp.push_back(arr[i]);
        
        sort(temp.begin(), temp.end());
        // sorting 까지 됐음
        
        int p = -1;
        
        // temp vector는 i들의 집합
        for(int i =0; i<temp.size(); i++)
        {
            if(temp[i] > v[2])
            {
                p = temp[i];
                answer.push_back(p);
                break;
            }
        }
        
        if(p == -1)
            answer.push_back(-1);
        
        temp.clear();
    }
    
    
    
    
    return answer;
}