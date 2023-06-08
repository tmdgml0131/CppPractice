#include <bits/stdc++.h>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    vector<int> vi;
    
    for(int i = 1; i<=number; i++)
    {
        int prime = 0;
        int sqrtNum = sqrt(i);
        for (int j = 1; j <= sqrtNum; j++) 
        {
            if (i% j == 0)
                prime += 2;  
        }

        // 제곱근이 정수인 경우 중복으로 세어진 약수를 제거합니다.
        if (sqrtNum * sqrtNum == i) 
            prime--;
        
        vi.push_back(prime);
    }
    
    for(auto& v : vi)
    {
        if(v > limit)
            v = power;
        
        answer += v;
    }
    return answer;
}