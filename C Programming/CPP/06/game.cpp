#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

int power(int down, int up)
{
    int result = down;
    for (int i = 1; i < up; i++)
    {
        result *= down;
    }
    return result;
}

void randomDice()
{
    srand(static_cast<unsigned int>(time(0)));
    int number = rand();
    int result = number % 6 + 1;
    cout << result << "입니다." << endl;
}

int main()
{
    int menu = 0;

    while (1)
    {
        cout << "Menu 1) 거듭제곱 2) 절대값 3) 주사위 4) 종료" << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            int up = 0;
            int down = 0;
            cout << "밑 : ";
            cin >> up;
            cout << "지수 : ";
            cin >> down;
            cout << power(up, down) << endl;
            break;
        }
        case 2:
        {
            int number = 0;
            cout << "숫자를 입력해주세요 : " << endl;
            cin >> number;
            cout << abs(number) << endl;
            break;
        }
        case 3:
        {
            cout << "당신이 굴린 주사위 값은 ? " << endl;
            randomDice();
            break;
        }
        case 4:
        {
            cout << "프로그램 종료" << endl;
            return 0;
        }
        default:
            cout << "다시 입력해주세요." << endl;
            break;
        }
    }
    return 0;
}