#include <cstdlib>
#include <ctime>  //* 접두어 c가 붙은 클래스들은 c 언어에서 사용하던 라이브러리 #include <time.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    srand((unsigned int)time(0));  // 시드값을 시간으로 조정
    string students[] = {"yoon", "kim", "sang", "seok"};
    int n = rand() % students->size();  // 난수 발생
    cout << students[n] << endl;
    return 0;
}