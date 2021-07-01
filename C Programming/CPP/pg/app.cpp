// 1. 슈퍼김밥 가게에 점심을 먹으러 간 케빈, 밥, 스튜어트 (제한시간 : 30분, 배점 : 15점)

// 개요
// for, while, switch, if 등의 구문을 활용하여 메인함수 코드를 구현합니다

// 문항설명
// 1) menu 함수(구현되어 있음)쪽 코드는 수정하지 않습니다 (수정 시 부정행위 처리)
// 2) 본 페이지 맨 밑에 프로그램 코드를 붙여넣기 후 코딩을 시작합니다
//    부분 점수가 부여되며 메인함수 안쪽에 학번/성명 (필수) 적고 코드를 작성합니다
//    코드작성이 완료 되면 감독관 허가 후 cpp파일만 업로드 합니다
// 3) 더치페이 시 소수점 1번째 자리까지 출력합니다 (수업시간에 학습한 조정자 활용. 실행예시 4 참고)
// 4) 음식 주문 시 마다 현재까지의 주문 금액을 누산 출력합니다
// 5) 메뉴에 없는 번호 입력 시 "올바른 값을 입력해주세요!"를 출력하고 다시 입력을 받습니다 (실행예시 1 참고)
// 6) 4번 메뉴 선택 시 케빈, 밥, 스튜어트(랜덤) 중 한 명이 주문을 취소 시켜 현재 주문 총합 금액이 0으로 리셋 됩니다
//    주문취소 대사는 다음과 같습니다 (아래 문구를 코드에 붙여넣어 작성합니다)
//    KEVIN : I MAKE THE RULES
//    BOB : THE RULES DON'T APPLY TO ME
//    STUART : I BREAK THE RULES
//    중간에 주문을 취소했던 당사자가 대금 결제자로 당첨 됩니다 (주문완료 후 사다리 메뉴 선택시)
//    (실행예시 2 참고)
// 7) 중간에 다시계산(4번메뉴 : 주문취소)하는 일이 없으면 사다리 기능 선택 시 점심을 사는 사람은 랜덤하게 결정됩니다
//    (실행예시 1 참고)
// 8) 주문완료 후 1, 2번이 아닌 값 입력 시 "잘못 선택하셨습니다. 주문 프로그램 종료..." 문구 출력 후 프로그램을
//    종료합니다 (실행예시 3 참고)
// 9) 부분 점수가 부여되니 최선을 다합니다. 시험에 사용하는 C++ 기술은 교재 6장까지의 내용만 허용됩니다

// // 주의사항
// 10) 수업시간에 배우지 않은 CPP 기법은 부정행위(0점) 처리됩니다
//     ex) 동적메모리할당, 클래스, STL, 연산자오버로딩, 상속 등등
// 11) 고득점자의 코드들는 유사도 검사를 진행하며 필요 시 별도의 질의응답 시간을 가질 수 있습니다

/* 실행예시 1
$$$슈퍼김밥 배드메뉴$$$
1) 애플김밥 : 3500원
2) 유부초밥 : 3000원
3) 불닭라면 : 2000원
4) 다시계산
5) 주문완료
1
현재 주문 총합 : 3500
9
올바른 값을 입력해주세요!
3
현재 주문 총합 : 5500
5
총 금액 : 5500원
1) 더치페이 2) 사다리(랜덤) : 2
STUART 당첨
*/

/* 실행예시 2
$$$슈퍼김밥 배드메뉴$$$
1) 애플김밥 : 3500원
2) 유부초밥 : 3000원
3) 불닭라면 : 2000원
4) 다시계산
5) 주문완료
2
현재 주문 총합 : 3000
2
현재 주문 총합 : 6000
1
현재 주문 총합 : 9500
4
KEVIN : I MAKE THE RULES
2
현재 주문 총합 : 3000
1
현재 주문 총합 : 6500
5
총 금액 : 6500원
1) 더치페이 2) 사다리(랜덤) : 2
KEVIN 당첨
*/

/* 실행예시 3
$$$슈퍼김밥 배드메뉴$$$
1) 애플김밥 : 3500원
2) 유부초밥 : 3000원
3) 불닭라면 : 2000원
4) 다시계산
5) 주문완료
1
현재 주문 총합 : 3500
5
총 금액 : 3500원
1) 더치페이 2) 사다리(랜덤) : 7
잘못 선택하셨습니다. 주문 프로그램 종료...
*/

/* 실행예시 4
$$$슈퍼김밥 배드메뉴$$$
1) 애플김밥 : 3500원
2) 유부초밥 : 3000원
3) 불닭라면 : 2000원
4) 다시계산
5) 주문완료
2
현재 주문 총합 : 3000
3
현재 주문 총합 : 5000
1
현재 주문 총합 : 8500
5
총 금액 : 8500원
1) 더치페이 2) 사다리(랜덤) : 1
각자 2833.3씩~
*/

// 아래 코드를 활용합니다
#include <iostream>
#include <iomanip>

using namespace std;

void menu()
{
    cout << left;
    cout << "$$$슈퍼김밥 배드메뉴$$$\n";
    cout << "1) 애플김밥 : 3500원\n";
    cout << "2) 유부초밥 : 3000원\n";
    cout << "3) 불닭라면 : 2000원\n";
    cout << "4) 다시계산\n";
    cout << "5) 주문완료\n";
}

double nBang(int total);

void randomGame(int cho);

int reset();

int main()
{
    // 학번 : 12181878
    // 성명 : 윤상석

    int number = 0;
    int total = 0;
    int cho = 0;

    menu();

    while (true)
    {
        cin >> number;
        switch (number)
        {
        case 1:
        {
            total += 3500;
            cout << "현재 주문 총합 : " << total << endl;
            break;
        }
        case 2:
        {
            total += 3000;
            cout << "현재 주문 총합 : " << total << endl;
            break;
        }
        case 3:
        {
            total += 2000;
            cout << "현재 주문 총합 : " << total << endl;
            break;
        }
        case 4:
        {
            cho = reset();
            total = 0;
            break;
        }
        case 5:
        {
            int nextLevel = 0;
            cout << "총 금액 : " << total << "원" << endl;
            cout << "1) 더치페이 2) 사다리(랜덤) " << endl;
            cin >> nextLevel;
            if (nextLevel == 1)
            {
                double result = nBang(total);
                cout << "각자 " << fixed << setprecision(1) << result << "씩~" << endl;
            }
            else if (nextLevel == 2)
            {

                randomGame(cho);
            }
            else
            {
                cout << "잘못 선택하셨습니다. 주문 프로그램 종료..." << endl;
            }
            return 0;
            break;
        }
        default:
            cout << "올바른 값을 입력해주세요!" << endl;
            break;
        }
    }
    return 0;
}

double nBang(int total)
{
    return total / 3;
}

void randomGame(int cho)
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand() % 3 + 1;
    if (cho != 0)
    {
        if (cho == 1)
        {
            cout << "KEVIN 당첨" << endl;
        }
        else if (cho == 2)
        {
            cout << "BOB 당첨" << endl;
        }
        else if (cho == 3)
        {
            cout << "STUART 당첨" << endl;
        }
    }
    if (number == 1)
    {
        cout << "KEVIN 당첨" << endl;
    }
    else if (number == 2)
    {
        cout << "BOB 당첨" << endl;
    }
    else if (number == 3)
    {
        cout << "STUART 당첨" << endl;
    }
}

int reset()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand() % 3 + 1;
    if (number == 1)
    {
        cout << "KEVIN : I MAKE THE RULES" << endl;
    }
    else if (number == 2)
    {
        cout << "BOB : THE RULES DON'T APPLY TO ME" << endl;
    }
    else if (number == 3)
    {
        cout << "STUART : I BREAK THE RULES" << endl;
    }
    return number;
}