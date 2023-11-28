#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str2;
    cin >> str1;
    int answer = 0;
    for(auto v : str1)
        answer += v - '0';
    cout << answer;
    return 0;
}