#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    int price = 5500;
    int count = money / price;
    int remainder = money % price;
    answer.push_back(count);
    answer.push_back(remainder);
    return answer;
}