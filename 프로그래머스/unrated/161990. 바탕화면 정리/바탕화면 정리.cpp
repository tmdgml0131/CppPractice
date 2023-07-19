#include <bits/stdc++.h>

using namespace std;
// 맨 위 - 맨 왼쪽 - 맨 아래 - 맨 오른쪽 차례대로
vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer;
    int top = 0;
    int bottom = -1;
    int left = 100;
    int right = 0;
    
    for(int i = 0; i<wallpaper.size(); i++)
    {
        // A 찾기
        if(wallpaper[i].find('#') != string::npos && top == 0)
        {
            answer.push_back(i);
            top++;
        }
        // B 찾기
        for(int j =0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#' && j <= left)
                left = j;
        }
        
        // C찾기
        if(wallpaper[i].find('#') != string::npos && i >= bottom)
            bottom = i+1;
        
        // D찾기
        for(int j =0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#' && j >= right)
                right = j+1;
        }
    }
    
    answer.push_back(left);
    answer.push_back(bottom);
    answer.push_back(right);
    return answer;
}