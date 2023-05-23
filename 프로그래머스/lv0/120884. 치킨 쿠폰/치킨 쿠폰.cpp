#include <string>
#include <vector>

using namespace std;

int solution(int chicken) 
{
    int answer = 0;
    int coupon = chicken;
    int sChicken = coupon / 10;
    int leftCoupon = coupon % 10;
    
    while(coupon >= 10)
    {
        answer += sChicken;
        coupon = sChicken + leftCoupon;
        sChicken = coupon / 10;
        leftCoupon = coupon % 10;
    }
    
    
    return answer;
}