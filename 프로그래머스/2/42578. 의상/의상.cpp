#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    map<string, int> ms;
    
    for(auto v : clothes)
        ms[v[1]]++;
    
    for(auto x : ms)
        answer = answer * (x.second + 1);
    
    answer = answer - 1;
    
    return answer;
}