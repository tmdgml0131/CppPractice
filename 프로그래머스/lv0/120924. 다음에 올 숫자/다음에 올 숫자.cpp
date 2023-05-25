#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> common) 
{
    int answer = 0;
    int magic = 0;
    
    if(common[1] - common[0] != common[2] - common[1])
    {
        magic = common[1] / common[0];
        answer = common[common.size()-1] * magic;
    }
    else
    {
        magic = common[1] - common[0];
        answer = common[common.size()-1] + magic;
    }
    
    
    
    return answer;
}