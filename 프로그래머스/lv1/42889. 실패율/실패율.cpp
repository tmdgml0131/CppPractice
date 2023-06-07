#include <bits/stdc++.h>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failureRate;

    for (int i = 1; i <= N; i++) 
    {
        int reached = 0;
        int notCleared = 0;

        for (auto stage : stages) 
        {
            if (stage >= i) 
            {
                reached++;
                if (stage == i) 
                    notCleared++;
            }
        }

        double rate = (reached == 0) ? 0 :                                                         static_cast<double>(notCleared) / reached;
        failureRate.push_back(make_pair(rate, i));
    }

    sort(failureRate.begin(), failureRate.end(), compare);

    for (auto p : failureRate) 
    {
        answer.push_back(p.second);
    }

    return answer;
}
