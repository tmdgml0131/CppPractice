#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) 
{
    map<string, int> m;
    int size = friends.size();

    for (int i = 0; i < size; ++i)
    {
        m[friends[i]] = i;  // indexing
    }

    vector<vector<int>> arr(size, vector<int>(size, 0));
    vector<int> order(size, 0);
    vector<int> result(size, 0);

    for (const auto& gift : gifts)
    {
        istringstream iss(gift);
        string a, b;
        iss >> a >> b;

        int giver = m[a];
        int receiver = m[b];
        arr[giver][receiver] += 1;
        order[giver] += 1;
        order[receiver] -= 1;
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i][j] == arr[j][i]) // 주고 받은 선물 갯수가 같을때
            {
                if (order[i] > order[j])
                    result[i] += 1;
                else if (order[j] > order[i])
                    result[j] += 1;
            }
            else // 주고 받은 선물 갯수가 다를때
            {
                if (arr[i][j] > arr[j][i])
                    result[i] += 1;
                else
                    result[j] += 1;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < size; ++i)
    {
        if (answer < result[i])
            answer = result[i];
    }

    return answer;
}
