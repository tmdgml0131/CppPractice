#include <bits/stdc++.h>

using namespace std;

int CountCommonElements(const unordered_set<string>& set1, const vector<string>& vec2)
{
    int count = 0;

    for (const auto& elem : vec2)
    {
        if (set1.count(elem) > 0)
            count++;
    }

    return count;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    unordered_map<string, vector<string>> reporter;
    unordered_map<string, int> reported;

    for (const auto& rep : report)
    {
        string p1, p2;
        stringstream ss(rep);
        ss >> p1 >> p2;

        if (find(reporter[p1].begin(), reporter[p1].end(), p2) == reporter[p1].end())
        {
            reporter[p1].push_back(p2);
            reported[p2]++;
        }
    }

    unordered_set<string> criminal;

    for (const auto& rep : reported)
    {
        if (rep.second >= k)
            criminal.insert(rep.first);
    }

    unordered_map<string, int> answersheet;

    for (const auto& rep : reporter)
    {
        int t = CountCommonElements(criminal, rep.second);
        answersheet[rep.first] = t;
    }

    for (const auto& id : id_list)
    {
        answer.push_back(answersheet[id]);
    }

    return answer;
}
