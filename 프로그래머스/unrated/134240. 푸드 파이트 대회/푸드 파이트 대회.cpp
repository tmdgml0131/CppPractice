#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> food) 
{
    string answer = "";
    
    for(int i = 1; i<food.size(); i++)
    {
        if(food[i] % 2 != 0)
            food[i] -= 1;
        
        food[i] /= 2;
        
        for(int j = 0; j<food[i]; j++)
            answer += to_string(i);
    }
    
    string tmp = answer;
    
    reverse(tmp.begin(), tmp.end());
    
    answer += "0" + tmp;
    
    return answer;
}