#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string t = to_string(a) + to_string(b);
    string tt = to_string(b) + to_string(a);
    
    int c = stoi(t);
    int cc = stoi(tt);
    
    if(c >= cc)
        answer = c;
    else
        answer = cc;
    
    return answer;
}