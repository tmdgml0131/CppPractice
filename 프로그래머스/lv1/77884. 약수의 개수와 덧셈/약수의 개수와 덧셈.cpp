#include <bits/stdc++.h>

using namespace std;

int solution(int left, int right) 
{
    int answer = 0;
    for(left; left<=right; left++)
    {
        int count = 0;
        for(int j = 1; j<left; j++)
        {
            if(left % j == 0)
                count++;
        }
        
        if(count % 2 == 0)
            answer -= left;
        else
            answer += left;
    }
    
    
    return answer;
}