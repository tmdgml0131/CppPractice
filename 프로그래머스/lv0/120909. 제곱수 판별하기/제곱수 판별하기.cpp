#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    for(int i = 0; i<=1000; i++)
    {
        if(n == i*i)
            answer = 1;
    }
    return answer;
}