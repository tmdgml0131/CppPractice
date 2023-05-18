#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int serv = 0;
    int q = 12000;
    int t = 2000;
    
    answer += q*n;
    serv = n/10;
    answer += t*(k-serv);
    return answer;
}