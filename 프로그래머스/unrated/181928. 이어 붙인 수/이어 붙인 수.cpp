#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    string sums = "";
    string sumss = "";
    int sum1 = 0;
    int sum2 = 0;
    for(auto& v : num_list)
    {
        if(v % 2 != 0)
            sums += to_string(v);
        else
            sumss += to_string(v);
    }
    
    answer += (stoi(sums) + stoi(sumss));
    
    return answer;
}