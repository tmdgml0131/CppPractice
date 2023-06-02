#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    for(int i = 0; i<numbers.size(); i++)
    {
        for(int j = 0; j<numbers.size(); j++)
        {
            if(i != j)
            {
                int t = numbers[i]+numbers[j];
                if(find(answer.begin(), answer.end(), t) == answer.end())
                    answer.push_back(t);
            }    
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}