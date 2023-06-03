#include <bits/stdc++.h>

using namespace std;
//a개를 가져가면 b개를 준다, 첫 콜라는 n개
int solution(int a, int b, int n) 
{
    int answer = 0;
    int freeBottle = 0;
    
    while (n >= a)
    {
        freeBottle = (n / a) * b;
        
        answer += freeBottle;
        n -= a * (n / a);
        n += freeBottle;
    }
    
    return answer;
}