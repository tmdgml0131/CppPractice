#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    int change = 0;
    int deletedZero = 0;

    while (s != "1") {
        string newS;
        for (char c : s) {
            if (c == '1') {
                newS.push_back(c);
            } else {
                deletedZero++;
            }
        }
        int len = newS.length();
        s = "";
        while (len > 0) {
            s = (char)('0' + len % 2) + s;
            len /= 2;
        }
        change++;
    }

    answer.push_back(change);
    answer.push_back(deletedZero);
    return answer;
}
