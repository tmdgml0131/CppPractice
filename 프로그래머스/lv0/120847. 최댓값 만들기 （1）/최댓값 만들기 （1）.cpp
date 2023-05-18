#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int big = 0;
    int bigbig = 0;
    int record = 0;
    
    for(int i = 0; i<numbers.size(); i++)
    {
        if(numbers[i] > bigbig)
        {
            bigbig = numbers[i];
            record = i;
        }
    }
    
    numbers[record] = 0;
    for(int i = 0; i<numbers.size(); i++)
    {
        if(numbers[i] > big)
        {
            big = numbers[i];
        }
    }
    return big * bigbig;
}