#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto& v : myString)
    {
        if(v == 'a')
            answer += 'A';
        else if(v >= 65 && v < 97 && v != 'A')
            answer += v+32;
        else
            answer += v;
    }
    return answer;
}