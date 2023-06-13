#include <bits/stdc++.h>

using namespace std;

string solution(string X, string Y) 
{
    string answer = "-1";
    map<int, int> mpX;
    map<int, int> mpY;
    vector<int> vi;
    
    for(auto& v : X)
        mpX[v - '0']++;
    for(auto& v : Y)
        mpY[v - '0']++;
    
    for(int i = 0; i<=9; i++)
    {
        int count = mpX[i];
        if(mpX[i] > mpY[i])
            count = mpY[i];
        
        for(int j = 0; j<count; j++)
            vi.push_back(i);
    }
    sort(vi.begin(), vi.end(), greater<>());
    
    if(!vi.empty())
    {
        answer = "";
        for(auto& v : vi)
        {
            string tmp = to_string(v);
            answer += tmp;
        }
    }
    
    if(answer[0] == '0')
        answer = "0";
    return answer;
}