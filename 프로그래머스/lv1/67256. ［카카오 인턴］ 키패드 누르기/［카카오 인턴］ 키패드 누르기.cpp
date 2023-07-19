#include <bits/stdc++.h>

using namespace std;

// *시작 - 1,4,7
// #시작 - 3,6,9
// 2,5,8,0 은 더 가까운 것, 거리가 같다면 손잡이 따라 달라짐
// 누르는 순서 적어달라.. 왼손 L, 오른손 R
string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    int lp = 10;
    int rp = 12;
    
    for(auto& v : numbers)
    {
        if(v == 1 || v == 4 || v == 7)
        {
            answer += "L";
            lp = v;
        }
        
        if(v == 3 || v == 6 || v == 9)
        {
            answer += "R";
            rp = v;
        }
        
        // 왼손 4, 오른손 2, 타겟 5, 핸드r 의 경우 r을 타야한다
        if(v == 2 || v == 5 || v == 8 || v == 0)
        {
            if(v==0)
                v=11;
            
            int leftlen = abs(v-lp)/3 + abs(v-lp)%3;
            int rightlen = abs(v-rp)/3 + abs(v-rp)%3;
            
            if(leftlen<rightlen)
            {
                answer+="L";
                lp=v;
            }
            else if(leftlen>rightlen)
            {
                answer+="R";
                rp=v;
            }
            else
            {
                if(hand=="left")
                {
                    answer+="L";
                    lp=v;
                }
                else
                {
                    answer+="R";
                    rp=v;
                }
            }
        }


    }
        
        
    
    return answer;
}