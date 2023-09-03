#include <bits/stdc++.h>

using namespace std;

// vec.erase(vec.begin());

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size()-1;
    while(left <= right)
    {
        if(people[left] + people[right] <= limit)
            left++;
        
        right--;
        answer++;
    }
    
    return answer;
}