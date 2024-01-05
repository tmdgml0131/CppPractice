//두 기차는 200/(50*2) = 2 시간 후에 만난다.  
//파리는 2시간동안 시간당 75마일의 속도로 이동하므로 2*75 = 150 마일을 이동한다.
// 50 75 200 150
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int t = c/(a*2);
    cout << b * t;
    return 0;
}