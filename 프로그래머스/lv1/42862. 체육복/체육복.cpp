#include <bits/stdc++.h>

using namespace std;
// 앞, 뒷번호만 빌리기 가능, 최대한 많이
// n은 전체 학생 수, lost는 체육복 없는 놈들, 여벌 체육복 있는 놈들은 reserve

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    vector<int> clothes(n + 1, 1); // 학생들의 체육복 상태를 나타내는 배열

    for (auto& v : lost) 
        clothes[v]--;
    

    for (auto& v : reserve) 
        clothes[v]++;
    

    for (int i = 1; i <= n; i++) 
    {
        if (clothes[i] == 0) 
        {
            // 앞번호 학생이 여벌 체육복을 가진 경우
            if (i - 1 >= 1 && clothes[i - 1] == 2) 
            { 
                clothes[i - 1]--;
                clothes[i]++;
            } 
            // 뒷번호 학생이 여벌 체육복을 가진 경우
            else if (i + 1 <= n && clothes[i + 1] == 2) 
            { 
                clothes[i + 1]--;
                clothes[i]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        if (clothes[i] >= 1) 
            answer++;
    }

    return answer;
}