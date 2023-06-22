#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) 
{
    vector<int> vi = ingredient;
    int answer = 0;
    int n = vi.size();  // 배열 크기
    
    for (int i = 0; i < n - 3; i++)
    {
        if (vi[i] == 1 && vi[i+1] == 2 && vi[i+2] == 3 && vi[i+3] == 1)
        {
            answer++;
            vi.erase(vi.begin() + i, vi.begin() + i + 4);
            n -= 3;  // 배열 크기 갱신
            i -= 3;  // 인덱스 이동
        }
    }
    
    return answer;
}


