#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    vector<string> decArr1;
    vector<string> decArr2;
    
    // 배열 암호화 해제
    // ------------------------------------------ //
    for(auto& v : arr1)
    {
        string tmp = "";
        while(v >=1)
        {
            if(v%2 == 0)
                tmp += '0';
            else
                tmp += '1';
            v /=2;
        }
        
        while(tmp.size() < n)
            tmp += to_string(v);
        
        reverse(tmp.begin(), tmp.end());
        decArr1.push_back(tmp);
    }
    
    for(auto& v : arr2)
    {
        string tmp = "";
        while(v >=1)
        {
            if(v%2 == 0)
                tmp += '0';
            else
                tmp += '1';
            v /=2;
        }
        while(tmp.size() < n)
            tmp += to_string(v);
        
        reverse(tmp.begin(), tmp.end());
        decArr2.push_back(tmp);
    }
    // ------------------------------------------------- //
    for(int i = 0; i<n; i++)
    {
        string tmp = "";
        for(int j=0; j<n; j++)
        {
            if(decArr1[i][j] == '1' || decArr2[i][j] =='1')
                tmp += '#';
            else
                tmp += ' ';
        }
        answer.push_back(tmp);
    }
    return answer;
}