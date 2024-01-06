#include <bits/stdc++.h>

using namespace std;
// 시작위한 최소 필요
// 끝났을 때 소모되는 소모
// 피로도 k
// 2차원 벡터배열 dungeons
int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int count = 0;
        int know = k;
        for(auto& v : dungeons)
        {
            if(v[0] <= know)
            {
                know -= v[1];
                count++;
            }
            else
            {
                break;
            }
        }
        answer = max(count, answer);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}