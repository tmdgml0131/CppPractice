#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    vector<int> tmp;
    for(int i = 0; i<score.size(); i++)
    {
        int min = 101;
        // v.insert(v.begin(), target);
        
        if(i < k)
        {
            tmp.push_back(score[i]);
            sort(tmp.begin(), tmp.end());
            answer.push_back(tmp[0]);
        }
        else
        {
            if(score[i] < tmp[0])
                answer.push_back(tmp[0]);
            else
            {
                tmp[0] = score[i];
                sort(tmp.begin(), tmp.end());
                answer.push_back(tmp[0]);
            }
        }
    }
    //t
    return answer;
}