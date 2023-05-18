#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    //5, 3, 1
    int rem = 0;
    
    answer += hp / 5;
    rem = hp % 5;
    
    answer += rem / 3;
    rem = rem % 3;
    
    answer += rem;
    
    return answer;
}