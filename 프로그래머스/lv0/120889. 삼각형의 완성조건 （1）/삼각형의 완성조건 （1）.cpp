#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int add = 0;
    int answer = 0;
    sort(sides.begin(), sides.end());
    add = sides[0] + sides[1];
    if(add > sides[2])
        answer = 1;
    else
        answer = 2;
    
    return answer;
}