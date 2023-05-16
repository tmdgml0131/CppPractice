#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    answer = my_string.erase(0, my_string.size()-n);
    return answer;
}