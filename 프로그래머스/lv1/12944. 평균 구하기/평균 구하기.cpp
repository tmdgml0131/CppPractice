#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) 
{
    double answer = 0;
    for(auto& v : arr)
        answer += v;
    
    return answer / arr.size();
}