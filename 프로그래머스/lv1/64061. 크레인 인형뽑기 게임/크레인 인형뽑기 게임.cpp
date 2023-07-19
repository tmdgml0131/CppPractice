#include <bits/stdc++.h>

using namespace std;

//2차원 배열 board / 위치 moves / answer = 사라진 인형 개수
//              15351214
//    12345     [3][0]    
// 1  00000     [1][4]
// 2  00103     [1][2]
// 3  02501     [2][v-1]
// 4  42442
// 5  35131
int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    vector<int> vi;
    
    for(auto& v : moves)
        v -= 1;
    
    for(auto& v : moves)
    {
        for(int i = 0; i<board.size(); i++)
        {
            int count = board[i][v];
            
            if(count == 0)
                continue;
            
            vi.push_back(count);
            board[i][v] = 0;
            break;
        }
        // 4 
        
        if(vi.size() >=2)
        {
            if(vi[vi.size()-1] == vi[vi.size()-2])
            {
                answer += 2;
                vi.pop_back();
                vi.pop_back();
            }
        }
    }
    
    
    return answer;
}