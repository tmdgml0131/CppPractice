#include <bits/stdc++.h>

using namespace std;

int letsgo(int v)
{
    int one = 0;
    string tmp = "";
    while(v != 1)
    {
        if(v%2 == 0)
        {
            tmp += '0';
            v /= 2;
        }
        else if(v%2 == 1)
        {
            tmp += '1';
            v /= 2;
        }
    }
    tmp += '1';
    reverse(tmp.begin(), tmp.end());
    for(auto v: tmp)
    {
        if(v == '1')
            one++;
    }
    return one;
}

int solution(int n) 
{
    int answer = 0;
    int nOne = letsgo(n);
    while(true)
    {
        n++;
        if(letsgo(n) == nOne)
            return n;
    }
    
    return nOne;
}