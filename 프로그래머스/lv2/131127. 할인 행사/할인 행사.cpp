#include <bits/stdc++.h>

using namespace std;

// want 원소들을 맵에 할당, map의 second는 number
// discount를 range로 >>
// range로 map의 second가 전부 0이라면 answer++
// discount의 start는 0, max는 start + 10이고 최대갑은 discount.size()

int solution(vector<string> want, vector<int> number, vector<string> discount) 
{
    int answer = 0;
    vector<string> vs;
    
    for(int i = 0; i<want.size(); i++)
    {
        for(int j = 0; j<number[i]; j++)
        {
            vs.push_back(want[i]);
        }
    }
    sort(vs.begin(), vs.end());
    //-------------------------------------------//
    vector<string> tmp;
    int start = 0;
    bool shouldEnd = false;
    while(!shouldEnd)
    {
        for(int i = start; i<start+10; i++)
        {
            if(start+10 > discount.size())
            {
                shouldEnd = true;
                break;
            }
            
            tmp.push_back(discount[i]);
        }
        
        
        sort(tmp.begin(), tmp.end());
        
        if(vs == tmp)
            answer++;
        
        tmp.clear();
        start++;        
    }
    return answer;
}