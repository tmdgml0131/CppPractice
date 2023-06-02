#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int answer = 0;
    int temp = 0;
    vector<int> ga;
    vector<int> se;
    // 가로길이에 큰 길이를 모두 몰아넣었다.
    for(auto& v : sizes)
    {
        if(v[0] < v[1])
        {
            temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        }
        ga.push_back(v[0]);
        se.push_back(v[1]);
    }
    sort(ga.begin(), ga.end(), greater<>());
    sort(se.begin(), se.end(), greater<>());
    return ga[0] * se[0];
}