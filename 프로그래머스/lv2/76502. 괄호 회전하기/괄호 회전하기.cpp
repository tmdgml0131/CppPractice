#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) 
    {
        stack<char> st;
        bool isValid = true;

        for (int j = 0; j < n; j++) 
        {
            char c = s[(i + j) % n];

            if (c == '[' || c == '{' || c == '(') 
            {
                st.push(c);
            } 
            else 
            {
                if (st.empty()) 
                {
                    isValid = false;
                    break;
                }

                char top = st.top();
                st.pop();

                if ((c == ']' && top != '[') || (c == '}'                                                           && top != '{') || (c == ')' && top != '(')) 
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid && st.empty()) 
            answer++;
    }

    return answer;
}