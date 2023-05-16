#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = to_string(n);
    for(char& v: s)
    {
        answer += (int)v - '0';
    }
    return answer;
}