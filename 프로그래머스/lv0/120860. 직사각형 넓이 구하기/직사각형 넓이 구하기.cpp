#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) 
{
    int answer = 0;
    vector<int> tx;
    vector<int> ty;
    int x, y;
    
    for(auto&v : dots)
    {
        tx.push_back(v[0]);
        ty.push_back(v[1]);
    }
    
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    
    x = tx[3] - tx[0];
    y = ty[3] - ty[0];
    answer = x * y;
    
    return answer;
}