#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    
    if(n % 2 != 0)
    {
        for(n; n>=0;)
        {
            answer += n;
            n -= 2;
        }
    }
    else
    {
        for(n; n>=0;)
        {
            answer += (n*n);
            n -= 2;
        }
    }
       
    return answer;
}