#include <bits/stdc++.h>

using namespace std;



int solution(int n) 
{
    const int MOD = 1234567;
    int a = 0, b = 1, c;

    if (n == 0) return a;
    for (int i = 2; i <= n; ++i) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    
    return b;
}