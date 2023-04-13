#include <iostream>
#include <string> //string class 사용 위해
#include <cstring> //C 스타일 문자열 라이브러리
#include <array>
#include <cctype>
#include <ctime>
#include <fstream>  // 파일 I/O 를 위해
#include <cstdlib>  // exit() 지원
#include <cmath>
using namespace std;



#pragma region 10.템플릿
/*
---------------------------------------- 10.템플릿 ----------------------------------------
# 템플릿
***


***
출처 : C++ 기초 플러스 6판 / 성안당
***
*/
#pragma endregion

#pragma region 10.프로그래밍 연습_템플릿
/*
---------------------------------------- 09.프로그래밍 연습_템플릿 ----------------------------------------
문제 :


해답 :

***
출처 : C++ 기초 플러스 6판 / 성안당
***
*/
#pragma endregion

#pragma region Chapter 4.복합 데이터형
    
    #pragma region 04.문자열
    /*
    -------------- 04.문자열-----------------
    모든 문자열의 끝은 \0, 즉 널 문자(null character)여야 한다.
    char cat[3] = { 'c', 'a', 't' }; -- > 문자열이 아니다.
    char cat[4] = { 'c', 'a', 't', '\0' } -- > 문자열이다.
    예시의 cat 문자열은, 문자열을 선언하기 위해 아주 짜증나는 method를 사용한다.
    문자들을 작은 따옴표로 감싸고 끝에 널 문자를 넣어야 하기 때문이다.하지만 이보다 획기적인 방법은 존재한다.
    char cat_2[4] = { "cat" }; -- > cat_2 배열은 위의 예시 cat[4] 와 완벽하게 똑같은 문자열을 구현한다.
    이렇게 큰따옴표로 묶인 문자열을 문자열 상수(string constant or string literal) 이라고 한다.
    문자열에 cout 을 사용할 경우 null character을 만나면 멈추게 되는데 예시는 다음과 같다.
    cat[2] = '\0';
    cout << cat;    -- > 출력 : ca*/
    #pragma endregion
    #pragma region 04.getline()
    /*
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
    */
    #pragma endregion
    #pragma region 04.get()
    /*
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
    */
    #pragma endregion
    #pragma region 04.String class 조작
    /*
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
    */
    #pragma endregion
    #pragma region 04.String class 기타기능
    /*
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
    char let2[20]{ "Jaguar" };
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
    */
    #pragma endregion
    #pragma region 04.구조체
    /*
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
    #pragma region 04.구조체의 배열
    /*
    ---------------------------------------- 04. 구조체의 배열    ----------------------------------------
    struct Explosive
    {
        char name[20]{};
        float volume{};
        double price{};
    };


    int main()
    {
        Explosive Non_Flyable[2]    // Explosive 구조체로 이루어진 Non_Flyable 이름을 가진 배열의 생성
        {
            {"Dynamite", 0.5f, 0.99}, // 0번 원소
            {"TNT", 1.f, 1.99}        // 1번 원소
        };
        cout << Non_Flyable[0].name;
        return 0;
    }

    출력 : Dynamite
    */
    #pragma endregion
    #pragma region 04.공동체 (Union)
    /*
    ---------------------------------------- 04. 공동체 (Union)    ----------------------------------------
    Struct는 서로 다른 형태의 데이터 타입을 보관이 가능하다. 반대로, 공동체(Union)은
    서로 다른 형태의 데이터 타입을 보관할 수 있지만, 어느 순간에는 한 데이터 타입으로 고정이 되게 된다.
    다음 예시를 보자.

    union Number
    {
        int int_num{};
        float float_num{};
        double double_num{}; // 각각의 자료형은 int, float, double을 가진다

        int_num = 1;  // int 값 저장
        float_num = 1.f; // float 값 저장, int 값 소실
        double_nume = 1.00; // double 값 저장, float 값 소실
    };
    이처럼 struct와는 다르게 union의 크기는, 가장 큰(바이트) 멤버의 크기가 된다.
    여러가지 데이터 형을 사용할 수는 있지만, 이들을 동시에 사용할 수 없을 때, union을 사용하면
    int, float가 메모리 크기가 가장 큰 double 자료형의 공간을 공유하기 때문에, 메모리의 절약이 가능하다.
    */
    #pragma endregion
    #pragma region 04.열거체 (Enum)
    /*
    ---------------------------------------- 04. 열거체 (Enum)    ----------------------------------------
    C++의 enum의 기능은 const를 사용하여 기호 상수를 만드는 것에 대한 또 다른 방편이다.
    또한, 제한적이지만 새로운 데이터 형을 정의할 수 있게 해준다. 다음 예시를 보자.
    enum Days{ MON, TUE, WED, THU, FRI, SAT, SUN };
    이 구문은 두 가지 일을 수행한다.
        1. Days를 새로운 데이터 형의 이름으로 만든다. enum형 변수들은 열거체(enumeration) 이라고 부른다.
        2. MON, TUE, WED,... 등을 0~6까지의 정수 값을 나타내는 기호 상수로 만들고, 열거자(enumerator)라 한다.
    기본적으로 첫번째 열거자에 0이 대입되고, 두번째 열거자에 1이 대입되는 방식으로 차례로 대입된다.
    
    열거체의 이름을 사용하여 열거형의 변수를 선언할 수 있다.
        Days LastDay; //LastDay는 Days형의 변수

    열거체 변수는 특별한 특성을 가지고 있다.
        1.열거체 변수에는 데이터형을 정의하는데 사용된 열거자 값들만 대입할 수 있다.
            LastDay = MON // 맞다, MON은 열거자다.
            LastDay = DoomsDay // 틀리다, DoomsDay는 열거자가 아니다
        2. 열거체는 대입 연산자만 사용하도록 정의되어 있다. 특히, 산술 연산은 허용되지 않는다.
            LastDay = MON;         // 맞다
            ++LastDay;             // 틀리다
            LastDay = MON+TUE      // 그럴듯하지만 틀리다
        3. 열거자 값의 설정은 대입 연산자를 사용한다.
            enum Days{ MON = 1, TUE = 3, WED = 5, THU = 7, FRI = 9, SAT = 11, SUN };
            이 경우, SUN은, 직전 열거자인 SAT의 Value 인 11의 다음 정수, 즉 12가 대입되게 된다.

    열거체는 특정한 상태 집합을 나타내야 할 때, 문서화 및 가독성 목적으로 매우 훌륭하다.
    다음 예시를 보자..
    // 문법이 맞지 않는건 가독성을 위해서니 넘어가주자..

    if(문서 삽입 오류 발생)
        return -1;
    if(문서 삭제 오류 발생)
        return -2;
    if(문서 갱신 오류 발생)
        return -3;

    이 경우, 각각의 오류에 대해, 프로그램은 -1, -2, -3 을 반환한다.
    그럼 프로그래머는 반환 값을 보고 코드를 살펴보며 -1, -2, -3 이 각각 지칭하는 오류가 무엇인지 찾아야한다.
    이는, 지금 같은 작은 프로그래밍에선 가능할지 모르지만, 수 많은 코드들이 뭉쳐있다면 결코 쉬운 일은 아닐 것이다.
    열거체는 이럴 때 빛을 발한다. 다음 예시를 보자

    enum 오류 { 삽입 = -1, 삭제 = -2, 갱신= -3 };

    if(문서 삽입 오류 발생)
        return 삽입;
    if(문서 삭제 오류 발생)
        return 삭제;
    if(문서 갱신 오류 발생)
        return 갱신;

    이 경우, 프로그래머는 반환 값(삽입, 삭제, 갱신)을 보고 어디서 오류가 발생했는지 즉시 알 수 있다. 
    */
    #pragma endregion
    #pragma region 04.포인터와 메모리 해제_1
    /*
    ---------------------------------------- 04. 포인터와 메모리 해제_1    ----------------------------------------
    포인터는 C++의 꽃으로, 포인터는 값 자체가 아닌, 값의 주소를 저장하는 변수이다.
    포인터 변수의 선언 및 역연산은 '*' 을 사용하며 주소를 알기 위해선 주소 연산자 '&'를 사용한다.
    다음 예시를 보자..

    int num1 = 1234;
    double num2 = 3.14;

    int* ptr_num1{}; // int 형 포인터 ptr_num1 의 선언
    double* ptr_num2{}; // double 형 포인터 ptr_num2 의 선언

    cout << "현재 num1의 값은 : " << num1 << "이고 " << "num1의 주소는 : " << &num1 << "입니다." << endl;
    cout << "현재 num2의 값은 : " << num2 << "이고 " << "num2의 주소는 : " << &num2 << "입니다." << endl;
    
    cout << "할당 되지 않은(초기값) ptr_num1의 주소는 : " << ptr_num1 << "입니다" << endl;
    cout << "할당 되지 않은(초기값) ptr_num2의 주소는 : " << ptr_num2 << "입니다" << endl;

    ptr_num1 = &num1;   // ptr_num1 은 포인터이기 때문에, ptr_num1 = num1 을 선언하면 오류가 나게 된다
    ptr_num2 = &num2;   // 따라서, ptr_num1 같은 포인터형 변수에는 '&'을 이용하여 주소 값을 넣어주어야 한다.

    cout << "할당 된 ptr_num1의 주소는 : " << ptr_num1 << "이며 num1의 주소는 : " << &num1 << "입니다." << endl;
    cout << "할당 된 ptr_num2의 주소는 : " << ptr_num2 << "이며 num2의 주소는 : " << &num2 << "입니다." << endl;

    cout << "ptr_num1은 num1을 가르키는 포인터 입니다. '*'을 사용하여 ptr_num1이 가르키는 값을 가져옵니다.."<< *ptr_num1 << endl;
    cout << "num1의 주소 : " << &num1 << endl << "ptr_num1의 주소 : " << &ptr_num1;
    // ptr_num1이 num1을 가르킨다 해서 ptr_num1의 주소가 num1의 주소와 같아지는 것은 아니다.

    출력 :
    현재 num1의 값은 : 1234이고 num1의 주소는 : 0133FB7C입니다.
    현재 num2의 값은 : 3.14이고 num2의 주소는 : 0133FB6C입니다.
    할당 되지 않은(초기값) ptr_num1의 주소는 : 00000000입니다
    할당 되지 않은(초기값) ptr_num2의 주소는 : 00000000입니다
    할당 된 ptr_num1의 주소는 : 0133FB7C이며 num1의 주소는 : 0133FB7C입니다.
    할당 된 ptr_num2의 주소는 : 0133FB6C이며 num2의 주소는 : 0133FB6C입니다.
    ptr_num1은 num1을 가르키는 포인터 입니다. '*'을 사용하여 ptr_num1이 가르키는 값을 가져옵니다..1234
    num1의 주소 : 0133FB7C
    ptr_num1의 주소 : 0133FB60

    *Warning : 포인터는 주소를 가르키는만큼 매우 신중하게 사용하여야 한다. 왜냐하면 할당 될 주소에
               무엇이 있을지 모르기 때문이다. 다음 예시를 보자

               00000001 의 주소에 플레이어가 소지한 돈이 있다고 가정하자.
               int* HP;     // Warning : 초기화 하지 않았기 때문에 HP 포인터에는 랜덤한 쓰레기 값이 들어가게 된다.
               만일 우연의 일치로 HP에 할당된 쓰레기 주소 값이 00000001이라고 가정하자.
               HP와 돈이 얽히면서 상황이 매우 복잡해지게 된다.
               이처럼 포인터는 반드시 생성 시 초기화를 해주어야 하고, 임의로 주소 값을 할당하면 안된다.
               이는, 프로그램을 실행하더라도 오류 메시지를 출력하지 않고 작동이 될 수 있기 때문에,
               이런 종류의 에러가 가장 찾기 힘든 버그이다. 


    */
    #pragma endregion
    #pragma region 04.포인터와 메모리 해제_2
    /*
    ---------------------------------------- 04.포인터와 메모리 해제_2    ----------------------------------------
    각 포인터는 이름에 의해 직접 접근할 수 있는 메모리를 위한 대용 이름을 제공했다.
    하지만 프로그램을 실행하는 동안(Run Time), 이름이 없는 메모리를 대입하는 것이 포인터의 진정한 가치다.
    이 경우, 포인터가 그 메모리에 접근할 수 있는 유일한 통로가 된다.
    C에선 malloc()이란 라이브러리 함수를 사용했지만, C++는 new 연산자라는 더 좋은 방법을 제공한다.
    다음 예시를 보자.
    int* pn = new int;
    new int 부분은, int형 데이터를 저장할 메모리가 필요하다고 프로그램에게 알린다.
    new 연산자는 뒤의 자료형을 보고 몇 바이트가 필요한지를 파악 후 적당한 메모리를 찾아 대입하고 주소를 리턴한다.
    리턴되는 주소는 pn에 대입되게 되며, pn은 주소이고 *pn은 그 주소에 저장되는 값이다.

    int* pt = new int;
    pt = 1001;      // 틀리다. pt는 int를 가르키는 주소 값이기 때문에 주소를 넣어주어야 한다
    *pt = 1001;     //맞다. *pt는 주소에 있는 int value이기 때문에 1001은 int 이므로 대입이 가능하다.
    cout << pt << endl << *pt;

    출력 : 
    pt의 주소
    1001
    */

    #pragma endregion
    #pragma region 04.포인터와 메모리 해제_3
    /*
    ---------------------------------------- 04. 포인터와 메모리 해제_3 ----------------------------------------
    new를 사용한 메모리 대입은 C++의 메모리 관리 기능의 절반에 불과하다.
    나머지 절반은, 사용한 메모리를 메모리 풀로 환수하는 delete 연산자이다.
    환수한 메모리는 프로그램의 다른 부분이 다시 사용할 수 있다. delete는 new로 대입한 메모리 블록을 지시하는 포인터와 함께 사용한다.

    int* pt = new int;      // new로 메모리 대입
    ...메모리를 사용하는 중..
    delete pt;              // delete로 메모리 해제 

    new를 사용한 후에는 *반드시* delete를 사용해 메모리를 해제 해야한다.
    그렇지 않으면, 대입은 되었지만, 더 이상 사용하지 않는 메모리 누수(Memory Leak)가 발생할 수 있다.
    메모리 누수의 규모가 너무 커지면 메모리를 요구하는 프로그램이 먹통이 될 수도 있다.
    
    *Caution : 이미 해제한 메모리를 delete를 통해 다시 해제하면 안된다. 
               delete는 new로 대입한 메모리를 해제할 때에만 사용해야 한다.
               단, delete로 널 포인터 (Null Pointer)에 사용하는 것은 안전하다.
    */
    #pragma endregion
    #pragma region 04.new를 사용한 동적 배열의 생성
    /*
    ----------------------------------- 04. new를 사용한 동적 배열의 생성..  ---------------------------------------
    프로그램이 하나의 값만을 요구한다면, new보다는 단순한 변수의 선언이 간단하다.
    하지만 배열, 문자열, 구조체와 같은 큰 데이터를 다룰 땐, new를 사용하는 것이 훨씬 더 효율적이다.
    프로그램이 실행되는 동안, 주어지는 정보에 따라 배열을 생성하거나 생성하지 않는 프로그램을 작성한다 가정해 보자.
    선언에 의해 배열을 생성하면, 프로그램이 *컴파일 될 때* 배열을 위한 메모리가 대입된다.
    프로그램이 실행될 때, 이 배열은 사용 여부에 관계 없이 메모리를 차지한다. 이것을 *정적 바인딩(Static Binding)*이라고 한다.
    정적 바인딩은 한 마디로, 컴파일 시간에 생성된다는 것을 말한다. 
    그러나 new를 사용하면, 배열은 Run-Time에 생성되며 필요 없다면 생성을 하지 않을 수도 있다.
    또는 프로그램을 실행하는 동안 배열의 크기를 결정할 수 있다. 이것을 *동적 바인딩(Dynamic Binding)*이라고 한다.

    C++에서는 동적 배열을 쉽게 만들 수 있다. 다음 예시를 보자.
    
    int* psome = new int[10];   // 10개의 int형 값을 저장할 블록을 대입

    new를 사용해 생성 했으므로, 사용을 마친 후 반드시 delete로 해제해 주어야 한다.

    delete [] psome;            // 동적 배열을 해제

    따라서 new / delete를 사용할 때 다음과 같은 규칙을 지켜야한다.
        
        1. new로 대입하지 않은 메모리는 delete로 해제하지 않는다.
        2. 같은 메모리 블록을 연달아 두 번 delete로 해제하지 않는다.
        3. new []로 메모리를 대입한 경우에는 delete[] 로 해제한다.
        4. new를 대괄호 없이  사용했으면 delete도 대괄호 없이 사용한다.
        5. null pointer는 delete를 사용하는 것이 안전하다. ( 아무 일도 일어나지 않는다. )
    */
    #pragma endregion
    #pragma region 04.동적 배열의 사용
    /*
    ---------------------------------------- 04.동적 배열의 사용    ----------------------------------------
    동적 배열의 사용은 C++에서 놀라울 정도로 간단하다.
    다음 예시를 보자.
    
    int* p3 = new int[3];   // int형 데이터 저장 가능한 크기 3의 공간 생성, p3를 배열 이름처럼 취급
    p3[0] = 1;
    p3[1] = 3;
    p3[2] = 5;
    cout << "p3[0]의 값은 : " << p3[0] << " 입니다." << endl;
    p3 = p3 + 1; // 포인터를 증가 시킨다.
    cout << "이제 p3[0]의 값은 : " << p3[0] << " 입니다.";
    p3 = p3 - 1; // 포인터를 원상 복구 시킨다.
    delete [] p3;          // delete 잊지 말자!

    출력 :
    p3[0]의 값은 : 1 입니다.
    이제 p3[0]의 값은 : 3 입니다.

    이는, p3[0]의 value인 1에, 정수 1을 더한 것이 아닌, p3[0]의 위치에서 1칸 옮겨(포인터를 옮겨) p3[1]을 가르키게 만들었기 때문이다.

    */
    #pragma endregion
    #pragma region 04.프로그램 분석
    /*
    ---------------------------------------- 04.프로그램 분석 ----------------------------------------
    대부분의 상황에서 C++는 배열 이름을 그 배열의 첫 번째 원소의 주소로 해석한다.
    즉,

    int* pw = wages; 라면
    wages = &wages[0]; 이다.

    그렇다면 배열의 이름이 배열의 주소인가? *절대로 아니다.* 배열의 이름은 배열의 첫번째 원소의 주소를 가리킨다.
    반면에 주소 연산자를 적용하면 전체 배열의 주소가 산출된다.

    int tell[20];
    cout << tell << endl;   // &tell[0]을 출력한다 = tell 배열의 1번째 원소의 주소값을 출력한다.
    cout << &tell << endl;  // tell 배열의 전체 주소 값을 출력한다.
    */
    #pragma endregion
    #pragma region 04.new를 사용한 동적 구조체의 생성
    /*
    ---------------------------------------- 04.new를 사용한 동적 구조체의 생성  ----------------------------------------
    컴파일 시간 보다는 실행 시간에 배열을 생성하는 것이 훨씬 유리하다는 것을 알아보았다.
    이것은 구조체에도 그대로 해당된다. new를 구조체에 사용할 때에는 두 가지를 알아야 한다.
    하나는, 구조체를 생성하는 것이고, 다른 하나는 구조체 멤버에 접근하는 것이다.
    다음 예시를 보자.

    inflatable* ps = new inflatable;

    이 코드는, inflatable 형의 구조체를 저장할 수 있는 크기의 새로운 메모리 블록을 확보하고
    주소를 ps에 대입한다. 멤버에 접근하는 것은 약간 까다롭다. 
    *동적 구조체에는 도트(.) 멤버 연산자 사용이 불가하기 때문이다.*
    그 이유는, 동적 구조체에는 이름이 없고, 우리는 주소만 알 수 있기 때문이다.
    C++는 이 문제를 해결하기 위해, 화살표 멤버 연산자 ( -> )를 사용한다.
    도트 멤버 연산자는 구조체 이름과 함께 사용하고, 화살표 멤버 연산자는 구조체를 지시하는 포인터와 사용한다.
    예를 들어, ps가 inflatble 형 구조체를 지시하는 포인터라면, ps->price는 ps가 지시하는 구조체의 price 멤버이다.

    구조체 멤버에 접근하는 다소 보기 흉한 다른 방법은, *ps가 포인터가 지시하는 값, 즉 구조체이기 때문에
    (*ps) 처럼 괄호를 붙여 사용하는 방법이다.

        inflatble* ps = new inflatble;
        ps->name;       // 멤버 접근하는 제 1 방법
        (*ps).name;     // 멤버 접근하는 제 2 방법


    new와 delete를 사용하는 예제
    프로그램이 1,000개의 문자열을 읽어들여야 한다고 가정하자.
    그중에서 가장 긴 문자열은 79개의 문자이지만 대부분의 문자열은 그것보다 훨씬 길이가 짧다.
    문자열 저장을 위해 char 형의 배열을 사용한다면, 크기가 80인 char형의 배열을 1,000개나 만들어야 한다.
    이를 위해선 전체 80,000바이트가 필요하다. 이렇게 할 경우, 대부분의 메모리 공간은 사용되지 않고 버려진다.

    좋은 대안은, char형을 지시하는 1,000개의 포인터를 원소로 가지는 배열을 만드는 것이다.
    문자열마다 new를 사용하여, 각 문자열의 크기에 맞는 메모리 블록을 대입하고,
    각 블록의 주소를 포인터 배열의 각 원소에 대입한다.
    다음 예제를 보자.

        int main()
        {
            char* name{};
            name = getname();   // 문자열의 주소를 name에 대입한다.
            cout << (int*) name << " : " << name << endl;
            delete [] name;     // 메모리를 다시 해제한다.

            name = getname();   // 해제한 메모리를 다시 사용한다.
            cout << (int*) name << " : " << name << endl;
            delete [] name;     // 메모리를 다시 해제한다.
            return 0;
        }

        char* getname()
        {
            char temp[80];                                  // 임시배열
            cout << "이름을 입력하십시오 : ";
            cin >> temp;
            char* pn = new char[strlen(temp) + 1 ];
            strcpy(pn, temp);                               // 문자열을 더 작은 공간으로 복사한다.
            return pn;                                        // 함수가 종료될 때, 임시 배열인 temp는 소멸한다.
        }

    프로그램 분석 :
        getname()에선, cin을 통해 문자열을 입력 받아 임시 배열인 temp에 저장한다.
        그 후, 정식으로 저장할 새로운 메모리 블록을 new를 사용하여 대입한다.
        문자열을 저장하려면 널 문자까지 포함하여 strlen(temp)+1 바이트가 필요하다.
        이 값이 new로 전달되어 적당한 크기의 새로운 메모리 블록이 확보되면,
        temp에 들어 있는 문자열을 새로운 메모리 블록으로 복사한다.
        getname()함수는 메모리 블록의 크기가 적절한지 검사하지 않는다.
        new를 통해 적당한 바이트 수를 대입한 것이므로 아무런 문제가 없기 때문이다.
        마지막으로 이 함수는 복사된 문자열이 저장되어 있는 메모리 블록의 주소 pn을 리턴한다.

        main()에선 리턴된 pn의 값(주소)를 name에 대입한다.
        이후, main()에선, getname()을 통해 대입 받은 주소와 문자열을 출력한다.
        다음으로, main()은 name이  지시하던 메모리를 해제, getname()을 다시 호출한다.
        
        이 예제에서는 getname()함수에서 대입한 메모리를 main()함수에서 해제하고 있다.
        이와 같이 new와 delete를 서로 다른 함수에서 사용하는 것은 좋은 생각이 아니다.
        *delete를 사용하는 일을 잊어버리기 쉽기 때문이다*
        이 예제는 단순히 이것이 가능하다는 것을 보여주는 것이다.
    */
    #pragma endregion
    #pragma region 04.자동 공간, 정적 공간, 동적 공간
    /*
    ---------------------------------------- 04.자동 공간, 정적 공간, 동적 공간 ----------------------------------------
    C++은 데이터를 저장해 두기 위한 메모리를, 대입 방법에 따라 
    자동 공간(Automatic storage), 정적 공간(Static storage), 동적 공간(Dynamic storage)로 구분한다.
    동적 공간은 자유 공간 또는 힙(Heap)이라고도 부른다.
    이들에 대해서 알아보자.

    자동 공간
        자동 공간을 사용하는 함수 안에서 정의되는 보통의 변수들을 자동 변수라고 한다.
        자동 변수들이 자신이 정의되어 있는 함수가 호출되는 순간에 자동으로 생겨나 
        그 함수가 종료되는 시점까지만 존재한다는 것을 뜻한다. 
        자동 변수는 자신들을 포함하고 있는 블록 안에서만 유효하다.
        자동 변수는 스택에 저장된다. 이것은, 메모리 상의 스택에 그 값이 순차적으로 저장되고, 역순으로 해제되는 
        LIFO (Last-In, First-Out) 을 뜻한다. 따라서 스택은 프로그램이 실행하는 동안 늘었다 줄었다를 반복한다.

    정적 공간
        정적 공간은 프로그램이 실행되는 동안 지속적으로 존재하는 공간이다.
        변수를 정적으로 만드는 방법은 두 가지이다. 하나는 함수의 외부에서 변수를 정의하는 것이고,
        다른 하나는 변수를 선언할 때 static 이라는 키워드를 붙이는 것이다.
        정적 공간은 추후에 자세하게 논의한다. 우리가 여기서 알아야 할 사항은,
        이 방법들이 변수의 수명을 정적으로 결정한다는 사실이다.
        정적 변수는 프로그램이 실행되는 동안 지속적으로 존재하지만, 자동 변수는 특정 함수나 블록이 실행되는 동안에만 존재한다.

    동적 공간
        new와 delete 연산자는 보다 융통성 있는 방법을 제공한다.
        이들은 자유 공간이라 불리는 메모리 풀(Memory Pool)을 관리한다.
        이 풀은, 자동 변수와 정적 변수가 사용하는 메모리와 분리되어 있다.
        이 풀에서, 데이터의 수명은 프로그램의 수명이나 함수의 수명에 얽매이지 않는다.
        그러나 메모리 관리는 점점 더 복잡해지고 있다. 스택의 경우,
        자동으로 늘어나고 줄어드는 매커니즘으로 인해, 값들이 메모리 상에서 인접하여 존재한다.
        그러나 new와 delete의 상호 작용으로 여유 공간을 확보할 수 있고, 더 복잡한 메모리 대입 요청의 처리가 가능하다.
    */
    #pragma endregion
    #pragma region 04.배열의 대안
    /*  
    ---------------------------------------- 04.배열의 대안---------------------------------------
    Vector 템플릿 클래스
        Vector 템플릿 클래스는, 프로그램이 실행되는 동안 vector 객체의 크기를 세팅할 수 있고,
        새로운 데이터를 마지막에 추가하거나, 중간에 삽입 할 수 있다. 실제로 vector 클래스는
        메모리 관리를 위해 new와 delete를 사용하지만, 그 과정은 자동으로 진행된다.
        이 장에선 vector의 간단한 구현에 대해서만 알아볼 것이다.
        
        #include<vector>
        Template : 
            vector<typeName> VectorName(NumberOfElements);
        Example : ( Int 형으로 이루어진 원소 10개를 포함하는 IntVector의 생성 )
            vector<int> IntVector(10);

    Array 템플릿 클래스
        vector 클래스는 내제 배열 형보다 많은 기능을 가지고 있지만,
        사용자가 고정된 크기의 배열만 필요하다면, 다소 비효율적이다.
        C++11은 내제 배열형을 사용함으로써, 다소 줄어들 안정성과 편리성에 대해
        Array 템플릿 클래스를 이용해 해결책을 제시한다.

        #include<array>
        Template :
            array<typeName, NumberOfElements> ArrayName;
        Example : ( Int 형으로 이루어진 원소 10개를 포함하는 IntArray의 생성 )
            arrat<int, 10> IntArray;

    Vector와 Array에 대해서는, 16장에서 보다 더 자세하게 다루기로 하겠다.

    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_1
    /*
    ---------------------------------------- 04.프로그래밍 연습_1 ----------------------------------------
    문제 : 입력을 읽어 출력하는 C++ 프로그램을 작성하라.

    입력 : 
        Seong il
        Yoon
        B
        22
    출력 : 
        성명 : Yoon, Seong il
        학점 : C
        나이 : 22

    *Note : 두 단어 이상으로된 이름을 받아야 한다. 학점을 한 단계 하향 조정해서 출력한다. A->B, B->C 식으로..

    해답 : 

    struct Student
    {
        char first[20]{};
        char last[20]{};
        char grade{};
        int age{};
    };

    Student std;
    cin.getline(std.first, 20);
    cin >> std.last >> std.grade >> std.age;

    std.grade += 1;

    cout << "성명 : " << std.last << ", " << std.first << endl;
    cout << "학점 : " << std.grade << endl << "나이 : " << std.age;
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_3(2번 생략)
    /*
    ---------------------------------------- 04.프로그래밍 연습_3(2번 생략) ----------------------------------------
    문제 : 성과 이름을 입력 받고, 라스트 네임, 콤마, 빈칸, 퍼스트 네임으로 이루어지는 제 3의 문자열을 구성 후
       출력 하는 프로그램을 작성하라. ( Char 형 사용 )

    입력 :
        Seong il
        Yoon

    출력 :
        Yoon, Seong il

    해답 :

    struct Naming
    {
        char first[20]{};
        char last[20]{};
        char mixed[40]{};
    };

    Naming name;
    cin.getline(name.first, 20);
    cin >> name.last;
    strcpy_s(name.mixed, name.last);
    strcat_s(name.mixed, ", ");
    strcat_s(name.mixed, name.first);
    cout << name.mixed;
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_4
    /*
    ---------------------------------------- 05.프로그래밍 연습_4 ----------------------------------------
    문제 : 이름, 성을 입력 받아, 성, 콤마, 빈칸, 이름으로 이루어지는 제 3의 문자열을 구성하고 출력하라. ( String 사용 )

    입력 :
        Seong il
        Yoon

    출력 :
        Yoon, Seong il

    해답 :
        struct Name
        {
            string first{};
            string last{};
            string name{};
        };

        Name full;
        getline(cin, full.first);   //string에서 getline(cin, 문자열) 로 한 줄 전체 읽기 가능
        cin >> full.last;
        full.name = full.last;
        full.name.append(", ");     //문자열.append() 로 뒤에 다른 문자열 추가 가능
        full.name.append(full.first);
        cout << full.name;
       
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_5
    /*
    ---------------------------------------- 05.프로그래밍 연습_5 ----------------------------------------
    문제 : 상표명, 중량(소수), 칼로리(정수)를 멤버 변수로 갖는 snack이란 CandyBar형 구조체 변수를 만든 후,
           그들을 각각, "Mocha Munch", 2.3, 350 으로 초기화 하라. 그 후, snack 변수의 내용을 출력하라.

    해답 :
        struct CandyBar
        {
            string name{};
            float mass{};
            int kCal{};
        };

        CandyBar snack{"Mocha Munch", 2.3f, 350};
        cout << snack.name << endl << snack.mass << endl << snack.kCal;
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_6
    /*
    ---------------------------------------- 04.프로그래밍 연습_6 ----------------------------------------
    문제 : 이름, 중량, 칼로리를 멤버 변수로 갖는 CandyBar란 구조체의 생성 후, CandyBar 구조체를 원소로 갖는
    배열을 생성하라. 원소들을 원하는 값으로 초기화 한 후, 각 구조체의 내용을 출력하라.

    해답 :
        struct CandyBar
        {
            string name{};
            float mass{};
            int kCal{};
        };
    
        CandyBar candy[2]
        {
            {"Lemon", 2.3f, 500},
            {"Cinamon", 3.7f, 300}
        };

        cout << candy[0].name << candy[0].mass << candy[0].kCal << endl;
        cout << candy[1].name << candy[1].mass << candy[1].kCal;
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_7
    /*
    ---------------------------------------- 04.프로그래밍 연습_7 ----------------------------------------
    문제 : 
    노미도피자헙은 피자에 관해서 다음 정보를 저장해야 한다.
        
        피자 회사의 이름
        피자의 지름
        피자의 중량

    이러한 정보를 저장하는 구조체 템플릿을 설계하고, 구조체형의 멤버 변수를 사용하는 프로그램을 작성하라.
    위 정보는, 사용자가 입력해야한다.

    해답 :
        struct Analysis
        {
            string name{};
            float radius{};
            float mass{};
        };

        Analysis pizza;
        getline(cin, pizza.name);
        cin >> pizza.radius >> pizza.mass;
        cout << pizza.name << " " << pizza.radius << " " << pizza.mass;

    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_8
    /*
    ---------------------------------------- 04.프로그래밍 연습_8 ----------------------------------------
    문제 :
    노미도피자헙은 피자에 관해서 다음 정보를 저장해야 한다.
        
        피자 회사의 이름
        피자의 지름
        피자의 중량

    이러한 정보를 저장하는 구조체 템플릿을 설계하고, 구조체형의 멤버 변수를 사용하는 프로그램을 작성하라.
    위 정보는, 사용자가 입력해야하며, 변수의 선언 대신 new를 사용하여 구조체를 대입하라. 
    그리고 피자 회사의 이름보다 피자의 지름을 먼저 요구하게 하라.

    해답 :
        struct Analysis
        {
            string name{};
            float diameter{};
            float mass{};
        };

        Analysis* pizza = new Analysis;
        cin >> pizza->diameter;
        cin.get();                      //이 문제의 핵심이다. 지름을 입력한 후 enter로 인한 개행 문자를 버려야한다.
        getline(cin, pizza->name);
        cin >> pizza->mass;

        cout << pizza->name << " " << pizza->diameter << " " << pizza->mass;
        delete pizza;
    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_9
    /*
    ---------------------------------------- 04.프로그래밍 연습_9 ----------------------------------------
    문제 :
    이름, 중량, 칼로리를 멤버 변수로 갖는 CandyBar란 구조체의 생성 후, CandyBar 구조체를 원소로 갖는
    배열을 new를 사용하여 동적으로 대입하라.

    해답 :
        struct CandyBar
        {
            string name{};
            float mass{};
            int kCal{};
        };

        CandyBar *candy = new CandyBar[2];

        candy[0].name = "Lemon";
        candy[0].mass = 2.3f;
        candy[0].kCal = 500;

        candy[1].name = "Cinamon";
        candy[1].mass = 4.3f;
        candy[1].kCal = 700;

        cout << candy[0].name;      //대입 체크용

    */
    #pragma endregion
    #pragma region 04.프로그래밍 연습_10
    /*
    ---------------------------------------- 04.프로그래밍 연습_10 ----------------------------------------
    문제 :
    40야드 달리기 결과에 대하여 세 번 입력 가능한 프로그램을 작성하고 횟수와 평균을 디스플레이하라.

    해답 :
        int runCount{};
        float total{};
        cout << "How many shot would ya give? ";
        cin >> runCount;
        if (runCount > 3)
        {
            cout << "Damnn! Too many shot! Do not be greedy! Try less than 4";
            return;
        }

        struct Dash
        {
            float runTime{};
        };

        Dash dash[3]{};

        for (int i = 0; i < runCount; i++)
        {
            cout << "No." << i+1  << "'s Runtime Result? ";
            cin >> dash[i].runTime;
            total += dash[i].runTime;
        }

        cout << "The average result of your runtime is " << total / runCount;
    */
    #pragma endregion



#pragma  endregion

#pragma region Chapter 5.루프와 관계 표현식
    
    #pragma region 05.for 루프
    /*
    ---------------------------------------- 05.for 루프 ----------------------------------------
    프로그래밍을 하다 보면 배열의 원소들을 모두 더한다든지, 문자열을 여러번 출력하는 등, 반복적인 작업을 수행 할 때가 많다.
    C++의 for루프를 사용하면 이러한 반복 작업을 쉽게 처리할 수 있다. 다음 예제를 보자

        int i{};    // 카운터 선언
        for(i = 0; i < 5; i++)
        {
            cout << "C++가 루프를 사용합니다." << endl;
            cout << i +1 << "번째 루프 중.." << endl;
        }
        cout << "루프를 종료합니다."
        return 0;

    출력 : 
        C++가 루프를 사용합니다.
        1번째 루프중..
        C++가 루프를 사용합니다.
        2번째 루프중..
        C++가 루프를 사용합니다.
        3번째 루프중..
        C++가 루프를 사용합니다.
        4번째 루프중..
        C++가 루프를 사용합니다.
        5번째 루프중..
        루프를 종료합니다.

    이는 간단하지만 강력한 루프의 예시이다.
    루프는 정수 i를 0으로 설정하며 시작한다. 
    i = 0 --> 루프 초기화 부분은 
    루프 조건 검사 부분에서 i가 5보다 작은지 검사한다. --> i < 5
    이 조건을 만족하면, 루프 몸체라고 부르는 다음 구문을 수행한다.
            
            cout << "C++가 루프를 사용합니다." << endl;
            cout << i << "번째 루프 중..";

    이제 프로그램은 루프 갱신 부분에서 i를 1만큼 증가 시킨다. --> i++
    
    프로그램은 이 과정을 i가 5가 될 때까지 계속한다. i가 5가 되면 루프 조건 검사를 만족하지 못하므로
    for Loop는 종료 되고 그 다음 구문인 return 0;를 수행한다.
    */
    #pragma endregion
    #pragma region 05.for 루프를 사용한 문자열 처리
    /*
    ---------------------------------------- 05.for 루프를 사용한 문자열 처리 ----------------------------------------
    for 루프를 사용하여 문자열을 구성하는 문자들에 차례대로 접근할 수 있다.
    string.size() 를 사용하여 string의 크기를 알아낸 후 for루프를 통한 역출력의 예시를 보자.

        cout << "단어 하나를 입력하시오" << endl;
        string word{};
        cin >> word;

        for(int i = word.size() -1 ; i >= 0; i--)
        {
            cout << word[i];
        }
        cout << endl << "종료";
        return 0;
    
    예시 입력 : size
    예시 출력 : ezis

    프로그램 설명 : 
        배열의 마지막 인덱스는 배열의 크기보다 1작기 때문에 word.size() 에서 1을 뺀 값으로 시작한다.
        이 경우 i는 3부터 시작하여 1씩 감소하다, 0보다 작아지면 루프를 중단하게 된다.
    */
    #pragma endregion
    #pragma region 05.증감 연산자와 포인터
    /*
    ---------------------------------------- 05.증감 연산자와 포인터 ----------------------------------------
    증감 연산자는 변수 뿐만 아니라 포인터에도 사용이 가능하다. 포인터에 증감 연산자를 사용하면,
    포인트가 가르키는 데이터형의 바이트 수만큼 그 값을 증가 시킨다. 다음 예제를 보자.

        int arr[5] { 1,3,5,7,9 };
        int* pt = arr;  // pt는 arr[0], 즉 1을 지시한다.
        ++pt;           // pt는 arr[1], 즉 3를 지시한다.
        ++*pt;          // pt는 arr[1]을 지시하며 1이 증가된 4이다.

    예제처럼, 접두형 연산자들은 오른쪽에서 왼쪽으로 결합을 하는 규칙을 따른다. 예제 마지막 줄 처럼
    ++*pt는, (*pt) 의 처리 이후 ( = 3 ), 증감 연산자를 사용하여 값을 1만큼 더해준다.


    */
    #pragma endregion
    #pragma region 05.While 루프
    /*
    ---------------------------------------- 05.While 루프 ----------------------------------------
    while 루프는, for 루프에서 초기화 부분과 갱신 부분을 없앤, 루프 몸체와 조건 검사 부분만 남겨 놓은 것이다.

        while(조건)
        {
            반복문
        }

    다음 예시를 보자..

        int i{};
        while(i<10)
        {
            cout << i + 1 << "번째 반복입니다." << endl;
            i++;
        }

    출력 :
        1번째 반복입니다.
        2번째 반복입니다.
        3번째 반복입니다.
        4번째 반복입니다.
        5번째 반복입니다.
        6번째 반복입니다.
        7번째 반복입니다.
        8번째 반복입니다.
        9번째 반복입니다.
        10번째 반복입니다.

    주목해야 할 것은 while 문 안의 마지막 반복문인 'i++' 이다.
    while은 조건을 만족하는 한, 무한하게 반복문을 수행한다.
    이는 while문을 쓸 때 조심해야 할 부분이며, 반복문을 수행하면서, 어느 순간에 while문을 탈출 할 수 있는지 
    프로그래머는 유의하여야 한다.
    */
    #pragma endregion
    #pragma region 05.clock() / ctime을 이용한 시간 지연 루프
    /*
    ---------------------------------------- 05.clock() / ctime을 이용한 시간 지연 루프 ----------------------------------------
    시간을 지연 시켜야 하는 프로그램을 작성해야 할 때가 있다.
    예를 들어, 주문을 받은 후, 5초 후에 다음 주문을 받을 수 있는 프로그램을 작성하는 경우
    5초 정도 기다렸다가 다음 동작으로 옮겨간다면, 대단히 좋은 프로그램으로 평가 받을 것이다.
    이러한 프로그램은 while을 통해 간단하게 구현할 수 있다. 다음 예시를 보자.

        long wait {};
        while (wait < 5)
        {
            wait++;
        }
    
    매우 간단하게 보이지만, 이 프로그램은 치명적인 단점이 있다.
    바로, 사용자의 컴퓨터 성능에 따라 프로그램의 지연시간이 달라지는 것이다.
    프로그램의 처리 속도는 컴퓨터의 '프로세서'의 성능에 따라 달라진다.
    예를 들어, A 컴퓨터의 프로세서는 1초에 while 반복문을 1개 수행한다 가정하자.
    while 문에 진입한 A 컴퓨터는, 프로그래머의 의도대로 5초 후에 프로세스를 종료할 것이다.
    하지만 최신 B 컴퓨터의 프로세서는 1초에 while 반복문을 10,000개 수행한다 가정하자.
    프로그래머가 의도한 대기 시간은 5초였지만, B 컴퓨터는 1초도 안되는 시간만을 기다린 후 다음 코드를 실행할 것이다.

    이에 대한 해결책은 clock()함수와 ctime 헤더파일의 사용이다.

    첫째, 헤더 파일은, 초당 시스템 단위 수를 알려주는 'CLOCKS_PER_SEC' 이란 기호 상수를 정의한다.
    clock() 함수가 리턴하는 시스템 시간을 이 상수로 나누면, 초 단위의 시간을 얻을 수 있다.

    둘째, ctime은 clock()함수가 리턴하는 데이터형의 대용 이름으로 clock_t를 정의한다.
    컴파일러는 그것을 long 형이나 unsigned int형, 또는 사용하는 시스템의 적당한 다른 데이터 형으로 변환한다.

    다음 예시를 보자..

    #include<ctime>
    


    cout << "지연 시간을 초 단위로 입력하십시오 : " << endl;
    float secs{};
    cin >> secs;

    clock_t delay = secs * CLOCKS_PER_SEC; // 사용자가 입력한 지연 시간을 시스템 단위 클록 수로 변환

    cout << "카운트를 시작합니다." << endl;
    clock_t start = clock();

    while (clock() - start < delay);       // 시간이 경과할 때까지 대기

    cout << "종료";


    입력 : 5
    대기 시간 : 5초

    */
    #pragma endregion
    #pragma region 05.do while 루프
    /*
    ---------------------------------------- 05.do while 루프 ----------------------------------------
    do-while 루프는 for 루프나 while 루프와는 다르게 탈출 조건 (exit-condition) 루프이다.
    루프 몸체를 먼저 실행하고, 조건을 나중에 검사한다는 뜻이다.
    쉽게 말하면, [무조건] 1번은 실행한 후, 조건에 따라 추가 실행을 할 것인지 종료할 것인지 정한다.

    do
        반복문

    while(조건문);

    다음 예시를 보자..


    int i{};
    do
    {
        cout << i + 1 << "번째 반복입니다." << endl;
        i++;
    } while (i < 5);

    출력 :
        1번째 반복입니다.
        2번째 반복입니다.
        3번째 반복입니다.
        4번째 반복입니다.
        5번째 반복입니다.

    */
    #pragma endregion
    #pragma region 05.Range 기반의 for 루프
    /*
    ---------------------------------------- 05.Range 기반의 for 루프 ----------------------------------------
    C++11 부터 range 기반의 for 루프라고 불리는 새로운 형태가 추가 되었다. 다음 예시를 보자..

    int nums[]{ 1,2,3,4,5 };
    
    for (int x : nums)
    {
        cout << x << endl;
    }

    출력 :
        1
        2
        3
        4
        5

    예제 for문의 조건절에 'int x : nums' 부분을 보자.
    int x는 손가락이라 생각하자. 손가락이 된 int형 타입 x는 
    차례대로 nums 배열안에 원소들을 하나하나 가르킨다. 


    */
    #pragma endregion
    #pragma region 05.중첩 루프와 2차원 배열
    /*
    ---------------------------------------- 05.중첩 루프와 2차원 배열 ----------------------------------------
    2차원 배열은 행(row)와 열(column)을 가진 표를 생각하면 된다.
    C++는 2차원 배열을 나타내는 데이터형을 따로 제공하진 않지만,
    배열의 배별, 즉 다른 배열을 원소로 사용하는 배열을 만들 수 있다.
    예를 들어, 5개 도시의 지난 4년 동안 연중 최고 온도를 저장하는 2차원 배열을 만들고자 한다면 다음과 같이 선언한다.

        int maxtemps[4][5];

    이 선언 구문은, maxtemps가 4개의 원소를 갖고, 그 각 원소는 5개의 정수를 저장 가능하다는 뜻이다.

    다음 2차원 배열의 초기화 예시를 보자.

        int example[2][2]{ {1,2 }, {3, 4} };
        cout << example[0][0] << endl;
        cout << example[0][1] << endl;
        cout << example[1][0] << endl;
        cout << example[1][1] << endl;

    출력 :
        1
        2
        3
        4

    const int raw{3};
    const int column{3};

    int example[raw][column]
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };



    for (int i{}; i < raw; i++)
    {
        for (int j{}; j < column; j++)
        {
            cout << example[i][j] << endl;
        }
    }

    출력 :
        1
        2
        3
        4
        5
        6
        7
        8
        9



    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_1
    /*
    ---------------------------------------- 05.프로그래밍 연습_1 ----------------------------------------
    문제 : 
    두 개의 정수를 입력 받는 프로그램을 작성하라. 입력한 두 정수를 포함하여, 그 사이에 있는
    모든 정수의 합을 계산하고 출력해야하며, 사용자는 둘 중에 작은 정수를 먼저 입력해야 한다.

    해답 : 
    
        int start{};
        int end{};
        int sum{};

        cin >> start;
        cin >> end;

        while (start <= end)
        {
            sum += start;
            start++;
        }

        cout << sum;

    입력 : 1, 10
    출력 : 55

    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_2
    /*
    ---------------------------------------- 05.프로그래밍 연습_2  ----------------------------------------
    문제 : 
    팩토리얼의 정의는 다음과 같다. '!' 심볼을 쓰며, 예시로, 4! 같은 경우는 4부터 시작하여 1까지 사이의 모든 정수의 곱이다.
    예 : 4! = 4 x 3 x 2 x 1 = 24..
    0!은 팩토리얼의 정의에 의하여 1이다.
    array 객체와 long double 형을 이용하여, 100! 까지의 모든 값을 출력하라.

    해답 :

        #include <array>

        array<long double, 101> factorials;
        factorials[0] = factorials[1] = 1L;
        for (int i = 2; i < 101; i++)
        {
            factorials[i] = i * factorials[i - 1];
        }
        for (int i{}; i < 101; i++)
        {
            cout << i << "! = " << factorials[i] << endl;
        }

    출력 :
    0! = 1
    1! = 1
    2! = 2
    3! = 6...
    100! = 9.33262e+157


    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_3
    /*
    ---------------------------------------- 05.프로그래밍 연습_3 ----------------------------------------
    문제 : 
    수를 입력 받는 프로그램을 작성하라. 수를 입력할 때마다, 프로그램은 입력 값들의 누계를 출력해야 한다.
    사용자가 0을 입력하면 프로그램은 종료된다.

    해답 :
    
        long double input{};
        long double sum{};

        do
        {
            cout << "수를 입력하세요.." << endl;
            cin >> input;
            sum += input;
            cout << "현재까지 입력된 수들의 누계는 : " << sum << "입니다." << endl;
        }
        while (input != 0);
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_4
    /*
    ---------------------------------------- 05.프로그래밍 연습_4 ----------------------------------------
    문제 : 
    고객 A는 단리 10%로 100,000을 투자했다. 따라서, A는 매년 원금의 10%인 10,000을 이자 수익으로 얻는다.
        
        A의 이자 수익 = 0.1 x 원금

    고객 b는 복리 5%로 100,000을 투자했다. 따라서 B는 전년도 원리금의 5%이다.
        
        B의 이자 수익 = 0.05 x 전년도 원리금

    고객 B의 투자 가치가 A의 투자 가치를 초과하는 년 수를 계산하고, 
    그 때, 두 사람의 투자 가치를 함께 출력하는 프로그램을 작성하라.

    해답 :
        long double a{ 100000L };
        long double b{ 100000L };
        int year{};
        float aint{ 0.1f };
        float bint{ 0.05f };

        while (b <= a)
        {
            year++;
            b += b * bint;
            a += aint * 100000;
        }
        cout << "현재 년도 : " << year << endl << "A 잔고 : " << a << endl << "B 잔고 : " << b;

    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_5
    /*
    ---------------------------------------- 05.프로그래밍 연습_5 ----------------------------------------
    문제 : 
    책의 월간 판매량(금액이 아닌 권수)로 입력 받는 프로그램을 작성하라.
    char* 또는 string 객체의 배열을 사용하여 월 이름을 초기화한다.
    루프를 사용하여 월 이름을 나타내는 프롬포트를 표시하고, 월간 판매량을 int형 배열에 저장한다.
    배열 내용의 합계를 계산 후, 그 해의 연간 총 판매량을 출력하라.

    해답 :
        string arr1[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        int arr2[12]{};
        int sum{};

        for (int i{}; i < 12; i++)
        {
            cout << arr1[i] << "의 판매량을 입력하시오." << endl;
            cin >> arr2[i];
            cout << arr1[i] << "'s sales record is : " << arr2[i] <<endl;
            sum += arr2[i];
        }

        cout << "올해의 판매량은 : " << sum << "입니다.";
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_6 (5번 변형)
    /*
    ---------------------------------------- 05.프로그래밍 연습_6 (5번 변형) ----------------------------------------
    문제 :
    책의 월간 판매량(금액이 아닌 권수)로 입력 받는 프로그램을 작성하라.
    char* 또는 string 객체의 배열을 사용하여 월 이름을 초기화한다.
    루프를 사용하여 월 이름을 나타내는 프롬포트를 표시하고, 월간 판매량을 int형 배열에 저장한다.
    배열 내용의 합계를 계산 후, 그 해의 연간 총 판매량을 출력하라.
    -> 이것을 2차원 배열에 저장하고 2년째와 3년째까지의 누적 판매량을 출력해라.

    해답 : 
        string arr1[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        int arr2[3][12]{};
        int sum[3]{};

        for (int i{}; i < 3; i++)
        {
            for (int j{}; j < 12; j++)
            {

                cout << i+1 << "년도의 " << arr1[j] << "의 판매량을 입력하시오." << endl;
                cin >> arr2[i][j];
                cout << i+1 << "년도의 " << arr1[j] << "'s sales record is : " << arr2[i][j] << endl;
                sum[i] += arr2[i][j];
            }
        }

        for (int i{}; i < 3; i++)
        {
            cout << i+1 << "년도의 판매량은 : " << sum[i] << "입니다."<<  endl;
        }

        cout << "총 누적 판매량은 : " << sum[0] + sum[1] + sum[2] << "입니다.";
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_7
    /*
    ---------------------------------------- 05.프로그래밍 연습_7 ----------------------------------------
    문제 :
    제작업체를 나타내는 문자열을 문자 배열에 보관하고, 제작년도를 정수로 보관하는 car라는 구조체를 설계하라.
    관리되는 차량의 수를 입력 받고, 그 대수만큼 new를 사용하여 car구조체의 동적 배열을 만들어라.
    각 구조체에 젖장할 제작업체와 제작년도에 관한 정보를 입력하도록 사용자에게 제시하라.

    해답 :
        struct Car
        {
            string name{};
            int year{};
        };

        int num{};
        cout << "몇 대의 차를 관리하시겠습니까?" << endl;
        cin >> num;
        Car* list = new Car[num];

        for (int i{}; i < num; i++)
        {
            cout << endl <<"#" << i + 1 << "자동차 -" << endl;
            cout << "제작 업체를 입력하세요 : ";
            cin >> list[i].name;
            cout << "제작 년도를 입력하세요 : ";
            cin >> list[i].year;
        }

        cout << "\n\n현재 귀하가 보유한 자동차 목록은 다음과 같습니다 : " << endl;

        for (int i{}; i < num; i++)
        {
            cout << list[i].year << "년형 - " << list[i].name << endl;
        }

        delete[]list;
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_8
    /*
    ---------------------------------------- 05.프로그래밍 연습_8 ----------------------------------------
    문제 : 
    char형의 배열을 사용하여, done 이라는 단어가 입력될 때까지, 한 번에 한 단어를 읽는 프로그램을 작성하라.
    입력된 단어 수를 done을 제외하고 보고해야 한다. ( cstring 헤더파일 포함, strcmp() 함수 사용 )

    입력 :
    Apple Banana Orange done

    출력 : 총 4단어가 입력 되었습니다.

    해답 :
        char word[80]{};
        int count{};

        while (strcmp(word, "done"))
        {
            cin >> word;
            count++;
        }
        cout << "총 " << count - 1 << "단어가 입력되었습니다.";

    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_9 (8번 변형)
    /*
    ---------------------------------------- 05.프로그래밍 연습_9 (8번 변형)----------------------------------------
    문제 :
    string class 객체를 사용하여, done 이라는 단어가 입력될 때까지, 한 번에 한 단어를 읽는 프로그램을 작성하라.
    입력된 단어 수를 done을 제외하고 보고해야 한다. ( string 헤더 파일 포함, 관계 연산자로 비교 )

    해답 :
        string word{};
        int count{};

        while (word != "done")
        {
            cin >> word;
            count++;
        }
        cout << "총 " << count - 1 << "단어가 입력되었습니다.";
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_10
    /*
    ---------------------------------------- 05.프로그래밍 연습_10 ----------------------------------------
    문제 :
    출력할 행 수를 요구하고, 중첩 루프를 사용하여,
    1행엔 별표 1개, 2행엔 별표 2개를
        
    입력 : 5

    출력 :
        *
       **
      ***
     ****
    *****
     
    의 형태로 출력하는 프로그램을 작성하라.

    해답 :
        int count{};
        cin >> count;
        for (int i{1}; i <= count; i++)
        {
            for (int k = count - i; k > 0 ; k--)
            {
                cout << " ";
            }

            for (int j = count - i; j < count; j++)
            {
                cout << "*";

            }
            if (i == count) return;
            cout << endl;
        }
    */
    #pragma endregion




#pragma endregion

#pragma region Chapter 6.분기 구문과 논리 연산자
    
    #pragma region 06.if 구문
    /*
    ---------------------------------------- 06.if 구문 ----------------------------------------
    C++ 프로그램은 하나의 특정한 행동을 할 것인지 말 것인지 선택해야 할 때, if 구문을 사용한다.
    if 구문에는 if와 if else 두 가지가 있다.
    다음 예시를 보자..

        if(조건)
        {
            statement
        }

    조건이 참으로 평가되면 statement를 수행한다. 거짓이라면, 실행하지 않고 건너 뛴다.

    if else는 if문에서 다른 선택지와 statement를 주는 것이다. 다음 예시를 보자.

        if(조건1)
        {
            statement 1
        }
        else if(조건2)
        {
            statement 2
        }
        else
        {
            statement 3
        }

    위 예제에서, 조건 1이 참이라면 statement 1을 실행 시킨 후 if문은 종료된다.
    조건 1이 거짓이고 조건 2가 참이라면, statement 2를 수행한다.
    만일, 조건 1,2 가 모두 거짓이라면, 마지막으로 statement 3을 수행한다.
    */
    #pragma endregion
    #pragma region 06.논리 표현식
    /*
    ---------------------------------------- 06.논리 표현식 ----------------------------------------
    1 == 1, 2 == 2, 3 > 2,,, 처럼 한 개의 조건을 검사하는 경우도 있지만,
    하나 이상의 조건을 검사해야 하는 경우가 있다.
    마트에서 요구르트를 사려면,
    
        1. 요구르트가 있어야 한다.
        2. 요구르트를 살 돈이 있어야 한다.
    
    두 조건을 모두 충족해야 한다.

    C++에서는 주어진 표현식을 조합하거나 변경할 수 있는 세 가지 연산자인
    논리합( || ), 논리곱( && ), 논리부정( ! ) 을 제공한다.

    논리합 OR 연산자 ( || )
        논리합 연산자는 OR 연산자라고도 불린다. 한 쪽 조건이라도 만족 될 경우, 참으로 처리한다.
        다음 예시를 보자

        5 == 5 || 4 == 4    ( 좌, 우측이 모두 true이기 때문에, 이 연산은 true다 )
        5 == 5 || 5 == 4    ( 좌측이 true이기 때문에, 이 연산은 true 다 )
        4 == 3 || 3 == 2    ( 모두 false이기 때문에, 이 연산은 false 다 )

    논리곱 AND 연산자 ( && )
        논리곱 연산자는 AND 연산자라고도 불린다. 모든 조건이 만족 될 경우, 참으로 처리한다.
        다음 예시를 보자.

        5 == 5 && 4 == 4    ( 좌, 우측이 모두 true이기 때문에, 이 연산은 true다 )
        5 == 5 && 5 == 4    ( 좌측만 true이기 때문에, 이 연산은 false 다 )
        4 == 3 && 3 == 2    ( 모두 false이기 때문에, 이 연산은 false 다 )

    논리부정 NOT 연산자 ( ! )
        논리부정 연산자는 표현식의 값을 반대로 만든다. 즉, true를 false로, false를 true로 변경한다.
        다음 예시를 보자

        5 == 5                  ( true 다 )
        !(5 == 5)               ( false다 )
        !(3 == 2 || 4 == 2)     ( true 다 )
    */
    #pragma endregion
    #pragma region 06.cctype 라이브러리
    /*
    ---------------------------------------- 06.cctype 라이브러리 ----------------------------------------
    C++는 is~~(ch) 함수를 통해 입력된 문자가 영문자인지, 화이트스페이스인지, 숫자인지, 구두점인지를 검사한다.
    또한, 소문자를 대문자로, 대문자를 소문자로 바꾸는 유용한 함수 또한 존재한다.
    다음 예시를 보자.

        #include <cctype>

        char ch{};
        isalpha(ch);        // 영문자인가?
        isspace(ch);        // 화이트스페이스인가?
        isdigit(ch);        // 숫자인가?
        ispunct(ch);        // 구두점인가?
        islower(ch);        // 소문자인가?
        isupper(ch);        // 대문자인가?
        tolower(ch);        // 대문자를 소문자로 리턴, 아니라면 그대로
        toupper(ch);        // 소문자를 대문자로 리턴, 아니라면 그대로
        isalnum(ch);        // 알파벳이거나 숫자인가?
        isblank(ch);        // 빈칸 또는 수평 탭인가?
        iscntrl(ch);        // 제어 문자인가?
        isgraph(ch);        // 인쇄 가능한가? ( 빈칸이 아닌가? )
        isxdigit(ch);       // 16진 숫자 (0~9, a~f 또는 A~F)인가?

    */
    #pragma endregion
    #pragma region 06.삼항 연산자
    /*
    ---------------------------------------- 06.삼항 연산자 ----------------------------------------
    C++는 if else 대신, 사용할 수 있는 ' ? : '연산자를 제공한다. 사용법은 다음과 같다.

        조건? 참 : 거짓

    얼핏 봐선 이해가 힘들 것이다. 다음 예시를 보자.

        (1==1)? cout<<"true" : cout << "false";

    먼저 ? 앞에 있는 (1==1)이 참인지 거짓인지 확인한다. 1==1은 참이므로, : 기준 좌측의 cout<<"true"를 실행한다.
        
        (1==2)? cout<<"true" : cout << "false";

    의 경우에는 cout << "false" 를 수행한다.
    */
    #pragma endregion
    #pragma region 06.switch 구문
    /*
    ---------------------------------------- 06.switch 구문 ----------------------------------------
    예를 들어, cheap, moderate, expensive, extravagant, excessive 라는 
    다섯 가지 선택 사항 중 하나를 선택해야 한다고 가정하자.
    이 경우, 선택 사항마다 if else 문을 사용하여 구조를 길게 확장할 수 있다.
    하지만 C++의 switch 구문을 사용하면, 이를 좀 더 쉽게 구현할 수 있다.
    다음 예시를 보자.

        switch (integer-expression)
        {
            case label1 : statement
                break;
            case label2 : statement
                break;
                ...
            default : statement

    이를 활용한 예시를 보자.

        int choice{};
        cin >> choice;
    
        switch (choice)
        {
            case 1: 
                cout << "11111111111111";
                break;
            case 2: 
                cout << "22222222222222";
                break;
            case 3: 
                cout << "33333333333333";
                break;
            case 4: 
                cout << "44444444444444";
                break;
            default: 
                cout << "aaaaaaaaaaaa";
                break;
        }
                
        

    */
    #pragma endregion
    #pragma region 06.enum을 활용한 switch문
    /*
    ---------------------------------------- 06.enum을 활용한 switch문 ----------------------------------------
    우리는 chapter 4에서 열거체의 유용성을 보았다. 열거체는 switch문에서 빛을 발한다.
    다음 예시를 보자..

    enum Days{MON, TUE, WED, THU, FRI, SAT, SUN}
    
    int code{};
    cin >> code;

        switch ((Days)code)
        {
        case MON:
            cout << "월요일";
            break;
        case TUE:
            cout << "화요일";
            break;
        case WED:
            cout << "수요일";
            break;
        case THU:
            cout << "목요일";
            break;
        case FRI:
            cout << "금요일";
            break;
        case SAT:
            cout << "토요일";
            break;
        case SUN:
            cout << "일요일";
            break;
        default:
            cout << "what the hell";
            break;
        }

    */
    #pragma endregion
    #pragma region 06.break와 continue 구문
    /*
    ---------------------------------------- 06.break와 continue 구문 ----------------------------------------
    break와 continue 구문은, 프로그램이 코드의 일부를 무시하고 건너뛰게 만든다.
    break는, switch 구문과, 모든 종류에 루프에 사용할 수 있다.
    break는, switch나 루프의 바로 뒤에 오는 구문을 실행하게 만든다.

    continue 구문은 루프에만 사용 가능하며, 루프 몸체의 나머지를 무시하고 새로운 루프 주기를 시작한다.

    다음 예시를 보자.

        int i{};

        while (true)                            // 무한 반복문
        {
            if (i == 3) break;                  // i가 3이 되면 반복문을 종료한다

            cout << "Hello" << endl;
            i++;
            continue;                           // 밑의 구문은 실행하지 않고 루프를 반복한다.
            cout << "Hello again" << endl;


        }

    출력 :
        Hello
        Hello
        Hello

    

    */
    #pragma endregion
    #pragma region 06.수를 읽어들이는 루프
    /*
    ---------------------------------------- 06.수를 읽어들이는 루프 ----------------------------------------
    
        int n{};
        cin >> n; 
        입력 : aaaaaaaaaaaaaaaaaa

    숫자를 입력받는 프로그램이, 사용자에 의해 단어가 입력된다면 무슨 일이 벌어질까?
    단순히 에러를 발생하는 것이 아닌, 네 가지 일이 벌어진다.

        * n의 값은 변하지 않는다.
        * 입력 큐에 잘못된 입력이 유지된다.
        * cin 객체의 에러 플래그가 설정된다.
        * cin 메서드 호출이 false( bool형으로 변환된다면 )를 리턴한다.
    
    cin 메서드가 false를 리턴하는 사실은, 수를 입력받는 루프를 종료시키기 위해 수가 아닌
    입력을 사용할 수 있다는 것을 의미한다. 또한, 에러 플래그를 설정한다는 사실은,
    프로그램이 다시 입력을 받기전에 그 에러플래그를 초기화해야 함을 의미한다.
    파일의 끝(EOF) 조건을 초기화하는 clear() method는 불량 입력 플래그도 초기한다.
    다음 예시를 보자..

        double golf[5]{};
        
        for(int i{}; i < 5; i++)
        {
            whille( !(cin>>golf[i]) )           // 이 구문으로 cin >> golf[i] 도 수행한다.
            {
                cin.clear;                      // cin >> golf[i]가 실패할 경우..(range문제, 데이터 타입 문제 등..) 입력 초기화
            }
            while(cin.get != '\n') continue;    // 불량입력을 제거한다
            cout << "골프 점수를 입력하세요";
        }

    */
    #pragma endregion
    #pragma region 06.간단한 파일 입/출력
    /*
    ---------------------------------------- 06.간단한 파일 입/출력 ----------------------------------------
    때로 키보드 입력은 최선의 선택이 아니다. 주식을 예로 들어보자.
    1,000 종목의 주식 시세가 들어 있는 파일을 다운 했다면,
    수작업으로 값을 입력하는 것보단, 프로그램이 파일을 직접 읽게 만드는 것이 편리할 것이다.
    C++에서는 I/O ( Input / Output )의 적용이 간단하다.
    이 주제는 17장에서 폭넓게 탐구한다. 여기선, 간단한 텍스트 파일 I/O만 살펴보자.

    * 텍스트 파일에 쓰기
        파일 출력은 다음과 같은 방식으로 처리된다.
        * fstream 헤더 파일을 포함해야 한다.
        * fstream 헤더 파일은 출력을 처리하는 ofstream 클래스를 정의한다.
        * 하나 이상의 ofstream 변수 또는 객체를 선언해야 한다.
        * ofstream 객체와 특정 파일의 연결이 필요하다. 한 가지 방법은, open() method의 사용이다.
        * 파일을 다루는 작업이 끝나면, close() method로 파일을 닫아준다.
    
        객체의 선언법과 파일 연결 방법은 다음과 같다.

        ofstream outFile;   // outFile은 ofstream 객체
        ofstream fout;      // fout은 ofstream 객체

        객체를 특정 파일에 연결하는 방법은 다음과 같다.

        outFile.open("fish.txt");   // fish.txt에 쓰는 데, outFile 사용
        char fileName[50];
        cin >> fileName;            // 사용자가 이름을 지정한다
        fout.open(fileName);        // 지정된 파일을 읽는데 fout 사용

        요약하자면, 파일 출력을 사용하는 기본 절차는 다음과 같다.
        1. fstream 헤더 파일의 포함
        2. ofstream 객체의 생성
        3. ofstream 객체와 파일의 연결
        4. ofstream 객체를 cout과 동일한 방식으로 사용

        다음 예시를 보자.

        #include <fstream>      // 파일 I/O 를 위해

        char automobile[50]{};
        int year{};
        double a_price{};
        double d_price{};

        ofstream outFile;
        outFile.open("carinfo.txt");

        cout << "자동차 메이커와 차종을 입력하시오." << endl;
        cin.getline(automobile, 50);
        cout << "연식을 입력하시오." << endl;
        cin >> year;
        cout << "구입 가격을 입력하시오." << endl;
        cin >> a_price;
        d_price = 0.913 * a_price;

        // cout으로 스크린에 정보 디스플레이

        cout << fixed;                      // 소수점 자리수 고정
        cout.precision(2);                  // 소수점 2째 자리까지
        cout.setf(ios_base::showpoint);     // 소수점 출력할 것
        cout << "메이커와 차종 : " << automobile << endl;
        cout << "연식 : " << year << endl;
        cout << "구입 가격 $" << a_price << endl;
        cout << "현재 가격 $" << d_price << endl;

        // cout 대신 outFile 사용하여 똑같은 일 처리
        outFile << fixed;
        outFile.precision(2);
        outFile.setf(ios_base::showpoint);
        outFile << "메이커와 차종 : " << automobile << endl;
        outFile << "연식 : " << year << endl;
        outFile << "구입 가격 $" << a_price << endl;
        outFile << "현재 가격 $" << d_price << endl;

        outFile.close();        //파일 처리 종료

        
        실행 프로그램이 들어 있는 디렉터리나 폴더에서 
        carinfo.txt 라는 새로운 파일을 찾을 수 있다. ( 컴파일러 환경에 따라 다를 수 있다. )
        파일에는 outFile 사용에 의해 만들어진 출력이 들어 있다.
        텍스트 에디터를 사용하여 파일을 열었을 때, 다음과 같은 내용이 있어야 한다.

            메이커와 차종 : ~~~
            연식 : ~~~
            구입 가격 : ~~~
            현재 가격 : ~~~


    * 텍스트 파일 읽기
        파일 입력은 다음과 같은 방식으로 처리된다.
        * fstream 헤더 파일을 포함
        * fstream 헤더 파일은, 입력을 처리하는 ifstream 클래스를 정의
        * 하나 이상의 ifstream 변수 또는 객체의 선언
        * ifstream과 특정 파일의 연결, open() method 사용
        * 파일을 다루는 작업이 끝나면, close() method 사용
        * ifstream 객체를 >>, get(), getline() 과 같은 연산자와 메서드를 함께 사용 가능.
        * ifstream 객체를 eof() 와 fail() 과 같은 method를 사용하여 입력 시도의 성공여부 확인 가능
        
        객체의 선언법은 다음과 같다.

        ifstream inFile;        // inFile은 ifstream 객체
        ifstream fin;           // fin은 ifstream 객체

        객체와 파일의 연결법은 다음과 같다.

        inFile.open("bowling.txt");
        char fileName[50];
        cin >> fileName;
        fin.open(fileName);

        객체들의 사용법은 다음과 같다.

        double wt{};
        inFile >> wt;               // bowling.txt에서 하나의 수를 읽는다.
        char line[81];
        fin.getline(line, 81);      // 한 행의 텍스트를 읽는다.

        
        입력을 위해 존재하지 않는 파일을 열려고 시도하면 무슨 일이 일어날까?
        에러는, ifstream 객체를 사용하려는 이어지는 시도들을 실패하게 만든다.
        파일의 개폐 여부를 아는 방법은, is_open() 메서드의 사용이다.
        다음 예시를 보자.

        inFile.open("bowling.txt");
        if( !inFile.is_open() )
        {
            exit(EXIT_FAILURE);
        }

        
        is_open() 메서드는, 파일이 열렸다면 true를 리턴한다.
        exit() 함수는 cstdlib 헤더 파일에 원형이 있다. 이 헤더파일은,
        운영 체제와 커뮤니케이션하는데 사용하는 매개변수 값으로 EXIT_FAILURE 를 정의한다.
        exit() 함수는 프로그램을 종료한다.

        다음 예시를 보자..

        #include <fstream>  // 파일 I/O 를 위해
        #include <cstdlib>  // exit() 지원

        char fileName[60];
        ifstream inFile;            // 파일 입력 처리 위한 객체
        cout << "데이터 파일의 이름을 입력하시오." << endl;
        cin.getline(fileName, 60);
        inFile.open(fileName);      // inFile을 파일에 연결

        if ( !inFile.is_open() )    // 파일을 여는데 실패하면
        {
            exit(EXIT_FAILURE);     // 프로그램을 종료한다.
        }

        double value;
        double sum{};
        int count{};                // 읽은 항목의 개수

        inFile >> value;            // 첫 번째 값을 얻는다
        while (inFile.good())       // 입력이 양호하고 EOF가 아닌 동안 ( EOF = 읽을 데이터가 없는 상태 )
        {
            count++;
            sum += value;
            inFile >> value;        // 다음 값을 얻는다.
        }

        if (inFile.eof())
        {
            cout << "파일 끝에 도달!";
        }
        else if (inFile.fail())
        {
            cout << "데이터 불일치로 입력 종료!";
        }
        else
        {
            cout << "알 수 없는 에러";
        }

        if (count == 0)
        {
            cout << "데이터 없음";
        }
        else
        {
            cout << "읽은 항목 개수 : " << count << endl;
            cout << "합계 : " << sum << endl;
            cout << "평균 : " << sum / count << endl;
        }

        inFile.close();
        ---------------------------------------
        scores.txt 파일을 생성하고 내용이 다음과 같다고 하자
        18 19 18.5 13.5 14
        16 19.5 20 18 12 18.5
        17.5

        출력 :
        데이터 파일의 이름을 입력하시오 : scores.txt
        파일 끝에 도달했습니다.
        읽은 항목의 개수 : 12
        합계 : 204.5
        평균 : 17.0417

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_1
    /*
    ---------------------------------------- 06.프로그래밍 연습_1 ----------------------------------------
    문제 :
    @ 기호가 나타날 때까지 키보드 입력을 읽어들여 대문자는 소문자로, 소문자는 대문자로 에코하는 프로그램을 작성하라.
    숫자들은 에코에서 제외하여야 한다. ( cctype 라이브러리를 사용하라. )

    해답 :
        char ch{};

        while (true)
        {
            cout << "Your input : ";

            cin >> ch;
            
            if (ch == '@') return;

            if (isalpha(ch))
            {
                if (isupper(ch))
                {
                   ch = tolower(ch);
                }
                else if(islower(ch))
                {
                   ch = toupper(ch);
                }
            }

            cout << "Your output : " << ch << endl;
        }

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_2
    /*
    ---------------------------------------- 06.프로그래밍 연습_2 ----------------------------------------
    문제 :
    double 형의 배열에 기부금을 10개까지 읽어들이는 프로그램을 작성하라.
    10개가 입력되기 전이라도, 수가 아닌 것이 입력되면 프로그램이 종료되어야한다.
    프로그램은 기부금들의 평균과, 평균보다 큰 기부금이 배열에 몇 개 들어 있는지 보고해야 한다.

    해답 :
        double donation[10]{};
        double amount{};
        double average{};
        int bigger{};

        for (int i{}; i < 10; i++)
        {
            cout << "기부금을 입력하세요 : ";
            while (!(cin >> donation[i])) return;

            amount += donation[i];
            
        }
        average = amount / 10;

        cout << "기부금 평균 : " << amount / 10 << endl;
        
        for (int i{}; i < 10; i++)
        {
            if (donation[i] > average)
            {
                bigger++;
            }

        }

        cout << "평균 이상 기부자 :" << bigger << "명";

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_3
    /*
    ---------------------------------------- 06.프로그래밍 연습_3 ----------------------------------------
    문제 :
    다음과 같은 샘플 프로그램을 작성하라.  ( 대소문자 구별 )

        다음 선택 사항 중에서 하나를 선택하십시오. ( 끝내려면 q )
        a ) apple       b ) banana
        c ) carrot      d ) durian
        
        입력 : f
        a, b, c, d 중에서 하나를 선택하십시오. ( 끝내려면 q ) : e
        a, b, c, d 중에서 하나를 선택하십시오. ( 끝내려면 q ) : a
        사과는 맛있습니다.

    해답 :
        char ch[80]{};


        cout << "다음 선택 사항 중에서 하나를 선택하십시오. ( 끝내려면 q )\n";
        cout << "a ) apple          b ) banana\nc ) carrot         d ) durian" << endl;

        do
        {
            cin >> ch;

            if (ch[1] != NULL)          // Null 은 아무것도 없는 상태, 빈 공간을 의미한다.
            {
                ch[0] = NULL;
            }
            
            if (ch[0] == 113) return;

            if (ch[0] < 97 || ch[0] > 100)
            {
                cout << "a, b, c, d 중에서 하나를 선택하십시오. ( 끝내려면 q ) : " << endl;
            }
        }
        while (!(ch[0] >=97 && ch[0] <=100));

        switch (ch[0])
        {
        case 97:
            cout << "사과는 맛있어";
            break;
        case 98:
            cout << "맛있으면 바나나";
            break;
        case 99:
            cout << "당근은 싫어";
            break;
        case 100:
            cout << "우웱";
            break;
        default:
            cout << "Unknown Error";
            break;
        }

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_4
    /*
    ---------------------------------------- 06.프로그래밍 연습_4 ----------------------------------------
    문제 :
    Cpp 라는 회원제  인터넷 사이트에서는 실명, 직함, Cpp 아이디로 자신을 나타낼 수 있다.
    회원 명부를 실명, 직함, Cpp 아이디로, 또는 가입 회원이 지정한 방식에 따라 열람하는
    프로그램을  다음 구조체에 기초하여 작성하라.

    해답 :
        struct cpp
        {
            char fullname[20];       // 실명
            char title[20];          // 직함
            char cppname[20];        // Cpp 아이디
            int preference{};        // 0 = 실명, 1 = 직함, 2 = 아이디
        };
    
        cpp list[3] = 
        {
            { "James", "Junior", "Joat", 0 },
            { "John", "Senior", "KingMaker", 1 },
            { "Peter", "CEO", "The King", 2 }
        };

        char ch[80];

        cout << "Cpp 회원 정보 열람\n";
        cout << "a ) By name          b ) By Title\nc ) By ID            d ) By preference" << endl << "(종료하려면 q)"<< endl;

        do
        {
            
            cin >> ch;
            
            if (ch[1] != NULL)          // Null 은 아무것도 없는 상태, 빈 공간을 의미한다.
            {
                ch[0] = NULL;
            }

            if (ch[0] == 113)
            {
                return;
            }

            switch (ch[0])
            {
            case 97:
                for (int i{}; i < 3; i++)
                {
                    cout << list[i].fullname << endl;
                }
                break;
            case 98:
                for (int i{}; i < 3; i++)
                {
                    cout << list[i].title << endl;
                }
                break;
            case 99:
                for (int i{}; i < 3; i++)
                {
                    cout << list[i].cppname << endl;
                }
                break;
            case 100:
                for (int i{}; i < 3; i++)
                {
                    switch (list[i].preference)
                    {
                    case 0:
                        cout << list[i].fullname << endl;
                        break;
                    case 1:
                        cout << list[i].title << endl;
                        break;
                    case 2:
                        cout << list[i].cppname << endl;
                        break;
                    default:
                        cout << "Unknown Error" << endl;
                        break;
                    }
                }
                break;
            default:
                cout << "Unknown Error" << endl;
                break;
            }

            cout << "원하는 것을 입력하세요 : " << endl;
        } while (true);

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_5
    /*
    ---------------------------------------- 06.프로그래밍 연습_5 ----------------------------------------
    문제 :
    Cpp 왕국은 화폐단위로 Ppc를 사용한다. Cpp 왕국의 소득세는 다음과 같다.
        
        5,000 Pcc 까지는           - 0%
        그 다음 10,000 Pcc 까지는  - 10%
        그 다음 20,000 Pcc 까지는  - 15%
        35,000 Pcc 이상 부터는     - 20%

    38,000 Pcc의 소득이 있는 사람은, ( 5000 x 0 ) + ( 10,000 * 0.10 ) + ( 20,000 * 0.15 ) + ( 3,000 * 0.20 ) = 4,600 Pcc 의 세금을 내야한다.
    소득을 입력하면 소득세를 산출하는 프로그램을 작성하라. 사용자가 음수를 입력하거나 수가 아닌 것을 입력하면 종료해야 한다.
    ( 최소 화폐와 세금 단위는 1이다 )

    해답 :
        int income{};
        int tax{};

        while ( cin >> income && income >= 0 )
        {
            if (income <= 5000)
            {
                tax = 0;
            }
            else if (income > 5000 && income <= 15000)
            {
                tax = (income - 5000) * 0.10;
            }
            else if (income > 15000 && income <= 35000)
            {
                tax = (income - 15000) * 0.15 + 1000;
            }
            else if (income > 35000)
            {
                tax = (income - 35000) * 0.20 + 4000;
            }

            cout << "소득세 : " << tax << endl;
        }

        
    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_6
    /*
    ---------------------------------------- 06.프로그래밍 연습_6 ----------------------------------------
    문제 : 
    Cpp에 대한 기부금을 추적하는 프로그램을 작성하라.
    프로그램은 사용자에게 기부할 사람이 몇 사람인지 묻는다. 그리고, 기부자의 이름과 기부금을 입력 받는다.
    정보는 동적으로 대입된 구조체 배열에 저장되며, 구조체는 이름과 기부금을 저장하는 char형 배열(또는 string 객체)와 double형 멤버이다.
    저장을 마친 후, 프로그램은 $10,000 또는 그 이상을 기부한 사람들에 대해서 기부자의 이름과 기부금을 나란히 표시하되,
    목록의 위에 '고액 기부자' 라는 제목을 붙인다.
    나머지 기부자들의 목록을 표시하되, 목록의 위에는 '소액 기부자' 라는 제목을 붙인다. 
    기부자가 없다면 "기부자가 없습니다" 를 출력한다.

    해답 :
        struct Donation
        {
            string name{};
            double money{};
        };

        cout << "총 기부 인원 수를 입력하세요 : " << endl;
        int size{};
        double sum{};
        cin >> size;

        Donation* members = new Donation[size];

        for (int i{}; i < size; i++)
        {
            cout << "이름을 입력하세요 : " << endl;
            cin >> members[i].name;
            cout << "기부금을 입력하세요 : " << endl;
            if (!(cin >> members[i].money && members[i].money >= 0))
            {
                cout << "올바른 값을 입력하세요";
                return;
            }
        }

        for (int i{}; i < size; i++)
        {
            sum += members[i].money;
        }

        if (sum == 0)
        {
            cout << "기부자가 없습니다.";
            return;
        }

        cout << "-----  고액 기부자    -----" << endl;

        for (int i{}; i < size; i++)
        {

            if (members[i].money >= 10000)
            {
                cout << "이름 : " << members[i].name << " 기부금 : " << members[i].money << endl;
            }
        }

        cout << "-----  소액 기부자    -----" << endl;

        for (int i{}; i < size; i++)
        {

            if (members[i].money < 10000)
            {
                cout << "이름 : " << members[i].name << " 기부금 : " << members[i].money << endl;
            }
        }

        delete []members;

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_7
    /*
    ---------------------------------------- 06.프로그래밍 연습_7 ----------------------------------------
    문제 :
    외따로 떨어진 q가 입력될 때까지, 한 번에 한 단어씩 입력을 읽는 프로그램을 작성하라.
    프로그램은 모음으로 시작하는 단어 수, 자음으로 시작하는 단어, 어느 범주에도 속하지 않는 단어 수를 보고해야 한다.
    프로그램 실행 예는 다음과 같다.

        단어를 입력하시오 ( 끝내려면 q ) :
        The 12 awesome oxen ambled
        quietly across 15 meters of lawn. q
        모음으로 시작하는 단어의 수 : 5
        자음으로 시작하는 단어의 수 : 4
        기타 : 2

    해답 :
        int consonant{};
        int vowel{};
        int other{};

        string str{};
        do
        {
            cin >> str;

            if (isalpha(str[0]))
            {
                switch (str[0])
                {
                case 'a':
                case 'A':
                    vowel++;
                    break;
                case 'e':
                case 'E':
                    vowel++;
                    break;
                case 'i':
                case 'I':
                    vowel++;
                    break;
                case 'o':
                case 'O':
                    vowel++;
                    break;
                case 'u':
                case 'U':
                    vowel++;
                    break;
                default:
                    consonant++;
                    break;
                }
            }
            else
            {
                other++;
            }


        } while (str != "q");

        cout << "모음으로 시작하는 단어 수 : " << vowel << endl;
        cout << "자음으로 시작하는 단어 수 : " << consonant << endl;
        cout << "기타 : " << other;


    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_8
    /*
    ---------------------------------------- 06.프로그래밍 연습_8 ----------------------------------------
    문제 :
    텍스트 파일을 열고, 파일의 끝까지 문자 단위로 읽고, 파일에 들어 있는
    문자들의 수를 보고하는 프로그램을 작성하라.

    해답 :
        #include<fstream>
        #include<cstdlib>

        const int SIZE = 20;

        char filename[SIZE];
        ifstream inFile;
        
        cout << "읽을 파일명 입력 : ";
        cin.getline(filename, SIZE);
        
        inFile.open(filename);
        
        if (!inFile.is_open())
        {
        	cout << "파일 열기 실패" << endl;
        	exit(EXIT_FAILURE);
        }
        
        char ch;
        int count = 0;
        inFile >> ch;
        
        while (inFile.good())
        {
        	++count;
        	inFile >> ch;
        }
        
        if (inFile.eof())
        {
            cout << "파일 끝에 도달\n";
        }
        
        if (count == 0)
        {
        	cout << "데이터가 없습니다.\n";
        }
        else
        {
            cout << "문자 수 : " << count << endl;
        }
        
        inFile.close();
        

    */
    #pragma endregion
    #pragma region 06.프로그래밍 연습_9
    /*
    ---------------------------------------- 06.프로그래밍 연습_9 ----------------------------------------
    문제 :
    파일로부터 정보를 얻는 프로그램을 만들어라.
    파일에 들어 있는 첫 항목은 기부자 수가 되어야 한다.
    파일의 나머지는 두 행씩 짝을 이루어, 순서대로 이름, 기부액을 출력해야한다.
    파일의 예시는 다음과 같다.

        2
        Sam
        2000
        Tom
        1000

    해답 :
        #include<fstream>
        #include<cstdlib>
        
        const int SIZE = 20;
        
        struct donation_info 
        {
            char name[20];
            double donation;
        };

        char filename[SIZE];

        ifstream inFile;
        cout << "읽을 파일명 입력 : ";
        cin.getline(filename, SIZE);

        inFile.open(filename);

        if (!inFile.is_open())
        {
            cout << "파일 열기 실패" << endl;
            exit(EXIT_FAILURE);
        }

        int n {};

        (inFile >> n).get();

        donation_info* SPRI = new donation_info[n];
        
        for (int i = 0; i < n; i++)
        {
            inFile.getline((SPRI + i)->name, SIZE);
            (inFile >> (SPRI + i)->donation).get();
        }


        for (int i = 0; i < n; i++)
        {
            if ((SPRI + i)->donation >= 10000)
            {
                cout << (SPRI + i)->name << "	$" << (SPRI + i)->donation << endl;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if ((SPRI + i)->donation < 10000)
            {
                cout << (SPRI + i)->name << "	$" << (SPRI + i)->donation << endl;
            }
        }

        inFile.close();
        

    */
    #pragma endregion

#pragma endregion

#pragma region Chapter 7.함수 - C++의 프로그래밍 모듈
    #pragma region 07.함수의 기본
    /*
    ---------------------------------------- 07.함수의 기본 ----------------------------------------
    함수에 관해서 알고 있는 내용을 복습해 보자. C++에서 함수를 사용하려면 다음과 같은 작업을 해야한다.

        * 함수 정의 제공
        * 함수 원형 제공
        * 함수 호출
    
    이 중, 함수 원형 제공은 프로그램의 실행을 위한 필요 충분 조건은 아니다. 하지만 함수의 원형을 함수의 정의보다
    먼저 제공하는 것은, 프로그래머로 하여금 코드의 가독성과, 특정 함수가 어떤 동작을 할 것인지 미리 예측할 수 있는
    프로토타입 ( ProtoType ) 을 제공한다. 다음 간단한 예제를 보자.

        void simple();      // 원형

        int main()
        {
            simple();       // 함수의 호출
            return 0;
        }

        // 함수 정의
        void simple()
        {
            cout << "봐라 Mr.Simple, Simple";
        }
        
    */
    #pragma endregion
    #pragma region 07.함수 정의
    /*
    ---------------------------------------- 07.함수 정의 ----------------------------------------
    함수는 두 그룹으로 나눌 수 있다. 리턴 값이 있는 함수와 없는 함수다. 다음 예시를 보자.

    void functionWithNoReturn()
    {
        cout << "Hi";
        return;             // 생략 가능하다.
    }

    int fuctionWithReturn(int a, int b)
    {
        if(a>b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    functionWithNoReturn() 함수는, return값이 없는 함수이다. 
    배달 요리 주방장이 음식은 만들었으나, 음식을 배달하지는 않는 것이다.

    fuctionWithReturn() 함수는, 두 정수 a / b 를 입력 받는 return 함수이다.
    두 정수의 크기를 비교한 후, 더 큰 값을 return 해주는 함수이다.
    배달 요리 주방장이 a / b 중, 더 양이 많은 음식을 주문 받았을 때, a / b 를 비교 후, 양이 더 많은 음식을 배달해 주는 것이다.


    */
    #pragma endregion
    #pragma region 07.함수 원형과 함수 호출
    /*
    ---------------------------------------- 07.함수 원형과 함수 호출 ----------------------------------------
    다음 예시를 보자.

        int bigger(int a, int b);       // 함수 원형

        int main()                      // main 함수
        {
            int a{7};
            int b{8};
            int c = bigger(a, b);// 함수 호출
            cout << c;
            return 0;
        }


        int bigger(int a, int b)        // 함수 정의
        {
            if(a>b)
            {
                return a;
            }
            else
            {
                return b;
            }
        }

    위 예제는, 정수 a와 b를 선언 후, bigger(int a, int b) method를 통해, a와 b 중 더 큰 값을
    새로운 정수 c에 저장한다. a는 7, b는 8이므로, 둘 중에 값이 더 큰 b가 새로운 정수 c에 저장된다.

    그렇다면 함수 원형은 왜 필요한가? 함수 원형은 컴파일러에게 함수의 인터페이스를 알려준다.
    즉, 리턴값이 있으면, 그 리턴값의 데이터형을 컴파일러에게 알려준다. 
    함수 원형을 제공하는 것이 불필요한 줄을 추가한다고 생각할 수 있다. 
    물론, 컴파일러가 파일의 내부를 조사하여 함수의 정의를 직접 확인할 수도 있다.
    하지만, 이러한 접근 방식은 매우 **비효율적이다.** 
    컴파일러가 함수를 찾기 위해 파일의 내부를 뒤지는 동안 main() 함수의 컴파일을 보류해야 한다.
    더욱 심각한 문제는, 함수가 파일 안에 들어 있지 않을 수도 있다는 것이다.
    함수 원형의 사용을 피할 수 있는 유일한 방법은, 함수를 처음 사용하는 곳의 바로 위에다 함수를 정의하는 것이다.
    */
    #pragma endregion
    #pragma region 07.배열의 범위를 사용하는 함수
    /*
    ---------------------------------------- 07.배열의 범위를 사용하는 함수 ----------------------------------------
    배열을 처리하는 C++ 함수는, 배열에 들어 있는 데이터의 종류, 시작 위치, 원소 개수에 관한 정보를 넘겨받아야 한다.
    배열을 처리하는 함수에 접근하는 방법은, 첫 번째 매개변수로 배열의 시작 위치를 지시하는 포인터를 전달하고,
    두 번째 매개변수로 배열의 크기를 전달하는 것이다. 그렇게 하면 배열의 모든 데이터를 인식하는데
    필요한 정보가 함수에 전달된다. 다른 방법은, 원소들의 범위를 지정하는 것이다.
    이것은 두개의 포인터 즉, 배열의 시작을 지시하는 포인터와 배열의 끝을 지시하는 포인터의 사용이다.

    16장에서 설명할 C++ 표준 템플릿 라이브러리 ( C++ Standard Template Library ) 에서는, 이러한 범위 접근법을 일반화한다.
    STL 접근 방법은 원소들의 범위를 지정하기 위해, "끝 바로 다음" 이라는 개념을 사용한다.
    즉, 어떤 배열이 있다고 했을 때, 배열의 끝을 인식하기 위한 매개변수는, 배열의 마지막 원소 바로 다음을 지시하는 포인터이다.
    다음과 같은 선언이 있다고 가정해 보자.

        double elbuod[20];

    그러면, 두 개의 포인터 'elbuod'와 'elbuod + 20'이 배열의 범위를 지정한다.
    먼저 'elbuod'는 첫번째 원소를, 'elbuod + 19'는 마지막 원소를 'elbuod + 20'은 마지막 바로 다음 원소를 지시한다.
    범위를 전달하는 것은, 어떤 원소들을 처리해야 하는지를 함수에게 알려준다.
    다음 예시를 보자.

        int sum_arr(const int* begin, const int* end);

        const int ArSize{ 8 };

        int main()
        {
            int cookies[ArSize]{ 1, 2, 4, 8, 16, 32, 64, 128 };

            int sum = sum_arr(cookies, cookies + ArSize);
            cout << "먹은 과자 수 합계 : " << sum << endl;

            sum = sum_arr(cookies, cookies + 3);
            cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다." << endl;

            sum = sum_arr(cookies + 4, cookies + 8);
            cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다." << endl;

            return 0;
        }


        int sum_arr(const int* begin, const int* end)
        {
            const int* pt;
            int total{};

            for (pt = begin; pt != end; pt++)
            {
                total += *pt;
            }
            return total;
        }
    */
    #pragma endregion
    #pragma region 07.const의 사용
    /*
    ---------------------------------------- 07.const의 사용 ----------------------------------------
    만일 함수의 목적이 데이터를 변경하는 것이 아니라면, 데이터가 변경되지 않도록 보호해야 한다.
    일반 변수의 경우, C++가 그것을 함수에 값으로 전달하고 함수는 복사본을 가지고 작업하기 때문에,
    이 문제는 자동으로 해결된다. 하지만 배열은 원본을 대상으로 작업하기 때문에, 배열의 값이
    변경되지 않도록 하려면, const 키워드를 형식 매개변수를 선언할 때 사용할 수 있다.

        void show_array(const double ar[], int n);

    이 선언은, 포인터 ar이 상수 데이터를 지시, ar을 사용해서는 그 데이터를 변경할 수 없다는 것을 뜻한다.
    만일, ar을 인위적으로 변경하기 위해 다음과 같이 제한을 어겼다고 가정해 보자.

        ar[0] += 10;

    이 경우, 컴파일러는 에러를 발생시킬 것이다.

    만일 데이터의 변경이 필요한 경우는 const의 사용을 자제해야 한다.
    하지만, 중요한 데이터가 있고, 유저나 프로그래머가 인위적이나 실수로 변경하면 안되는 데이터라면
    적재적소에 위치에 const를 사용하여야 한다.

    */
    #pragma endregion
    #pragma region 07.포인터와 const
    /*
    ---------------------------------------- 07.포인터와 const ----------------------------------------
    포인터에 const를 사용하는 것은 난해한 구석이 있다. const라는 키워드는 포인터에 두 가지 방법으로 사용된다.
    첫 번째 방법은, 상수 객체를 지시하는 포인터를 만드는 것이다. 
    상수 객체를 지시하는 포인터를 사용하여 그 포인터가 지시하는 값을 변경할 수 없다.
    두 번째 방법은, 포인터 자신을 상수로 만드는 것이다. 
    상수 포인터를 사용하여 그 포인터가 지시하는 장소를 변경할 수 없다. 
    다음 예제를 보자.

        int age{39};
        const int* pt = &age;

    이 선언은 포인터 pt가 const int를 지시하고 있음을 말해준다. 따라서, 포인터인 pt를 통해
    그 값을 변경할 수 없다.

        *pt += 1;       // pt는 const int를 지시하고 있으므로 사용할 수 없다.
        cin >> *pt;     // 마찬가지 이유로 사용할 수 없다.

    이제 다소 난해한 문제를 고민해 보자. pt에 대한 선언은 그것이 지시하는 값이 실제로 상수라는 것을 의미하진 않는다.
    단지 pt가 관계하는 한에서만 그 값이 상수라는 것을 의미한다.
    예를 들어, pt는 age를 지시하고 있지만, age는 const가 아니므로, age 변수를 직접 사용하여 age의 값을 변경할 수 있다.

        *pt = 20;       // pt는 const int를 지시하므로, 사용할 수 없다.
        age = 20;       // age는 const로 선언되지 않았기 때문에 사용할 수 있다.

    지금까지 우리는 일반 변수의 주소를 일반 포인터에 대입했다.
    하지만 아직 다른 두 가지 가능성이 남아있다.
    하나는 const 변수의 주소를 const를 지시하는 포인터에 대입하는 것이고,
    다른 하나는, const 변수의 주소를 일반 포인터에 대입하는 것이다.
    다음 예시를 보자..

        const float g_earth = 9.80f;            
        const float* pe = &g_earth;             // 사용할 수 있다.

        const float g_moon = 1.63;
        float* pm = g_moon;                     // 사용할 수 없다.

    위 예시는 굉장히 심플한 로직을 따른다.
    g_moon의 주소를 pm에 대입이 가능하다면, pm을 사용하여 g_moon의 값을 변경할 수 있게 된다.
    그리고 그것은 g_moon이 const인 것을 무의미하게 만든다.
    따라서, C++는 const 변수의 주소를 const가 아닌 일반 포인터에 대입하는 것을 금지한다.
    ( 필사적으로 원한다면, 데이터형 변환인 const_cast를 사용할 수 있다.. 이는 15장에서 서술한다.. )

    const 데이터들을 원소로 가지는 다음과 같은 배열이 있다고 가정하자.

        const int nums[3]{1,2,3};
        int sum(int arr[], int n);      // const int arr[] 이여야 한다.

        int j = sum(nums, 3);           // 허용되지 않는다.
    
    상수 배열의 주소를 대입할 수 없도록 금지하는 것은, 상수가 아닌 형식 매개변수를
    사용하여 배열의 이름을 전달 매개변수로 함수에 전달할 수 없다는 것을 의미한다.

    위 함수 호출은, const 포인터인 nums를 const가 아닌 포인터 arr에 대입하려고 시도한다.
    하지만 컴파일러는 이러한 함수 호출을 허용하지 않는다.

    
    
    const를 사용하는 또 하나의 방법은 포인터 자신의 값을 변경하지 못하게 막는 것 이다.

        int sloth{ 3 };
        int change{};
        const int* ps = &sloth;             // const int 를 지시하는 포인터
        int* const finger = &sloth;         // int 를 지시하는 const 포인터

        cout << sloth << endl;              // sloth의 값
        cout << ps << endl;                 // ps는 'sloth의 주소'를 가르킨다
        cout << finger << endl;             // sloth의 주소
        sloth = 4;                          // sloth의 값 변경 ( 직접 대입 )
        cout << sloth << endl;              // sloth의 변경된 값 ( 4 )
        ps = &change;                       // ps는 'change의 주소'를 가르킨다
        // ps = {003213};                   // ERROR! ps는 const int이므로, ps 자체를 변경할 순 없다!
        *finger = 5;                        // finger가 가르키는 'sloth의 주소값'을 5로 변경
        // *ps = 5;                         // ERROR! ps가 가르키는 주소값의 '변수'를 변경할 수 없음! 
        cout << sloth << endl;              // 5
        cout << ps << endl;                 // change의 주소
        cout << finger << endl;             // sloth의 주소
        

    마지막 선언은 const의 위치만 바뀌었다. 이러한 형태의 선언은
    finger가 sloth만을 지시하도록 제한한다. 하지만, finger를 사용하여 sloth의 값을 변경할 순 있다.
    그리고 가운데에 있는 선언은 ps를 사용하여 sloth의 값을 변경할 수 없다.
    하지만, ps가 다른 위치를 가리킬 수는 있다. 쉽게 말해서,
    finger와 *ps 는 const이고, *finger와 ps는 const가 아니다.
    */
    #pragma endregion
    #pragma region 07.함수와 2차원 배열
    /*
    ---------------------------------------- 07.함수와 2차원 배열 ----------------------------------------
    2차원 배열을 매개변수로 사용하는 함수를 작성하려면, 배열의 이름이 주소로 취급 된다는 사실을 기억할 필요가 있다.
    다음 예제를 보자..

        int data[3][4] =
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,0,0,0}
        };
        int total = sum(data, 3);

    sum() 함수의 원형은 과연 어떤 모습일까? 그리고 sum() 함수는 왜 열의 수(4)가 아닌 행의 수(3)을 매개변수로 입력 받을까?

    data는 세 개의 원소를 가진 배열의 이름이다. 그것의 첫 번째 원소는 그 자체가 4개의 int값을 가진 배열이다.
    그러므로 data의 데이터형은 4개의 int 값을 가진 배열을 지시하는 포인터이다. 그래서 함수 원형은 다음과 같이 될 것이다.

        int sum(int (*ar2)[4], int size);

    즉, 2차원 배열은 1차원 배열로 이루어진 n개만큼의 원소를 가진 다른 배열이라고 할 수 있다.
    */
    #pragma endregion
    #pragma region 07.C 스타일 문자열을 리턴하는 함수
    /*
    ---------------------------------------- 07.C 스타일 문자열을 리턴하는 함수 ----------------------------------------
    문자열을 리턴하는 함수를 작성하고 싶다고 가정하자. 함수로는 문자열 자체를 리턴할 수 없다.
    대신, 문자열의 주소를 리턴할 수 있다. 이것이 더 효율적이다. 다음 예제를 보자.

    char* buildstr(char c, int n);

    
    const int ArSize{ 8 };

    int main()
    {
        int times{};
        char ch{};

        cout << "문자를 입력하세요 : " << endl;
        cin >> ch;
        cout << "정수를 입력하세요 : " << endl;
        cin >> times;

        char* ps = buildstr(ch, times);
        cout << ps << endl;
        delete[]ps;

        ps = buildstr('+', 20);
        cout << ps << "--done--" << ps << endl;
        delete[]ps;

        return 0;
    }

    char* buildstr(char c, int n)
    {
        char* pstr = new char[n + 1];
        pstr[n] = '\0';
        while (n-- > 0)
        {
            pstr[n] = c;
        }
        return pstr;
    }

    변수 pstr은 buildstr() 함수의 지역 변수이다. 따라서 함수가 종결되면, pstr에 대입되었던
    기억 장소는 자동으로 해제된다. 그러나, 이 함수는 종결하기 전, pstr의 값을 리턴하기 때문에,
    main()의 ps 포인터를 통하여 문자열에 접근할 수 있다.

    */
    #pragma endregion
    #pragma region 07.함수와 구조체
    /*
    ---------------------------------------- 07.함수와 구조체 ----------------------------------------
    구조체 변수는 보통의 변수처럼 함수에 값으로 전달할 수 있다. 이때, 함수는 구조체의 원본이 아닌
    복사본을 대상으로 작업한다. 또한, 함수는 구조체를 리턴할 수 있다. 배열의 이름은
    배열의 첫 번째 원소의 주소라는 등의 특별한 어떤 것이 구조체에는 없다.
    구조체 이름은 그냥 구조체 이름일 뿐이다.
    구조체를 이용하는 가장 직접적인 방법은, 기본적인 데이터형처럼 사용하는 것이다.
    그러나, 구조체를 값으로 전달하는 것은 단점이 있다.
    구조체의 덩치가 클 경우, 구조체를 복사하는 데 시간이 걸리고,
    기억 장소에 대한 요구도 높아진다. **이것은 시스템 성능을 저하시킨다.**
    이런 이유로, 많은 프로그래머들은 구조체의 주소를 전달한다.
    이를 ( passing by reference ), 또는 ( call by reference )라 하며, 값을 전달하는 경우,
    ( passing by value ), 또는 ( call by value ) 라고 한다. 이는 8장에서 더 자세하게 다룰 것이다.
    */
    #pragma endregion
    #pragma region 07.구조체의 전달과 리턴
    /*
    ---------------------------------------- 07.구조체의 전달과 리턴 ----------------------------------------
    구조체를 값으로 전달하는 것은, 구조체의 크기가 비교적 작은 경우에 알맞다.
    첫 번째 예제는 여행 소요시간을 다룬다. 서울에서 대구까지 3시간 50분이 걸리고,
    대구에서 경주까지는 1시간 25분이 걸린다고 한다. 시간과 분을 멤버로 가지는
    구조체를 만들면, 이러한 소요시간을 나타낼 수 있다. 두개의 소요시간을 합하는 것은
    분 값의 일부를 시간 값으로 올리는 일이 생길 수도 있으므로 조금 어렵다.

    예를 들어, 위의 두 소요시간의 합은, 4시간 75분이다. 이것을 5시간 15분으로 표시해야한다.
    소요시간 구조체 두 개를 매개변수로 넘겨받아 그들의 합을 나타내는 구조체를 
    다시 리턴하는 함수에 대해 살펴보자. 그러한 구조체를 정의하는 것은 간단하다.

        struct travel_time
        {
            int hours{};
            int mins{};
        }

    그 다음, 구조체의 합을 계산하여 리턴하는 sum()함수의 원형에 대해서 살펴보자.
    sum()함수의 리턴값과 매개변수는 travel_time형이어야 한다.
    따라서, 함수의 원형은 다음과 같을 것이다.

        travel_time sum(travel_time t1, travel_time t2);

    두 소요시간의 합을 구하려면 분 값 멤버끼리 먼저 더해야 한다. 나머지 셈(%)을 사용하여
    60으로 나누는 것은 시간 값으로 올리고 남는 분 값을 구한다. 다음 예제를 보자..

        
        //-------------------------[ ProtoType ]-----------------------------------//
        struct travel_time
        {
            int hours{};
            int mins{};
        };

        travel_time sum(travel_time t1, travel_time t2);
        void show_time(travel_time t);

        //-------------------------[   FBody   ]-----------------------------------//
        const int Mins_per_hr{ 60 };

        int main()
        {
            travel_time day1{ 5, 45 };      // 5시간 45분
            travel_time day2{ 4, 55 };      // 4시간 55분


            travel_time trip = sum(day1, day2);
            cout << "이틀간 소요 시간 : ";
            show_time(trip);

            travel_time day3{ 4,32 };
            cout << "사흘간 소요 시간 : ";
            show_time(sum(trip, day3));

            return 0;
        }
        //-------------------------[ Func.Def. ]-----------------------------------//
        travel_time sum(travel_time t1, travel_time t2)
        {
            travel_time total;

            total.mins = (t1.mins + t2.mins) % Mins_per_hr;
            total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;

            return total;
        }

        void show_time(travel_time t)
        {
            cout << t.hours << "시간" << t.mins << "분" << endl;
        }

    출력 :
        이틀간 소요 시간 : 10시간 40분
        사흘간 소요 시간 : 15시간 12분
    */
    #pragma endregion
    #pragma region 07.구조체 주소의 전달
    /*
    ---------------------------------------- 07.구조체 주소의 전달 ----------------------------------------
    구조체 전체를 함수에 전달하는 대신, 구조체의 주소만 함수에 전달하여 시간과 공간을 절약하고 싶다고 가정하자.
    이렇게 하려면, 구조체를 지시하는 포인터를 사용하도록 함수를 작성해야 한다. 
    
        //-------------------------[ ProtoType ]-----------------------------------//
        struct travel_time
        {
            int hours{};
            int mins{};
        };
        
        travel_time sum(travel_time* t1, travel_time* t2);
        void show_time(const travel_time* t);
        //-------------------------[   FBody   ]-----------------------------------//
        const int Mins_per_hr{ 60 };
        
        int main()
        {
            travel_time day1{ 5, 45 };      // 5시간 45분
            travel_time day2{ 4, 55 };      // 4시간 55분
            
            travel_time day3 = sum(&day1, &day2);
        
            show_time(&day3);
            return 0;
        }
        //-------------------------[ Func.Def. ]-----------------------------------//
        
        travel_time sum(travel_time* t1, travel_time* t2)
        {
            travel_time total;
        
            total.mins = (t1->mins + t2->mins) % Mins_per_hr;
            total.hours = t1->hours + t2->hours + (t1->mins + t2->mins) / Mins_per_hr;
        
            return total;
        }
        
        void show_time(const travel_time* t)
        {
            cout << t->hours << "시간" << t->mins << "분" << endl;
        }
    */
    #pragma endregion
    #pragma region 07.함수와 string 클래스 객체
    /*
    ---------------------------------------- 07.함수와 string 클래스 객체 ----------------------------------------
    string 클래스 객체는 배열보다 구조체와 훨씬 관련이 있다.
    예를 들면, 한 구조체를 다른 구조체에 대입할 수 있고, 한 객체를 다른 객체에 대입할 수 있다.
    한 구조체를 완전한 하나의 엔티티로 함수에 전달할 수 있고, 한 객체를 완전한 하나의 엔티티로 함수에 전달할 수 있다.
    여러 개의 문자열이 필요한 경우, char형의 2차원 배열 대신, string 객체의 1차원 배열을 선언할 수 있다.
    다음 예제는 string 객체의 배열을 선언하고, 그 내용을 디스플레이하는 함수에 그 배열을 전달하는
    간단한 예제를 제공한다.
        
        //-------------------------[ ProtoType ]-----------------------------------//
        void display(const string sa[], int n);

        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            const int size{ 5 };
            string list[size];
            cout << "좋아하는 밤 하늘의 광경을 " << size << "개 입력하시오 : " << endl;
            for (int i{}; i < size; i++)
            {
                cout << i+1  << " : ";
                getline(cin, list[i]);
            }

            cout << "입력하신 내용은 다음과 같습니다 : " << endl;
            display(list, size);

            return 0;
        }

        //-------------------------[ Func.Def. ]-----------------------------------//
        void display(const string sa[], int n)
        {
            for (int i{}; i < n; i++)
            {
                cout << i + 1 << " : " << sa[i] << endl;
            }
        }

    프로그램 실행 결과 :
        
        좋아하는 밤 하늘의 광경을 5개 입력하시오 :
        입력 :
            1. A
            2. B
            3. C
            4. D
            5. E
        입력하신 내용은 다음과 같습니다 : 
            1. A
            2. B
            3. C
            4. D
            5. E

    이 예제에서 주목할 것은, 프로그램이 string을 마치 int형과 같은 내장 데이터형을 다루듯이 다룬다는 점이다. 
    string의 배열을 원한다면, 보통의 배열 선언 형식을 그대로 사용하면 된다.
        
        string list[size];

    이제 list 배열의 각 원소는 string 객체이고, 다음과 같이 사용될 수 있다.
        
        getline(cin, list[i]);

    마찬가지로, 형식 매개변수 sa는 string 객체를 지시하는 포인터이다. 그래서, sa[i]는
    string 객체이고, 다음과 같이 사용될 수 있다.

        cout << i+1 << ": " << sa[i] << endl;
    */
    #pragma endregion
    #pragma region 07.함수와 array 객체
    /*
    ---------------------------------------- 07.함수와 array 객체 ----------------------------------------
    C++에서 클래스 객체는 구조체에 기반을 두고 있다. 따라서 구조체에 적용되는
    동일한 프로그래밍 고려 사항들 중 일부가 클래스에도 적용된다. 예를 들면,
    값으로 객체를 함수로 전달할 수 있는데, 이러한 경우 그 함수가 원본 객체가 아닌
    사본으로 동작한다. 또는, 포인터를 객체로 보낼 수 있는데, 이를 통해서 그 함수가
    원본 객체로 동작하도록 한다. C++11 array 템플릿 클래스를 사용하는 다음의 예를 살펴보자.

    1년간 사계절의 각각에 대하여 비용 숫자를 지니기 위한 array 객체를 하나 가지고 있다고 가정해 보자.

        array<double, 4> expenses;

    만약 expenses에 저장된 내용을 표시하기 위한 함수를 원한다면, 우리는 값으로 expenses 함수로 보내야한다.

        show(expenses);

    그러나, 만약 우리가 expenses 객체를 수정하는 함수를 원할 경우에는 그 객체의 주소를 함수로 보내야만 한다.

        fill(&expenses);

    어떻게 우리가 이 두 함수를 선언할 수 있을까? expenses의 변수형은 array<double ,4> 타입이기 때문에
    다음과 같이 함수 원형에 표시되어야 한다.

        void show(array<double, 4> da);     // da 객체
        void fill(array<double, 4> *pa);    // pa 객체에 대한 포인터

    이러한 고려 사항들이 예제 프로그램의 핵심을 이루고 있는데, 몇 가지 특징적인 사안들이 추가되어 있다.
    
    첫째, 4를 심볼릭 상수로 대신한다.

        const int Seasons {4};

    둘째, 그 사계절을 표현하는 4개의 string 객체를 지닌 상수 array 객체를 추가한다.
        
        const array<string, Seasons> Snames =
         {"Spring", "Summer", "Fall", "Winter"};
    
    배열 템플릿은 기초 데이터 타입을 고수하는 것에 한정되지 않고, 클래스 타입도
    사용 가능하다. 다음 예제를 보자...

        //-------------------------[ ProtoType ]-----------------------------------//
        const int Seasons{ 4 };
        const array<string, Seasons> Sname{ "Spring", "Summer", "Fall", "Winter" };
        
        void fill(array<double, Seasons>* pa);
        void show(array<double, Seasons> da);
        
        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            array<double, Seasons> expenses{};
            fill(&expenses);
            show(expenses);
        
            return 0;
        }

        //-------------------------[ Func.Def. ]-----------------------------------//
        void fill(array<double, Seasons>* pa)
        {
            for (int i{}; i < Seasons; i++)
            {
                cout << Sname[i] << "에 소요되는 비용 : ";
                cin >> (*pa)[i];
            }
        }
        
        void show(array<double, Seasons>da)
        {
            double total{};
            cout << endl << "계절별 비용" << endl;
        
            for (int i{}; i < Seasons; i++)
            {
                cout << Sname[i] << " : $" << da[i] << endl;
                total += da[i];
            }
            cout << "총 비용 : $" << total << endl;
        }

    프로그램 실행 결과 :
        Spring에 소요되는 비용 :
        Summer에 소요되는 비용 :
        Fall에 소요되는 비용 :
        Winter에 소요되는 비용 :

        입력 :
        1,2,3,4

        출력 :
        Spring에 소요되는 비용 : $1
        Summer에 소요되는 비용 : $2
        Fall에 소요되는 비용 : $3
        Winter에 소요되는 비용 : $4
        총 비용 : $10

    */
    #pragma endregion
    #pragma region 07.재귀 호출
    /*
    ---------------------------------------- 07.재귀 호출 ----------------------------------------
    C++ 함수는 자기 자신을 호출 할 수 있는 능력을 가지고 있다. 이것을 재귀 호출이라고 하낟.
    재귀 호출은 인공지능과 같은 특별한 프로그래밍에서 매우 중요한 도구이다.
    
    * 단일 재귀 호출
    재귀 함수가 자신을 호출하면 새로 호출되는 함수도 다시 자기 자신을 호출하게 되므로,
    호출의 연쇄를 끝내는 조건이 없다면, 재귀 호출은 끝없이 반복될 것이다.
    호출의 연쇄를 끝내기 위해 일반적으로 사용하는 방법은, 재귀 호출 부분을 if 구문의
    일부로 만드는 것이다. 다음 예시를 보자..

        void recurs(argumentlist)
        {
            statements1
            if(test)
            {
                recurs(arguments)
            }
            statements
        }
    test가 거짓이 되면, 재귀 호출은 종료되게 된다.
    
    재귀 호출은 흥미로운 연쇄이벤트를 만든다.
    if 구문이 참인 동안, recurs() 함수 호출은 statements1 부분만 수행하고 statement2의 수행은
    유보한 채, 새로운 recurs() 함수 호출로 진행한다. if 구문이 거짓이 되면, 마지막 함수 호출에서
    statements2가 진행되고 이전 단계의 recurs() 호출로 제어가 넘어가 유보해 두었던 statements2 부분을
    수행한다. 이렇게 재귀 호출의 사슬을 되짚어 올라가게 되면, recurs() 함수의 재귀 호출이
    5번 일어났을 때, statements1 부분이 함수가 호출된 순서대로 5번 먼저 수행된 후,
    recurs()함수가 호출된 순서와는 반대로 statemets2 부분이 다시 수행된다.

    다음 예제를 보자..

        //-------------------------[ ProtoType ]-----------------------------------//
        void countdown(int n);
        
        //-------------------------[   FBody   ]-----------------------------------//
        
        
        int main()
        {
            countdown(4);
        
            return 0;
        }
        
        
        
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        
        void countdown(int n)
        {
            cout << "카운트 다운 ... " << n << endl;
            if (n > 0)
            {
                countdown(n - 1);
            }
            cout << n << ": Kamoom!\n";
               
        }
    
    프로그램 실행 결과 :
        카운트 다운 ... 4                // 1단계
        카운트 다운 ... 3                // 2단계 
        카운트 다운 ... 2                // 3단계
        카운트 다운 ... 1                // 4단계
        카운트 다운 ... 0                // 5단계
        0: Kaboom!                       // 5단계
        1: Kaboom!                       // 4단계
        2: Kaboom!                       // 3단계
        3: Kaboom!                       // 2단계
        4: Kaboom!                       // 1단계
    */
    #pragma endregion
    #pragma region 07.다중 재귀 호출
    /*
    ---------------------------------------- 07.다중 재귀 호출 ----------------------------------------
    재귀 호출은 하나의 작업을 서로 비슷한 두 개의 작은 작업으로 반복적으로 분할해가면서
    처리해야 하는 상황에서 특히 유용하다. 예를 들어, 눈금자를 그리는 상황을 생각하자.
    두 개의 끝을 먼저 표시 후, 그들의 중간 지점을 찾아 눈금을 표시한다.
    동일한 절차를 눈금자의 왼쪽 절반에 대해 수행한다. 오른쪽에도 마찬가지로 수행한다.
    눈금 간격을 더욱 세분하려면 현재의 눈금 구획에 대해 동일한 절차를 수행한다.
    이러한 재귀적인 접근을 **분할과 정복 ( Divide - and - Conquer )** 이라고 한다.
    
    다음 예제는 subdivide()라는 재귀 함수를 사용하여 이것을 설명한다.
    처음 subdivide() 함수는, 양쪽 끝이 | 문자이고 나머지가 모두 빈칸 문자로 채워진
    하나의 문자열을 사용한다. 이 프로그램은 subdivide() 함수를 6번 호출하는 루프를 사용한다.


        //-------------------------[ ProtoType ]-----------------------------------//
        void subdivide(char ar[], int low, int high, int level);
        const int Len{ 66 };
        const int Divs{ 6 };
        
        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            char ruler[Len];
            for (int i{1}; i < Len - 2; i++)
            {
                ruler[i] = ' ';
            }
            ruler[Len - 1] = '\0';
            int max = Len - 2;
            int min{};
        
            ruler[min] = ruler[max] = '|';
            cout << ruler << endl;
            
            for (int i{ 1 }; i <= Divs; i++)
            {
                subdivide(ruler, min, max, i);
                cout << ruler << endl;
                for (int j{ 1 }; j < Len - 2; j++)
                {
                    ruler[j] = ' ';
                }
            }
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        
        void subdivide(char ar[], int low, int high, int level)
        {
            if (level == 0) return;
        
            int mid = (high + low) / 2;
            ar[mid] = '|';
            subdivide(ar, low, mid, level - 1);
            subdivide(ar, mid, high, level - 1);
        }

    프로그램 실행 결과 :
        |                                                               |
        |                               |                               |
        |               |               |               |               |
        |       |       |       |       |       |       |       |       |
        |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
        | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
        |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    프로그램 분석 :
        subdivide() 함수는 재귀 호출 단계를 제어하기 위해 level이란 변수를 사용한다.
        함수가 자신을 호출할 때마다 level은 1씩 감소하며 0이 되면 종료된다.
        subdivide() 함수는, 자신을 두 번 호출한다.
        한 번은 왼쪽 구획을 나누기 위해서, 다른 한번은 오른쪽 구획을 나누기 위해서이다.
        최초의 중간 지점은 왼쪽 구획을 나누기 위한 호출에서 오른쪽 끝이 되고,
        오른쪽 구획을 나누기 위한 호출에서는 왼쪽 끝이 된다.

        재귀 호출의 수는 기하급수적으로 증가하는데, 한 번의 호출이 두 번의 호출을,
        두 번의 호출은 네 번의 호출을.. 이런식으로 계속 진행하면
        6단계의 호출은 눈금자를 64개의 칸으로 채우게 된다. ( 2^6 = 64 )

        함수 호출의 수가 계속해서 2배씩 증가하기 때문에, 재귀 호출이 많이 요구되는
        경우에 이와 같은 재귀는 잘못된 선택이다.
        하지만, 필요한 재귀 호출의 단계가 적을 경우, 이것은 우아하고 간단한 선택이다.
    */
    #pragma endregion
    #pragma region 07.함수를 지시하는 포인터
    /*
    ---------------------------------------- 07.함수를 지시하는 포인터 ----------------------------------------
    데이터와 마찬가지로 함수도 주소를 가지고 있다. 함수의 주소는 그 함수에 해당하는
    기계어 코드가 저장되어 있는 메모리 블록의 시작 주소이다.

    * 함수포인터의 기초
    주어진 행 수만큼 프로그램 코드를 작성하는데 걸리는 시간을 평가하는 estimate()라는 함수를 설계해야한다 가정하자.
    또한, estimate() 함수는 여러 명의 프로그래머가 사용할 것이라고 가정하자.
    estimate() 함수를 위한 코드는 모든 사용자에게 동일할 것이다.
    그러나 estimate()함수는 프로그래머들 각자가 자신만의 독특한 알고리즘으로 시간을 평가할 수 있도록 허용해야 한다.
    그러기 위해선, 프로그래머 각자가 원하는 특별한 알고리즘 함수의 주소를 estimate() 함수에 전달해야 한다.
    이를 위해선, 다음과 같은 절차를 따라야 한다.

        * 함수의 주소를 얻는다
        * 함수를 지시하는 포인터를 선언한다
        * 함수를 지시하는 포인터를 사용하여 그 함수를 호출한다
    
    함수의 주소를 얻는 것은 간단하다. 뒤에 붙는 괄호를 빼고 함수 이름만 사용하면 된다.

        process(think);             // process()에 think()의 주소를 전달
        thought(think());           // thought()에 think()의 리턴값을 전달

    포인터와 마찬가지로, 포인터가 지시하는 함수의 데이터 형을 지정해야 한다.
    예를 들어 함수 원형이 다음과 같은 시간 평가 함수를 작성했다고 가정하자.

        double pam(int);

    이 함수를 지시하는 포인터의 적절한 선언은 다음과 같다.

        double (*pf)(int);          // pf는 하나의 int를 매개변수로 취하고
                                    // double형을 리턴하는 함수를 지시한다.
        ----------------------------------------------------------------------------------
        double *pf(int);            // pf()는 double 형을 지시하는 포인터를 리턴하는 함수
        double (*pf)(int);          // pf는 double을 리턴하는 함수를 지시하는 포인터

    이는 연산자 우선순위 때문이다.
    
    이처럼 pf를 바르게 선언한다면, 일치하는 함수의 주소를 그것에 대입할 수 있다.
        
        double pam(int);
        double (*pf)(int);
        pf = pam;                   // pf는 이제 pam() 함수를 지시한다.

    이제 앞에서 언급했던 estimate() 함수 이야기로 돌아가자.
    작성된 코드의 행 수와, pam() 함수와 같은 시간 평가 함수의 주소를 estimate() 함수에 전달하고 싶다고 가정하자.
    그러면 estimate() 함수의 원형은 다음과 같이 될 것이다.

        void estimate(int lines, double (*pf)(int));

    이 선언의 두 번째 매개변수는 int형을 매개변수로, double 형을 리턴하는 함수를 지시하는 포인터이다.
    estimate()함수가 pam()함수를 사용하게 하려면, 다음과 같이 estimate()에 pam() 함수의 주소를 전달해야 한다.

        estimate(50, pam);

    자 이제, 마지막이다. 포인터를 사용하여 포인터가 지시하는 함수를 호출해보자.

        double pam(int);
        double (*pf)(int);
        pf = pam;
        double x = pam(4);
        double y = (*pf)(5);

    실제로 C++는 pf도 함수 이름처럼 사용하는 것을 허용한다.

        double y = pf(5);

    첫 번째 형태는 보기 흉하지만, 함수 포인터를 사용하고 있다는 사실을 시각적으로 더 강하게 인식시킨다.
    
    */
    #pragma endregion
    #pragma region 07.함수 포인터 예제
    /*
    ---------------------------------------- 07.함수 포인터 예제 ----------------------------------------
    다음 예제는 함수를 지시하는 포인터의 사용을 보여준다.
    프로그램은 estimate() 함수를 두 번 호출한다.
    첫 번째 호출은 gildong() 함수의 주소를,
    두 번째 호출은 moonsoo() 함수의 주소를 전달한다.
    첫 번째 호출에서 estimate()는 gildong() 함수를 사용하여 필요한 시간 수를 계산한다.
    두 번째 호출에서 estimate()는 moonsoo() 함수를 사용하여 필요한 시간 수를 계산한다.
    이러한 방식의 프로그램 설계는, 추후의 프로그램 개발을 용이하게 한다.

        //-------------------------[ ProtoType ]-----------------------------------//
        double gildong(int);
        double moonsoo(int);
        void estimate(int lines, double(*pf)(int));
        
        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            int code{};
        
            cout << "필요한 코드 행 수를 입력하세요 : ";
            cin >> code;
        
            cout << "홍길동의 시간 예상 : " << endl;
            estimate(code, gildong);
        
            cout << "박문수의 시간 예상 : " << endl;
            estimate(code, moonsoo);
        
            return 0;
        }

        //-------------------------[ Func.Def. ]-----------------------------------//
        double gildong(int lns)
        {
            return 0.05 * lns;
        }
        
        double moonsoo(int lns)
        {
            return 2.0 * lns;
        }
        
        void estimate(int lines, double(*pf)(int))
        {
            cout << lines << "행을 작성하는데 ";
            cout << (*pf)(lines) << "시간이 걸립니다.\n";
        }

    프로그램 실행 결과 :
        필요한 코드 행 수를 입력하세요 : **20**
        홍길동의 시간 예상 :
        20행을 작성하는데 1시간이 걸립니다.
        박문수의 시간 예상 :
        20행을 작성하는데 40시간이 걸립니다.
    */
    #pragma endregion
    #pragma region 07.함수 포인터의 변형
    /*
    ---------------------------------------- 07.함수 포인터의 변형 ----------------------------------------
    함수 포인터는 표기법이 난해하다는 문제를 가진다.
    다음은 동일한 특징과 리턴값을 가지는 함수 원형들이다.

        const double* f1(const double ar[], int n);
        const double* f2(const double [], int);
        const double* f3(const double*, int);

    보기에는 달라보이지만, 모두 같은 함수이다.
    먼저, 함수 원형의 매개변수 const double ar[]과 
    const double[], const double*는 정확하게 같은 의미이다.
    두 번째,함수 원형에 식별자를 제외할 수 있다.
    const double ar[]은 const double []가 될 수 있고,
    const double* ar은 const double* 이 될 수 있다.
    그러므로, 위 세개의 함수는 같은 의미이다.

    반면, 함수 정의에서는 식별자를 제공해야 하며,
    const double ar[] 또는 const double* ar 이 명시 되어야 한다.

    다음 이 세 개의 함수를 가리킬 수 있는 포인터를 선언한다고 생각해보자.
    엄밀하겐, pa가 포인터라면, 함수 이름을 (*pa)로 대체하고 함수 원형을 작성해야 한다.
        
        const double* (*p1)(const double*, int);

    이것은 다음과 같이 초기화 형태로 조합이 가능하다.

        const double* (*p1)(const double*, int) = f1;

    C++ 자동 형 변환을 사용하면 아래와 같이 단순하게 작성이 가능하다.

        auto p2 = f2;           // C++11 자동 형 변환

    이제 아래와 같은 구문이 있다고 하자..

        cout << (*p1)(av, 3) << ": " << *(*p1)(av,3) << endl;
        cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

    (*p1)(av, 3)과 p2(av, 3)은 모두 av와 3을 매개변수로 하는 함수 ( f1()) & f2() )를 호출하고 있다.
    그러므로, 이 두 함수의 리턴 값이 출력되며, 리턴 값은 const double* 형( double 값의 주소 )이 된다.
    실제 값은, 그 주소에 저장되어 있기 때문에, * 연산자를 사용, *(*p1)(av,3), *p2(av,3)과 같이 표현해야 하낟.

    세 개의 함수가 함께 동작하기 위해서는 함수 포인터의 배열을 가지고 운영을 해야한다.
    이 경우, 각 함수의 호출을 위해 for 루프를 사용할 수 있다.
    단일 포인터 선언처럼 보이지만, 세 개 포인터의 배열을 지시하기 위해 [3]을 사용한다.

        const double* (*pa[3])(const double*, int) = (f1, f2, f3);

    왜 [3]을 넣어야 할까? pa는 세 개의 원소를 가지는 배열이고,
    세 개의 원소를 가지는 배열을 선언하기 위한 첫 단계가 pa[3]이다.

    여기에 auto를 사용할 수 있을까? 불가능하다. 자동 형 변환은 단일 값을 초기화할 때 사용되며,
    리스트를 초기화할 때는 사용할 수 없다. 그러나, 배열 pa에 대해서
    다음과 같은 대입으로 선언이 가능하다.

        auto pb = pa;

    배열의 이름은 배열의 첫 번째 원소를 가리키기 때문에, pa와 pb는 함수를 가리키는 포인터이다.
    함수를 호출하려면 어떻게 해야할까? pa[i]와 pb[i]는 모두 배열 내 존재하는 포인터이고,
    각 원소를 가리키는 표현식으로 각 함수를 호출하면 된다.

        const double* px = pa[0](av,3);
        const double* py = (*pb[1])(av,3);

    그리고 double 값을 얻기 위해 * 연산자를 사용할 수 있다.

        double x = *pa[0](av,3);
        double y = *(*pb[1])(av,3);

    pa와 &pa의 차이를 확실하게 알아야 한다.
    pa는 배열의 첫 번째 원소의 주소이다. 그러므로, 단일 포인터의 주소이다.
    그러나 &pa는 전체 배열의 주소이다. 숫자상으로 pa와 &pa는 같을 수 있지만 데이터 형이 다르다.
    또 다른 차이는 pa는 첫 번째 원소의 값을 한 번에 얻을 수 있지만, &pa는 같은 값을 얻기 위해
    두 단계를 거쳐야 한다.

        **&pa == *pa == pa[0]
    
    예제는 다음 게시물에서 설명한다..
    */
    #pragma endregion
    #pragma region 07.함수 포인터를 가지는 배열
    /*
    ---------------------------------------- 07.함수 포인터를 가지는 배열 ----------------------------------------
    다음 예제이다..


        //-------------------------[ ProtoType ]-----------------------------------//
        // 표현식만 다를뿐 모두 같은 함수이다.
        const double* f1(const double ar[], int n);
        const double* f2(const double[], int);
        const double* f3(const double*, int);
        
        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            double av[3]{ 1112.3, 1542.6, 2227.9 };
        
            // 함수를 가리킨다.
            const double* (*p1)(const double*, int) = f1;
            auto p2 = f2;      // C++11 자동 형 변환
        
            cout << "함수 포인터 : \n";
            cout << "주소 값\n";
        
            cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
            cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
        
            // 포인터들의 배열 pa
            // auto는 리스트 초기화에 사용할 수 없다.
            const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
            // 그러나, 단일 값을 초기화할 때는 사용할 수 있다.
            // pb는 pa의 첫 번째 원소를 가리킨다.
            auto pb = pa;
        
            cout << "\n함수 포인터를 원소로 가지는 배열 : \n";
            cout << "주소 값\n";
        
            for (int i{}; i < 3; i++)
            {
                cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
            }
        
            cout << "\n함수 포인터를 가리키는 포인터 : \n";
            cout << "주소 값\n";
        
            for (int i{}; i < 3; i++)
            {
                cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
            }
        
            // 함수 포인터를 원소로 가지는 배열을 가리키는 포인터
            cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터 : \n";
            cout << "주소 값\n";
        
            // pc를 선언하는 간단한 방법
            auto pc = &pa;
        
            cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
        
            // pd를 선언하는 복잡한 방법
            const double* (*(*pd)[3])(const double*, int) = &pa;
        
            //pdb에 리턴 값을 저장한다.
            const double* pdb = (*pd)[1](av, 3);
            cout << pdb << ": " << *pdb << endl;
        
            // 또 다른 방법
            cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
        
            return 0;
        }
        //-------------------------[ Func.Def. ]-----------------------------------//
        const double* f1(const double* ar, int n)
        {
            return ar;
        }
        const double* f2(const double ar[], int n)
        {
            return ar + 1;
        }
        const double* f3(const double ar[], int n)
        {
            return ar + 2;
        }
    */
    #pragma endregion
    #pragma region 07.typedef를 이용한 단순화
    /*
    ---------------------------------------- 07.typedef를 이용한 단순화 ----------------------------------------
    C++는 선언을 단순하게 하기 위해 auto외에 다른 방법을 제공한다.
    typedef 키워드는 데이터 형에 가명을 붙일 수 있다.

        typedef double real;       // double에 real이라는 가명을 만든다.

    이 기법은 식별자로 가명을 선언하고 앞에 typedef 키워드를 삽입한다.
    그래서 함수 포인터 형을 p_fun이라는 가명으로 만들 수 있다.

        typedef const double *(*p_fun)(const double*, int);
                                // p_fun은 형 이름이다.
        p_fun p1 = f1;          // p1 함수 f1을 가리키는 포인터이다.

    정교하게 만들기 위해 아래와 같이 사용할 수 있다.

        p_fun pa[3] = {f1, f2, f3};         // pa는 3개 함수 포인터의 배열이다.
        p_fun (*pd)[3] = &pa;               // pa는 3개 함수 포인터의 배열을 가리킨다.

    typedef는 단지 입력한 가명을 저장하는 것 뿐만 아니라, 코드를 작성하면서
    오류를 줄여 주면서 프로그램을 더 쉽게 이해할 수 있게 도와준다.

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_1
    /*
    ---------------------------------------- 07.프로그래밍 연습_1 ----------------------------------------
    문제 :
    쌍을 이루는 두 수를 반복해서 입력할 것을 사용자에게 요구하는 프로그램을 작성하라.
    쌍을 이루는 두 수 중에 적어도 어느 하나가 0으로 입력될 때까지 입력은 계속된다.
    프로그램은 각 쌍에 대하여 두 수의 조화 평균을 계산하는 함수를 사용한다.
    그 함수는 계산 값을 main()에 return하며, main()은 그 결과를 보고해야 한다.
    조화평균은 다음과 같은 공식을 따른다.

        조화평균 = 2.0*x*y / (x+y)

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        double calculate(double a, double b);
        
        //-------------------------[   FBody   ]-----------------------------------// 
        int main()
        {
            double x{};
            double y{};
            double result{};
            while (true)
            {
                cout << "숫자 2개를 입력하세요 : " << endl;
                cin >> x;
                if (x == 0) break;
                cin >> y;
                if (y == 0) break;
                result = calculate(x, y);
                cout << result << endl;
            }
            
            cout << "프로그램이 종료됩니다...";
            return 0;
        }
        //-------------------------[ Func.Def. ]-----------------------------------//
        double calculate(double a, double b)
        {
            return 2.0 * a * b / (a + b);
        }

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_2
    /*
    ---------------------------------------- 07.프로그래밍 연습_2 ----------------------------------------
    문제 :
    골프 스코어를 최대 10개까지 입력할 것을 사용자에게 요구하여 배열에 저장하는 프로그램을 작성하라.
    10개의 스코어를 입력하기 전이라도 사용자가 입력을 끝 낼 수 있어야 한다.
    프로그램은 모든 스코어를 한 줄에 출력하고, 평균 스코어를 보고해야 한다.
    입력 / 출력 / 평균 스코어 계산을 위해 세 가지 서로 다른 배열 처리 함수를 사용하라.

    해답 :
        //-------------------------[ ProtoType ]--------------------------------
        const int SIZE = 10;
        void input(int ar[], int size);
        double average(int ar[], int size, int num);
        void output(int ar[], int count, double avg);
        
        //-------------------------[   FBody   ]--------------------------------
        int main()
        {
            int arr[SIZE]{};
            input(arr, SIZE);
            return 0;
        }
        
        //-------------------------[ Func.Def. ]--------------------------------
        void input(int ar[], int size)
        {
            int count{};
            double avg{};
        
            cout << "종료를 원하시면 숫자가 아닌 문자를 입력하세요." << endl;
            for (int i{}; i < size; i++)
            {
                cout << i + 1 << "번 라운드의 점수 : ";
                if (cin >> ar[i])
                {
                    count++;
                }
                else
                {
                    return;
                }
                cout << endl;
            }
            avg = average(ar, size, count);
            output(ar, count, avg);
        }
        
        double average(int ar[], int size, int num)
        {
            double sum{};
            for (int i{}; i < size; i++)
            {
                sum += ar[i];
            }
            return sum / num;
        }
        
        void output(int ar[], int count, double avg)
        {
            for (int i{}; i < count; i++)
            {
                cout << ar[i] << " ";
            }
            cout << endl <<"평균 값은 : " << avg << "입니다.";
        }

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_3
    /*
    ---------------------------------------- 07.프로그래밍 연습_3 ----------------------------------------
    문제 :
    다음과 같은 구조체 선언이 있다.
        
        struct Box
        {
            char maker[40];
            float height;
            float width;
            float length;
            float volume;
        };
    
    1. box 구조체를 값으로 전달 받아, 각 멤버의 값을 출력하는 함수를 작성하라.
    2. box 구조체의 주소를 전달 받아, volume 멤버를 다른 세 가지 멤버의 곱으로 설정하는 함수를 작성하라.
    3. 앞의 두 함수를 사용하는 간단한 프로그램을 작성하라.

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        struct Box
        {
            char maker[40];
            float height;
            float width;
            float length;
            float volume;
        };
        void output(Box boo);
        void setVolume(Box* boo);

        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            Box box = { "Hi", 1, 2, 3, 4 };
            output(box);
            setVolume(&box);
            cout << endl;
            output(box);
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        void output(Box boo)
        {
            cout << "Maker : " << boo.maker << "\nHeight : " << boo.height 
                 << "\nWidth : " << boo.width << "\nLength : " << boo.length 
                 << "\nVolume : " << boo.volume << endl;
        }
        void setVolume(Box* boo)
        {
            boo->volume = boo->height * boo->length * boo->width;
        }

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_4
    /*
    ---------------------------------------- 07.프로그래밍 연습_4 ----------------------------------------
    문제 :
    사용자가 수의 범위를 정하고, 그 집합에서 몇 개의 수를 뽑는 복권 시스템이 있다.
    예를 들어, 1~47 범위를 정하고, 5개의 수를 뽑을 수 있다.
    또한, 1~27과 같은 두 번째 범위를 정하고, 하나의 수를 뽑을 수 있다.
    그랑프리를 타려면 뽑아 낸 모든 수가 들어맞아야 한다.
    승률은 47개의 수에서 번호 5개를 모두 맞출 확률과
    27개의 수에서 1개의 수를 바르게 뽑을 확률을 곱한 것이다.
    이러한 종류의 변형 복권 시스템의 승률을 계산할 수 있도록 프로그램을 작성하라.

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            int start{};
            int end{};
            int second_start{};
            int second_end{};
            double arr[5]{};
            double win{ 1.0 };
            double winwin{ 0 };
            double winwinwin{ 0 };
        
            cout << "첫 번째 범위를 입력하세요.." << endl;
            cout << "시작 : \n";
            cin >> start;
            cout << "끝 : \n";
            cin >> end;
            cout << "두 번째 범위를 입력하세요.." << endl;
            cout << "시작 : \n";
            cin >> second_start;
            cout << "끝 : \n";
            cin >> second_end;
        
            int first_size = end - start + 1;
            int second_size = second_end - second_start + 1;
        
            for (double i{ 5 }; i > 0; i--)
            {
                win *= static_cast<double>(i / (first_size - (5 - i)));
            }
        
            winwin = 1.0 / (second_size);
        
            winwinwin = win * winwin;
        
            cout << "당신의 당첨 확률 : " << winwinwin;
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_5
    /*
    ---------------------------------------- 07.프로그래밍 연습_5 ----------------------------------------
    문제 :
    하나의 정수를 매개변수로 취하고, 그 매개변수의 팩토리얼을 리턴하는 재귀함수를 정의하라.

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        long long factorial(long long num);
        long long factorial2(long long num);
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            long long num{};
            cin >> num;
            long long dam = factorial(num);
            long long damdam = factorial2(num);
            cout << dam << endl;
            cout << damdam;
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        long long factorial(long long num)          // 재귀함수 미사용
        {
            long long dam{1};
            for (num; num >= 1; num--)
            {
                dam *= num;
            }
            return dam;
        }
        
        long long factorial2(long long num)         // 재귀함수 사용
        {
            if (num > 0)
            {
                 return num * factorial2(num - 1);
            }
            else
            {
                return 1;
            }
        }


    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_6
    /*
    ---------------------------------------- 07.프로그래밍 연습_6 ----------------------------------------
    문제 :
    다음과 같은 함수를 사용하는 프로그램을 작성하라.

    Fill_array()는, int형 값들의 배열 이름과 배열 크기를 매개변수로 취한다.
    이 함수는, 배열에 저장할 int형 값들을 입력하라는 프롬포트를 표시한다.
    배열이 가득 차거나, 숫자가 아닌 것이 입력되면 입력 받기를 멈추고,
    그때까지 입력 받은 값의 개수를 리턴한다.

    show_array()는 int형 값들의 배열 이름과 배열 크기를 매개변수로 취하고,
    배열의 내용을 출력한다.
    
    Reverse_array()는 int형 값들의 배열 값들의 배열 이름과 배열 크기를 매개변수로 취하고
    배열에 저장된 값들의 순서를 뒤집는다.

    프로그램은 이 함수들을 사용하여, 배열을 채우고, 출력하고, 순서를 뒤집고 출력해야한다.

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        void Fill_array(int arr[], int size);
        void Show_array(int arr[], int size);
        void Reverse_array(int arr[], int size);
        //-------------------------[   FBody   ]-----------------------------------// 
        int main()
        {
            int arr[5]{};
            Fill_array(arr, 5);
            Show_array(arr, 5);
            Reverse_array(arr, 5);
            Show_array(arr, 5);
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        void Fill_array(int arr[], int size)
        {
            for (int i{}; i < size; i++)
            {
                cout << "배열 값을 입력하세요 : " << endl;
                cout << i + 1 << "번 원소의 값 : ";
                cin >> arr[i];
            }
        }
        void Show_array(int arr[], int size)
        {
            cout << "\n\n배열 값을 출력합니다 : " << endl;
            for (int i{}; i < size; i++)
            {
                cout << i + 1 << "번 원소의 값 : ";
                cout << arr[i] << endl;
            }
        }
        void Reverse_array(int arr[], int size)
        {
            cout << "\n뒤집기!" << endl;
            int i, j, temp;
            for (i = 0, j = size - 1; i < j; i++, j--) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_7
    /*
    ---------------------------------------- 07.프로그래밍 연습_7 ----------------------------------------
    문제 :
    배열과 구조체를 다루는 함수의 작성이다.
    주어진 프로그램의 골격을 보고, 주석문으로 서술된 함수들을 작성하라.

        #include <iostream>
        using namespace std;

        //-------------------------[ ProtoType ]-----------------------------------//
        const int SLEN{ 30 };
        struct Student
        {
            char fullName[SLEN]{};
            char hobby[SLEN]{};
            int oopLevel{};
        };

        int getinfo(Student pa[], int n);
        // getinfo()는 두 개의 매개변수를 취한다. Student 구조체 배열의 첫 원소를 지시하는 포인터와 배열의 원소 수를 나타내는 int 값이다
        // 이 함수는, 학생 정보의 저장 및 배열이 다 차거나 학생 이름에 빈 줄이 입력되면 종료된다.
        // 이 함수는 배열의 실제로 채워진 원소 수를 리턴한다.
        //
        void display1(Student st);
        // display1()은 Student 구조체를 매개변수로 취하며 그 구조체의 내용을 출력한다.

        void display2(const Student* ps);
        // display2()는 Student 구조체의 주소를 매개변수로 취하며 구조체의 내용을 출력한다.

        void display3(const Student pa[], int n);
        // display3()은 구조체 배열 첫 번째 원소의 주소와 배열의 원소 수를 입력 받고, 구조체의 내용을 출력한다.

        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            cout << "학급의 학생 수를 입력하시오 : ";
            int class_size{};
            cin >> class_size;

            while (cin.get() != '\n')
                continue;

            Student* ptr_stu = new Student[class_size];
            int entered = getinfo(ptr_stu, class_size);

            for (int i{}; i < entered; i++)
            {
                display1(ptr_stu[i]);
                display2(&ptr_stu[i]);
            }

            display3(ptr_stu, entered);
            cout << "프로그램을 종료합니다.\n";
            return 0;
        }

        //-------------------------[ Func.Def. ]-----------------------------------//

        // getinfo()는 두 개의 매개변수를 취한다. Student 구조체 배열의 첫 원소를 지시하는 포인터와 배열의 원소 수를 나타내는 int 값이다
        // 이 함수는, 학생 정보의 저장 및 배열이 다 차거나 학생 이름에 빈 줄이 입력되면 종료된다.
        // 이 함수는 배열의 실제로 채워진 원소 수를 리턴한다.
        int getinfo(Student pa[], int n)
        {

        }

        // display1()은 Student 구조체를 매개변수로 취하며 그 구조체의 내용을 출력한다.
        void display1(Student st)
        {
            cout << "Full Name : " << st.fullName << "\nHobby : " << st.hobby << "\nOopLevel : " << st.oopLevel << endl;
        }

        // display2()는 Student 구조체의 주소를 매개변수로 취하며 구조체의 내용을 출력한다.
        void display2(const Student* ps)
        {

        }

        // display3()은 구조체 배열 첫 번째 원소의 주소와 배열의 원소 수를 입력 받고, 구조체의 내용을 출력한다.
        void display3(const Student pa[], int n)
        {

        }


    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        const int SLEN{ 30 };
        struct Student
        {
            char fullName[SLEN]{};
            char hobby[SLEN]{};
            int oopLevel{};
        };
        
        int getinfo(Student pa[], int n);
        void display1(Student st);
        void display2(const Student* ps);
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            cout << "학급의 학생 수를 입력하시오 : ";
            int class_size{};
            cin >> class_size;
        
            while (cin.get() != '\n')
                continue;
            
            Student* ptr_stu = new Student[class_size];
            int entered = getinfo(ptr_stu, class_size);
        
            for (int i{}; i < entered; i++)
            {
                display1(ptr_stu[i]);
            }
            cout << "--------------------------\n";
            for (int i{}; i < entered; i++)
            {
                display2(&ptr_stu[i]);
            }
            cout << "--------------------------\n";
            display3(ptr_stu, entered);
            cout << "프로그램을 종료합니다.\n";
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        int getinfo(Student pa[], int n)
        {
            int count{};
            for (int i{}; i < n; i++)
            {
                cout << "학생 이름 : ";
                cin.getline(pa[i].fullName, SLEN);
                if (pa[i].fullName[0] == '\0') break;
                cout << "학생 취미 : ";
                cin.getline(pa[i].hobby, SLEN);
                cout << "학생 OopLevel : ";
                if (!(cin >> pa[i].oopLevel).get()) break;
                count++;
            }
            cout << "----------- 입력 완료 -----------\n";
            return count;
        }

        void display1(Student st)
        {
            cout << "Full Name : " << st.fullName << "\nHobby : " << st.hobby << "\nOopLevel : " << st.oopLevel << "\n\n";
        }
        
        void display2(const Student* ps)
        {
            cout << "Full Name : " << ps->fullName << "\nHobby : " << ps->hobby << "\nOopLevel : " << ps->oopLevel << "\n\n";
        
        }
        
        void display3(const Student pa[], int n)
        {
            for (int i{}; i < n; i++)
            {
                cout << "Full Name : " << pa[i].fullName << "\nHobby : " << pa[i].hobby << "\nOopLevel : " << pa[i].oopLevel << "\n\n";
            }
            
        }
        
    */
    #pragma endregion
    #pragma region 07.프로그래밍 연습_8
    /*
    ---------------------------------------- 07.프로그래밍 연습_8 ----------------------------------------
    문제 :
    calculate() 함수를 설계하라.
    calculate() 함수의 첫 번째와 두번째 매개변수는 double 형이다.
    세 번째 매개변수는 두 개의 double형을 매개변수로 취급하여 double형을 리턴하는
    함수를 지시하는 포인터이다. 그리고 calculate() 함수 역시 double 형이다.
    따라서, calculate() 함수는 자신의 세 번째 매개변수가 지시하는 함수가,
    두 개의 double 형 매개변수를 취하고 계산하여 리턴하는 값을 다시 리턴한다.
    예시를 보자..

        double add(double x, double y)
        {
            return x+y;
        }

    그러면 다음과 같은 calculate() 함수의 호출은

        double q = calculate(2.5, 10.4, add);

    2.5와 10.4를 add() 함수에 전달, add() 함수가 계산하여 리턴하는 값 (12.9)를 리턴하여 q에 대입한다.

    이 함수들과 함께, add() 스타일의 다른 함수를 최소한 하나 더 프로그램에 사용하라.
    프로그램은 사용자가 쌍을 이루는 두 수를 반복해서 입력할 수 있도록 루프를 사용한다.
    좀 더 진도를 나가고 싶다면, add() 스타일의 함수들을 지시하는 포인터들의 배열을 만들고,
    이 포인터들을 사용하여 calculate() 함수를 일련의 add 스타일의 함수들에 연속적으로 적용하는 루프를 만들어라.

    HINT : 다음은 세 개의 함수 포인터 배열을 선언하는 방법이다.
        
        double (*pf[3]) (double, double);

    해답 :
        //-------------------------[ ProtoType ]-----------------------------------//
        double add(double x, double y);
        double sub(double x, double y);
        double mul(double x, double y);
        double div(double x, double y);
        double calculate(double x, double y, double(*pf)(double, double));
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            double(*pf[4])(double, double) { add, sub, mul, div };
        
            for (;;)
            {
                double x{};
                double y{};
                double arr[4]{};
                int n{};
        
                cout << "두 수 입력 (종료를 원하면 아무 문자나 입력) : " << endl;
                if (!(cin >> x >> y)) break;
        
                for (int i{}; i < 4; i++)
                {
                    arr[i] = calculate(x, y, pf[i]);
                    cout << arr[i] << endl;
                }
                
            }
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        double calculate(double x, double y, double(*pf)(double, double))
        {
            return (pf(x, y));
        }
        double add(double x, double y)
        {
            return x + y;
        }
        double sub(double x, double y)
        {
            return x - y;
        }
        double mul(double x, double y)
        {
            return x * y;
        }
        double div(double x, double y)
        {
            return x / y;
        }
        

    */
    #pragma endregion


#pragma endregion

#pragma region Chapter 8.함수의 활용
    
    #pragma region 08.C++ 인라인(Inline) 함수
    /*
    ---------------------------------------- 08.C++ 인라인(Inline) 함수 ----------------------------------------
    인라인 함수는 프로그램의 실행 속도를 높이기 위해 C++에 새로 보강된 것이다.
    일반 함수와 인라인 함수의 가장 큰 차이는, 프로그래머가 코드를 어떻게 작성하느냐에 있는 것이 아닌,
    C++ 컴파일러가 코드를 프로그램에 어떻게 결합하느냐에 있다.

    컴파일 작업의 최종 산출물은 기계어 명령으로 이루어진 실행 프로그램이다. 프로그램을 실행하면, 운영 체제는
    이 명령들을 컴퓨터의 메모리에 로드한다. 로드된 명령들은 각각 하나의 특정 메모리 주소를 갖는다.
    그러고 나서 컴퓨터는 이 명령들을 순차적으로 실행한다. 루프나 분기문을 만나면,
    프로그램은 앞이나 뒤의 특정 주소로 점프하여 명령을 건너뛴다.
    일반적인 함수의 호출은 프로그램을 다른 주소로 점프시켰다가, 
    함수의 처리가 종결되면 다시 원래의 자리로 돌아오는 것이다. 그 작업을 좀 더 자세히 살펴보자.

    프로그램이 함수 호출 명령에 도달했을 때, 그 함수 호출 명령 바로 다음에 있는 명령의 주소를 메모리에 저장하고,
    스택에 매개변수를 복사한 후, 그함수가 시작되는 메모리 위치로 점프한다. 그런 다음,
    그 함수의 코드를 수행하고, 함수의 리턴 값을 레지스터에 복사한 후, 저장해 두었던 주소의 명령으로 돌아온다.
    이렇게 앞뒤로 점프를 수행하고, 점프할 위치를 기억하려면 함수를 사용하는데 시간이 많이 걸린다.

    C++ 인라인 함수는, 컴파일된 함수 코드가 프로그램의 다른 코드 안에 직접 삽입되어 있어 이 문제의 해결이 가능하다.
    컴파일러가 함수 호출을 그에 대응하는 함수 코드로 대체한다는 것을 의미한다.

    인라인 코드를 사용하면, 함수의 점프 없이 함수를 그 자리에서 처리하므로, 그함수를 수행하기 위해
    프로그램이 다른 주소로 점프했다가 돌아올 필요가 없다.
    따라서 인라인 함수는 일반 함수보다 약간 빠르게 수행된다. 그러나 메모리 측면에서는
    인라인 함수가 일반 함수보다 불리하다. 어떤 프로그램에서 인라인 함수를 열 번 호출한다면,
    프로그램은 그 함수의 사본을 프로그램의 코드 안에 열 번이나 삽입해야 한다.

    인라인 함수를 사용하려면 다음 두 가지 작업 중에 적어도 한 가지를 반드시 해야한다.

        * 함수 선언 앞에 inline이라는 키워드를 붙인다.
        * 함수 정의 앞에 inline이라는 키워드를 붙인다.
    
    일반적인 관행은, 원형을 아예 생략하고, 원형이 놓일 자리에 함수 정의 전체를 놓는 것이다.

    다음 예시를 보자.

        // 인라인 함수 정의
        inline double square(double x) { return x * x; }
        
        //-------------------------[   FBody   ]-----------------------------------//
        int main()
        {
            double a{};
            double b{};
            double c{ 13.0 };
        
            a = square(5.0);
            b = square(4.5 + 7.5);
        
            cout << "a = " << a << ", b = " << b << endl;
            cout << "c = " << c;
            cout << ", c의 제곱 " << square(c++) << endl;
            cout << "현재 c = " << c << endl;
            return 0;
        }

    프로그램 실행 결과 :
        a = 25, b = 144
        c = 13, c의 제곱 = 169
        현재 c = 14

    이 실행 결과는 인라인 함수가 일반 함수처럼 매개변수를 값으로 전달하는 것을 보여준다.
    매개변수가 4.5 + 7.5 와 같은 수식일 경우, 그 수식의 값, 이 경우는 12를 전달한다.
    이것이 C++ 인라인 함수가 C의 매크로 정의보다 더 많은 능력을 발휘하게 만든다.

    이 프로그램은 원형을 생략했지만, C++의 함수 원형 기능이 그대로 유지된다.
    그것은 함수를 처음으로 사용하는 위치보다 앞서 나오는 전체 함수 정의가 함수 원형의 역할도 하기 때문이다.
    */
    #pragma endregion
    #pragma region 08.참조 변수
    /*
    ---------------------------------------- 08.참조 변수 ----------------------------------------
    C++는 참조 변수라는 새로운 복합형을 언어에 추가했다.
    참조는 미리 정의된 어떤 변수의 실제 이름 대신 쓸 수 있는 대용 이름이다.
    그런데 대용 이름이 어디에 쓸모가 있을까? 참조의 주된 용도는 함수의 형식 매개변수에 사용하는 것이다.
    참조를 매개변수로 사용하면, 그 함수는 복사본 대신 원본 데이터를 가지고 작업한다.
    덩치 큰 구조체를 처리해야 하는 함수에서 포인터 대신 참조를 사용할 수 있다.
    참조는 클래스를 설계할 때 필수적으로 사용된다. 참조를 정의하고 사용하는 기본적인 방법에 대해 알아보자.

    C와 C++은 변수의 주소를 나타내기 위해 & 기호를 사용한다. C++는 & 기호에 또 하나의 의미를 추가하며
    참조 선언을 나타내게 하였다. 다음 예시를 보자.

        int rats{};
        int& rodents = rats;    // rodents를 rats의 대용 이름으로 만든다.

    &가 주소 연산자가 아닌, 데이터형 식별자의 일부로 사용되었다.
    int& 는 int에 대한 참조를 의미한다. 참조 선언은 rats와 rodents를 서로 바꾸어 사용할 수 있게 해준다.
    다음 예시를 보자..

        int main()
        {
            int rats{ 10 };
            int& rodents = rats;
        
            cout << "rats = " << rats;
            cout << ", rodents = " << rodents << endl;
            rodents++;
        
            cout << "rats = " << rats;
            cout << ", rodents = " << rodents << endl;
        
            cout << "rats의 주소 = " << &rats;
            cout << ", rodents의 주소 = " << &rodents << endl;
            return 0;
        }

    프로그램 실행 결과 :
        rats = 10, rodents = 10
        rats = 11, rodents = 11
        rats의 주소 = 00EFFDDC, rodents의 주소 = 00EFFDDC

    실행 결과를 보면, rats와 rodents는 같은 값과 같은 주소를 갖고 있다.
    그리고 rodents를 1만큼 증가시키는 일이 두 변수 모두에 영향을 주었다.
    참조와 포인터에 관한 예시를 보자

        int rats {101};
        int& rodents = rats;
        int* prats = &rats;

    이제 rodents나 *prats를 rats와 서로 바꾸어 사용할 수 있고, 
    &rodents나 prats를 &rats와 서로 바꾸어 사용할 수 있다.
    이러한 관점에서 보면, 참조는 내용 참조 연산자 *가 암묵적으로 받아들여지도록 가장한
    포인터와 비슷해 보인다. 그러나 포인터오 ㅏ참조 사이에는 표기 방식 외에도 차이가 존재한다.

    우선 앞에 예제에서 참조를 선언할 때, 그 참조를 초기화해야 했다.
    포인터를 선언할 때처럼, 참조를 먼저 선언하고 나중에 값을 지정할 수는 없다.

        int rats{};
        int& rodents;
        rodents = rats;         //이렇게 할 수 없다.

    참조는 const 포인터와 상당히 비슷하다. 참조는 만들 때 반드시 초기화를 해야하고,
    일단 어떤 특정 변수에 연결되면 그것을 고수해야 한다. 즉,

        int& rodents = rats;

        ==

        int* const pr = &rats;

    다음 예시를 보자..

        int main()
        {
            int rats{ 10 };
            int& rodents = rats;
        
            cout << "rats = " << rats;
            cout << ", rodents = " << rodents << endl;
        
            cout << "rats의 주소 = " << &rats;
            cout << ", rodents의 주소 = " << &rodents << endl;
        
            int bunnies{ 50 };
            rodents = bunnies;          // 참조를 바꿀 수 있는가??
            
            cout << "bunnies = " << bunnies;
            cout << ", rats = " << rats;
            cout << ", rodents = " << rodents << endl;
        
            cout << "bunnies의 주소 = " << &bunnies;
            cout << ", rodents의 주소 = " << &rodents << endl;
        
            return 0;
        }

    프로그램 실행 결과 :
        rats = 10, rodents = 10
        rats의 주소 = 0055FD94, rodents의 주소 = 0055FD94
        bunnies = 50, rats = 50, rodents = 50
        bunnies의 주소 = 0055FD7C, rodents의 주소 = 0055FD94

    rodents는 rats를 참조했다. 그 후, 프로그램은 rodents로 하여금 bunnies를 참조하려고 했다.

        rodents = bunnies;

    언뜻 보기에 rodents의 값이 50으로 변했기 때문에, 성공한 것처럼 보이지만,
    rats또한 50으로 바뀌었고, rats와 rodents가 여전히 같은 주소를 공유하고 있다.
    이 주소는 bunnies의 주소와는 다르다. rodents가 rats의 대용 이름이기 때문에
    그 대입 구문은 실제로는 다음 구문과 동일한 것이다.

        rats = bunnies;

    즉, "rats 변수에 bunnies 변수의 값을 대입하라" 는 의미이다.
    쉽게 말해서, 참조는 대입문이 아니라 초기화 선언에 의해서만 설정할 수 있다.
    

    */
    #pragma endregion
    #pragma region 08.함수 매개변수로서의 참조
    /*
    ---------------------------------------- 08.함수 매개변수로서의 참조 ----------------------------------------
    참조는 주로 함수의 매개변수로 사용된다. 참조로 전달하면 피호출 함수가 호출 함수의 변수를 사용할 수 있다.
    C++에 새로 추가된 이 기능은, 오로지 값으로만 전달하는 C로부터 탈피하는 것이다.
    값으로 전달하는 C에서, 피호출 함수는 호출 함수가 건네주는 값의 복사본을 대상으로 작업한다.

    컴퓨터 프로그래밍에서 아주 흔하게 만나는 두 변수의 값을 서로 교환하는 문제를 통해서,
    참조를 사용하는 방법과 포인터를 사용하는 방법을 비교해 보자.
    값으로 전달되는 변수들의 경우에는 원본을 쓰지 않고 복사본의 내용만 교환하고 함수를 종결하기에
    원하는 바대로 작동하지 않는다. 그러나 변수를 참조로 전달하면, 그 함수는 데이터의 원본을 가지고 작업한다.
    또한, 포인터를 사용하여 데이터의 원본에 접근할 수도 있다. 다음 예시를 보자...

        //-------------------------[ ProtoType ]-----------------------------------//
        void swapr(int& a, int& b);         // a, b는 int형 변수의 대용 이름
        void swapp(int* p, int* q);         // p, q는 int형을 지시하는 주소
        void swapv(int a, int b);           // a, b는 새로운 변수
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            int wallet1{ 3000 };
            int wallet2{ 3500 };
        
            cout << "지갑 1 = " << wallet1 << "원";
            cout << ", 지갑 2 = " << wallet2 << "원\n";
        
            cout << "참조를 이용하여 내용들을 교환:\n";
            swapr(wallet1, wallet2);
            cout << "지갑 1 = " << wallet1 << "원";
            cout << ", 지갑 2 = " << wallet2 << "원\n";
        
            cout << "포인터를 이용하여 내용들을 다시 교환:\n";
            swapp(&wallet1, &wallet2);
            cout << "지갑 1 = " << wallet1 << "원";
            cout << ", 지갑 2 = " << wallet2 << "원\n";
        
            cout << "값으로 전달하여 내용 교환 시도:\n";
            swapv(wallet1, wallet2);
            cout << "지갑 1 = " << wallet1 << "원";
            cout << ", 지갑 2 = " << wallet2 << "원\n";

            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        void swapr(int& a, int& b) 
        {
            int temp{};
            temp = a;
            a = b;
            b = temp;
        }
        void swapp(int* p, int* q)
        {
            int temp{};
            temp = *p;
            *p = *q;
            *q = temp;
        }
        void swapv(int a, int b)
        {
            int temp{};
            temp = a;
            a = b;
            b = temp;
        }

    프로그램 실행 결과 :
        지갑 1 = 3000원, 지갑 2 = 3500원
        참조를 이용하여 내용들을 교환:
        지갑 1 = 3500원, 지갑 2 = 3000원
        포인터를 이용하여 내용들을 다시 교환:
        지갑 1 = 3000원, 지갑 2 = 3500원
        값으로 전달하여 내용 교환 시도:
        지갑 1 = 3000원, 지갑 2 = 3500원


    */
    #pragma endregion
    #pragma region 08.참조의 특성
    /*
    ---------------------------------------- 08.참조의 특성 ----------------------------------------
    다음 예제를 보자

        //-------------------------[ ProtoType ]-----------------------------------//
        double cube(double a);
        double refcube(double& ra);
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            double x{ 3.0 };
        
            cout << cube(x);
            cout << " = " << x << "의 세제곱\n";
            cout << refcube(x);
            cout << " = " << x << "의 세제곱\n";
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        double cube(double a)
        {
            a *= a * a;
            return a;
        }
        
        double refcube(double& ra)
        {
            ra *= ra * ra;
            return ra;
        }

    프로그램 실행 결과 :
        27 = 3의 세제곱
        27 = 27의 세제곱

    refcube()는 main()에 있는 x의 값을 변경하고, cube()는 main()에 있는 x의 값을 변경하지 않는다.
    이것을 통해 매개변수를 값으로 전달하는 것이 왜 일반적인지 그 이유를 알 수 있다.
    변수 a는 cube()의 범위에서만 사용된다. a를 아무리 변경해도 main()에 있는 x는 영향을 받지 않는다.
    그러나 refcube()는 참조로 전달했으므로, ra를 변경하면 곧바로 x가 영향을 받는다.
    함수에 전달하는 정보를 함수가 변경하지 않고 사용만 하도록 하려면, 상수 참조를 사용해야 한다.

        double refcube(const double& ra)    
    
    이렇게 하면, 컴파일러가 ra의 값을 변경하려고 시도하는 코드를 발견했을 떄, 에러 메시지를 내보낸다.
    또한, 예제처럼 간단한 함수의 작성 시, 쓸데없이 참조로 전달하지 않고 값으로 전달해야 한다.
    참조 매개변수는 구조체나 클래스와 같이 덩치 큰 데이터를 다룰 때에나 유익하다.

    참조 매개변수를 사용하는 함수에 비슷한 여러 개의 매개변수를 전달하면, 제약이 따를 것이다.
    무엇보다도 ra가 어떤 변수의 대용 이름이라면, 그 변수를 실제 매개변수로 사용해야 한다.
    따라서 다음과 같은 코드는 잘못된 것이다.

        double z = refcube(x + 3.0);        // 컴파일 되지 않는다.

    그 이유는 x + 3.0 은 변수가 아니기 때문이다. 이는 다음 예시와 같은 말이다.

        x + 3.0 = 5.0       // 터무니 없다
    */
    #pragma endregion
    #pragma region 08.임시 변수, 참조 매개변수, const
    /*
    ---------------------------------------- 08.임시 변수, 참조 매개변수, const ----------------------------------------
    C++는 실제 매개변수와 참조 매개변수가 일치하지 않을 떄, 임시 변수를 생성할 수 있다.
    최신 C++는 매개변수가 const 참조일 경우에만 이것을 허용한다. 

    먼저, 임시 변수는 언제 생성되는 것일까? 참조 매개변수가 cosnt일 경우, 컴파일러는
    다음과 같은 두 가지 상황에서 임시 변수를 생성한다.

        * 실제 매개변수가 올바른 데이터형이지만 lvalue가 아닐 때
        * 실제 매개변수가 잘못된 데이터형이지만 올바른 데이터형으로 변환할 수 있을 떄
    
    lvalue는 참조가 가능한 데이터 객체이다. x = 5는 말이 되지만, 5 = x는 말이 되지 않는다.
    즉, x는 lvalue 이지만 5는 rvalue이다.

    다음 예문을 보자..

        double refcube(const double &ra)
        {
            return ra * ra * ra;
        }

    이제 다음과 같은 코드가 있다고 가정하자..

        double side{ 3.0 };
        double* pd = &side;
        double& rd = side;
        
        long edge{ 5L };
        double lens[4]{ 2.0, 5.0, 10.0, 12.0 };
        
        double c1 = refcube(side);              // ra는 side
        double c2 = refcube(lens[2]);           // ra는 lens[2]
        double c3 = refcube(rd);                // ra는 rd이며 side
        double c4 = refcube(*pd);               // ra는 *pd이며 side
        double c5 = refcube(edge);              // ra는 임시변수
        double c6 = refcube(7.0);               // ra는 임시변수
        double c7 = refcube(side + 10.0);       // ra는 임시변수

    매개변수 side, lens[4], rd, *pd는 이름을 가지고 있는 double형 데이터 객체이다.
    따라서 이들에 대한 참조 매개변수를 생성할 수 있으며, 임시 변수는 필요 없다.
    edge는 변수이긴 하지만 데이터형이 일치하지 않는다. 즉, double 형에 대한 참조로는
    long형을 참조할 수 없다. 그리고 매개변수 7.0과 side + 10.0 은 데이터형은 일치하지만
    이름을 가지고 있는 데이터 객체가 아니다. 이러한 경우, 컴파일러는 익명의 임시 변수를 만들고,
    ra로 하여금 그것을 참조하게 한다. 임시 변수는 함수가 호출되어 있는 동안 유지되지만,
    그 후에 컴파일러는 그것을 맘대로 없앨 수 있다. 

    그런데 이러한 행동이 상수 참조인 경우는 옳지만, 다른 경우는 옳지 않은 이뉴는 무엇일까?

        void swapr(int& a, int& b)
        {
            int temp{};

            temp = a;
            a = b;
            b = temp;
        }
    
    초창기의 C++에서 다음과 같이 했다면 무슨 일이 일어났을까?

        long a {3};
        lonng b{5};
        swapr(a,b);

    데이터 형이 일치하지 않으므로, 컴파일러는 두 개의 int형 임시 변수를 만들고
    그것들을 3, 5로 초기화한 후, 임시 변수의 내용을 서로 교환한다.
    그러므로 여기서 a와 b는 변경되지 않는다.

    간단히 말해서, 참조 매개변수를 가진 함수의 목적이 매개변수로 전달되는 변수를
    변경하는 것이라면, 임시 변수의 생성은 그 목적을 방해한다. 이것을 해결하는 방법은
    이러한 상황에서는 임시 변수의 생성을 허용하지 않는 것이다.

    이제 refcube()에 대해 생각해 보자. 이 함수의 의도는, 전달된 값의 변경이 아닌
    단순히 값만 사용하는 것이므로, 임시 변수가 전혀 문제를 일으키지 않는다.
    임시 변수는 오히려 그 함수가 좀 더 다양한 매개변수를 사용할 수 있도록 해 준다.
    그러므로 참조가 const로 선언되어 있으면, C++는 필요할 때 임시 변수를 생성한다.
    기본적으로, 형식 매개변수가 const 참조로 되어 있는 함수는,
    데이터형이 일치하지 않는 실제 매개변수를 전달 받았을 떄, 정보를 값으로 전달받는
    전통적인 방식, 즉, 임시 변수의 사용으로 원본 데이터를 변경하지 않는다.
        
    */
    #pragma endregion
    #pragma region 08.lvalue, rvalue, 그리고 const의 이점
    /*
    ---------------------------------------- 08.lvalue, rvalue, 그리고 const의 이점 ----------------------------------------
    함수 호출 실제 매개변수가 lvalue가 아니거나, 그에 대응하는 const 참조 매개변수의
    데이터형과 일치하지 않을 떄, C++는 정확한 데이터형의 익명 변수를 생성하고, 그 익명 변수에
    함수 호출 실제 매개변수의 값을 대입하고, 매개변수가 그 익명 변수를 참조하게 한다.

    C++11부터 rvalue 참조라고 부르는 두 번째 종류의 참조를 소개한다.
    rvalue를 참조할 떄 사용할 수 있으며 &&를 사용하여 다음과 같이 선언한다.

        double&& rref = sqrt(36.00);        // double &는 허용되지 않는다.
        double j = 15.0;
        double&& jref = 2.0 * j + 18.5;     // double &는 허용되지 않는다.
        cout << rref << '\n';               // 6.0을 출력한다.
        cout << jref << '\n';               // 48.5를 출력한다.

    rvalue 참조는 라이브러리 디자이너로 하여금 특정 기능을 더욱 효율적으로 구현할 수 있도록한다.
    18장에서는 move semantic이라 불리는 방법의 구현을 위해 rvalue 참조가
    어떻게 사용 되었는지를 살펴본다.

    **가능하면 const를 사용하자**
    참조 매개변수를 상수 데이터에 대한 참조로 선언하는 이유는, 다음과 같은 세 가지 이점 때문이다.
    
        * const를 사용하면, 실수로 데이터 변경을 일으키는 에러의 방지가 가능하다.
        * 원형에 const를 사용하면, 함수가 const와 const가 아닌 실제 매개변수를
          모두 처리할 수 잇지만, 원형에 const를 생략한 함수는 const가 아닌 데이터만 처리할 수 있다.
        * const 참조를 사용하면, 함수가 자신의 필요에 따라 임시 변수를 생성하여 사용할 수 있다.
    
    */
    #pragma endregion
    #pragma region 08.구조체에 대한 참조
    /*
    ---------------------------------------- 08.구조체에 대한 참조 ----------------------------------------
    참조는 C++의 사용자 정의 데이터형인 구조체나 클래스를 다루는데 아주 유용하다.
    구조체에 대한 참조를 사용하는 방법은, 기본 데이터형의 변수에 대한 참조를 선언할 때와 마찬가지로
    구조체 매개변수를 선언할 때 참조 연산자 &를 앞에 붙이면 된다.

        struct free_throws
        {
            string name{};
            int made{};
            int attemps{};
            float percent{};
        }

    위와 같은 형에 대하여 참조를 사용하는 함수는 다음과 같이 원형을 지닐 수 있다.

        void set_pc(free_throws& ft);               // 구조체에 대하여 참조를 사용한다.

    이 함수가 구조체를 변경하지 않으면 const를 사용할 수 있다.

        void display(const free_throws& ft);        // 구조체에 대하여 변경을 허용하지 않는다.

    다음 예시를 보자..

        //-------------------------[ ProtoType ]-----------------------------------//
        struct free_throws 
        {
            string name{};
            int made{};
            int attempts{};
            float percents{};
        };
        void display(const free_throws& ft);
        void set_pc(free_throws& ft);
        free_throws& accumulate(free_throws& target, const free_throws& source);
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
        // 부분 초기화 - 멤버는 0에 세팅된 상태로 남는다
            free_throws one{ "A", 1, 2 };
            free_throws two{ "B", 3, 4 };
            free_throws three{ "C", 5, 6 };
            free_throws four{ "D", 7, 8 };
            free_throws five{ "E", 9, 10 };
            free_throws team{ "ThrowGoods"};
        
        // 초기화하지 않음
            free_throws dup;
            set_pc(one);
            display(one);
            accumulate(team, one);
            display(team);
        
        // 리턴 값을 매개변수로 사용한다.
            display(accumulate(team, two));
            accumulate(accumulate(team, three), four);
            display(team);
        
        // 리턴 값을 대입 값으로 사용한다.
            free_throws dub = accumulate(team, five);
            cout << "team 출력 :\n";
            display(team);
            cout << "대입 이후 dup 출력 :\n";
            display(dup);
            set_pc(four);
        
        // 문제의 소지가 있는 대입
            accumulate(dup, five) = four;
            cout << "문제 소지가 있는 대입 이후 dup 출력 :\n";
            display(dub);
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        void display(const free_throws& ft)
        {
            cout << "Name : " << ft.name << '\n';
            cout << "Made : " << ft.made << '\t';
            cout << "Attempts : " << ft.attempts << '\t';
            cout << "Percent : " << ft.percents << '\n';
        }
        
        void set_pc(free_throws& ft)
        {
            if (ft.attempts != 0)
            {
                ft.percents = 100.0f * float(ft.made) / float(ft.attempts);
            }
            else
            {
                ft.percents = 0;
            }
        }
        
        free_throws& accumulate(free_throws& target, const free_throws& source)
        {
            target.attempts += source.attempts;
            target.made += source.made;
            set_pc(target);
            return target;
        }

    프로그램 실행 결과 :
        Name : A
        Made : 1        Attempts : 2    Percent : 50
        Name : ThrowGoods
        Made : 1        Attempts : 2    Percent : 50
        Name : ThrowGoods
        Made : 4        Attempts : 6    Percent : 66.6667
        Name : ThrowGoods
        Made : 16       Attempts : 20   Percent : 80
        team 출력 :
        Name : ThrowGoods
        Made : 25       Attempts : 30   Percent : 83.3333
        대입 이후 dup 출력 :
        Name :
        Made : 0        Attempts : 0    Percent : 0
        문제 소지가 있는 대입 이후 dup 출력 :
        Name : ThrowGoods
        Made : 25       Attempts : 30   Percent : 83.3333

    ## 왜 참조를 리턴하는가?
    전통적인 리턴 매커니즘과 참조를 리턴하는 것이 어떻게 다른지 알아보자.

    전통적인 리턴은 값을 기준으로 함수 매개변수를 통해 값을 전달하는 방식으로 동작한다.
    함수가 종료되면 리턴에 의해 그 값은 다시 호출한 함수로 전달된다.
    개념적으로, 이 값은 임시 장소에 복사되고 호출 프로그램은 이 값을 사용한다.
    다음의 내용을 보자..

        double m = squr(16.0);
        cout << squrt(25.0);

    첫 번째 구문에서 결과 값인 4.0은 임시 장소에 복사된다. 그런 다음,
    임시 장소에 있는 그 값은 m으로 복사된다. 두 번째 구문에서 결과 값인 5.0은
    임시 장소에 복사된 후, 그 임시 장소의 내용들이 cout으로 전달된다.

    다음 구문을 보자..
        
        dup = accumulate(team, five);

    만약 accumulate()가 어떤 구조체에 대한 래퍼런스 대신에, 구조체 자체를 리턴한다면
    전체 구조체를 임시 장소에 복사하고, 그 복사한 것을 dup에 복사할 것이다.
    하지만, 참조를 리턴으로 사용하는 경우, team은 직접적으로 dup에 복사되어
    보다 효율적인 방법이 될 수 있다.


    ## 참조를 리턴할 때 주의할 점
    참조를 리턴할 때 기억해야 할 가장 중요한 것은, 함수가 종료할 때, 수명이 함께
    끝나는 메모리 위치에 대한 참조를 리턴하지않도록 조심하는 것이다. 다음과 같은 코드를 사용하면 안된다.

        const free_throws& clone2(free_throws& ft)
        {
            free_throws newguy;         // 큰 에러의 첫 걸음
            newguy = ft;                // 정보를 복사한다.
            return newguy;              // 복사본에 대한 참조를 리턴한다.
        }

    이 코드는 함수가 종료될 때 함께 사라질 운명인 임시 변수(newguy)를 리턴한다.

    이 문제를 피하는 가장 간단한 방법은, 함수에 매개변수로 전달된 참조를 리턴하는 것이다.
    참조 배개변수는 호출 함수가 사용하는 데이터를 참조한다.

    새로운 저장소를 생성하기 위해서 new를 사용하는 두 번째 방법은 new의 사용이다.

        const free_throws& clone(free_throws& ft)
        {
            free_throws *pt;
            *pt = ft;                   // 정보를 복사한다.
            return *pt;              // 복사본에 대한 참조를 리턴한다.
        }
    
    이 코드는 언뜻 보면 구조체를 리턴하는 것처럼 보이지만, 함수 선언을 보면
    실제로는 구조체에 대한 참조를 리턴한다. 그러면 이제 이 함수를 다음과 같이 이용할 수 있다.

        free_throws& jolly = clone(three);

    이러한 접근은 반드시 메모리가 더 이상 필요 없을 때, new에 의한 메모리를 delete로 삭제해야 한다.
    그러나, clone() 호출이 new 호출을 안에 감추고 있으므로, 나중에 delete를 사용하는 것을
    잊어버릴 가능성이 높다. 16장에서 설명할 unique_ptr을 사용하면 그러한 삭제가 자동으로 이루어지게 할 수 있다.
    
    ## 참조를 리턴할 때 왜 const를 사용하는가
    일반적으로 모호한 코드는 에러를 일으킬 확률을 높이기에 설계할 때 모호한 코드를 추가하지 않는 것이 좋다.
    리턴형을 const 참조로 만드는 것은 프로그래머가 모호한 에러를 만들지 않는 좋은 방법이다.
    그러나 경우에 따라서 const를 쓰지 않는 것이 옳을 때도 있다. 11장에서 설명하는 오버로딩 연산자가 그것의 한 예이다.
    */
    #pragma endregion
    #pragma region 08.클래스 객체와 참조
    /*
    ---------------------------------------- 08.클래스 객체와 참조 ----------------------------------------
    일반적으로 C++는 클래스 객체를 함수에 전달할 때 참조를 사용한다.
    string 클래스를 사용하는 하나의 예제를 살펴보자. 이 예제는 서로 다른 설계를
    선택할 수 있음을 보여 준다. 이 선택들 중 어떤 것은 좋지 않다. 기본 아이디어는,
    주어진 문자열을 다른 문자열에 끝에 추가하는 함수를 만드는 것이다.

    다음 예제는 이것을 수행하는 세 개의 함수를 제공한다. 그러나, 이 함수들 중 하나는 결함이 있어
    프로그램을 먹통으로 만들거나 컴파일이 되지 않을 수도 있다.

        //-------------------------[ ProtoType ]-----------------------------------//
        string version1(const string& s1, const string& s2);
        const string& version2(string& s1, const string& s2);       // 부수 효과
        const string& version3(string& s1, const string& s2);       // 나쁜 설계
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            string input{};
            string copy{};
            string result{};
        
            cout << "문자열을 입력하시오 : ";
            getline(cin, input);
            copy = input;
            cout << "입력한 문자열 : " << input << endl;
            result = version1(input, "***");
            cout << "바뀐 문자열 : " << result << endl;
            cout << "원래 문자열 : " << input << endl;
        
            result = version2(input, "###");
            cout << "바뀐 문자열 : " << result << endl;
            cout << "원래 문자열 : " << input << endl;
        
            cout << "원래 문자열 재설정\n";
            input = copy;
            result = version3(input, "@@@");
            cout << "바뀐 문자열 : " << result << endl;
            cout << "원래 문자열 : " << input << endl;
        
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        string version1(const string& s1, const string& s2)
        {
            string temp{};
            
            temp = s2 + s1 + s2;
            return temp;
        }
        const string& version2(string& s1, const string& s2)
        {
            s1 = s2 + s1 + s2;
            return s1;
        }
        const string& version3(string& s1, const string& s2)
        {
            string temp;
        
            temp = s2 + s1 + s2;
            return temp;
        }

    프로그램 실행 결과 :
        문자열을 입력하시오 : It's not my fault
        입력한 문자열 : It's not my fault
        바뀐 문자열 : ***It's not my fault***
        원래 문자열 : It's not my fault
        바뀐 문자열 : ###It's not my fault###
        원래 문자열 : ###It's not my fault###
        원래 문자열 재설정
        바뀐 문자열 :                                // 실행 실패 시점
        원래 문자열 : It's not my fault

    함수 버전 1은 셋 중에서 가장 간단하다.
        
        string version1(const string& s1, const string& s2)
        {
            string temp{};

            temp = s2 + s1 + s2;
            return temp;
        }

    이 함수는 두 개의 string을 취하고, string 클래스 덧셈을 사용하여
    원하는 특성을 가진 새로운 문자열을 만든다. 두 매개변수가 const라는 점을 주목하라.
    이 함수는 다음과 같이 string 객체를 전달해도 동일한 결과를 낼 것이다.

        string version4(string s1, string s2);

    이 경우, s1, s2는 새로 만들어지는 객체가 될 것이다.
    그래서 참조를 사용하는 것이 새로운 객체를 만들 필요가 없고 불필요한 과정을 줄여 더 효율적이다.

    temp 객체는 version1() 함수에 지역적인 새로운 객체다. 이것은 함수가 종료될 때, 자신의 존재를 끝낸다.
    그래서 temp를 참조로 리턴하면 그 참조는 동작하지 않는다. 그래서 함수형이 string이다.
    이것은, temp의 내용이 임시 리턴 위치로 복사된 후, main()에서 그 리턴 위치의 내용이 result라는 이름의
    string으로 복사되는 것을 의미한다.

    version2() 함수는 임시 문자열을 만들지 않고, 원래 문자열을 직접 변경한다.

        const string& version2(string& s1, const string& s2)
        {
            s1 = s2 + s1 + s2;
            // 함수에 전달된 참조를 리턴하므로 안전하다.
            return s1;
        }
    
    s2와 달리 s1은 const를 사용하여 선언되지 않았기에 이 함수가 s1을 변경하는 것은 허용된다.

    s1이 main()에 있는 객체에 대한 참조이기에, s1을 참조로 리턴하는 것은 안전하다.
    s1이 input에 대한 참조이기에, 다음과 같은 행은

        result = version2(input,"###");

    실제로 다음과 동등하다.

        version2(input, "###");
        result = input;

    그러나, s1이 input에 대한 참조이기에, 이 함수를 호출하는 것은 input을 변경하는 부수효과를 가진다.

        원래 문자열 : It's not my fault.
        바뀐 문자열 : ###It's not my fault.###
        원래 문자열 : ###It's not my fault.###

    버전3는 하면 안되는 것이 무엇인지 보여준다.

        const string& version3(string& s1, const string& s2)
        {
            string temp;
        
            temp = s2 + s1 + s2;
            // 지역 변수에 대한 참조를 리턴하므로 안전하지 않다.
            return temp;
        }

    이것은 version#() 내에 지역적으로 선언된 변수에 대한 참조를 리턴하는 결함을 가진다.
    이 함수는, 컴파일 되지만 프로그램이 그 함수를 실행하려 할 때, 실패하거나 오류가 발생한다.
    구체적으로, 다음과 같은 코드에서 대입이 문제를 일으킨다.

        result = version3(input, "@@@");

    프로그램이 더 이상 사용되지 않는 메모리를 참조하려 시도하기 때문이다.
    */
    #pragma endregion
    #pragma region 08.또 하나의 객체 레슨 : 객체, 상속, 참조
    /*
    ---------------------------------------- 08.또 하나의 객체 레슨 : 객체, 상속, 참조 ----------------------------------------
    한 클래스에서 다른 클래스로 기능을 전달하는 것을 가능하게 하는 C++ 언어의 기능을 상속(Inheritance) 이라 부른다.
    상속이라는 강력한 기능에 대해선 13장 '클래스의 상속'에서 자세히 논의한다. 상속의 또 한가지 측면은,
    데이터형의 변환 없이 기초 클래스 참조가 파생 클래스 객체를 참조할 수 있다는 것이다.
    다음 예제는, 동일한 함수를 함수 호출 매개변수만 다르게 사용하여, 데이터를 파일에 쓰고
    화면상에도 디스플레이함으로써 이를 설명한다. 

        //-------------------------[ ProtoType ]-----------------------------------//
        void file_it(ostream& os, double fo, const double fe[], int n);
        const int LIMIT{ 5 };
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            ofstream fout;
            const char* fn = "ep=data.txt";
            fout.open(fn);
        
            if (!fout.is_open())
            {
                cout << fn << " 파일을 열 수 없습니다. 끝.\n";
                exit(EXIT_FAILURE);
            }
            double objective;
            cout << "대물렌즈 초점 거리를 mm 단위로 입력하십시오 : ";
            cin >> objective;
            double eps[LIMIT];
        
            cout << LIMIT << " 가지 대안렌즈의 초점거리를 mm단위로 입력하십시오 : \n";
        
            for (int i{}; i < LIMIT; i++)
            {
                cout << "대안렌즈 #" << i + 1 << ": ";
                cin >> eps[i];
            }
        
            file_it(fout, objective, eps, LIMIT);
            file_it(cout, objective, eps, LIMIT);
            cout << "종료\n";
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        void file_it(ostream& os, double fo, const double fe[], int n)
        {
            ios_base::fmtflags initial;
            initial = os.setf(ios_base::fixed);     // 초기 포멧팅 상태 저장
            os.precision(0);
            os << "대물렌즈의 초점 거리 : " << fo << "mm\n";
            os.setf(ios::showpoint);
            os.precision(1);
            os.width(17);
            os << "대안렌즈 초점거리";
            os.width(15);
            os << "확대 배율 " << endl;
            for (int i{}; i < n; i++)
            {
                os.width(17);
                os << fe[i];
                os.width(15);
                os << int(fo / fe[i] + 0.5) << endl;
            }
            os.setf(initial);                   // 초기 포멧팅 상태 복원
        }
        
    프로그램 실행 결과 :
        대물렌즈 초점 거리를 mm 단위로 입력하십시오 : 10
        5 가지 대안렌즈의 초점거리를 mm단위로 입력하십시오 :
        대안렌즈 #1: 1
        대안렌즈 #2: 2
        대안렌즈 #3: 3
        대안렌즈 #4: 4
        대안렌즈 #5: 5
        대물렌즈의 초점 거리 : 10mm
        대안렌즈 초점거리     확대 배율
                      1.0             10
                      2.0              5
                      3.0              3
                      4.0              3
                      5.0              2
        종료

    이 예제의 중요한 점은, ostream &형인 os 매개변수가 cout과 같은 ostream 객체와
    fout과 같은 ofstream 객체를 참조할 수 있다는 것이다.
    또한 이 프로그램은 두 가지 데이터형에 대해 ostream 포맷팅 메서드를 어떻게 사용할 수 있는지 설명한다.
    
    setf() 메서드는 다양한 포맷팅 상태를 설정할 수 있게 한다.
    setf(ios_base::fixed)는 고정 소수점 표기를 사용하는 모드에 객체를 놓는다.
    메서드 호출 setf(ios_base::showpoint)는 뒤따르는 숫자들이 0인 경우에도 뒤에 붙은 소수점을
    표시하는 모드에 객체를 놓는다. precision() 메서드는, 소수점의 오른쪽에 표시할 수 있는
    숫자들의 개수를 지정한다. 이 모든 설정들은 다른 메서드 호출에 의해 재설정될 때까지
    효력을 그대로 유지한다. width(0 호출은 다음 출력 동작에 사용할 필드 폭을 설정한다.
    이 설정은 하나의 값을 디스플레이 하는 데에만 사용되고, 디폴트로 다시 돌아간다.

    file_it() 함수는 흥미 있는 두 개의 메서드 호출을 사용한다.
    
        ios_base::fmtflags initial;
        initial = os.setf(ios_base::fixed);     // 초기 포멧팅 상태 저장
        ...
        os.setf(initial);                       // 초기 포멧팅 상태 복원

    setf() 메서드는 호출 하기 전, 유효한 모든 포멧팅 설정들의 복사본을 리턴한다.
    ios_base::fmtflags 는 이 정보를 저장하는데 필요한 데이터형의 장식적 이름이다.
    그래서 initial 에 대입하는 것은 file_it() 함수가 호출되기 전의 유효한 설정들을 저장한다.
    그러고 나서, initial 변수를 setf()에 매개변수로 사용하여 모든 포멧팅 설정을 리셋할 수 있다.

    결정적 요점 :
    각 객체는 자기 자신의 포맷팅 설정을 저장한다. 그래서 프로그램이 file_it()에 cout을 전달했을 때 cout의 설정이 변경되었다가 다시 원래 상태로 복원된다.
    프로그램이 file_it()에 fout을 전달했을 때 fout의 설정이 변경 되었다가 다시 원래 상태로 복원된다.
    */
    #pragma endregion
    #pragma region 08.참조 매개변수는 언제 사용하는가?
    /*
    ---------------------------------------- 08.참조 매개변수는 언제 사용하는가? ----------------------------------------
    참조 매개변수를 사용하는 주된 이유는 다음 두 가지이다.
        
        * 호출 함수에 있는 데이터 객체의 변경을 허용하기 위헤
        * 전체 데이터 객체 대신, 참조를 전달하여 프로그램의 속도를 높이기 위해
    
    두 번째 이유는 구조체나 클래스 객체와 같이 덩치 큰 데이터 객체를 다룰 때 가장 중요하다.
    위의 두가지 이유는 포인터를 매개변수로 사용하는 것과 같은 이유이다.
    사실상 참조 매개변수는 포인터를 사용하도록 짜여진 코드의 또 다른 인터페이스이기 때문에,
    이것은 이치에 맞는다. 그렇다면 참조는 언제 사용하는가? 포인터는 언제 사용하는가?
    값으로 전달은 언제 사용하는가? 다음은 이를 위한 몇 가지 지침이다.

    함수가 전달된 데이터를 변경하지 않고 사용만 하는 경우 :
        * 데이터 객체가 기본 데이터형이나 작은 구조체라면 값으로 전달한다.
        * 데이터 객체가 배열이라면 포인터가 유일한 선택이므로 포인터를 사용한다. 
          포인터를 const를 지시하는 포인터로 만든다.
        * 데이터 객체가 덩치 큰 구조체라면 const 포인터나 const 참조를 사용하여
          프로그램의 속도를 높인다. 이것은 구조체나 클래스 설계를 복사하는데 드는
          시간과 공간을 절약한다. 포인터나 참조를 const로 만든다
        * 데이터 객체가 클래스 객체라면 const 참조를 사용한다. 클래스 설계 자체가
          흔히 참조를 사용할 것을 요구한다. 이것이 C++에 const 기능을 추가한
          주된 이유이기도 하다. 클래스 객체 매개변수의 전달은 참조로 전달하는 것이 표준이다.

    함수가 호출 함수의 데이터를 변경하는 경우 :
        * 데이터 객체가 기본 데이터형이면 포인터를 사용한다. fixit(&x)와 같은 코드가 있다면
          (여기서 x는 int형), 이 함수의 목적은 x를 변경하려는 것이 분명하다.
        * 데이터 객체가 배열이면 유일한 선택은 포인터를 사용하는 것이다.
        * 데이터 객체가 구조체이면 참조 또는 포인터를 사용한다.
        * 데이터 객체가 클래스 객체면 참조를 사용한다.
     
    이것은 단지 지침일 뿐이다. 다른 방식을 사용한다면, 그 나름대로 이유가 있을 것이다.
    예를 들어, cin은 cin >> &n 대신, cin >> n 을 사용할 수 있도록 기본 형에 대한 참조를 사용한다.
    */
    #pragma endregion
    #pragma region 08.디폴트 매개변수
    /*
    ---------------------------------------- 08.디폴트 매개변수 ----------------------------------------
    C++에 새로 추가된 기능인 디폴트 매개변수를 살펴보자.
    디폴트 매개변수는 함수 호출에서 실제 매개변수를 생략했을 경우 실제 매개변수 대신 사용되는 값이다.
    예를 들어, void wow(int n)에서 n이 1로 내정되도록 디폴트 값을 지정했다면,
    wow()는 wow(1)과 같다. 디폴트 매개변수는 함수 사용에 매우 큰 융통성을 부여한다.
    
    디폴트 값은 어떻게 설정하는가? 함수 원형을 사용해야 한다. 컴파일러는 함수 원형을 살펴보고
    그 함수가 몇 개의 매개변수를 사용하는지를 알아내므로, 함수 원형이 디폴트 매개변수의 존재 여부를
    프로그램에게 알려주어야 한다. 다음은 이것을 설명하는 left() 함수의 원형이다.

        char* left(const char* str, int n{1} );

    함수가 새로운 문자열을 리턴하므로 그것의 데이터형은 char*, 즉 문자를 지시하는 포인터여야한다.
    원본 문자열은 변경하지 않을 생각이므로 첫 번째 매개변수에 const 제한자를 사용하여야 한다.
    그리고 n이 1이라는 디폴트 값을 가져야 하므로 n에 1을 대입한다. 디폴트 매개변수의 디폴트 값은 초기화 값이다.
    그러므로 앞에 제시한 함수 원형은 n을 1이라는 값으로 초기화한다. 따라서 n을 그대로 두면 n은 1이라는 값을 가진다.
    그러나 매개변수를 전달하면 새로운 값이 1을 대체한다.

    매개변수 리스트를 사용할 때에는 디폴트 매개변수를 오른쪽에서 왼쪽의 순서로 첨가해야 한다.
    즉, 어떤 매개변수를 디폴트 매개변수로 만드려면, 그 매개변수보다 오른쪽에 있는 모든 매개변수를 디폴트 매개변수로 만들어야 한다.

        int harpo(int n, int m = 4, int j = 5);         // 맞다
        int chico(int n, int m = 6, int j);             // 틀리다
        int groucho(int k = 1, int m = 2, int n = 3)    // 맞다

    실제 매개변수는 왼쪽에서 오른쪽으로 가면서 해당하는 형식 매개변수에 대입된다.
    매개변수를 건너 뛸 수는 없다. 즉, 다음은 허용되지 않는다.

        beeps = harpo(3,,8);                            // 틀리다, m을 4로 설정하지 않는다.

    디폴트 매개변수는 기술의 발전이 아닌 편리한 도구일 뿐이다. 다음 예제를 보자

        //-------------------------[ ProtoType ]-----------------------------------//
        const int ArSize = 80;
        char* left(const char* str, int n = 1);
        
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            char sample[ArSize];
            cout << "문자열을 입력하시오 : \n";
            cin.get(sample, ArSize);
            char* ps = left(sample, 4);
            cout << ps << endl;
            delete[] ps;
            ps = left(sample);
            cout << ps << endl;
            delete[] ps;
            
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        char* left(const char* str, int n)
        {
            if (n < 0)
            {
                n = 0;
            }
            char* p = new char[n + 1];
            int i{};
            for (i = 0; i < n && str[i]; i++)
            {
                p[i] = str[i];                  // 문자들을 복사한다
            }
            while (i <= n)
            {
                p[i++] = '\0';                  // 문자열의 나머지를 '\n'으로 설정한다
            }
            return p;
        }

    프로그램 실행 결과 :
        문자열을 입력하시오 :
        forthcoming
        fort
        f
    
        
        i < n && str[i]

    i < n 이라는 조건 검사는 루프가 n개의 문자를 복사한 후 중단한다는 것을 의미한다.
    조건 검사의 두 번째 부분은 str[i] 라는 표현식이다. 이것은 복사될 문자의 코드이다.
    루프가 널 문자에 도달하면 그 문자 코드가 0이 되어 루프를 탈출한다.
    마지막에 있는 while 루프는 새로운 문자열을 널 문자로 종결시킨다. 그러고도 대입된 
    메모리가 남아 있다면, 모두 널 문자로 설정한다.

    새 문자열의 크기를 정하는 또 하나의 방법은 n을, 전달된 값과 문자열의 길이를 비교하여 더 작은 값으로 지정하는 것이다.

        int len = strlen(str);
        n = (n < len)? n : len;
        char* p = new char[n+1];

    이렇게 하면, new가 새 문자열을 저장하는데 꼭 필요한 만큼의 공간만 대입한다.
    이것은 left("HI!", 32767)과 같은 함수 호출이 발생했을 떄 유용하다.
    앞에서 다룬 첫번째 방법은 Hi! 를 32767 크기의 배열의 복사하고
    처음 세 문자를 제외한 나머지 모든 공간을 널 문자로 설정한다.
    그러나 방금 다룬 방법은, Hi! 를 고작 네 문자 크기의 배열에 복사한다.
    그러나 strlen()을 호출함으로써 프로그램의 덩치가 커지고 처리속도가 느려진다.
    또한, cstring 헤더 파일의 포함이 요구된다. C++에서는 신뢰성을 더 중시한다.
    조금 느리더라도 정확하게 작동하는 프로그램이 빠르기만한 프로그램보다는 훨씬 낫다.
    */
    #pragma endregion
    #pragma region 08.함수 오버로딩
    /*
    ---------------------------------------- 08.함수 오버로딩 ----------------------------------------
    함수의 다형(Polymorphism)은 C++에 새로 추가된 기능이다.
    디폴트 매개변수는 매개변수의 개수를 다르게 사용함으로써 같은 함수를 호출하는 반면,
    함수 오버로딩(Function Overloading)은 서로 다른 여러 개의 함수가 하나의 이름을 공유하는 것이다.
    여기서 '다형' 이라는 말은, 다양한 형태를 가진다는 뜻이다. 이와 비슷하게, '함수 오버로딩' 이라는 표현은
    여러 개의 함수를 같은 이름으로 연결한다는 뜻이다. 즉, 이름을 오버로딩 하는 것이다. 함수 오버로딩은,
    본질적으로는 같은 일을 처리하지만, 매개변수 리스트가 서로 다른 여러 개의 함수를 하나의 이름으로
    만들 수 있게 해준다. 

    함수 오버로딩의 열쇠는 함수의 매개변수 리스트이다. 이것을 함수 시그니쳐(Function Signature)라고 한다.
    만약, 두 함수가 같은 개수, 같은 데이터형의 매개변수를 가지고 있고, 매개변수의 순서까지 동일하다면,
    두 함수의 시그니처는 같다. 이때 변수의 이름은 달라도 상관 없다.
    다음 예제를 보자..

        void print(const char* str, int width);             // #1
        void print(double d, int width);                    // #2
        void print(long l, int width);                      // #3
        void print(int i, int width);                       // #4
        void print(const char* str);                        // #5
    ---------------------------------------------------------------
        print("Pancakes", 15);                              // #1 사용
        print("Syrup");                                     // #5 사용
        print(1999.0, 10);                                  // #2 사용
        print(1999, 12);                                    // #4 사용
        print(1999L, 15);                                   // #3 사용

    오버로딩된 함수를 사용할 때에는, 함수 호출에서 올바른 데이터형의 매개변수를 사용하는지 확인해야 한다.

        unsigned int year = 3210;
        print(year, 6);                 // 모호한 함수 호출이다.

    print() 함수의 이러한 호출은 대응하는 원형이 없다. 대응하는 원형이 없을 경우,
    C++는 표준적인 데이터형 변환을 시도하여 어떻게든 대응이 이루어지도록 노력하기에, 여러 원형 중에서
    어느 것이 사용될지 장담할 수 없다.

    시그니처들은 서로 다른 것처럼 보이더라도 함께 공존할 수 없다. 예를 들어, 다음과 같은 두 원형을 생각해보자.

        double cube(double x);
        double cube(double& x);

    여기에서 함수 오버로딩을 사용할 수 있으리라고 잘못 생각할 수 있다. 왜냐하면 함수 시그니처가 서로 달라 보이기 때문이다.
    그러나 모든 것을 컴파일러 입장에서 생각해야 한다. 다음과 같은 코드가 있다고 가정해 보자.

        cout << cube(x);

    매개변수 x는 double x를 사용하는 원형이나 double& x를 사용하는 원형에 둘 다 일치한다. 컴파일러는
    어느 함수를 사용해야 할지 알지 못한다. 그러므로 컴파일러는 함수 시그니처를 검사할 때,
    그러한 혼동을 피하기 위해, 어떤 데이터형에 대한 참조와 그 데이터형 자체를 같은 시그니처로 간주한다.

    대응하는 함수를 찾는 과정에서 const와 const가 아닌 변수는 구분된다. 다음 예제를 보자.

        void dribble(char* bits);           // #1 오버로딩 된다
        void dribble(const char* cbits);    // #2 오버로딩 된다 
        void dabble(char* bits);           // #3 오버로딩 되지 않는다
        void drivel(const char* bits);     // #4 오버로딩 되지 않는다

    함수 오버로딩을 가능하게 하는 것은 함수의 데이터형이 아닌 시그니처라는 사실을 명심하라.
    예를 들어, 다음 두 선언은 함께 공존할 수 없다.

        long gronk(int n, float m);             // 같은 시그니처이므로
        double gronk(int n, float m);           // 공존할 수 없다.

    함수 시그니처가 다른 경우에만 다른 리턴형을 가질 수 있다.

        long gronk(int n, float m);             // 서로 다른 시그니처이므로
        double gronk(float n, float m);         // 공존할 수 있다.

		***
		출처 : C++ 기초 플러스 6판 / 성안당
		***
    */
    #pragma endregion
    #pragma region 08.오버로딩 예제
    /*
    ---------------------------------------- 08.오버로딩 예제 ----------------------------------------
    이 장에서 우리는, 어떤 문자열에서 처음 n개의 문자를 취하여 리턴하는 elft() 함수를 만들었다.
    이제 어떤 정수에서 처음 n자리의 숫자를 취하여 리턴하는 또 다른 left() 함수를 만들어보자.

    정수 처리 함수는 문자열 처리 함수에 비해 약간 어렵다. 왜냐하면 정수는 각각의 자리가 배열 원소에 하나씩
    저장되어 있지 않기 때문이다. 이것을 해결하는 한 가지 방법은, 정수를 나타내는 숫자가 몇 개인지 먼저
    카운트 하는 것이다. 어떤 수를 10으로 나누면 하나의 숫자가 떨어져 나간다. 그러므로 나눗셈을 이용하여
    그 정수를 나타내는 숫자가 몇 개인지 카운트 할 수 있다.

        usgined digits{1};
        while (n /= 10)
        {
            digits++;
        }

    이 루프는 아무것도 남지 않을 때까지 n으로부터 몇 개의 숫자를 제거할 수 있는지 카운트한다.
    n /= 10은 n = n/10보다 간결하다. 만일 n이 8이면, 8/10이 되고, 정수 나눗셈이므로 n에 0이 대입된다.
    그럼 즉각 루프를 탈출하고 digits에는 1이 남는다. 이제 정수가 5자리의 숫자이고, 처음 세 자리를
    리턴하기를 원한다고 가정하자. 그 정수를 10으로 나눈 결과를 다시 한 번 10으로 나누면 구할 수 있다.
    10으로 나눌 때마다 오른쪽 끝 자리가 떨어져 나가기 때문이다. 잘라버릴 숫자 개수는
    전체 숫자 개수에서 알고 싶은 숫자 개수를 빼면 된다. 예를 들어, 전체가 9자리인데 앞의 네 자리를 알고 싶다면
    끝에 5자리를 잘라버리면 된다.

        ct = digits - ct;
        while(ct--)
        {
             num /= 10;
        }
        return num;

    다음 예제를 보자..

        //-------------------------[ ProtoType ]-----------------------------------//
        unsigned long left(unsigned long num, unsigned ct);
        char* left(const char* str, int n = 1);
        
        //-------------------------[   FBody   ]-----------------------------------//   
        int main()
        {
            char trip[80] = "Hawaii!!";
            char* ptrip = trip;
            unsigned long n = 12345678;
            int i{};
            char* temp;
            
            for (int i{ 1 }; i < 10; i++)
            {
                cout << left(n, i) << endl;
                temp = left(ptrip, i);
                cout << temp << endl;
                delete[] temp;
            }
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        unsigned long left(unsigned long num, unsigned ct)
        {
            unsigned digits = 1;
            unsigned long n = num;
        
            if (ct == 0 || num == 0)
            {
                return 0;                   // 숫자가 없으면 0을 리턴
            }
        
            while (n /= 10)
            {
                digits++;
            }
            if (digits > ct)
            {
                ct = digits - ct;
                while (ct--)
                {
                    num /= 10;
                }
                return num;                 // 남아 있는 ct개의 숫자를 리턴
            }
        
            else
            {
                return num;                 // 'ct >= 전체 숫자 개수' 이면
            }                               // 그 정수 자체를 리턴
        }
        
        char* left(const char* str, int n)
        {
            if (n < 0)
            {
                n = 0;
            }
            char* p = new char[n + 1];
            int i{};
            for (i; i < n && str[i]; i++)
            {
                p[i] = str[i];
            }
            while (i<=n)
            {
                p[i++] = '\0';
            }
            return p;
        }

    프로그램 실행 결과 : 
        1
        H
        12
        Ha
        123
        Haw
        1234
        Hawa
        12345
        Hawai
        123456
        Hawaii
        1234567
        Hawaii!
        12345678
        Hawaii!!
        12345678
        Hawaii!!
    */
    #pragma endregion
    #pragma region 08.함수 오버로딩은 언제 사용하는가?
    /*
    ---------------------------------------- 08.함수 오버로딩은 언제 사용하는가? ----------------------------------------
    함수 오버로딩은 서로 다른 데이터형을 대상으로 하지만, 기본적으로는 같은 작업을 수행하는 함수들에만 사용하는 것이 바람직하다.
    또한 독자는 디폴트 매개변수를 사용하여 같은 목적을 수행할 수 있는지 확인하는 것이 좋다.
    
        char* lef(const* str, unsigned n);          // 두 개의 매개변수
        char* left(const char* str);                // 한 개의 매개변수

    디폴트 매개변수를 사용하는 하나의 함수를 사용하는 것이 더 간단하다. 함수를 단지 하나만 작성하면 되고,
    프로그램도 하나의 함수를 저장하기 위한 메모리만 요구한다. 그리고 함수를 수정할 필요가 생겼을 때도 하나의 함수만 수정하면 된다.
    그러나 서로 다른 데이터형의 매개면수를 요구하고 디폴트 매개변수가 소용이 없을 땐, 함수 오버로딩을 사용해야 한다.
    */
    #pragma endregion
    #pragma region 08.함수 템플릿
    /*
    ---------------------------------------- 08.함수 템플릿 ----------------------------------------
    함수 템플릿은 함수의 일반화 서술이다. 즉, 함수 템플릿은 int형이나 double형과 같은 구체적인 데이터형을 포괄할 수 있는
    일반형으로 함수를 정의한다. 어떤 데이터형을 템플릿에 매개변수로 전달하면, 컴파일러가 그 데이터형에 맞는 함수를 생성한다.
    이것을 일반화 프로그래밍(Generic Programming) 이라고 한다.
    데이터형이 매개변수에 의해 표현되므로, 템플릿을 때로는 매개변수화 데이터형(Parameterized Type)이라고 한다.

    우리는 전 장에서 두 개의 int형을 교환하는 함수를 정의했다. 이번엔 두 개의 double 값을 교환하는 함수를 정의한다고 가정하자. 
    이것을 해결하는 방법은, 기존에 만든 int 값 교환함수에서 int를 double로 각각 바꿔주는 방법이 있다.
    두 개의 char 값을 교환해야 할 때에도 이와 똑같은 방법을 사용할 수 있다.
    상황이 발생할 때마다 매번 이런 식으로 데이터형을 바꾼다는 것은 귀중한 시간을 낭비할 뿐만 아니라 실수를 저지를 위험도 있다.

    C++의 함수 템플릿 기능은 이 과정을 자동화하여 시간을 절약하고 코드의 신뢰성을 높여준다.
    함수 템플릿은 임의 데이터형으로 함수를 정의하는 것을 허용한다. 예를 들면, 두 변수의 값을 교환하는 다음과 같은 템플릿을 설정할 수 있다..
        
        template <class T>
        void swap(T &a, T &b)
        {
            T temp{};
            temp = a;
            a = b;
            b = temp;
        }

    첫 번째 행은 템플릿을 설정하고, 임의 데이터형의 이름을 T로 정한다는 뜻이다.
    키워드 template와 class(class 대신 typename을 사용해도 된다.)를 반드시 사용해야 한다.
    또한 각진 괄호를 사용해야 한다. 나머지 코드는 T형의 두 값을 교환하는 알고리즘을 서술한다.
    이 템플릿은 함수를 만드는 것이 아닌 함수를 정의하는 방법을 컴파일러에게 알려 주는 것이다.
    다음 예제를 보자..

        //-------------------------[ ProtoType ]-----------------------------------//
        template<typename T>
        void Swap(T &a, T &b);
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            int i{ 10 };
            int j{ 20 };
            cout << "i, j = " << i << ", " << j << ".\n";
            cout << "컴파일러가 생성한 int형 덧셈기를 사용하면\n";
            Swap(i,j);
            cout << "이제 i, j = " << i << ", " << j << ".\n";
        
            double x{ 24.5 };
            double y{ 81.7 };
            cout << "x, y = " << x << ", " << y << ".\n";
            cout << "컴파일러가 생성한 double형 교환기를 사용하면\n";
            Swap(x, y);
            cout << "이제 x, y = " << x << ", " << y << ".\n";
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        template <typename T>
        void Swap(T &a, T &b)
        {
            T temp;
            temp = a;
            a = b;
            b = temp;
        }
    
    프로그램 실행 결과 :
        i, j = 10, 20.
        컴파일러가 생성한 int형 덧셈기를 사용하면
        이제 i, j = 20, 10.
        x, y = 24.5, 81.7.
        컴파일러가 생성한 double형 교환기를 사용하면
        이제 x, y = 81.7, 24.5.
    */
    #pragma endregion
    #pragma region 08.템플릿의 오버로딩
    /*
    ---------------------------------------- 08.템플릿의 오버로딩 ----------------------------------------
    모든 데이터형이 항상 같은 알고리즘을 사용할 리는 없기에, 일반적 오버로딩처럼 템플릿의 정의를 오버로딩 할 수 있다.
    다음 예시를 보자..

    //-------------------------[ ProtoType ]-----------------------------------//
    template<typename T>
    void Swap(T &a, T &b);

    template<typename T>
    void Swap(T *a, T *b, int n);

    void Show(int a[]);

    const int Lim{ 8 };

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        int i{ 10 };
        int j{ 20 };
        cout << "i, j = " << i << ", " << j << ".\n";
        cout << "컴파일러가 생성한 int형 덧셈기를 사용하면\n";
        Swap(i,j);
        cout << "이제 i, j = " << i << ", " << j << ".\n";

        int d1[Lim]{1, 2, 3, 4, 5, 6, 7, 8};
        int d2[Lim]{2, 4, 6, 8, 10, 12, 14, 16 };
        cout << "원본 배열 : \n";
        Show(d1);
        Show(d2);
        Swap(d1, d2, Lim);
        cout << "교환된 배열 :\n";
        Show(d1);
        Show(d2);

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    template <typename T>
    void Swap(T &a, T &b)
    {
        T temp;
        temp = a;
        a = b;
        b = temp;
    }

    template<typename T>
    void Swap(T a[], T b[], int n)
    {
        T temp;
        for (int i{}; i < n; i++)
        {
            temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }

    void Show(int a[])
    {
        cout << a[0] << a[1] << "/";
        cout << a[2] << a[3] << "/";
        for (int i{ 4 }; i < Lim; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }

프로그램 실행 결과 :
    i, j = 10, 20.
    컴파일러가 생성한 int형 덧셈기를 사용하면
    이제 i, j = 20, 10.
    원본 배열 :
    12/34/5678
    24/68/10121416
    교환된 배열 :
    24/68/10121416
    12/34/5678
    */
    #pragma endregion
    #pragma region 08.템플릿 제한
    /*
    ---------------------------------------- 08.템플릿 제한 ----------------------------------------
    다음과 같은 템플릿 함수가 있다고 가정해 보자.

        template <Class T>
        void f(T a, T b)
        (...)

    종종 코드에서 형에 따라 어떠한 연산이 가능할 것인지에 대한 가정을 한다.
    예를 들면, 다음 구문처럼 대입이 정의되고 있고, T형이 built-in 배열형이라면 해당 구문은 참이 아니다.

        a = b;

    이와 유사하게 다음 구문은 >가 정의되었다고 가정하지만, T가 일반 구조체라면 참이 아니다.

        if(a > b)

    또한 > 연산자는 배열 이름으로 정의되지만, 배열 이름은 주소이기 때문에 배열의 주소를 비교한다.
    따라서 사용자가 의도하는 바와 다를 수 있다. 다음의 구문은 곱셈 연산자가 T형으로 정의된 경우인데,
    T가 배열이나 포인터 또는 구조체인 경우에는 해당되지 않는다.

        T c = a * b;

	어던 형을 다루지 않는 템플릿 함수를 사용하는 것은 쉬운 작업이다. 한편 C++ 구문이 허용하지 않아도
	템플릿 함수를 일반화 하는 것이 때론 이치에 맞다. 예로, + 연산자가 구조체에는 적용되지 않더라도
	구조체를 재편성 하도록 연산자를 재정의하는 것은 괜찮을 수 있다.
	이러한 연산자의 오버로드는 11장에서 다룬다.
    */
    #pragma endregion
    #pragma region 08.명시적 특수화
    /*
    ---------------------------------------- 08.명시적 특수화 ----------------------------------------
    다음과 같은 구조체를 정의한다고 가정하자.

        struct job
        {
            char name[40];
            double salary{};
            int floor{};
        }

    이러한 구조체 두 개를 만들고 두 구조체의 내용을 교환하려 한다. 원본 템플릿은 다음과 같은
    코드를 사용하여 내용을 교환한다.

        temp = a;
        a = b;
        b = temp;

    C++에서는 하나의 구조체를 다른 하나의 구조체에 대입할 수 있기 때문에, Any형이 job 구조체인 경우도 코드는 동작한다.
    그러나 salary와 floor 멤버만 교환하고, name 멤버는 그대로 두고 싶다고 가정하자.
    이 경우는, 이제 코드가 달라져야 한다. 그러나 Swap()에 넘겨주는 매개변수는 첫 번째 경우와 같아야한다.
    그렇다면 새로운 코드에 템플릿 오버로딩을 사용할 수 없다.

    그러나 명시적 특수화(Explicit Specialization)라는 특수화된 함수 정의를, 필요한 코드와 함께 제공할 수 있다.
    컴파일러가 함수 호출에 정확히 대응하는 특수화된 정의를 발견하면, 템플릿을 찾기 않고 그 정의를 사용한다.
    이러한 특수화 형식은 C++가 발전하면서 계속 변화해 왔다.

    **3세대 특수화**
    특수화 방식을 모두 실험한 후, C++98 표준은 이 방식을 다음과 같이 정립하였다.

        * 함수 이름이 하나 주어지면, 사용자는 템플릿이 아닌 함수, 템플릿 함수, 명시적 특수화 템플릿 함수를 가질 수 있다.
          또한, 이 모든 것들의 오버로딩 버전도 가질 수 있다.
        * 명시적 특수화를 위한 원형과 정의 앞에 template <>가 와야한다. 그리고 특수형의 이름을 서술해야 한다.
        * 특수화는 템플릿을 무시하고, 템플릿이 아닌 함수는 특수화와 템플릿 둘 다 무시한다.
    
    다음은 job형 구조체를 교환하는 세 가지 형식의 함수 원형이다.

        // 템플릿이 아닌 함수 원형
        void Swap(job &, job &);

        // 템플릿 원형
        template <typename T>
        void Swap(T &, T &);

        // job형을 위한 명시적 특수화
        template <> void Swap<job>(job&, job&);
    ------------------------------------------------------------------------------

        template <Class T>
        void Swap(T &, T &);

        // job 형에 대한 명시적 특수화
        template <> void Swap<job>(job&, job&);
        int main()
        {
            double u, v;
            ...
            Swap(u, v);     // 템플릿 사용
            job a, b;
            ...
            Swap(a,b);      // void Swap<job>(job&, job &) 사용
        }

    이것이 job을 위한 특수화라는 것을 함수 매개변수의 데이터형이 알려주기에,
    Swap<job>에 있는 <job>은 생략할 수 있다. 그러므로 원형도 다음처럼 간단히 나타낼 수 있다.

        template<> void Swap(job&, job&);
    */
    #pragma endregion
    #pragma region 08.명시적 특수화 예제
    /*
    ---------------------------------------- 08.명시적 특수화 예제 ----------------------------------------
        //-------------------------[ ProtoType ]-----------------------------------//
        template <typename T>
        void Swap(T& a, T& b);
        
        struct job
        {
            char name[40]{};
            double salary{};
            int floor{};
        };
        
        //명시적 특수화
        template <> void Swap<job>(job& j1, job& j2);
        
        void Show(job& j);
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            cout.precision(2);
            cout.setf(ios::fixed, ios::floatfield);
            
            int i{ 10 };
            int j{ 20 };
        
            cout << "i, j = " << i << ", " << j << ".\n";
            cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
            Swap(i, j);
            cout << "이제 i, j = " << i << ", " << j << ".\n";
        
            job sue = { "Susan", 73000.60, 7 };
            job sidney = { "sidney", 78000.00, 9 };
            cout << "job 교환 전 : \n";
            Show(sue);
            Show(sidney);
            Swap(sue, sidney);
        
            cout << "job 교환 후 : \n";
            Show(sue);
            Show(sidney);
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        template <typename T>
        void Swap(T &a, T &b)
        {
            T temp;
            temp = a;
            a = b;
            b = temp;
        }
        
        template<> void Swap<job>(job& j1, job& j2)
        {
            double t1;
            int t2;
            t1 = j1.salary;
            j1.salary = j2.salary;
            j2.salary = t1;
            t2 = j1.floor;
            j1.floor = j2.floor;
            j2.floor = t2;
        }
        
        void Show(job& j)
        {
            cout << j.name << ": (" << j.floor << "층에 거주)" << "$" << j.salary << endl;
        }
    */
    #pragma endregion
    #pragma region 08.구체화와 특수화
    /*
    ---------------------------------------- 08.구체화와 특수화 ----------------------------------------
    소스 코드에 함수 템플릿을 넣는다고 해서 함수 정의가 저절로 생성되는 것은 아니다.
    그것은 단지 함수 정의를 생성할 계획을 세우는 것에 불과하다. 컴파일러가 특정 데이터형에 맞는 함수 정의를
    생성하기 위해 템플릿을 사용할 떄, 그 결과를 템플릿의 구체화(Instantiation)이라고 한다. 이전 예제에서
    Swap(i,j) 함수 호출은, 컴파일러가 int형을 사용하는 Swap()을 구체화하게 만든다.
    템플릿은 함수 정의가 아니며, int형을 사용하는 특정 구체화가 함수 정의다. 이러한 구체화를
    암시적 구체화(implicit Instantiation) 이라고 한다. 그 이유는, 프로그램이 int형 매개변수를 요구하는
    Swap() 함수를 사용한다는 사실을 컴파일러에게 알림으로써, 그에 맞는 함수 정의를 만들 필요가 있다는 것을
    컴파일러가 암시적으로 인식하기 때문이다. 지금은 C++가 명시적 구체화(Explicit instantiation)도 허용한다.
    이것은 컴파일러가 Swap<int>() 와 같은 특정 구체화를 생성하도록 사용자가 지시할 수 있는 것을 의미한다.

        template void Swap<int>(int, int);          // 명시적 구체화

    명시적 구체화를 명시적 특수화와 서로 비교해보자. 명시적 특수화는 다음 두 선언 중 어느 하나를 사용한다.

        template <> void Swap<int>(int &, int &);
        template <> void Swap(int &, int &);

    이 선언들은 함수 정의를 생성하기 위해 Swap() 템플릿을 사용하지 말고, int형에 맞게 특별히 명시적으로
    정의된 함수 정의를 사용하라. 는 것을 의미한다. 명시적 특수화 선언은
    키워드 template 뒤에 <>를 가지는 반면에, 명시적 구체화는 <>를 생략한다

    명시적 구체화는 프로그램에서 함수를 사용하여 생성할 수 있다. 예를 들면, 다음의 내용을 생각해 볼 수 있다.

        template <class T>
        T Add(T a, T b)
        {
            return a+b;
        }
        ...
        int m = 6;
        double x = 10.2;
        cout << Add<double>(x, m);      // 명시적 구체화

    이 템플릿은 함수 호출(x,m)와 매치되지 않을 것이다. 매개변수가 서로 다르기 때문이다.
    그러나 Add<double> (x,m) 을 사용하게 되면 double 구체화를 강요하게 되고
    매개변수 m은 double형의 cast로서, 두 매개변수가 일치하게 된다.

        template <class T>
        void Swap(T &, T &);        // 템플릿 원형

        template <> void Swap<job>(job &, job &);           // job을 위한 명시적 특수화
        int main()
        {
            template void Swap<char>(char &, char&);        // char를 위한 명시적 구체화
        
            short a, b;
            ...
            Swap(a, b);                                         // short를 위한 암시적 템플릿 구체화
            job n, m;
            ...
            Swap(n, m);                                         // job을 위한 명시적 특수화
            char g,h;
            ...
            Swap(g,h);                                          // char를 위한 명시적 템플릿 구체화
            ...
        }



    */
    #pragma endregion
    #pragma region 08.컴파일러는 어느 함수를 선택할까?
    /*
    ---------------------------------------- 08.컴파일러는 어느 함수를 선택할까? ----------------------------------------
    함수 오버로딩, 템플릿, 템플릿 오버로딩 등이 있기 때문에, 어느 함수 정의를 사용할 것인지 C++는 전략을 가지고 있다.
    이러한 전략을 오버로딩 분석(Overloading Resolution) 이라 한다.

        * 1단계 : 후보 함수들의 목록을 만든다. 호출 함수와 이름이 동일한 함수와 템플릿들이다.
        * 2단계 : 후보 중, 계속 존속하는 함수들의 목록을 만든다. 매개변수의 개수가 일치하는 함수들이다.
                  이들에 대해서 암시적 변환 절차가 이루어진다. 실제 매개변수의 각 데이터형이, 대응하는 형식
                  매개변수의 데이터형과 정확하게 일치하는 경우도 포함한다. float가 double형으로 변환 될 수 있는 것 같은 예이다.
        * 3단계 : 가장 적당한 함수가 있는지 판단한다. 그런 함수가 없다면 함수 호출은 에러로 간주한다.
    
    C++는 정확한 대응을 만들기 위해 몇 가지 사소한 변환 ( Trival Conversion )을 허용한다.
    9장에서는 volatile이라는 키워드도 설명한다.

    **부분순서화 규칙을 설명하는 예제**
    다음 예제는 어떤 템플릿 정의를 사용할 것인지 결정하는 부분순서화 규칙을 나타내는 프로그램이다.

        //-------------------------[ ProtoType ]-----------------------------------//
        template <typename T>
        void ShowArray(T arr[], int n);             // 템플릿 A
        
        template <typename T>
        void ShowArray(T* arr[], int n);            // 템플릿 B
        
        struct debts
        {
            char name[40]{};
            double amount{};
        };
        
        //-------------------------[   FBody   ]-----------------------------------//    
        int main()
        {
            int things[6]{ 1, 2, 3, 4, 5, 6 };
            struct debts mr_E[3] =
            {
                {"A", 200.0},
                {"B", 400.0},
                {"C", 600.0}
            };
        
            double* pd[3];
        
            // 포인터들을 배열 mr_E에 있는 구조체들의 amount 멤버로 설정
            for (int i{}; i < 3; i++)
            {
                pd[i] = &mr_E[i].amount;
            }
        
            cout << "Mr.E의 재산 목록 : \n";
        
            // things는 int형의 배열이다.
            ShowArray(things, 6);               // 템플릿 A를 사용
            cout << "Mr.E의 채무 목록 : \n";
        
            // pd는 double형을 지시하는 포인터들의 배열이다.
            ShowArray(pd, 3);                   // 더 특수화된 템플릿 B를 사용했다
        
            return 0;
        }
        
        //-------------------------[ Func.Def. ]-----------------------------------//
        template <typename T>
        void ShowArray(T arr[], int n)
        {
            cout << "템플릿 A\n";
            for (int i{}; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
        template <typename T>
        void ShowArray(T* arr[], int n)
        {
            cout << "템플릿 B\n";
            for (int i{}; i < n; i++)
            {
                cout << *arr[i] << " ";
            }
            cout << endl;
        }

    프로그램 실행 결과 : 
        Mr.E의 재산 목록 :
        템플릿 A
        1 2 3 4 5 6
        Mr.E의 채무 목록 :
        템플릿 B
        200 400 600

    */
    #pragma endregion
    #pragma region 08.프로그래밍 연습_1
    /*
    ---------------------------------------- 08.프로그래밍 연습_1 ----------------------------------------
    문제 :
    평상시에는 문자열의 주소를 하나의 매개변수로 취하여, 그 문자열을 한 번 출력하는 함수를 작성하라.
    그러다가 0이 아닌 int형 값을 두 번째 매개변수로 제공하면, 그 시점에 도달할 때까지 그 함수가
    호출되었던 횟수만큼 그 문자열을 반복해서 출력해야한다.


    해답 :
    //-------------------------[ ProtoType ]-----------------------------------//
    void PrintA(char* a, int n = 0);

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        char a[50]{};
        int n{};

        while (true)
        {
            cout << "문자열 입력 : \n";
            cin.getline(a, 50);
            cout << "숫자 입력 : \n";
            (cin >> n).get();
            if (n != 0)
            {
                for (int i{}; i < n; i++)
                {
                    PrintA(a);
                }
                break;
            }
            PrintA(a, n);
        }

        cout << "프로그램 종료";

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    void PrintA(char* a, int n)
    {
        cout << a << endl;
    }

    */
    #pragma endregion
    #pragma region 08.프로그래밍 연습_2
    /*
    ---------------------------------------- 08.프로그래밍 연습_2 ----------------------------------------
    문제 :
    CandyBar 구조체는 세 개의 멤버 상표명, 중량, 칼로리를 가진다.
    CandyBar에 대한 참조, char형을 지시하는 포인터, double형, int형을 매개변수로 취하고,
    마지막 세 매개변수의 값을 사용하여 구조체의 해당 멤버를 설정하는 프로그램을 작성하라.
    마지막 세 매개변수는, "CandyCandy", 1.99, 300의 디폴트 값을 가져야한다.

    해답 :
    //-------------------------[ ProtoType ]-----------------------------------//
    struct CandyBar
    {
        char name[80]{};
        double weight{};
        int kcal{};
    };

    void setBar(CandyBar& a, const char* b = "CandyCandy", double c = 1.99, int d = 300);
    void print(CandyBar& a);

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        CandyBar a;
        setBar(a);
        print(a);

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    void setBar(CandyBar& a, const char* b, double c, int d)
    {
        strcpy_s(a.name, b);
        a.weight = c;
        a.kcal = d;
    }
    void print(CandyBar& a)
    {
        cout << a.name << " " << a.weight << " " << a.kcal;
    }


    */
    #pragma endregion
    #pragma region 08.프로그래밍 연습_3
    /*
    ---------------------------------------- 08.프로그래밍 연습_3 ----------------------------------------
    문제 :
    string 객체의 참조를 매개변수로 취하고, string의 내용을 대문자로 변환하는 함수를 작성하라.
    실행 예는 다음과 같아야 한다.
    
        문자열을 입력하시오 (끝내려면 q) : go away
        GO AWAY
        
        다음 문자열을 입력하시오 (끝내려면 q) : q
        끝.

    해답 :
    //-------------------------[ ProtoType ]-----------------------------------//
    void setString(string& a);

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        string a{};
        cout << "문자열을 입력하시오 (끝내려면 q) : ";
        getline(cin, a);
        while (a != "q")
        {
            setString(a);
            cout << a << endl;
            cout << "다음 문자열을 입력하시오 (끝내려면 q) : ";
            getline(cin, a);
        }
        cout << "끝.";

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    void setString(string& a)
    {
        for (int i{}; a[i] != '\0'; i++)
        {
            if (isalpha(a[i]))
            {
                a[i] = toupper(a[i]);
            }
        }
    }


    */
    #pragma endregion
    #pragma region 08.프로그래밍 연습_4
    /*
    ---------------------------------------- 08.프로그래밍 연습_4 ----------------------------------------
    문제 :
    T형 항목 5개를 원소로 가진 배열을 매개변수로 취하고, 그 배열에서 가장 큰 항목을 찾아
    리턴하는 템플릿 함수를 작성하라. 

    해답 :
    //-------------------------[ ProtoType ]-----------------------------------//
    template <class T>
    T compare(T arr[]);

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        int arr[5]{};
        double arr2[5]{};
        int big{};
        double bigbig{};

        for (int i{}; i < 5; i++)
        {
            cout << "배열의 " << i+1 << "번쨰 int 형 원소 : ";
            cin >> arr[i];
        }
        for (int i{}; i < 5; i++)
        {
            cout << "배열의 " << i + 1 << "번쨰 double 형 원소 : ";
            cin >> arr2[i];
        }

        big = compare(arr);
        bigbig = compare(arr2);
        cout << "int 형 중 최고는 : " << big << "\ndouble 형 중 최고는 : " << bigbig;

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    template <class T>
    T compare(T arr[])
    {
        T big{};
        big = arr[0];
        for (int i{}; i < 5; i++)
        {
            if (arr[i] >= big)
            {
                big = arr[i];
            }
        }
        return big;
    }


    */
    #pragma endregion
    #pragma region 08.프로그래밍 연습_5
    /*
    ---------------------------------------- 08.프로그래밍 연습_5 ----------------------------------------
    문제 :
    T형 항목들을 원소로 가진 배열과, 그 배열의 원소 개수를 나타내는 정수를 매개변수로 취하고,
    그 배열에서 가장 큰 항목을 리턴하는 템플릿함수를 작성하라.
    이 함수는, char를 지시하는 포인터의 배열과, 포인터의 개수를 매개변수로 취하고,
    가장 긴 문자열의 주소를 리턴하는 특수화를 제공해야 한다.
    여러 개의 문자열이 가장 긴 길이를 갖는 것으로 나온다면, 가장 먼저 나오는 문자열의 주소를 리턴해야 한다.

    해답 :
    //-------------------------[ ProtoType ]-----------------------------------//
    template <class T>
    T compare(T arr[], int n = 0);

    template <> char* compare(char* arr[], int n);

    //-------------------------[   FBody   ]-----------------------------------//
    int main()
    {
        int arr[5]{};
        double arr2[5]{};
        int big{};
        double bigbig{};
        const char* arr3[5] =
        {
            "1", "12", "123", "1234", "12345"
        };
        const char* char_max{};

        for (int i{}; i < 5; i++)
        {
            cout << "배열의 " << i+1 << "번쨰 int 형 원소 : ";
            cin >> arr[i];
        }
        for (int i{}; i < 5; i++)
        {
            cout << "배열의 " << i + 1 << "번쨰 double 형 원소 : ";
            cin >> arr2[i];
        }

        big = compare(arr);
        bigbig = compare(arr2);
        cout << "int 형 중 최고는 : " << big << "\ndouble 형 중 최고는 : " << bigbig << endl;
        cout << "--------------------------------------------------------------\n";
        char_max = compare(arr3, 5);
        cout << "char 형 중 최고는 : " << char_max;

        return 0;
    }

    //-------------------------[ Func.Def. ]-----------------------------------//
    template <class T>
    T compare(T arr[], int n)
    {
        T big{};
        big = arr[0];
        for (int i{}; i < 5; i++)
        {
            if (arr[i] >= big)
            {
                big = arr[i];
            }
        }
        return big;
    }

    template <> char* compare(char* arr[], int n)
    {
        char* max = arr[0];
        for (int i{}; i < n; i++)
        {
            if (strlen(arr[i]) > strlen(max))
            {
                max = arr[i];
            }
        }
        return max;
    }

    */
    #pragma endregion




#pragma endregion

#pragma region Chapter 9. 메모리 모델과 이름 공간

    #pragma region 09.분할 컴파일
	/*
	---------------------------------------- 09.분할 컴파일 ----------------------------------------
	# 분할 컴파일
	***
    C와 마찬가지로 C++는 프로그램을 구성하는 함수들을 별개의 파일에 넣는 것을 권장한다.
    #include 기능은 각각의 파일에 구조체 선언을 넣는 대신, 그것을 헤더 파일에 넣은 후, 그 헤더 파일을
    각각의 소스 파일에 포함 시킨다. 그러므로 원본 프로그램을 다음과 같이 나눌 수 있다.

        * 구조체 선언, 구조체를 사용하는 함수들의 원형이 있는 헤더 파일
        * 구조체에 관련된 함수들의 코드가 들어 있는 소스 코드 파일
        * 구조체에 관련된 함수둘을 호출하는 코드가 들어 있는 소스 코드 파일
    
    **함수 정의나 변수 선언은 헤더 파일에 넣으면 안 된다.**
    간단한 상황에서는 그렇게 하는 것도 별 문제가 없지만 대개는 곤란한 일이 생긴다

    흔히 헤더파일에는 다음과 같은 것들을 넣는다.
    
        * 함수 원형
        * #define이나 const를 사용하여 정의하는 기호 상수
        * 구조체 선언
        * 클래스 선언
        * 템플릿 선언
        * 인라인 함수
    
    헤더 파일을 포함시킬 때, 괄호인지 큰따옴표로 묶여 있는지 확인하라.
    괄호로 묶여 있으면, 컴파일러는 표준 헤더 파일들이 들어 있는 호스트 시스템의
    파일 시스템 영역에서 그것을 찾는다.

    그러나 큰따옴표로 묶여 있으면, 컴파일러는 먼저 현재 작업 디렉토리나 소스 코드 디렉토리에서 그것을 찾는다.
    **그러므로 사용자가 만든 헤더 파일을 포함시킬 때에는 큰따옴표를 사용해야 한다,**
    


	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.기억 존속 시간, 사용 범위, 링크_1
	/*
	---------------------------------------- 09.기억 존속 시간, 사용 범위, 링크_1 ----------------------------------------
	# 기억 존속 시간, 사용 범위, 링크_1
	***
    ## 기억 존속 시간
    C++는 네 가지 유형으로 데이터를 저장한다. 각 유형은 메모리에 데이터를 존속시키는 시간에서 차이가 난다.

        * 자동 기억 존속 시간 ( Automatic Storage Duration ) : 
          함수 매개변수를 포함, 함수 정의 안에 선언된 변수는 자동 기억 존속 시간을 가진다.
          프로그램 실행이 그들을 정의하고 있는 함수나 블록 안으로 들어갈 때 생성되며 대입된 메모리는,
          프로그램 실행이 해당 함수나 블록을 떠날 때 해제된다.
          C++는 두 종류의 자동 변수를 가진다.

        * 정적 기억 존속 시간 ( Static Storage Duration ) :
          함수 정의의 바깥에서 정의된 변수 또는 키워드 static을 사용하여 정의된 변수는, 정적 기억 존속 시간을 가진다.
          그들은 프로그램이 실행되는 전체 시간 동안 존속한다.
          C++은 세 종류의 정적 변수를 가진다.

        * 쓰레드 존속 시간 ( Thread Storage Duration [C+11] ) :
          멀티코어 프로세서, 즉, 여러 작업을 동시에 처리할 수 있는 CPU를 사용하여,
          연산 작업을 쓰레드 단위로 쪼개 처리할 수 있다.

        * 동적 기억 존속 시간 ( Dynamic Storage Duration ) :
          new 연산자를 사용하여 대입된 메모리는, delete 연산자로 해제되거나 프로그램이 종료할 때까지 존속된다.
          이 메모리는 동적 기억 존속 시간을 가지며, 때로는 이 메모리를 자유 공간이라 부른다.
    ***
    ## 사용 범위와 링크
    사용 범위 ( Scope )는 어떤 이름이 하나의 파일 안에서 얼마나 널리 알려지는가를 나타낸다.
    링크 ( Linkage )는 서로 다른 번역 단위들이 이름을 공유하는 것을 말한다.
    외부 링크 ( External Linkage )를 가진 이름은 여러 파일들이 공유할 수 있다. 
    내부 링크 ( Internal Linkage )를 가진 이름은 한 파일 안에 있는 함수들만 공유할 수 있다.

	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.기억 존속 시간, 사용 범위, 링크_2
	/*
	---------------------------------------- 09.기억 존속 시간, 사용 범위, 링크_2 ----------------------------------------
	# 09.기억 존속 시간, 사용 범위, 링크_2
	***
    ## 자동 변수
    함수 매개변수와, 함수 안에서 선언된 변수는 기본적으로 자동 기억 존속 시간을 가진다.
    이들은 또한 지역 사용 범위를 가지며, 링크는 없다.

    어떤 변수를 블록 안에서 정의하면, 그 변수의 기억 존속 시간과 사용 범위는 그 블록에서만 한정된다.
    함수들이 수시로 시작되고 종료됨에 따라, 자동 변수의 개수도 늘어나거나 줄어들기 때문에,
    프로그램은 실행 동안에 자동 변수를 스스로 관리 해야 한다. 
    일반적인 방법은 메모리의 일부를 예약해 두고, 변수들의 생성과 소멸을 스택으로 관리하는 것이다. 
    프로그램은 두 개의 포인터를 이용해서 스택을 관리한다. 한 포인터는 다음 번 데이터의 저장을 위해 비어 있는
    메모리 위치인 스택의 꼭대기를 지시한다. 
    다른 한 포인터는 다음 번 데이터의 저장을 위해 비어 있는 메모리 위치인 스택의 꼭대기를 지시한다. 
    **스택은 LIFO ( Last-In, First Out; 후입선출 ) 설계이다. 가장 나중에 들어온 변수가 가장 먼저 나간다는 뜻이다.**
    
    ## 정적 변수
    C++는, 세 가지 유형의 링크(외부 링크, 내부 링크, 링크 없음)를 가지는, 정적 변수를 제공한다.
    정적 변수의 개수는 프로그램이 실행되는 동안에 변하지 않기에, 그들을 관리하는 데
    스택과 같은 특별한 장치는 필요 없다. 그 대신 컴파일러는 모든 정적 변수를 수용할 수 있을 만큼
    넉넉하게 크기가 정해진 메모리 블록을 대입한다. 이 블록에 저장되는 정적 변수들은
    프로그램이 실행되는 동안에 계속 존재한다. 그리고 정적 변수를 명시적으로 초기화하지 않으면,
    컴파일러는 그것을 모두 0으로 초기화한다.

    다음 코드 예시는 세 가지 유형의 정적 변수를 보여준다.
    ```cpp
        int global = 1000;          // 정적 기억 존속 시간, 외부 링크
        static int one_file = 50;   // 정적 기억 존속 시간, 내부 링크

        void funct1(int n)
        {
            static int count = 0 ;  // 정적 기억 존속 시간, 링크 없음
        }
    ```
    ***
    
    ## 제한자
    기억 공간 제한자 ( Storage Class Specifier ) 와 cv 제한자라고 부르는 몇 가지 C++ 키워드가
    기억 공간에 대한 추가 정보를 제공한다. 기억 공간 제한자의 목록은 다음과 같다.

        * auto ( C+11에서는 제한자에서 빠짐 )
        * register
        * static
        * extern
        * thread_local ( C+11에서 추가됨 )
        * mutable
    
    C+11 이전에는 **auto 키워드**는 어떤 변수가 자동 변수라는 선언에 사용되었다. ( C++11에서는 자동 형변환에 사용 )
    
    **register 키워드**는 레지스터 기억 공간을 지정하는 선언에 사용된다.
    
    **static 키워드**는 파일 범위 선언에 사용될 때 내부 링크를 나타내며, 지역 선언에 사용될 때는 지역 변수를 위한
    정적 기억 존속 시간을 가리킨다.

    **extern 키워드**는 참조 선언을 나타낸다. 그 선언은 다른 곳에 이미 정의되어 있는 변수를 참조한다.
    
    **thread_local 변수**는 존속 시간이 쓰레드의 존속 시간과 같다.

    **mutable 키워드**는 const 관점에서  설명할 수 있으므로 cv-제한자를 먼저 살펴보기로  하겠다.

    **Cv-제한자**
    다음은 cv-제한자이다.

        * const
        * volatile
    const는 가장  흔한 cv-제한자로, 메모리가 일단 초기화된 후에는 프로그램이 그 메모리를 변경할 수 없다는 뜻이다.

    **volatile 키워드**는, 프로그램 코드가 변경하지 않더라도 특정 메모리 위치에 있는 값이 변경될 수 있다는 것을 나타낸다.
    
    
    이제 다시 mutable 키워드로  돌아가자. mutable은 특정 구조체(또는 클래스)가 const로 선언되어 있다 하더라도,
    그 구조체의 특정 멤버를 변경할 수 있음을 나타내는데 사용할 수 있다.
    다음 예시를 보자
    ```cpp
        struct data
        {
            char name[30];
            mutable int accesses;
        };

        const data veep = {"clay", 0, ...};
        strcpy(veep.name, "sad");               // 허용되지 않는다
        veep.accesses++;                        // 허용된다.
    ```

    veep에 적용한 const 제한자는 프로그램이 veep의 멤버를 변경하지 못하게 한다.
    그러나 accesses 멤버에 적용한 mutable 제한자는 accesses가 그러한 제한을 적용받지 않게 조치한다.

	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.기억 존속 시간, 사용 범위, 링크_3
	/*
	---------------------------------------- 09. 기억 존속 시간, 사용 범위, 링크_3 ----------------------------------------
	# 기억 존속 시간, 사용 범위, 링크_3
	***
    ##함수와 링크
    변수와 마찬가지로, 선택의 폭이 좁기는 하지만 함수 역시 링크 속성을 가진다.
    C++는 하나의 함수 안에서 다른 함수를 정의할 수 없다. 따라서 모든 함수는
    자동적으로 정적 기억 존속 시간을 가진다. 이것은 프로그램이 실행되는 동안 모든 함수가 계손 존재한다는 것을 의미한다.
    기본적으로, 함수는 외부 링크를 가진다. 이 말은 여러 파일이 함수를 공유할 수 있다는 뜻이다.
    함수는 static 키워드를 사용하여 함수에 내부 링크를 부여할 수 있다. 이것은 그 함수의 사용범위를 하나의 파일로 제한한다.
    
    ```cpp
        static int private(double x);

        static int private(double x)
        {

        }
    ```
    이것은 함수가 파일에만 알려진다는 것을 의미한다.
    따라서 같은 이름의 함수를 다른 파일에서도 사용할 수 있다는 것을 의미한다.
    변수와 마찬가지로, 정적 함수는 정적 선언이 들어 있는 파일에서 외부 정의를 무시한다.

    ##언어 링크
    언어 링크 ( Language Linking ) 이라는 또 다른 형태의 링크가 있다. 이것은 함수에 영향을 준다. 
    C++에서는 같은 이름의 함수를 여러 개 가질 수 있으므로, 이들이 모두 서로 다른 기호 이름으로 변환되어야 한다.
    C++ 컴파일러는 오버로딩된 함수들에 대해ㅐ서 서로 다른 기호 이름을 생성하기 위해서 이름 맹글링 ( Name mangling ) 과정을 거친다.
    예를 들면, C++ 컴파일러는 spiff(int)를 _spiff_i로 변환할 수 있다.
    이러한 접근 방식을 C++ 언어 링크 ( C++ Language Linkage )라고 한다.
    
    ## 기억 공간 형식과 동적 대입
    동적 메모리는 사용 범위나 링크 규칙이아닌, new와 delete  연산자에 의해 다루어진다.
    그러므로 동적 메모리는 어떤 하나의 함수로부터 대입받고, 다른 함수에서 이를 해제할 수 있다.

    자동 메모리와는 달리, 동적 메모리는 LIFO가 아니다. 자동 메모리의 대입 순서와 해체 순서는
    new와 delete를 언제 사용하느냐에 달려 있다. 


	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.이름 공간_1
	/*
	---------------------------------------- 09.이름 공간_1 ----------------------------------------
	# 이름 공간_1
	***
    C++에서는 변수, 함수, 구조체, 열거체, 클래스, 클래스 멤버와 구조체 멤버를
    이름을 통해서 참조할 수 있다. C++ 표준은 이름 사용 범위를 더 잘 제어할 수 있도록
    이름 공간이라는 기능을 제공한다.

    ## 구식 C++ 이름 공간
    선언 영역 ( Declarative Region )은 선언을 할 수 있는 영역이다.
    예를 들면, 전역 변수는 모든 함수의 바깥에서 선언할 수 있다. 그 변수의 선언 영역은
    그것이 선언된 파일이다. 어떤 변수를 함수 안에 선언한다면,
    그 변수의 선언 영역은 그것이 선언된 블록이다.

    잠재 사용 범위 ( Potential Scope )는 그 변수를 선언한 지점부터 선언 영역의 끝까지이다.
    변수는 처음으로 그것을 정의한 지점의 위에서는 사용할 수 없기 때문에, 잠재 사용 범위는 선언 영역보다 좁다.
    하지만 잠재 사용 범위에서 변수가 보이지 않을 수도 있다.

    ## 새로운 이름 공간 기능
    다음 코드는 **namespace**라는 새로운 키워드를 사용하여 Jack과 Jill 이라는 두 개의 이름 공간을 만든다.

    ```cpp
        namespace Jack {
            double pail;        // 변수 선언
            void fetch();       // 함수 원형
            int pal;            // 변수 선언
            struct well {..};   // 구조체 선언
        }

		namespace Jill {
			double bucket(double n) {...}         // 함수 정의
			double fetch;                         // 변수 선언
			int pal;                              // 변수 선언
			struct Hill {..};                     // 구조체 선언
		}
    ```
    어떤 하나의 이름 공간에 속한 이름은 다른 이름 공간에 속한 이름과 충돌하지 않는다.
    그래서 Jack의 fetch는 Jill의 fetch와 공존할 수 있고, Jill의 Hill은
    외부 Hill과 공존할 수 있다.

    이름 공간은 항상 열려 있다. 그것은, 기존의 이름 공간에 새로운 이름을 추가할 수 있다는 것을 의미한다.
    예를 들어, 다음과 같은 구문은 Jill이라는 이름 공간에 속해 있는 기존의 이름 리스트에
    goose라는 새로운 이름을 추가한다.

    ```cpp
        namespace Jill {
            char* goose(const char*);
        }
    ```

    물론, 어떤 주어진 이름 공간에 속해 있는 이름에 접근할 수 있는 방법이 필요하다.
    가장 간단한 방법은 사용 범위 결정 연산자 :: 을 사용하여, 어떤 이름을 주어진 공간으로 제한하는 것이다.

    ```cpp
        Jack::pail = 12.34;     // 변수를 사용한다.
        Jill::Hill mole;        // Hill형의 구조체를 생성한다.
    ```

	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.이름 공간_2
	/*
	---------------------------------------- 09.이름 공간_2 ----------------------------------------
	# 이름 공간_2
	***
    이름 공간을 사용할 때마다, 매번 이름을 제한한다는 것은 성가시므로,
    C++는 이름 공간에 속해 있는 이름을 간편하게 사용할 수 있는, using 선언과 using 지시자라는
    두 가지 방법을 제공한다. using 선언은 하나의 특별한 식별자를 사용할 수 있게 만들고,
    using 지시자는 그 이름공간 전체에 접근할 수 있게 만든다.

    using 선언은 제한된 이름 앞에 키워드 using을 붙이는 것이다.
    ```cpp
        using Jill::fetch;
    ```

    using 선언은 하나의 이름만을 사용할 수 있게 만든다. 이와는 대조적으로,
    using 지시자는 모든 이름을 사용할 수 있게 만든다. using 지시자는 하나의 이름 공간 앞에
    using namespace 라는 키워드를 붙이는 것이다. 이렇게 하면 사용 범위 결정 연산자를 사용하지 않고도
    그 이름 공간에 속한 모든 이름을 사용할 수 있게 된다.

    ```cpp
        using namespcae Jack;       // Jack에 속한 모든 이름을 사용할 수 있다.
    ```

    using 지시자와 using 선언과 관련하여 기억해야 할 것은,
    그들이 이름 충돌의 가능성을 증가시킨다는 것이다. 즉, 이름 공간 Jadk과 이름 공간 Jill을
    둘 다 사용할 수 있게 하고, 사용 범위 결정 연산자를 사용한다면 모호함이 없다.

    실제로 컴파일러는 모호함이 발생하기 때문에, 두 using  선언을 함께 사용하는 것을 허용하지 않는다.
    일반적으로, 사용할 수 있게 하려는 이름이 무엇인지 분명하게 나타내 주므로 using 지시자보단 using 선언을
    사용하는 것이 더 안전하다. 

	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 09.프로그래밍 연습_
	/*
	---------------------------------------- 09.프로그래밍 연습_ ----------------------------------------
	문제 :
    다음과 같은 구조체 선언이 주어진다.
    ```cpp
        struct chaff
        {
            char dross[20];
            int slag;
        };
    ```
    위치 지정 new를 사용하여 그러한 구조체 두 개짜리 배열을 버퍼에 넣는 프로그램을 작성하라.
    그 후, 구조체들의 멤버에 값을 대입하고 ( char형 배열에는 strcpy()를 사용 ), 루프를 사용하여
    그 내용을 디스플레이 하라.

	해답 :
	//-------------------------[ ProtoType ]-----------------------------------//
	struct chaff
	{
		char dross[20];
		int slag;
	};

	//-------------------------[   FBody   ]-----------------------------------//
	int main()
	{
		chaff* p1;
		int i;
		char* buffer = new char[500];
		p1 = new(buffer) chaff[2];
		strcpy_s(p1[0].dross, "Yahoo");
		p1[0].slag = 5;
		strcpy_s(p1[1].dross, "Korea");
		p1[1].slag = 5;

		for (i = 0; i < 2; i++)
		{
			cout << p1[i].dross << ": " << p1[i].slag << endl;
		}

		return 0;
	}

	//-------------------------[ Func.Def. ]-----------------------------------//

	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion

#pragma endregion

#pragma region Chapter 10. 객체와 클래스
	
    #pragma region 10.Intro
	/*
	---------------------------------------- 10.Intro ----------------------------------------
	# Intro
	***
    C++은 C를 개선하여, 객체 지향 프로그래밍을 쉽게 구현할 수 있도록 만든 프로그래밍 언어이다.

    다음은 OOP의 가장 중요한 기능들이다.

    * 추상화 ( Abstraction )
    * 캡슐화 ( Encapsulation ) 와 데이터 은닉 ( Data Hiding )
    * 다형성 ( Polymorphism )
    * 상속 ( Inheritance )
    * 코드의 재활용 ( Reusability of code )
    
    클래스 ( Class )는 이러한 OOP 기능들을 구현하고 결합하는 데 사용되는 가장 중요한 C++의 도구이다.
    이 장에서는, 클래스가 무엇인지, 추상화, 캡슐화, 데이터 은닉을 설명하고, 클래스로 이 기능들을
    어떻게 구현하는지 설명한다. 또한 클래스에 속하는 객체들을 생성하고 파괴하는 역할을 하는
    특수한 멤버 함수인 생성자 ( Constructor )와 파괴자 ( Destructor )도 설명한다.
    마지막으로, 클래스 프로그래밍에서 중요한 역할을 하는 this 포인터에 대해 알아본다.


	***
	출처 : C++ 기초 플러스 6판 / 성안당
	***
	*/
    #pragma endregion
    #pragma region 10.추상화와 클래스
    /*
    ---------------------------------------- 10.추상화와 클래스 ----------------------------------------
    # 추상화와 클래스
    ***
    컴퓨터 분야에서 추상화란 정보를 사용자 인터페이스로 표현하는 것이다.
    즉, 어떤 문제에 필수적인 조작적 기능들을 추상화하고, 그것으로 해결책을 표현하는 것이다.
    C++에서는 클래스가 추상화 인터페이스를 구현하는 사용자 정의 데이터형이다.

    ## 데이터형이란 무엇인가?
    C와 같은 절차식 프로그래밍 언어를 사용할 때 우리는 이와 비슷한 상황에 놓이게 된다.
    먼저 우리는 메모리에 저장되는 형태만으로 데이터형을 생각하기 쉽다.
    예를 들어, char는 1바이트 메모리를 나타내고, double은 8바이트 메모리를 나타낸다.
    그러나 좀 더 생각해 보면, 데이터형이란 그것을 대상으로 수행할 수 있는 연산에 의해
    정의된다는 것을 알 수 있다. 예를 들어, int형은 모든 산술 연산을 수행할 수 있다.
    즉, int형을 대상으로 덧셈, 뺄셈, 곱셉, 나눗셈을 수행할 수 있으며 나머지 연산자(%) 도 사용이 가능하다.

    이제 포인터에 대해 생각해 보자. 포인터는 int형과 같은 크기의 메모리를 요구하고,
    내부적으로는 int형으로 나타낸다. 하지만 포인터는 int형에 적용할 수 있는 연산을 허용하지 않는다.
    그러므로 어떤 변수를 int형으로 선언하거나 float형을 지시하는 포인터로 선언한다고 할 때, 그러한 선언은
    단지 메모리만 대입하는 것이 아니라, 그 데이터형으로 수행할 수 있는 연산까지도 함게 정의하는 것이다.
    쉽게 말해, 기본형을 서술하는 것은 다음과 같은 세 가지를 결정하는 것이다.

    * 데이터 객체에 필요한 메모리의 크기를 결정한다.
    * 메모리에 있는 비트들을 어떻게 해석할 것인지 결정한다. 
    ( long 값과 float 값이 메모리에서 동일한 비트 수를 사용할 수 있지만, 그들은 서로 다른 수치 값으로 해석된다. )
    * 데이터 객체를 사용하여 수행할 수 있는 연산이나 메서드를 결정한다.
    
    내장된 기본 데이터형의 경우에, 동작에 관한 정보들이 컴파일러에 내장된다.
    그러나 프로그래머가 C++에서 사용자 정의 데이터형을 정의한다면, 프로그래머가 이와 같은
    정보를 직접 제공해야 한다. 이를 대가로, 프로그래머는 실세계의 요구에 더 잘 대응하는
    새로운 사용자 정의 데이터형을 정의할 수 있는 능력과 융통성을 부여받는다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.C++의 클래스
    /*
    ---------------------------------------- 10.C++의 클래스 ----------------------------------------
    # C++의 클래스
    ***
    클래스는 추상화를 사용자 정의 데이터형으로 변환해 주는 C++의 수단이다.
    클래스는 데이터 표현과 데이터를 조작하는 메서드들을 하나의 패키지 안에 결합한다.
    주식을 나타내는 클래스를 한번 생각해 보자.

    먼저, 주식을 나타내는 방법에 대해서 생각하자.
    주식 한 주를 기본 단위로 삼고, 한 주를 표현하는 클래스를 정의할 수도 있다.
    그러나 이런 방식으로 100주를 나타내려면 100개의 객체가 필요하며 이것은 실용성이 없다.
    대신, 한 사람이 어떤 한 주식에 대해 가지고 있는 지분을 기본 단위로 표현할 수 있다.
    클래스를 정의하는 첫 번째 시도로서는 이것이 조금 어려워 보이므로, 다소 이상적이고 단순화된 개념을 적용한다.

    * 어떤 회사의 주식을 획득한다.
    * 동일한 주식을 더 많이 매입한다.
    * 주식을 매도한다.
    * 그 주식의 주가를 갱신한다.
    * 지분에 대한 정보를 표시한다.
    
    이 인터페이스를 지원하기 위해서는 몇 가지 정보를 저장해야 한다.

    * 회사명
    * 보유 주식 수
    * 주식 1주의 가치 ( = 주가 )
    * 보유 주식의 총 가치
    
    이제 우리는 클래스를 정의할 수 있다. 일반적으로, 클래스 서술은
    두 부분으로 이루어진다.

    * 클래스 선언 ( Class Declaration ) : 데이터 멤버과 public 인터페이스, 
    ( 메서드라 부르는 ) 멤버 함수를 이용하여 데이터 표현을 서술한다.
    * 클래스 메서드 정의 ( Class Method Definitions ) : 클래스 멤버 함수가 어떻게 구현되는지를 서술한다.
    
    간단히 말해서, 클래스 선언은 클래스의 개요를 제공하는 것이고, 메서드 정의는 세부 사항을 제공하는 것이다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 및 접근제어자
    /*
    ---------------------------------------- 10.클래스 및 접근제어자 ----------------------------------------
    # 클래스 및 접근제어자
    ***
    다음 예시를 보자
    
    ```cpp
    #ifndef STOCK00_H_
    #define STOCK00_H_

    #include <string>

    class Stock
    {
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }

    public :
        void acquire(const std::string &co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
    };

    #endif
    ```
    
    먼저 C++의 키워드인 class는 위에 있는 코드가 클래스 설계를 위한 정의라는 사실을 나타낸다. 
    이 구문은 Stock을 이 새로운 클래스의 데이터형 이름으로 만든다. 이 선언으로 우리는 Stock형의 변수인,
    객체 ( Object )나 인스턴스 ( Instance )를 선언할 수 있게 된다. 객체 하나는 한 사람의 주식 지분을 표현할 수 있다.

    ```cpp
        Stock sally;
        Stock solly;
    ```

    sally 와 solly라는 두 개의 Stock 객체를 생성한다. 예를 들어, sally 객체는
    Sally라는 사람이 보유하고 있는 특정 회사 주식의 지분을 나타낼 수 있다.

    다음으로, 저장하기로한 정보는 company나 shares와 같은 클래스 데이터 멤버의 형태로 나타낸다.
    예를 들어, sally 객체의 company 멤버에는 회사명을 저장하고, shares멤버에는 Sally가 보유하고 있는 주식 수를 저장한다.
    또한 share_val 멤버에는 주가를 저장하고, total_val 멤버에는 보유하고 있는 주식의 총 가치를 저장한다.
    이와 비슷하게, 우리가 원하는 연산은 sell()이나 update()와 같은 클래스 함수 멤버(또는 메서드)의 형태로 나타난다.
    멤버 함수는 set_tot()와 같이 그 지라이에서 정의될 수 있다. 또는 클래스에 속해 있는 다른 멤버 함수들처럼
    원형에 의해 표현될 수도 있다. 함수 인터페이스의 서술 단계에서는 함수의 원형만으로 충분하다.

    ## 접근 제어
    또한 private과 public이라는 새로운 키워드가 도입되었다. 이 레이블들은 클래스 멤버에 대한 접근 제어를 서술한다.
    특정 클래스의 객체를 사용하는 프로그램은, 그 객체의 public 부분에는 직접 접근할 수 있다. 그러나 프로그램은
    public 멤버 함수를 통해서만 ( 또는 11장에서 설명하는 프렌드 함수를 통해서만 ) 그 객체의 private 멤버에 접근할 수 있다.
    예를 들어, Stock 클래스의 shares 멤버의 값을 변경하는 유일한 방법은 Stock 클래스의 public 멤버 함수 중의 하나를 사용하는 것이다.
    그러므로 public 멤버 함수는 객체의 private 멤버와 프로그램을 잇는 다리 역할을 한다. 
    이와 같이, 프로그램이 데이터에 직접 접근하지 못하게 차단하는 것을 **데이터 은닉 ( Data Hiding )**이라 한다. 
    데이터 은닉은 데이터에 직접 접근하지 못하게 막아 줄 뿐만 아니라, 데이터 표현이 어떻게 되어 있는지에 대해
    클래스 사용자가 신경 쓰지 않도록 해 준다.

    ## 멤버 접근 제어 : public 또는 private?
    클래스 멤버는, 그것이 데이터 항목이든 아니면 멤버 함수이든 간에, 클래스의 public 부분이나 private 부분 어느 한쪽에 선언될 수 있다.
    그런데 데이터를 은닉하는 것이 OOP의 기본 규칙 중 하나이기 때문에, 일반적으로 데이터 항목들은 private 부분에 선언된다.
    클래스 인터페이스를 구성하는 멤버 함수들은 public 부분에 선언된다. 그렇게 하지 않으면, 프로그램에서 그 함수들을 호출할 수 없다.
    
    클래스 객체에 대한 디폴트 접근 제어가 private으로 지정되어 있기 때문에, 클래스 선언에서 키워드 private는 없어도 된다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 멤버 함수의 구현
    /*
    ---------------------------------------- 10.클래스 멤버 함수의 구현 ----------------------------------------
    # 클래스 멤버 함수의 구현
    ***
    클래스 선언에서 원형으로 나타낸 멤버 함수들에 대한 코드를 제공해야 한다.
    메머 함수 정의는 리턴형과 매개변수를 가질 수 있다. 또한 다음과 같은 두 가지 특성을 지닌다.

    * 멤버 함수를 정의할 때, 그 멤버 함수가 어느 클래스에 속하는지를 나타내기 위해 사용 범위 결정 연산자( :: )를 사용해야 한다.
    * 클레스 메서드는 그 클래스의 private 부분에만 접근할 수 있다.
    
    멤버 함수의 함수 머리는 그 함수가 어느 클래스에 속하는지 나타내기 위해서 사용 범위 결정 연산자 ( :: )를 사용해야 한다.
    예를 들어, update() 멤버 함수의 머리는 다음과 같아야 한다.

    ```cpp
        void Stock::update(double price)
    ```

    이것은 Stock 클래스의 멤버 함수인 update() 함수를 정의한다는 의미이다.
    사용 범위 결정자 (::)는 그 메서드의 정의가 어느 클래스에 적용되는 것인지를 알려 준다.
    Stock 클래스에 속해 있는 다른 멤버 함수들은 사용 범위 결정 연산자를 사용하지 않고도 update() 메서드를 사용할 수 있다.
    하지만 클래스 선언이나 메서드 정의 밖에서 update()를 사용하려면 특별한 수단이 필요하다. 이는 후에 다룬다.

    메서드가 가지고 있는 두 번째 특별한 특징은, 메서드가 클래스의 private 멤버들에 접근할 수 있다는 것이다.

    ```cpp
    cout << "회사명: " << company;
    ```

    이 간단한 코드에서, company는 Stock 클래스의 private 데이터 멤버이다. 멤버가 아닌 함수들을 사용하여
    데이터 멤버에 접근을 시도하면, 컴파일러가 즉각 멈추게 한다. 다음 예시를 보자.

    ```cpp
    #include <iostream>
    #include "stock00.h"

    void Stock::acquire(const std::string& co, long n, double pr)
    {
        company = co;
        if ( n < 0 )
        {
            std::cout << "주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
            shares = 0;
        }
        else
        {
            shares = n;
            share_val = pr;
            set_tot();
        }
    }

    void Stock::buy(long num, double price)
    {
        if ( num < 0 )
        {
            std::cout << "매입 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다. \n";
        }
        else
        {
            shares += num;
            share_val = price;
            set_tot();
        }
    }

    void Stock::sell(long num, double price)
    {
        using std::cout;
        if ( num < 0 )
        {
            cout << "매도 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다. \n";
        }
        else if ( num > shares )
        {
            cout << "보유 주식보다 많은 주식을 매도 할 수 없으므로, 거래가 취소되었습니다. \n";
        }
        else
        {
            shares -= num;
            share_val = price;
            set_tot();
        }
    }

    void Stock::update()
    {
        share_val = price;
        set_tot();
    }

    void Stock::show()
    {
        std::cout << "회사명: " << company
                  << " 주식 수 : " << shares << "\n"
                  << "주가: $" << share_val
                  << " 주식 총 가치 : $" << total_val << "\n";
    }

    ***
    **멤버 함수 설명**
    멤버 함수들 중에서 네 개가 total_val 멤버의 값을 설정 또는 재설정한다.
    이것을 수행하는 계산을 네 번 작성하지 않고, 그 클래스는 각 함수로 하여금
    set_tot() 함수를 호출하게 한다. 이 함수는 단순히 그 코드를 구현하는 수단일 뿐
    public 인터페이스의 일부가 아니므로, 그 클래스는 set_tot()를 private 멤버 함수로 만들었다.
    ```

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.인라인 메서드
    /*
    ---------------------------------------- 10.인라인 메서드 ----------------------------------------
    # 인라인 메서드
    ***
    클래스 선언 안에 정의를 가지는 모든 함수는 자동으로 인라인 함수가 된다.
    클래스 선언은 짧은 멤버 함수들에 대해서 인라인 함수를 사용하는 경우가 많다.
    원한다면 클래스 선언의 외부에 멤버 함수를 정의하고, 그것을 인라인 함수로 만들 수 있다.
    그렇게 하려면, 클래스 세부 구현 부분에서 그 함수를 정의할 때 **inline** 이라는 제한자를 앞에 붙이면 된다.

    ```cpp
        class Stock
        {
        private:
            ...
            void set_tot();             // 정의를 따로 분리한다.
        public:
            ...
        };

        inline void Stock::set_tot()    // 정의에 inline을 사용한다.
        {
            total_val = shares * share_val;
        }
    ```
    인라인 함수에 적용되는 특별한 규칙은, 인라인 함수들은 그들이 사용되는 각각의 파일에서 정의될 것을 요구한다.
    코드 수정 규칙에 따르면, 클래스 선언 안에 메서드를 정의하는 것은, 그 메서드 정의를 원형으로 대체하고,
    클래스 선언 바로 뒤에 그 메서드 정의를 인라인 함수로 다시 작성하는 것과 같다.
    ***
    # 어느 객체가 메서드를 사용할까?
    객체 사용에서 가장 중요한 측면 중의 하나를 알아보자.

    ```cpp
        shares += num;
    ```

    어떤 객체의 shares 멤버를 사용하고 있다. 그런데 그 객체가 과연 어느 객체인가?
    먼저, 객체를 생성하는 방법부터 알아보자. 가장 간단한 것은 클래스 변수를 선언하는 것이다.

    ```cpp
        Stock kate, joe;
    ```

    이것은 kate와 joe라는, Stock 클래스의 두 객체를 생성한다.

    ```cpp
        kate.show();        // kate 객체가 멤버 함수를 호출한다.
        joe.show();         // joe 객체가 멤버 함수를 호출한다.
    ```

    여기서 첫 번째 kate.show() 호출은 kate 객체의 멤버 함수인 show()를 호출하는 것이다.
    이것은 show() 메서드가 shares를 kate.shares로, share_val을 kate.share_val로 해석하는 의미이다.
    마찬가지로 joe.show()의 호출은 각각 joe.shares, joe.share_val로 해석한다는 뜻이다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 사용하기
    /*
    ---------------------------------------- 10.클래스 사용하기 ----------------------------------------
    # 클래스 사용하기
    ***
    C++의 목표는, 클래스 사용을 마치 int나 char와 같은 내장된 기본 데이터형을 사용하는 것과 비슷하게 만드는 것이다.
    다음 예시를 통해 간단하지만, 클래스 관련 기능들을 알아보자.

    ```cpp
    #include <iostream>
    #include "stock00.h"

    int main()
    {
        Stock cat;
        cat.acquire("Smart", 20, 12.50);
        cat.show();
        cat.buy(15, 18.125);
        cat.show();
        cat.sell(400, 20.00);
        cat.show();
        cat.buy(300000, 40.125);
        cat.show();
        cat.sell(300000, 0.125);
        cat.show();
        return 0;
    }
    ```
    프로그램의 출력 :
        회사명: Smart : 주식수 20
        주가: $12.5 주식 총 가치: $250
        회사명: Smart : 주식수 35
        주가: $18.125 주식 총 가치: $634.375
        보유 주식보다 많은 주식을 매도할 수 없으므로, 거래가 취소되었습니다.
        회사명: Smart : 주식수 35
        주가: $18.125 주식 총 가치: $634.375
        회사명: Smart : 주식수 300035
        주가: $40.125 주식 총 가치: $1.20389e+07
        회사명: Smart : 주식수 35
        주가: $0.125 주식 총 가치: $4.375
        
    # 실행상의 변경
    Cat의 재정적인 감각은 논외로 하고, 프로그램의 결과가 일관적이지 않은 숫자 양식으로 인해
    사용자를 곤혹스럽게 하는 경우가 있을 수 있다. 여기 인터페이스를 변경하지 않은 상태에서 문제를 개선하는 방법이 있다.
    ostream 클래스는 양식을 컨트롤하는 멤버 함수를 지녔다. 

    ```cpp
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    ```

    이것은 플래그를 고정 소수점 표기를 사용하기 위해 cout 개체 안에 플래그를 세팅한다.
    이와 유사하게 다음 구문으로 소수점 이하 세자리까지 보여줄 수 있다.

    ```cpp
        std::cout.precision(3);
    ```

    하지만 이렇게 메서드에 대한 변경 사항을 구현할 때에는, 다시 양식이 변경되기 전까진
    존재하기 때문에, 클라이언트 프로그램의 차후 output에 영향을 줄 수 있다.
    그러므로, show()가 호출되기 이전의 상태로 정보를 리셋하는 것이 안정된 사용법이다.

    ```cpp
        std::sreamsize prec =
            std::cout.precision(3);     // 정확성을 위해 이전 값을 저장
        ...

        std::cout.precision(prec);      // 과거 값으로 리턴

        // 원본 플래그를 저장
        std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

        // 저장된 값을 리셋
        std::cout.setf(orig, std::ios_base::floatfield);
    ```


    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.중간 요약
    /*
    ---------------------------------------- 10.중간 요약 ----------------------------------------
    # 중간 요약
    ***
    클래스 설계의 첫 단계는 클래스의 선언이다.
    클래스의 선언은 구조체 선언과 모양이 비슷하다.
    선언부는 데이터 멤버, 함수 멤버를 가지며 클래스 선언은 private 부분을 가진다.
    private 부분에 선언된 멤버들은 멤버 함수들을 통해서만 접근할 수 있다.
    클래스 선언은 또한 public 부분을 가진다. public 부분에 선언된 멤버들은
    클래스 객체를 사용하여 프로그램이 직접 접근 가능하다.
    일반적으로 데이터 멤버들은 private, 멤버 함수는 public에 들어간다.

    ```cpp
        class className
        {
        private:
            // data member declarations
        public:
            // member function prototypes
        };
    ```

    public 부분에 있는 내용은 설계의 추상화 부분인 public 인터페이스가 된다.
    private 부분에 데이터를 넣어 캡슐화 하는 것은, 데이터의 무결성을 보호하기 위한 것으로, 데이터 은닉이라고 한다.
    따라서 클래스의 사용은 추상화, 데이터 은닉, 캡슐화라는 OOP의 목표를 쉽게 구현할 수 있게 해 주는 C++의 방법이다.

    클래스 설계의 두 번째 단계는 클래스 멤버 함수의 구현이다.
    클래스 선언에 함수 원형 대신 완전한 함수를 넣을 수 있지만, 일반적으로, 매우 짧은 함수를 제외하고,
    함수 정의들을 따로 분리하여 제공한다.
    그런 경우, 멤버 함수가 어느 클래스에 속하는지를 나타내기 위해 사용 범위 결정 연산자를 사용한다.
    예를 들어, Bozo 클래스가 char를 지시하는 포인터를 리턴하는 Retort()라는 멤버 함수를 가진다고 가정하자.
    함수 머리는 다음과 같아야 한다.

    ```cpp
    char* Bozo::Retort();
    ```

    다시 말해, Retort()는 단순히 char* 형 함수가 아닌, Bozo 클래스에 속한 char*형 함수다.
    즉, 이 함수의 완전한 이름은 Bozo::Retort()이다.
    ***
    어떤 클래스의 객체를 생성하려면, 클래스 이름을 마치 데이터형처럼 사용하면 된다.

    ```cpp
        Bozo Bozetta;
    ```
    
    사용자는, 클래스 객체를 사용함으로써 클래스 멤버 함수(또는 메서드)를 호출한다.
    도트 멤버 연산자를 사용하여 그러한 호출을 수행할 수 있다.

    ```cpp
        cout << bozetta.Retort();
    ```

    이것은 Retort() 멤버 함수를 호출한다. 그리고 Retort() 함수가 특정 데이터 멤버를 언급할 때마다
    그 함수는 bozetta 객체 안에 선언된 데이터들을 사용한다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 생성자와 파괴자_1
    /*
    ---------------------------------------- 10.클래스 생성자와 파괴자_1 ----------------------------------------
    # 클래스 생성자와 파괴자_1
    ***
    클래스를 사용할 때 일반적으로 제공해야 하는 생성자 ( Constructor ) 와 파괴자 ( Destructor )라는 표준 함수가 있다.
    C++가 내세우는 목표 중의 하나는, 클래스 객체를 표준 데이텨형 사용하듯 사용할 수 있게 만드는 것이다.
    
    ```cpp
        int year = 2001;                    // 적법한 초기화

        struct thing
        {
            char* pn;
            int m;
        };

        thing amabob = {"wodget", -23};     // 적법한 초기화
        Stock hot = {"Sukie's Autos, Inc.", 200, 50.25};  // 컴파일 에러
    ```

    Stock 객체를 초기화할 수 없는 이유는, 데이터들이 private 접근 제어를 가져, 프로그램이 데이터 멤버에 접근할 수 없기 때문이다.
    프로그램이 데이터 멤버에 접근할 수 있는 유일한 방법은 멤버 함수의 이용이다. 그러므로 초기화를 위해
    적당한 멤버 함수를 하나 고안할 필요가 있다.
    C++는 이를 위해, 객체가 생성될 때 자동으로 초기화 시켜주는 **클래스 생성자 ( Class Constructor )**라는 특별한 멤버 함수를 제공한다.
    클래스 생성자는 새로운 객체를 생성하고 그들의 데이터 멤버에 값을 대입해준다.
    생성자의 이름은 클래스의 이름과 같다. 예를 들어, Stock이라는 클래스의 생성자는 Stock()이다.
    생성자는 리턴값이 없는데도 불구하고 void로 선언하지 않고, 생성자에는 데이터형을 선언하지 않는다.
    ***
    Stock 객체는 생성자에 세 개의 매개변수를 제공해야 한다.
    company 멤버의 값만 제공하고, 다른 값들은 0으로 설정하기를 원한다고 가정하자.
    디폴트 매개변수를 사용함으로써 이것을 할 수 있다.

    ```cpp
        Stock(const string& co, long n = 0, double pr = 0.0);
    ```
    
    이제, 그 생성자를 위한 한 가지 정의 예를 살펴보자.

    ```cpp
        //생성자 정의
        Stock::Stock(const string& co, long n, double pr)
        {
        company = co;

            if ( n<0 )
            {
                std::cerr <<"주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
                shares = 0;
            }
            else
            {
                shares = n;
            }

            share_val = pr;
            set_tot();
        }
    ```

    

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 생성자와 파괴자_2
    /*
    ---------------------------------------- 10.클래스 생성자와 파괴자_2 ----------------------------------------
    # 클래스 생성자와 파괴자_2
    ***
    ## 생성자 사용하기

    C++는 생성자를 이용하여 객체를 초기화하는 두 가지 방법을 제공한다.
    그 중 하나는 생성자를 명시적으로 호출하는 것이다.

    ```cpp
        Stock food = Stock("World Cabbage", 250, 1.25);
    ```

    이것은 food 객체의 company 멤버를 문자열 "World Cabbage"로 설정하고, shares 멤버를 250, share_val 멤버를 1.25로 지정한다.

    두 번째 방법은 생성자를 암시적으로 호출하는 것이다.

    ```cpp
        Stock food("Wolrd Cabbage", 250, 1.25);
    ```

    두 방법 모두 호출은 같다. 

    C++는 해당 클래스의 객체를 생성할 때마다 클래스 생성자를 사용한다.
    동적 메모리 대입을 위해 new를 사용할 때에도 마찬가지이다.

    ```cpp
        Stock* pstock = new Stock("Electroshock Games", 18, 19.0);
    ```
    이 구문은 Stock 객체를 생성하고, 매개변수를 통해 제공되는 값으로 그것을 초기화 한다.
    그 후, 그 객체의 주소를 pstock 포인터에 대입한다. 이 경우 객체는 이름을 가지지 않는다.
    그러나 그 포인터를 사용하여 객체를 다룰 수 있는데, 객체를 지시하는 포인터는 11장에서 자세히 설명한다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 생성자와 파괴자_3
    /*
    ---------------------------------------- 10.클래스 생성자와 파괴자_3 ----------------------------------------
    # 클래스 생성자와 파괴자_3
    ***
    ## 디폴트 생성자
    
    디폴트 생성자 ( Default constructor )는 명시적인 초기화 값을 제공하지 않을 때 객체를 생성하는 데 사용된다.

    ```cpp
        Stock cat;      // 디폴트 생성자를 사용한다
    ```

    Stock 클래스의 경우, 디폴트 생성자는 다음과 같이 될 것이다.

    ```cpp
        Stock::Stock() {};
    ```

    이것의 결과는, 멤버들이 초기화되지 않은 stock 객체를 생성하는 것이다.
    이것은 마치 다음과 같은 구문이 x에 값을 제공하지 안호 변수 x를 생성하는 것과 같다.

    ```cpp
        int x;
    ```

    디폴트 생성자는 매개변수를 갖지 않으므로 그 선언에 아무런 값도 나타나지 않는다.
    디폴트 생성자는 사용자가 어떠한 생성자도 정의하지 않을 경우에만 컴파일러가 제공한다.
    사용자가 디폴트가 아닌 Stock(const char* co, int n, double pr)와 같은
    생성자를 제공하며 디폴트 생성자를 제공하지 않으면, 다음과 같은 선언은 에러가 된다.

    ```cpp
        Stock stock1;       // 에러
    ```

    에러가 발생하는 이유는, 초기화되지 않은 객체의 생성을 사용자가 원하지 않을지도 모르기 때문이다.
    그러나 명시적 초기화 없이 객체를 생성하고 싶을 경우, 사용자 자신의 디폴트 생성자를 정의해야 한다.

    디폴트 생성자는 두 가지 방법으로 정의할 수 있다.

    첫 번째 방법은, 기존의 생성자에 있는 모든 매개변수에 디폴트 값을 제공하는 것이다.

    ```cpp
        Stock(const string& co = "Error", int n = 0, double pr = 0.0);
    ```

    두 번째 방법은 함수 오버로딩을 사용하여 매개변수가 없는 또 하나의 생성자를 정의하는 것이다.

    ```cpp
        Stock();
    ```

    사용자는 하나의 디폴트 생성자만 가질 수 있다.
    실제적으로는 반드시 모든 멤버들이 알려진 적당한 값을 가져야하므로, 대개 디폴트 생성자는
    모든 멤버들의 값에 암시적인 초기화를 제공한다.

    ```cpp
        Stock::Stock()      //디폴트 생성자
        {
            company = "no name";
            shares = 0;
            share_val = 0.0;
            total_val = 0.0;
        }
    ```
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
#pragma endregion
    #pragma region 10.클래스 생성자와 파괴자_4
    /*
    ---------------------------------------- 10.클래스 생성자와 파괴자_4 ----------------------------------------
    # 클래스 생성자와 파괴자_4
    ***
    ## 파괴자
    생성자를 사용할 때, 프로그램은 객체의 수명이 다할 때까지 그 객체를 추적하는 책임을 맡는다.
    객체의 수명이 끝나는 시점에서, 프로그램은 파괴자(Destructor)라는 특별한 멤버 함수를 자동으로 호출한다.
    Stock 클래스를 위한 파괴자를 하나 살펴보자.

    파괴자는 틸데(~)가 붙은 클래스 이름으로 만들어진다.
    그래서, Stock 클래스의 파괴자는 ~Stock()이다.
    생성자와 같이 파괴자는 리턴값, 선언된 데이터형을 갖지 않지만, 파괴자는 매개변수 또한 가지면 안된다.
    따라서 Stock 파괴자의 원형은 다음과 같아야 한다.

    ```cpp
        ~Stock();
    ```
    
    파괴자가 언제 호출되는지 알 수 있도록 하기 위해, 파괴자를 다음과 같이 코딩할 수 있다.

    ```cpp
        Stock::~Stock()     //클래스 파괴자
        {
            std::cout<< "안녕, " << company << "!\n";
        }
    ```

    파괴자의 호출 결정은 컴파일러가 처리한다. 일반적으로 사용자가
    코드에 명시적으로 파괴자를 호출하면 안된다.
    클래스 객체의 수명이 다했을 때, 파괴자는 자동으로 호출되는 것이기 때문에,
    반드시 파괴자가 있어야 한다. 사용자가 파괴자를 제공하지 않으면, 컴파일러가 디폴트 파괴자를 선언한다.
    객체를 파괴하는 코드를 발견하면, 컴파일러는 그 파괴자를 위한 정의를 제공한다.

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 개선하기
    /*
    ---------------------------------------- 10.클래스 개선하기 ----------------------------------------
    # 클래스 개선하기
    ***
    
    ## 헤더 파일

    ```cpp
    // stock10.h
    #ifndef STOCK10_H_
    #define STOCK10_H_
    #include <string>

    class Stock
    {
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }

    public:
    // 두 개의 생성자
        Stock();        // 디폴트 생성자
        Stock(const std::string& co, long n = 0, double pr = 0.0);
        ~Stock();       // 파괴자
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
    };
    #endif
    ```

    ## 세부 구현 파일
    ```cpp
    // stock10.cpp
    #include <iostream>
    #include "stock10.h"

    // 생성자들
    Stock::Stock()
    {
        std::cout << "디폴트 생성자가 호출되었습니다.\n;
        company = "no name";
        shares = 0;
        share_val = 0.0;
        total_val = 0.0;
    }

    Stock::Stock(const std::string& co, long n, double pr)
    {
        std::cout << co << "를 사용하는 생성자가 호출되었습니다.\n";
        company = co;

        if( n < 0 )
        {
            std::cerr << "주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
            shares = 0;
        }
        else
            shares = n;

        share_val = pr;
        set_tot();
    }

    // 클래스 파괴자
    Stock::~Stock()
    {
        std::cout << "안녕, " << company << "!\n"; 
    }

    // 다른 메서드들
    void Stock::buy(long num, double price)
    {
        if ( num < 0 )
            std::cout << "매입 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n"; 
        else
        {
            shares += num;
            share_val = price;
            set_tot();
        }
    }

    void Stock::sell(long num, double price)
    {
        if ( num < 0 )
            std::cout << "매도 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n";
        else
        {
            shares -= num;
            share_val = price;
            set_tot();
        }
    }

    void Stock::update(double price)
    {
        share_val = price;
        set_tot();
    }

    void Stock::show()
    {
        using std::cout;
        using std::ios_base;
        // set format to #.###
        ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
        std::streamsize prec = cout.precision(3);

        cout << "회사명 : " << company 
             << " 주식 수 : " << shares << '\n';

        cout << " 주가 : $" << share_val;
        // set format to #.##
        cout.precision(2);
        cout << "주식 총 가치 : $ " << total_val << '\n';

        // 원본 포맷 저장
        cout.setf(orig, ios_base::floatfield);
        cout.precision(prec);
    }
    ```

    ## 클라이언트 파일
    
    ```cpp
    // usestock1.cpp
    #include <iostream>
    #include "stock10.h"

    int main()
    {
        using std::cout;
        cout << "생성자 를 사용하여 새로운 객체들을 생성한다.\n";
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();

        cout << "stock1을 stock2에 대입한다.\n";
        stock2 = stock1;
        cout << "stock1과 stock2를 출력한다.\n";
        stock1.show();
        stock2.show();

        cout << "생성자를 사용하여 객체를 재설정한다.\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "갱신된 stock1:\n";
        stock1.show();
        cout << "프로그램을 종료합니다.\n";

        return 0;
    }

    프로그램 결과:
        생성자들을 사용하여 새로운 객체들을 생성한다.
        NanoSmart를 사용하는 생성자가 호출되었습니다.
        회사명: NanoSmart   주식 수: 12
          주가: $20.00         주식 총 가치: $240.00
        Boffo Objects를 사용하는 생성자가 호출되었습니다.
        회사명: Boffo Objects    주식 수: 2
          주가: $2.00            주식 총 가치: $4.00
        stock1을 stock2에 대입한다.
        stock1과 stock2를 출력한다.
        회사명: NanoSmart   주식 수: 12
          주가: $20.00         주식 총 가치: $240.00
        회사명: NanoSmart   주식 수: 12
          주가: $20.00         주식 총 가치: $240.00
        생성자를 사용하여 객체를 재설정한다.
        Nifty Foods를 사용하는 생성자가 호출되었습니다.
        안녕, Nifty Foods!
        갱신된 stock1:
        회사명: Nifty Foods    주식 수:10
          주가: $50.00         주식 총 가치 : $500.00
        프로그램을 종료합니다.
        안녕, NanoSmart!
        안녕, Nifty Foods!
    ```

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.const 멤버 함수
    /*
    ---------------------------------------- 10.const 멤버 함수 ----------------------------------------
    # const 멤버 함수
    ***
    다음과 같은 코드가 있다고 하자.

    ```cpp
        const Stock land = Stock("kda");
        land.show();
    ```

    컴파일러는 두 번째 라인에 대해 이의를 제기할 것이다.
    왜냐하면 const이기 때문에, 변경하면 안 되는 호출 객체를 show() 에 해당하는 코드가 수정하지 않는다는
    보장을 하지 않기 때문이다. show() 메서드는 매개변수를 갖지 않는다. 대신에 show() 메서드가 사용하는 객체는
    메서드 호출에 의해 암시적으로 제공되고 있다. 그러므로 함수가 호출 객체를 변경하지 않는다고 약속하는
    새로운 문법이 필요하다.

    ```cpp
        void show() const;              // 호출 객체를 변경하지 않는다고 약속한다
    ```

    마찬가지로 show() 함수의 정의의 시작 부분도 다음과 같이 된다.
    
    ```cpp
        void Stock::show() const;      // 호출 객체를 변경하지 않는다고 약속한다
    ```
    이런 방식으로 선언되고 정의된 클래스 함수들을 **const 멤버 함수** 라고 한다.

    필요할 때 함수의 형식 매개변수로 const 참조와 포인터를 사용해야 하듯이, 호출 객체를
    변경하면 안 되는 클래스 메서드들은 const로 만들어야 한다.

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.생성자와 파괴자에 대한 요약
    /*
    ---------------------------------------- 10.생성자와 파괴자에 대한 요약 ----------------------------------------
    # 생성자와 파괴자에 대한 요약
    ***
    
    ## 생성자
    생성자는 그 클래스의 객체가 생성될 때마다 호출되는 특별한 종류의 클래스 멤버 함수이다.
    클래스 생성자는 그 클래스와 같은 이름을 가진다. 그러나 함수 오버로딩을 통해, 같은 이름을 사용하는
    생성자를 하나 이상 가질 수 있다. 이 경우, 각각의 생성자는 자신만의 유일한 시그내처 또는 매개변수 리스트를 가져야 한다.
    또한 생성자는 데이터형을 가지지 않고, 클래스 객체의 멤버들을 초기화하는 데 사용된다.
    초기화는 생성자의 매개변수 리스트와 일치하게 이루어져야 한다.

    ```cpp
        Bozo(const char* fname, const char* lname);     // 생성자 원형
    ```

    이 경우에, 이것을 사용하여 다음과 같이 새로운 객체들을 초기화 할 수 있다. 

    ```cpp
        Bozo bozetta = Bozo("Bozetta", "Biggens");      // 기본 형식
        Bozo fufu("Fufu", "O'Dweeb");                   // 짧은 형식
        Bozo* pc = new Bozo("Popo", "Le Peu");          // 동적 객체
    ```

    또한 초기화 리스트도 사용이 가능하다.
    ```cpp
        Bozo bozetta = Bozo{"Bozetta", "Biggens"};      // C++11
        Bozo fufu{"Fufu", "O'Dweeb"};                   // C++11
        Bozo* pc = new Bozo{"Popo", "Le Peu"};          // C++11
    ```

    생성자가 한 개의 매개변수만 가지고 있을 경우, 그 생성자는 생성자의 매개변수와 동일한 데이터형을 가진
    하나의 값으로 객체를 초기화할 경우에 호출된다.
    ```cpp
        Bozo(int age)
    ```
    그렇다면 다음 형식 중 하나를 사용하여 객체를 초기화할 수 있다.
    ```cpp
        Bozo dribble = Bozo(44);        // 제1 형식
        Bozo roon(66);                  // 제2 형식
        Bozo tubby = 32;                // 매개변수가 하나인 생성자를 위한 특별 형식
    ```

    세 번째 예는 새로 나온 내용으로, 11장에서는 이것의 허용을 금지하는 방법을 설명한다.

    ## 디폴트 생성자
    디폴트 생성자는 매개변수가 없으며, 명시적으로 초기화하지 않고 객체를 생성할 때 사용한다.
    사용자가 어떠한 생성자도 제공하지 않으면, 사용자를 대신하여 컴파일러가 디폴트 생성자를 정의한다.
    그렇지 않을 경우 사용자가 디폴트 생성자를 제공해야 하며, 사용자가 제공하는 디폴트 생성자는
    어떠한 매개변수도 사용하지 않거나, 모든 매개변수에 디폴트 값을 사용해야 한다.

    ```cpp
        Bozo();                                 // 디폴트 생성자의 원형
        Bistro(const char* s = "Chez Zero");    // Bistro 클래스 디폴트 생성자
    ```

    프로그램은 초기화되지 않은 객체들에 대해 디폴트 생성자를 사용한다.
    ```cpp
        Bozo bubi;                              // 디폴트 생성자를 사용한다.
        Bozo* pb = new Bozo;                    // 디폴트 생성자를 사용한다.
    ```

    ## 파괴자
    객체가 생성될 때 프로그램이 생성자를 호출하는 것처럼, 객체가 파괴될 때 프로그램은 파괴자를 호출한다.
    파괴자는 클래스당 하나만 가질 수 있으며 리턴형을 갖지 않는다.
    ```cpp
        ~Bozo();                                // 클래스 파괴자
    ```

    클래스 파괴자는 클래스 생성자가 new를 사용할 때 필요하게 된다.

    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.this 포인터
    /*
    ---------------------------------------- 10.this 포인터 ----------------------------------------
    # this 포인터
    ***
    하나의 메서드가 두 개의 객체를 동시에 처리할 필요가 있다.
    그것을 가능케 하기 위해 C++는 **this** 라는 특별한 포인터를 제공한다.

    Stock 클래스 선언은 데이터를 출력은 하지만 분석은 하지 않는다.
    예를 들어, show()의 출력을 살펴보면, 사용자가 직접 어느 주식이 현재 최대 가치인지 알 수 있다.
    하지만, 프로그램이 total_val 에 접근할 수 없기 때문에, 프로그램이 사용자에게 알려줄 순 없다.
    프로그램이 저장된 데이터에 대해 알 수 있게 만드는 가장 직접적인 방법은,
    값을 리턴하는 메서드를 제공하는 것이다. 일반적으로 이를 위해 다음과 같은 인라인 코드를 사용한다.

    ```cpp
        class Stock
        {
        private:
            ...
            double total_val;
            ...
        public:
            double total() const { return total_val;}
            ...
        };
    ```

    이 정의는 결과적으로 total_val을 읽기 전용 메모리로 만든다.

    클래스 선언에 이 함수를 추가하면, 프로그램은 여러 회사들의 주식을 조사하여 그 중에서
    최대 가치를 지닌 주식이 무엇인지 알 수 있다. 하지만 this 포인터를 통해 다른 방식으로 접근 할 수 있다.
    그것은 두 개의 Stock 객체를 조사하여 둘 중 더 큰 것에 대한 참조를 리턴하는 멤버 함수를 정의하는 것이다.

    1. 비교할 두 개의 객체를 그 멤버 함수에 어떤 방법으로 제공할 것인가?
    예를 들어, 최고가를 알려주는 topval() 이름의 메서드를 만들었다고 가정하자.
    stock1.topval() 은 stock1의 객체의 데이터에, stock2.topval() 은 stock2의 객체의 데이터에 접근한다.
    그 메서드로 두 객체를 비교하려면, 두 번째 객체를 매개변수로 전달해야 한다. 이 경우, 매개변수를
    참조로 전달하는 것이 훨씬 효율적이다. 즉, topval() 메서드가 const Stock&형의 매개변수를 사용하도록 할 수 있다.

    2. 그 메서드의 응답을 호출 프로그램에 어떤 방법으로 알릴 것인가?
    가장 직접적인 방법은, 둘 중 주식 가치가 더 큰 객체에 대한 참조를 그 메서드가 리턴하는 것이다.
    그러므로 그 메서드는 원형이 다음과 같을 것이다.

    ```cpp
        const Stock& topval(const Stock& s) const;
    ```

    이 함수는 한 객체에는 암시적으로, 다른 객체에는 명시적으로 접근한다. 그 후, 둘 중 하나에 대한 참조를 리턴한다.
    괄호 안에 있는 const는 그 함수가 명시적으로 접근된 객체를 변경하지 않는다는 뜻이다.
    괄호 뒤에 있는 const는 그 함수가 암시적으로 접근된 객체를 변경하지 않는다는 뜻이다.
    함수는 두 const 객체 중 하나에 대한 참조를 리턴하므로, 리턴형도 const 참조여야한다.

    ```cpp
        top = stock1.topval(stock2);
    ```

    위 구문은, stock1에 암시적으로, stock2에 명시적으로 접근하여, 두 객체를 비교 후 주식 총 가치가 더 큰 객체에 대한 참조를 리턴한다.
    하지만 이런 표기법은 혼란스럽다. 관계 연산자 ( > , < ) 를 사용하여 비교한다면 더 간단할 것이다.
    이는 11장에서 배울 **연산자 오버로딩**을 통해서 할 수 있다. 

    ```cpp
        const Stock& Stock::topval(const Stock& s) const
        {
            if(s.total_val > total_val)
                return s;                   // 매개변수로 전달받은 객체
            else
                return ??????               // 메서드를 호출한 객체
        }
    ```

    여기에서 s.total_val은 매개변수로 전달된 객체의 주식 총 가치이다.
    그리고 total_val은 메시지를 전달받은 객체의 주식 총 가치이다. s.total_val이 total_val보다 크면
    그 함수는 s를 리턴한다. 그렇지 않으면 그 메서드를 호출하는데 사용된 객체를 리턴한다.
    
    문제는 **"그 객체를 무엇이라고 부를 것인가?"** 이다.

    stock1.topval(stock2) 호출을 사용하면, s는 stock2에 대한 참조이다.(즉, stock2의 대용 이름)
    그러나, stock1의 대용 이름은 없다.

    C++가 이 문제를 해결하는 방법은 **this라는 포인터**에 사용이다.
    
    this 포인터는 멤버 함수를 호출하는데 사용된 객체를 지시한다. 
    일반적으로 모든 클래스 메서드들은 그 메서드를 호출하는 객체의 주소로 설정되는 하나의 this 포인터를 갖는다.
    실제로 topval()에 사용되고 있는 total_val은
    this -> total_val(), 의 약식 표기이다.
    ***
    
    그러나 this는 그 객체의 주소이기 때문에, 우리가 리턴하려는 것은 this가 아니다.
    우리가 리턴하려는 것은 객체 자체이기 때문에, *this 에 의하여 표현된다.


    ```cpp
        const Stock& Stock::topval(const Stock& s) const
        {
            if (s.total_val > total_val)
                return s;                   // 매개변수로 전달 받은 객체
            else
                return *this;               // 호출한 객체
        }

    ```


    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.객체 배열
    /*
    ---------------------------------------- 10.객체 배열 ----------------------------------------
    # 객체 배열
    ***
    객체 배열은 표준 데이터형의 배열을 선언하는 것과 완전히 동일한 방법으로 선언한다.

    ```cpp
        Stock mystuff[4];       // 4개의 Stock 객체로 이루어진 배열을 생성한다.
    ```

    배열의 각 원소는 Stock 객체이다. 따라서 Stock 메서드들과 함께 사용할 수 있다.
    또한 생성자를 사용하여 배열 원소들을 초기화할 수 있다. 그러한 경우,
    각각의 원소에 대해 생성자를 호출해야 한다.
    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion
    #pragma region 10.클래스 사용 범위
    /*
    ---------------------------------------- 10.클래스 사용 범위 ----------------------------------------
    # 클래스 사용 범위
    ***


    ***
    출처 : C++ 기초 플러스 6판 / 성안당
    ***
    */
    #pragma endregion

#pragma endregion


//720페이지

#pragma region 메인
//-------------------------[ ProtoType ]-----------------------------------//
class A
{
public:
    A() { cout << "호출"; }
};

//-------------------------[   FBody   ]-----------------------------------//    
int main()
{
    int printAmount = 1;
    int prePrintAmount{};

    for (int i = 0; i < 5; i++)
    {
        prePrintAmount = printAmount;

        for (int j = 4; j > i; j--)
        {
            cout << " ";
        }

        for (; printAmount > 0; printAmount--)
        {
            cout << "* ";
        }
        
        printAmount = ++prePrintAmount;

        if (printAmount == 6)
        {
            cout << "\n";

            printAmount -= 2;
            prePrintAmount = printAmount;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    cout << " ";
                }

                for (; printAmount > 0; printAmount--)
                {
                    cout << "* ";
                }

                printAmount = --prePrintAmount;

                if (prePrintAmount == 0)
                    exit(0);

                cout << "\n";
            }

        }

        cout << "\n";
    }
    

    return 0;
}

//-------------------------[ Func.Def. ]-----------------------------------//



#pragma endregion