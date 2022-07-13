#include <iostream>
#include <string> //string class 사용 위해
#include <cstring> //C 스타일 문자열 라이브러리
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

#pragma region Chapter 4. 복합 데이터형
    /*
    -------------- 04.문자열 -----------------
    모든 문자열의 끝은 \0, 즉 널 문자(null character)여야 한다.
    char cat[3] = {'c', 'a', 't'}; --> 문자열이 아니다.
    char cat[4] = {'c', 'a', 't', '\0'} --> 문자열이다.
    예시의 cat 문자열은, 문자열을 선언하기 위해 아주 짜증나는 method를 사용한다. 
    문자들을 작은 따옴표로 감싸고 끝에 널 문자를 넣어야 하기 때문이다. 하지만 이보다 획기적인 방법은 존재한다.
    char cat_2[4] = {"cat"}; --> cat_2 배열은 위의 예시 cat[4] 와 완벽하게 똑같은 문자열을 구현한다.
    이렇게 큰따옴표로 묶인 문자열을 문자열 상수 (string constant or string literal) 이라고 한다.
    문자열에 cout 을 사용할 경우 null character을 만나면 멈추게 되는데 예시는 다음과 같다.
    cat[2] = '\0';
    cout << cat;    --> 출력 : ca
    ------------------- 04.getline() -------------------------
    만약 cin을 통해 Jack Kim 이란 이름을 받는다면 출력 결과는 어떻게 될까?
    char name[20]{};
    cin >> name;
    입력 : Jack Kim
    출력 : Jack
    입력은 분명 Jack Kim이였지만 출력은 Jack 까지만 나온다.. cin은 빈칸, 탭, 캐리지 리턴과 같은 화이트스페이스를 만나면 
    그 위치에서 문자열이 끝난 것으로 간주하기 때문에 Jack과 Kim 사이의 빈칸을 만나면 Jack을 name에 할당하고 Kim은 큐에 남겨 놓는다.
    그렇다면 Jack Kim을 온전히 출력하려면 어떻게 해야할까??
    답은 getline() 함수의 사용이다. getline()함수엔 2가지 매개변수가 들어간다.
    첫 번째는 입력을 저장할 배열의 이름, 두번째는 입력 문자들의 한계이다. 한계가 20이라면 19개까지 문자를 저장할 수 있다.
    다음은 getline() 함수의 예시이다.
    const int size{20};
    char name[size]{};
    cin.getline(name, size);
    cout << name;
    입력 : Jack Kim
    출력 : Jack Kim
    ------------------- 04.get()----------------------------
    편리한 getline()도 단점이 있다. 다음 예시를 보자
    
    cout << "아파트 입주 날짜 입력";
    int year;
    cin >> year;
    cout << "거주 중인 도시 입력";
    char address[80];
    cin.getline(address, 80);
    cout << "입주 날짜 : " << year << endl;
    cout << "거주 도시 : " << address << endl;
    cout << "등록 완료";

    입력 : 1966, Seoul
    출력 : 1966 입력 즉시 종료, 1966만 출력하고 Seoul은 입력 기회 없음..
    이는 cin 이 입주 연도를 읽어들이고 enter를 누를 때 개행 문자를 큐에 남겨 두기 때문에, cin 다음 cin.getline이 호출될 때 큐에 남아있는 엔터가
    getline() 함수에 입력되기 때문이다. 해결법은 매개변수가 없는 get() 함수의 사용이다.
    
    방법 1 :
    cout << "아파트 입주 날짜 입력";
    int year;
    (cin >> year).get();      //변화!
    cout << "거주 중인 도시 입력";
    char address[80];
    cin.getline(address, 80);
    cout << "입주 날짜 : " << year << endl;
    cout << "거주 도시 : " << address << endl;
    cout << "등록 완료";

    방법 2 : 
    cout << "아파트 입주 날짜 입력";
    int year;
    cin >> year;
    cin.get();            //변화!
    cout << "거주 중인 도시 입력";
    char address[80];
    cin.getline(address, 80);
    cout << "입주 날짜 : " << year << endl;
    cout << "거주 도시 : " << address << endl;
    cout << "등록 완료";

    -------------- 04.String class 조작 -----------------
    string 은 다음과 같은 방식으로 객체를 대입/결합/추가 할 수 있다.
    string s1{ "Hi" };
    string s2{};
    string s3{};
    -- 객체의 대입 --
    s2 = s1;
    cout << s2 << endl;
    -- 객체의 결합 --
    s3 = s1 + s2;
    cout << s3 << endl;
    -- 객체의 추가 --
    s3 += " I am Iron man.";
    cout << s3;

    출력 : 
    Hi // 대입 cout
    HiHi // 결합  cout
    HiHi I am Iron man. // 추가 cout

    -------------- 04.String class 기타기능 -----------------
    문자열은 strcpy 와 strcat을 사용하여 대입과 추가를 할 수 있다.
    단, strcpy / strcat의 잠재적 문제점은, 대입이나 추가를 할 문자열의 크기가
    기존 문자열보다 크기가 더 크다면 버퍼 오버플로우가 발생할 수 있는 문제가 있다.
    예컨대, char a[5] 라는 문자열에 "I am Iron man" 과 같은 문자열을 대입하면 
    배열의 크기인 5보다 크기 때문에 에러가 발생하게 된다. 이를 위해서
    strcpy_s / strcat_s 함수가 나오게 되었다.
    두 함수는 원래의 매개변수였던, 목표변수 / 선택변수 사이에 할당될 메모리의 크기를 적는 매개 변수가 추가 되었습니다.
    아래의 예시를 보겠습니다.
    
    char let1[20]{};
    char  let2[20]{ "Jaguar" };
    string let3{};
    string let4{ "Panther"};

    //string 객체 대입 / 문자 배열의 대입
    let3 = let4;
    strcpy_s(let1, 20, let2);
    cout << let3 << endl << let1 << endl;
    //string 객체 추가 / 문자 배열의 추가
    let3 += let4;
    strcat_s(let1, 20, let2);
    cout << let3 << endl << let1 << endl;
    //string 객체 길이 구하기 / C 스타일 문자열 길이 구하기
    int length1 = let3.size();
    int length2 = strlen(let1);
    cout << length1 << endl << length2 << endl;

    출력 :
    Panther
    Jaguar
    PantherPanther
    JaguarJaguar
    14
    12

    -------------- 04.구조체 -----------------
    한 명의 축구 선수에 관련된 정보를 저장해야 한다고 가정해보자.
    이름, 나이, 성별, 체중, 연봉 등 다양한 데이터 타입의 정보를 저장해야한다.
    지금까지 배운 배열은 이 용도로 적당하지 않다. *배열은 원소들의 데이터형이 모두 같아야 하기 때문이다.*
    다양한 데이터 타입의 묶음과 같은 요구를 해결해주는 것이 C++의 구조체(Structure)이다.
    또한, 축구 선수들로 구성된 팀을 만들 경우, 동일한 구조체로 만들어진 팀원이 있다면, 배열로 처리가 가능하다.
    이는, 객체 지향 프로그래밍의 핵심인 Class의 기초가 된다. 
    구조체는 사용자가 정의할 수 있는 데이터형으로, 구조체의 선언 및 정의 - 구조체 변수의 생성으로 만들어진다.

    struct Explosive // struct(구조체 서술 정의) Explosive(구조체 이름) 
    {
        char name[20]{};
        float volume{};
        double price{};
    }; //세미클론은 템플릿 선언을 끝낸다

    구조체의 생성 이후, 그 데이터 형의 변수들을 생성할 수 있다.

    Explosive A;
    Explosive B;
    Explosive C;

    *Note : C언어에서는 구조체 변수 생성시 앞에 struct 키워드가 필요하다. C++에선 생략가능 (ex. struct Explosive A )
    Explosive 구조체 변수인 A, B, C는 모두 위에서 생성한 name, volume, price 인자를 가지고 있다.
    A, B, C 는 멤버 연산자인 (.)을 사용하여 구조체의 개별적인 멤버에 접근이 가능하다.

    다음 예시를 보자..

    struct Explosive
    {
        char name[20]{};
        float volume{};
        double price{};
    };

    int main()
    {

        Explosive A 
        {
            "Ballon", // name
            1.88f,    // volume
            29.99     // price
        };
        Explosive B {};

        cout << A.name << endl;
        cout << "할당되지 않은 B의 이름은 : " << B.name << "입니다.";
    
        return 0;
    }

    출력 : Ballon

    *Note : 구조체의 선언은 함수(main이던 다른 함수던..) 내부에 있든 외부에 있든 상관이 없지만,
            내부선언의 경우, 그 선언이 들어 있는 함수에서만 사용 할 수 있다.
            일반적으로 프로그래머들은 모든 함수들이 구조체를 사용할 수 있도록 구조체를 함수 외부에서 선언한다.

    *Note : Explosive B 처럼, 할당없이 초기화 할 경우, name, volume, price, 각 인자들은 0바이트로 초기화 된다.
    


    
    */
#pragma endregion

//201페이지


//-------------------------[ ProtoType ]-----------------------------------//

void Say();

//-------------------------[   FBody   ]-----------------------------------//

struct Explosive // struct(구조체 서술 정의) Explosive(구조체 이름) 
{
    char name[20]{};
    float volume{};
    double price{};
};

int main()
{
    Say();
    return 0;
}


//-------------------------[ Func.Def. ]-----------------------------------//

void Say()
{
    
    cout << "\n\n\nEnd Fuction";
}