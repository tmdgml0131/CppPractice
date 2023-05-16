#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for(int i =0; i < num_str.size(); i++)
    {
        string t(1, num_str[i]);
        answer += stoi(t);
    }
    return answer;
}