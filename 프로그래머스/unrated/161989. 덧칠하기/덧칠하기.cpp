#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    vector<int> vi(n + 1, true); 

    for (auto& v : section)
        vi[v] = false;

    for (int i = 1; i <= n; i++) 
    {
        if (!vi[i]) 
        {
            for (int j = i; j <= i + m - 1 && j <= n; j++) 
                vi[j] = true;

            answer++; 
        }
    }
    return answer;
}
