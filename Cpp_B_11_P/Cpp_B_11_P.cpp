#include <iostream>
#include <string> //string class 사용 위해
#include <cstring> //C 스타일 문자열 라이브러리
#include <array>
#include <cctype>
#include <ctime>
#include <fstream>  // 파일 I/O 를 위해
#include <cstdlib>  // exit() 지원
using namespace std;



#pragma region 08.템플릿
/*
---------------------------------------- 08.템플릿 ----------------------------------------
*/
#pragma endregion

#pragma region 08.프로그래밍 연습_템플릿
/*
---------------------------------------- 08.프로그래밍 연습_템플릿 ----------------------------------------
문제 :


해답 :


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

#pragma region 08.함수의 활용
    
    #pragma region 08.C++ 인라인(Inline) 함수
    /*
    ---------------------------------------- 08.C++ 인라인(Inline) 함수 ----------------------------------------


    */
    #pragma endregion



#pragma endregion

    


//498페이지

#pragma region 메인
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


#pragma endregion