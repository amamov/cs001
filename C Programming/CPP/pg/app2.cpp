// 2. 알파벳, 홀짝, 주사위, 동전, 미니언즈 (제한시간 : 50분, 배점 : 15점)

// 개요
// 수업시간에 학습한 반복문, 함수, 조정자, 조건문, 연산자, 난수처리(랜덤)등을 점검합니다

// 문항설명
// 1) main 함수(구현되어 있음)쪽 코드는 수정하지 않습니다. (수정 시 부정행위 처리)
// 2) 첫 번째 행은 영문 소문자 부터 대문자 홀짝 주사위 동전 미니언즈 순으로 출력합니다 (출력화면 참고)
// 3) 오와 열을 정확히 맞춥니다 (수업시간에 학습한 조정자 활용)
// 4) 알파벳 함수는 소문자와 대문자 두 종류로 소문자는 a~z까지 차례대로 대문자는 랜덤 출력(중복허용)입니다
//    (수업시간에 학습한 함수 오버로딩을 적용)
// 5) 홀짝의 수치는 1~100 사이의 랜덤 넘버입니다
// 6) 주사위는 1~6사이의 랜덤넘버, 동전은 앞면/뒷면 한글 출력입니다.
// 7) 미니언즈 함수 구현 시 케빈, 밥, 스튜어트의 대사는 아래 실행예시를 참고합니다
// 8) 각 함수를 한 줄(함수 별로 세미콜론 1개)로 코드 작성 시 결강 지우개(1회권)를 드립니다
// 9) 부분 점수가 부여되니 최선을 다합니다. 시험에 사용하는 C++ 기술은 교재 6장까지의 내용만 허용됩니다

// // 주의사항
// 10) 수업시간에 배우지 않은 CPP 기법은 부정행위(0점) 처리됩니다
//     ex) 동적메모리할당, 클래스, STL, 연산자오버로딩, 상속 등등
// 11) 고득점자의 코드들는 유사도 검사를 진행하며 필요 시 별도의 질의응답 시간을 가질 수 있습니다

/* 실행예시                      
  소문자   대문자  홀짝         주사위  동전 미니언즈
     a      E  23 is odd!     2  앞면 BOB : THE RULES DON'T APPLY TO ME
     b      X  88 is even     6  뒷면 KEVIN : I MAKE THE RULES
     c      Y  41 is odd!     2  앞면 BOB : THE RULES DON'T APPLY TO ME
     d      M  38 is even     1  뒷면 KEVIN : I MAKE THE RULES
     e      O  73 is odd!     6  앞면 BOB : THE RULES DON'T APPLY TO ME
     f      O  33 is odd!     1  앞면 BOB : THE RULES DON'T APPLY TO ME
     g      L  63 is odd!     2  앞면 BOB : THE RULES DON'T APPLY TO ME
     h      P  94 is even     5  뒷면 BOB : THE RULES DON'T APPLY TO ME
     i      C  81 is odd!     5  앞면 BOB : THE RULES DON'T APPLY TO ME
     j      W  48 is even     2  뒷면 STUART : I BREAK THE RULES
     k      A  53 is odd!     6  앞면 BOB : THE RULES DON'T APPLY TO ME
     l      U  21 is odd!     1  앞면 STUART : I BREAK THE RULES
     m      V  83 is odd!     1  앞면 KEVIN : I MAKE THE RULES
     n      O  43 is odd!     2  앞면 BOB : THE RULES DON'T APPLY TO ME
     o      W  67 is odd!     4  앞면 STUART : I BREAK THE RULES
     p      F   2 is even     1  뒷면 BOB : THE RULES DON'T APPLY TO ME
     q      R  86 is even     2  뒷면 BOB : THE RULES DON'T APPLY TO ME
     r      H  54 is even     6  뒷면 KEVIN : I MAKE THE RULES
     s      R  53 is odd!     1  앞면 KEVIN : I MAKE THE RULES
     t      V  87 is odd!     1  앞면 KEVIN : I MAKE THE RULES
     u      L  33 is odd!     4  앞면 STUART : I BREAK THE RULES
     v      L  63 is odd!     5  앞면 BOB : THE RULES DON'T APPLY TO ME
     w      N  74 is even     5  뒷면 KEVIN : I MAKE THE RULES
     x      Q  35 is odd!     5  앞면 BOB : THE RULES DON'T APPLY TO ME
     y      K  72 is even     5  뒷면 STUART : I BREAK THE RULES
     z      E  48 is even     1  뒷면 KEVIN : I MAKE THE RULES

C:\oop1\week008\Debug\week008.exe(프로세스 17112개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

// 학번 : 12181878
// 성명 : 윤상석

void header();
char abc(char k);
char abc();
bool isodd(unsigned int pick);
void dice();
string coin(unsigned int pick);
void minions(string name);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    unsigned int pick;

    header();
    for (unsigned int k = 97; k <= 122; ++k)
    {
        pick = rand();

        cout << setw(6) << abc(k) << " ";
        cout << setw(6) << abc() << " ";

        cout << setw(3) << pick % 100 + 1;

        if (isodd(pick % 100 + 1))
            cout << setw(8) << " is odd! ";
        else
            cout << setw(8) << " is even ";

        dice();
        cout << setw(6) << coin(pick % 2);

        if (pick % 3 == 0)
            minions("BOB");
        else if (pick % 3 == 1)
            minions("KEVIN");
        else
            minions("STUART");
    }
    return 0;
}

void header()
{
    cout << setw(6) << "소문자";
    cout << setw(12) << "대문자";
    cout << setw(8) << "홀짝";
    cout << setw(18) << "주사위";
    cout << setw(8) << "동전";
    cout << setw(13) << "미니언즈" << endl;
}

char abc(char k)
{
    return k;
}

char abc()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int number = rand() % 90 + 1;
    if (number < 65)
    {
        number = 65 + rand() % 26;
    }

    return number;
}

bool isodd(unsigned int pick)
{
    if (pick % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dice()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand();
    int result = number % 6 + 1;
    cout << setw(6) << result << " ";
}

string coin(unsigned int pick)
{
    if (pick == 0)
    {
        return "앞면 ";
    }
    else
    {
        return "뒷면 ";
    }
}

void minions(string name)
{
    if (name == "BOB")
    {
        cout << name << " : THE RULES DON'T APPLY TO ME" << endl;
    }
    else if (name == "KEVIN")
    {
        cout << name << " : I MAKE THE RULES" << endl;
    }
    else if (name == "STUART")
    {
        cout << name << " : I BREAK THE RULES" << endl;
    }
}