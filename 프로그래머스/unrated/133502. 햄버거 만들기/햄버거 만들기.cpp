#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient) 
{
    vector<int> vi = ingredient;
    int answer = 0;
    int n = vi.size();  
    
    for (int i = 0; i < n - 3; i++)
    {
        if (vi[i] == 1 && vi[i+1] == 2 && vi[i+2] == 3 && vi[i+3] == 1)
        {
            answer++;
            vi.erase(vi.begin() + i, vi.begin() + i + 4);
            n -= 4;  
            i -= 3;  
        }
    }
    
    return answer;
}


