#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) 
{
    double answer = (double)num1 / (double)num2 * 1000;
    int t = (int) answer;
    return t;
}