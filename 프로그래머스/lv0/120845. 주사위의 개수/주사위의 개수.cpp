#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 1;
    vector<int> t;
    for(auto& v: box)
    {
        t.push_back(v/n);
    }
    for(auto& v: t)
    {
        answer *= v;
    }
    return answer;
}