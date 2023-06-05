#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    int box = score.size() / m;
    vector<int> lowest;
    vector<int> tmp;
    sort(score.begin(), score.end(), greater<>());
    
    for(int i = 0; i<score.size(); i++)
    {
        tmp.push_back(score[i]);
        if(tmp.size() == m)
        {
            lowest.push_back(tmp[m-1]);
            tmp.clear();
        }
            
    }
    
    for(int i = 0; i<box; i++)
    {
        answer += lowest[i] * m; 
    }
    
    return answer;
}