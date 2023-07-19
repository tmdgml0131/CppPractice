#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string my_string) 
{
    vector<int> answer;
    
    // 아스키 65 = A
    for(int i = 65; i<=122; i++)
    {
        int count = 0;
        
        for(auto& v : my_string)
            if(v == i)
                count++;
        answer.push_back(count);
        
        if(i == 90)
            i+=6;
    }
    return answer;
}