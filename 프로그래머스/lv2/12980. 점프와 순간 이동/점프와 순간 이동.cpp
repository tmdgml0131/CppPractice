#include <bits/stdc++.h>

using namespace std;
// 슈트 점프는 건전지 듬
// 슈트 텔레포트는 건전지 안듬
// 슈트 텔포는 현재 이동한 거리 x 2
// 건전지 최소값 리턴

int solution(int n)
{
    int ans = 0;
    int count = 0;
    
    while(n>=1)
    {
        if(n%2 == 0)
        {
            n /= 2;
        }
        else
        {
            n -= 1;
            count++;
        }
    }
    
    return count;
}