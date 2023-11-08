#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
	while (true)
	{
        int popCount = 0;
        
		queue<int> qi;

		for (int i = 0; i < progresses.size(); i++)
		{
            progresses[i] += speeds[i];
            qi.push(progresses[i]);
		}

		while (!qi.empty())
		{
			if (qi.front() >= 100)
            {
				qi.pop();
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
				popCount++;
			}
			else
			{
				break;
			}
		}

		if (popCount > 0)
			answer.push_back(popCount);

		if (qi.empty())
			break;
	}
    
    return answer;
}