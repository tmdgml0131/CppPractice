#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) 
{
    vector<int> answer;
    int up = denom1*numer2 + denom2 * numer1;
    int down = denom1*denom2;
    
    int max_div = min(up, down);
    
    for(int i = max_div; i>=1; i--)
    {
        if(up % i == 0 && down % i == 0)
        {
            max_div = i;
            break;
        }
    }
    
    up /= max_div;
    down /= max_div;
    
    answer.push_back(up);
    answer.push_back(down);
    return answer;
}