#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) 
{
    int answer = 0;
    
    if(a % 2 == 0 && b % 2 ==0)
    {
        answer += (a - b);
        
        if(answer < 0)
            answer *= -1;
    }
    else if((a+b) % 2 != 0)
        answer += 2 * (a+b);
    else if(a % 2 != 0 && b % 2 != 0)
        answer += (a*a + b*b);
    
    return answer;
}