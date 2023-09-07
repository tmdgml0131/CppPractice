#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) 
{
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < n; i++) {
        if (citations[i] <= i) {
            return i;
        }
    }

    return n; // 모든 논문이 h번 이상 인용된 경우
}