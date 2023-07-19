#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    
    int countX = 0;  // x의 개수
    int countOther = 0;  // x가 아닌 다른 글자의 개수
    int startIndex = 0;  // 현재 읽고 있는 문자열의 시작 인덱스

    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == s[startIndex]) 
            countX++;
        else 
            countOther++;

        if (countX == countOther) 
        {
            // 현재까지 읽은 문자열을 분리하고 개수 증가
            answer++;
            startIndex = i + 1;  // 다음 문자열의 시작 인덱스로 설정
            countX = 0;
            countOther = 0;
        }
    }

    // 마지막으로 읽은 문자열이 남은 경우에도 분리하고 개수 증가
    if (countX > 0 || countOther > 0) 
        answer++;

    return answer;
}
