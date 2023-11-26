/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// 첫째줄 시 분 초
// 둘째줄 초단위
// 출력 시 분 초 단위로 언제 끝나는지
int main()
{
    int hour, minute, second, elapsed;
    int total = 0;
    cin >> hour >> minute >> second >> elapsed;
    
    total = (hour*3600) + (minute*60) + second + elapsed;
    
    hour = total/3600;
    total %= 3600;

    minute = total/60;
    total %= 60;
    
    second = total;
    
    if(hour >=24)
        hour %= 24;
        
    cout << hour << " " << minute << " " << second;
    return 0;
}
