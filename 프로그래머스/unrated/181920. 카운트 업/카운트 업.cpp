#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start, int end) {
    vector<int> answer;
    int count = end-start;
    for(int i = 0; i<=count; i++)
    {
        answer.push_back(start);
        start++;
    }
    return answer;
}