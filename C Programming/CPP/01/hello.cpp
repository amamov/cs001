#include <iostream>
//* # : 전처리기이다. 전처리기는 컴파일을 시작하면 우선적으로 처리한다.
//* iostream : 기본 입출력과 관련된 객체들을 정의한 헤더파일이다. 표준 라이브러리 디렉토리에 존재
// using namespace std;

//* std : namespace, 표준 라이브러리에 있는 변수나 함수는 std 표준 네임스페이스에 포함되어있다.
//* cout : 출력을 담당하는 객체, cout은 std 스코프 안에 cout이 있다. iostream 안에 있다.
//* ::는 스코프 연산자 (범위 지정)
//* endl : 한 줄 바꿀 때

int main() {
    std::cout << "hello world!" << std::endl;
    return 0;
}