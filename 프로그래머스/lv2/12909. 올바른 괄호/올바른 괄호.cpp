#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    stack<char> parentheses;

    for (char c : s) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false;
            }
            parentheses.pop();
        }
    }

    return parentheses.empty();
}

