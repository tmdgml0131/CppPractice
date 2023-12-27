// 욱제가 치킨 두 마리(...)를 살 수 있으면 치킨 두 마리(...)를 사고 남은 두 통장 잔고의 합을, 
// 살 수 없으면 현재 두 통장의 잔고의 합을 출력한다.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b, c;
    cin >> a >> b >> c;
    
    int sum;
    
    sum = a+b;
    
    sum >= 2*c ? cout<< sum-2*c : cout << sum;
    
    return 0;
}