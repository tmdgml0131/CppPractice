#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    vector<int> temp;
    for(int i = 0; i<commands.size(); i++)
    {
        for(int start = commands[i][0]-1; start <= commands[i][1]-1; start++)
        {
            temp.push_back(array[start]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);
        temp.clear();
    }
    return answer;
}