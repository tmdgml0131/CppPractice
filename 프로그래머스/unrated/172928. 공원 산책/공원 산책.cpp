#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    vector<int> answer;
    int minX = 0;
    int minY = 0;
    int maxX = park[0].size();
    int maxY = park.size();
    int startX = -1;
    int startY = -1;
    
    // startPoint 찾기
    for(int i = 0; i<maxX; i++)
    {
        for(int j = 0; j<maxY; j++)
        {
            if(park[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
        }
        if(startX != -1)
                break;
    }
    
    
    for(auto& v : routes)
    {
        int move = 0;
        // -1, -2, -3, -4 => NSWE
        int direction = -7;
        for(auto& v2 : v)
        {
            // routes 알파벳 처리
            if(!isdigit(v2) && v2 != ' ')
            {
                if(v2 == 'N')
                    direction = -1;
                else if(v2 == 'S')
                    direction = -2;
                else if(v2 == 'W')
                    direction = -3;
                else if(v2 == 'E')
                    direction = -4;
            }
            else if(v2 - '0' >=0 && v2 - '0' <=9)
            {
                move = v2 - '0';
            }
        }
        // 방향 및 이동 설정 완료
        
        bool canMove = true;
        if(direction == -1)
        {
            if(startX + 1 - move <= maxY && startX - move >= minY)
            {
                for(int i = startX; i >= startX - move; i--)
                {
                    if(park[i][startY] == 'X')
                        canMove = false;
                }
                if(canMove)
                    startX -= move;    
            }
        }
        else if(direction == -2)
        {
            if(startX + 1 + move <= maxY && startX + move >= minY)
            {
                for(int i = startX; i <= startX + move; i++)
                {
                    if(park[i][startY] == 'X')
                        canMove = false;
                }
                if(canMove)
                    startX += move;    
            }
        }
        else if(direction == -3)
        {
            if(startY + 1 - move <= maxX && startY - move >= minX)
            {
                for(int i = startY; i >= startY - move; i--)
                {
                    if(park[startX][i] == 'X')
                        canMove = false;
                }
                if(canMove)
                    startY -= move;    
            }
        }
        else if(direction == -4)
        {
            if(startY + 1 + move <= maxX && startY + move >= minX)
            {
                for(int i = startY; i <= startY + move; i++)
                {
                    if(park[startX][i] == 'X')
                        canMove = false;
                }
                if(canMove)
                    startY += move;    
            }
        }
    }
    
    answer.push_back(startX);
    answer.push_back(startY);
    return answer;
}