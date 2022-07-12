#include <iostream>
using namespace std;

#pragma region 개념
#pragma region 템플릿
//int sum(int a, int b)
//{
//    cout << "Calling int..";
//    return a + b;
//}
//
//template<typename T>
//T sum(T a, T b) //인텔리센스가 알아서 맞는 타입 T를 찾아줌..
//{
//    cout << "Calling template..";
//    return a + b;
//
#pragma endregion
#pragma region 포인터-메인으로 이동
     /*int num1 = 1234;
     double num2 = 3.14;

     int* ptr_num1{};
     double* ptr_num2{};

     cout << "현재 num1의 값은 : " << num1 << "이고 " << "num1의 주소는 : " << &num1 << "입니다." << endl;
     cout << "현재 num2의 값은 : " << num2 << "이고 " << "num2의 주소는 : " << &num2 << "입니다." << endl;
     cout << "할당 되지 않은(초기값) ptr_num1의 주소는 : " << ptr_num1 << "입니다" << endl;
     cout << "할당 되지 않은(초기값) ptr_num2의 주소는 : " << ptr_num2 << "입니다" << endl;
     ptr_num1 = &num1;
     ptr_num2 = &num2;
     cout << "할당 된 ptr_num1의 주소는 : " << ptr_num1 << "이며 num1의 주소는 : " << &num1 << "입니다." << endl;
     cout << "할당 된 ptr_num2의 주소는 : " << ptr_num2 << "이며 num2의 주소는 : " << &num2 << "입니다." << endl;
     cout << "ptr_num1은 num1을 가르키는 포인터 입니다. '*'을 사용하여 ptr_num1이 가르키는 값을 가져옵니다.."<< *ptr_num1 << endl;
     cout << "num1의 주소 : " << &num1 << endl << "ptr_num1의 주소 : " << &ptr_num1;*/
#pragma endregion
#pragma region 순수가상함수-메인으로 이동
     //class Hamsu
     //{
     //public:
     //    virtual void Drive()
     //    {
     //        cout << "driving.." << endl;
     //        return;
     //    }
     //    virtual void Stop()
     //    {
     //        cout << "stopping.." << endl;
     //        return;
     //    }
     //    virtual void Back()
     //    {
     //        cout << "going back.." << endl;
     //    }
     //    virtual void Peer() = 0; //순수 가상함수가 포함된 class는 instance 생성이 불가하다.
     //    
     //};
     ////예 : 'hamsu a;' << 에러 발생!

     //class Pear :public Hamsu
     //{
     //public:
     //    string name{"Pear"};
     //    
     //public:
     //    virtual void Peer() override // 순수가상함수가 포함된 class를 상속 받는 sub-class는 반드시 순수가상함수를 구현해야함.
     //    {
     //        cout << name << "의 순수가상함수 구현 완료\n";
     //    }
     //};

     ////0 1 1 2 3 5 8 13 21 34
     //Pear a;
     //a.Peer();
     //a.name = "Change";
     //a.Peer();
     //
#pragma endregion
#pragma endregion

//153페이지


//-------------------------[ ProtoType ]-----------------------------------//

void Say();

//-------------------------[   FBody   ]-----------------------------------//

int main()
{
    Say();
    return 0;
}


//-------------------------[ Func.Def. ]-----------------------------------//

void Say()
{
    int a{ 'M' };
    cout << a;
}