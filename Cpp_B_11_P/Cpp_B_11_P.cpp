#include <iostream>
#include <string> //string class 사용 위해
#include <cstring> //C 스타일 문자열 라이브러리
#include <array>
#include <ctime>
using namespace std;



#pragma region 05.템플릿
/*
---------------------------------------- 05.템플릿 ----------------------------------------
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
    #pragma region 05.템플릿
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
    문제 : 두 개의 정수를 입력 받는 프로그램을 작성하라. 입력한 두 정수를 포함하여, 그 사이에 있는
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
    문제 : 팩토리얼의 정의는 다음과 같다. '!' 심볼을 쓰며, 예시로, 4! 같은 경우는 4부터 시작하여 1까지 사이의 모든 정수의 곱이다.
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
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_4
    /*
    ---------------------------------------- 05.프로그래밍 연습_4 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_5
    /*
    ---------------------------------------- 05.프로그래밍 연습_5 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_6
    /*
    ---------------------------------------- 05.프로그래밍 연습_6 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_7
    /*
    ---------------------------------------- 05.프로그래밍 연습_7 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_8
    /*
    ---------------------------------------- 05.프로그래밍 연습_8 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_9
    /*
    ---------------------------------------- 05.프로그래밍 연습_9 ----------------------------------------
    */
    #pragma endregion
    #pragma region 05.프로그래밍 연습_10
    /*
    ---------------------------------------- 05.프로그래밍 연습_10 ----------------------------------------
    */
    #pragma endregion




#pragma endregion
     
    


//262페이지


//-------------------------[ ProtoType ]-----------------------------------//

void Say();

//-------------------------[   FBody   ]-----------------------------------//

struct Explosive // struct(구조체 서술 정의) Explosive(구조체 이름) 
{
    
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