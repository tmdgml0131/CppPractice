#include <bits/stdc++.h>
using namespace std;
/*
세 각의 크기가 모두 60이면, Equilateral
세 각의 합이 180이고, 두 각이 같은 경우에는 Isosceles
세 각의 합이 180이고, 같은 각이 없는 경우에는 Scalene
세 각의 합이 180이 아닌 경우에는 Error*/

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a+b+c != 180)
    {
        cout << "Error";
        return 0;
    }

    if(a == b && b == c)
    {
        cout << "Equilateral";
        return 0;
    }
    
    if(a != b && b != c && a != c)
    {
        cout << "Scalene";
        return 0;
    }
    
    cout << "Isosceles";
    return 0;
    
    return 0;
}