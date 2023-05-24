#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    int answer = 1;
    
    for(int i = 1; i<n; i++)
    {
        answer++;
        string t = to_string(answer);
        
        // 3의 배수거나, 3을 찾을 수 있을 때
        if(answer % 3 == 0 || (t.find('3') != string::npos))
        {
            while(answer % 3 == 0  || (t.find('3') != string::npos))
            {
                answer++;
                t = to_string(answer);
            }  
        }
    }
    
    return answer;
}