#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) 
{
    // board 범위 넘어가면 board[0] 이나 board[1] 로 고정
    vector<int> answer;
    int x = 0;
    int y = 0;
    int x_max = board[0] / 2;
    int y_max = board[1] / 2;
    bool isNeg = false;
    
    for(auto& v : keyinput)
    {
        if(v == "up")
        {
            y++;
        }
        else if(v == "down")
        {
            y--;
        }
        else if(v == "left")
        {
            x--;
        }
        else if(v == "right")
        {
            x++;
        }
        
        if(x < 0)
            isNeg = true;
        if(y < 0)
            isNeg = true;
        
        if(abs(x) > x_max && !isNeg)
            x = x_max;
        else if(abs(x) > x_max && isNeg)
            x = x_max * -1;
        
        if(abs(y) > y_max && !isNeg)
            y = y_max;
        else if(abs(y) > y_max && isNeg)
            y = y_max * -1;
        
        isNeg = false;
    }
    
    if(abs(x) > x_max && !isNeg)
        x = x_max;
    else if(abs(x) > x_max && isNeg)
        x = x_max * -1;
        
    if(abs(y) > y_max && !isNeg)
        y = y_max;
    else if(abs(y) > y_max && isNeg)
        y = y_max * -1;
    
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}