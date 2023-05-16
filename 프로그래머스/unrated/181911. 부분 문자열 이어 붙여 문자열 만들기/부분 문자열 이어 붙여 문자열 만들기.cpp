#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) 
{
    string answer = "";
    int x, y = 0;
    for(int i = 0; i<my_strings.size(); i++)
    {
        x = parts.at(i).at(0);
        y = parts.at(i).at(1);
        
        answer += my_strings[i].substr(x, y-x+1);
    }
    return answer;
}