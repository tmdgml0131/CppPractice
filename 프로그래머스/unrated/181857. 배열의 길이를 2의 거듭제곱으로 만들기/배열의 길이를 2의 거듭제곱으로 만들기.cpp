#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int length = arr.size();
    
    // arr의 길이가 2의 정수 거듭제곱이 아닌 경우
    while ((length & (length - 1)) != 0) {
        arr.push_back(0);
        length++;
    }
    
    return arr;
}