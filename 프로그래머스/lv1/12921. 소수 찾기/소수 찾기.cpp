#include <bits/stdc++.h>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    vector<bool> isPrime(n + 1, true);  // 각 숫자의 소수 여부를 저장하는 배열

    // 0과 1은 소수가 아님
    isPrime[0] = isPrime[1] = false;

    // 에라토스테네스의 체 알고리즘 적용
    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (isPrime[i]) 
        {
            // i의 배수들은 소수가 아님
            for (int j = i * i; j <= n; j += i) 
            {
                isPrime[j] = false;
            }
        }
    }

    // 소수인 숫자들의 개수를 세기
    for (int i = 2; i <= n; i++) 
    {
        if (isPrime[i]) 
        {
            answer++;
        }
    }

    return answer;
}
