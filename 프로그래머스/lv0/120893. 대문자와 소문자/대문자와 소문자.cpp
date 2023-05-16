#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto& v : my_string)
    {
        if(v >= 97)
            answer += v - 32;
        else
            answer += v +32;
    }
    return answer;
}