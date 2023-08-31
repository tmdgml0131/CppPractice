#include <bits/stdc++.h>
using namespace std;

long long solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    long long a = 1;
    long long b = 2;
    
    for (int i = 3; i <= n; i++) {
        long long temp = (a + b) % 1234567;
        a = b;
        b = temp;
    }
    
    return b % 1234567;
}