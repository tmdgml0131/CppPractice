#include <vector>

using namespace std;

vector<vector<int>> solution(int n) 
{
    // n개의 행과 열을 가진 n*n의 정방행렬을 생성 후 전부 0으로 초기화
    vector<vector<int>> spiral(n, vector<int>(n, 0));
    
    int num = 1; // 배치할 숫자
    int rowStart = 0, rowEnd = n - 1; // 행의 시작과 끝 인덱스
    int colStart = 0, colEnd = n - 1; // 열의 시작과 끝 인덱스
    
    while (num <= n * n) 
    {
        // 오른쪽 방향으로 숫자 배치
        for (int col = colStart; col <= colEnd; col++) 
        {
            spiral[rowStart][col] = num++;
        }
        rowStart++;
        
        // 아래쪽 방향으로 숫자 배치
        for (int row = rowStart; row <= rowEnd; row++) 
        {
            spiral[row][colEnd] = num++;
        }
        colEnd--;
        
        // 왼쪽 방향으로 숫자 배치
        for (int col = colEnd; col >= colStart; col--) 
        {
            spiral[rowEnd][col] = num++;
        }
        rowEnd--;
        
        // 위쪽 방향으로 숫자 배치
        for (int row = rowEnd; row >= rowStart; row--) 
        {
            spiral[row][colStart] = num++;
        }
        colStart++;
    }
    
    return spiral;
}
