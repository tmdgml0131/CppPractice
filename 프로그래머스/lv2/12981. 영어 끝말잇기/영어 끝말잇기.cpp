#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    // n 사람의 수
    // 몇 번 사람이 몇 번 차례에 탈락
    vector<int> answer;
    map<string, int> ms;
    map<int, int> mi;
    bool isClear = true;
    
    int count = 0;
    string prev = "";
    
    for(auto& v: words)
    {
        count++;
        
        // 몇 번째 참가자가 몇 번째 차례인지
        if(count % n == 0)
            mi[n]++;
        else
            mi[count%n]++;
        
        // 끝말잇기 실패
        if(prev.empty())
            prev = v;
        else if(v[0] != prev[prev.size()-1])
        {
            isClear = false;
            break;
        }
            
        // 중복 실패
        if(ms[v] == 1)
        {
            isClear = false;
            break;
        }
        else
            ms[v]++;
        
        prev = v;
    }
    
    if(isClear)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        if(count % n == 0)
        {
            answer.push_back(n);
            answer.push_back(mi[n]);
        }
            
        else
        {
            answer.push_back(count % n);
            answer.push_back(mi[count%n]);
        }
            
    }
    
    
    return answer;
}