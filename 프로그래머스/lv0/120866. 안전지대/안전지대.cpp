#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board) 
{
    int answer = 0;
    int n = board.size();
    
    for(int i = 0; i<board.size(); i++)
    {
        for(int j =0; j<board.size(); j++)
        {
            if(board[i][j] == 1)
            {
                for(int t = i-1; t<=i+1; t++)
                {
                    for(int s = j-1; s<=j+1; s++)
                    {
                        if(t >= 0 && t < n && s >= 0 && s < n && board[t][s] != 1)
                            board[t][s] = 2;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i<board.size(); i++)
    {
        for(int j =0; j<board.size(); j++)
        {
            if(board[i][j] == 0)
                answer++;
        }
    }
    
    
    return answer;
}