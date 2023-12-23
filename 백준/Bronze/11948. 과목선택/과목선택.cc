// 물화생지역지, 물화생지 / 역지 가장 높게 3과목 / 1과목
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    vector<int> t1;
    vector<int> t2;
    
    t1.push_back(a);
    t1.push_back(b);
    t1.push_back(c);
    t1.push_back(d);
    
    t2.push_back(e);
    t2.push_back(f);
    
    sort(t1.begin(), t1.end(), greater<>());
    sort(t2.begin(), t2.end(), greater<>());
    
    int answer;
    
    answer += t1[0];
    answer += t1[1];
    answer += t1[2];
    
    answer += t2[0];
    
    cout << answer;
    
    
    return 0;
}