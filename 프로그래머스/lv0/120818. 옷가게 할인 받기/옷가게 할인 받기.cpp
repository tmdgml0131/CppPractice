#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = 0;
    int discount = 0;
    
    if(price >= 500000)
        discount = 20;
    else if(price >= 300000)
        discount = 10;
    else if(price >= 100000)
        discount = 5;
    
    answer = price * (100 - discount) / 100;
    
    return answer;
}